QT       += core gui widgets sql
TARGET = KnowledgeField
CONFIG += c++11 static debug_and_release
TEMPLATE = lib

DEFINES += STATIC_LIB

VPATH += ../../../src/libs/KnowledgeField

INCLUDEPATH +=  ../../../src ../../../lib/src ../../../lib/src/libxml2/include ../../../lib/src/libiconv/include

SOURCES += knowledge_field_t.cpp \
    alertshow.cpp \
    teststart.cpp

HEADERS += knowledge_field_t.h \
    alertshow.h \
    teststart.h

FORMS += \
    alertshow.ui \
    teststart.ui

LIBS += -L../ATProject -lATProject -L../ATGUI -lATGUI -L../ATCore -lATCore -L../libiconv -liconv -L../libxml2 -lxml2
