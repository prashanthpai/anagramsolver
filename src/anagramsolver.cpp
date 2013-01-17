/*
Copyright 2012 Prashanth Pai

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This package is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#include "anagramsolver.h"
#include "ui_anagramsolver.h"


double systemTime()
{
        static struct timeval t;
        gettimeofday(&t,NULL);
        return ((double)t.tv_sec) + ((double)t.tv_usec / 1000000.0);
}


AnagramSolver::AnagramSolver(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AnagramSolver)
{
    ui->setupUi(this);
    const QRect screen = QApplication::desktop()->screenGeometry();
    this->move( screen.center() - this->rect().center() );
}

AnagramSolver::~AnagramSolver()
{
    delete ui;
}

int AnagramSolver::load_File()
{
    QFile file(":/text/ds.dat");
    if (!file.open(QFile::ReadOnly))
    {
        ui->outputWindow->setText("Initializing resource...FAILED!\n");
        return 0;
    }

    QTextStream in(&file);
    QString line;
    QStringList list;

    line=in.readLine();
    while(!line.isNull() && !line.isEmpty())
    {
        list=line.split(":");
        hash.insert(list.at(0),list.at(1));
        line=in.readLine();
    }

    file.close();
//    Q_CLEANUP_RESOURCE(resource);
    ui->outputWindow->setText("Initializing resource...DONE!\n");
    return 1;
}

void AnagramSolver::on_solveButton_clicked()
{
    double t_start,t_end;
    t_start=systemTime();

    QRegExp inputString("[a-z][a-z][a-z]*");
    QString result,value,query;
    QStringList list;

    query=ui->inputWindow->toPlainText();
    if(query.isEmpty())
    {
        ui->outputWindow->setText("Input field cannot be left blank.\nPlease enter an anagram to be solved!");
        ui->elapsedTimeWindow->clear();
        return;
    }
    query=query.trimmed();
    query=query.toLower();
    qSort(query.begin(),query.end());
    if(query.length()<2)
    {
        ui->outputWindow->setText("Invalid input.\nInput word must be at least two characters long.\n");
        ui->elapsedTimeWindow->clear();
        return;
    }
    if(!inputString.exactMatch(query))
    {
        ui->outputWindow->setText("Invalid input.\nInput word must contain only alphabets without any whitespace or special characters.\n");
        ui->elapsedTimeWindow->clear();
        return;
    }
    if(hash.contains(query))
    {
        value=hash.value(query);
        list=value.split(" ",QString::SkipEmptyParts);
        for(int i=0;i<list.size(); i++)
        {
            result.append(list.at(i));
            result.append("\n");
        }
    }
    else
    {
        result="No Solution!\nThis program currently supports only English words.";
    }

    ui->outputWindow->setText(result);
    t_end=systemTime();
    ui->elapsedTimeWindow->setText(QString::number(t_end-t_start));
}


void AnagramSolver::on_aboutButton_clicked()
{
    About *aboutDialog = new About(this);
    aboutDialog->show();
    aboutDialog->raise();
    aboutDialog->activateWindow();
}

