QT       += core gui

TARGET = anagramsolver
TEMPLATE = app

VERSION = 0.3

CONFIG(debug, debug|release) {
    DESTDIR = build/debug
} else {
    DESTDIR = build/release
}

OBJECTS_DIR = $${DESTDIR}/obj
MOC_DIR = $${DESTDIR}/moc
RCC_DIR = $${DESTDIR}/rcc
UI_DIR = $${DESTDIR}/ui

SOURCES += src/main.cpp \
        src/anagramsolver.cpp \
    src/about.cpp \
    src/license.cpp

HEADERS  += src/anagramsolver.h \
    src/about.h \
    src/license.h

FORMS    += src/anagramsolver.ui \
    src/about.ui \
    src/license.ui

RESOURCES += \
    src/resource.qrc

target.path = /opt/extras.ubuntu.com/anagramsolver/
INSTALLS += target

iconfiles.files += src/icons/*
iconfiles.path = /opt/extras.ubuntu.com/anagramsolver/icons/
INSTALLS += iconfiles

shortcutfiles.files += extras-anagramsolver.desktop
shortcutfiles.path = /usr/share/applications/
INSTALLS += shortcutfiles
