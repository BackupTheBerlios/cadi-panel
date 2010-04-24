# -------------------------------------------------
# Project created by QtCreator 2010-02-06T20:39:39
# -------------------------------------------------
TARGET = cadi
TEMPLATE = app
SOURCES += main.cpp \
    cadi.cpp \
    distribution.cpp \
    de.cpp \
    process.cpp \
    shellscripts.cpp \
    modules/general.cpp \
    modules/categories.cpp \
    modules/update.cpp \
    modules/hardwareCPU.cpp \
    modules/hardwareMEM.cpp \
    data/db.cpp
HEADERS += cadi.h \
    distribution.h \
    de.h \
    process.h \
    shellscripts.h \
    modules/general.h \
    modules/categories.h \
    modules/update.h \
    modules/hardwareCPU.h \
    modules/hardwareMEM.h \
    data/db.h
FORMS += cadi.ui \
    modules/general.ui \
    modules/categories.ui \
    modules/update.ui \
    modules/hardwareCPU.ui \
    modules/hardwareMEM.ui
OBJECTS_DIR = build
MOC_DIR = build
RCC_DIR = build
UI_DIR = build
RESOURCES += resources.qrc
QT += xml \
    sql
