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

#ifndef ANAGRAMSOLVER_H
#define ANAGRAMSOLVER_H

#include <QWidget>
#include <QRect>
#include <QDesktopWidget>
#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QHash>
#include <QtAlgorithms>

#include <sys/time.h>
#include "about.h"


namespace Ui {
    class AnagramSolver;
}

class AnagramSolver : public QWidget
{
    Q_OBJECT

public:
    explicit AnagramSolver(QWidget *parent = 0);
    int load_File();
    ~AnagramSolver();

private slots:
    void on_solveButton_clicked();
    void on_aboutButton_clicked();

private:
    Ui::AnagramSolver *ui;
    QHash<QString, QString> hash;

};

#endif // ANAGRAMSOLVER_H
