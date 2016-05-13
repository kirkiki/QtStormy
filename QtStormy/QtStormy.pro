#-------------------------------------------------
#
# Project created by QtCreator 2016-05-10T10:56:17
#
#-------------------------------------------------

QT += core gui widgets network charts

greaterThan(QT_MAJOR_VERSION, 4): QT += core gui widgets network

TARGET = QtStormy
TEMPLATE = app

win32:LIBS+= -lws2_32

SOURCES += main.cpp\
    Api/File.cpp \
    Api/Packet.cpp \
    MainFenetre.cpp \
    Ram.cpp \
    ConnectionWidget.cpp \
    DataWidget.cpp \
    CpuWidget.cpp \
    Cpu.cpp

HEADERS  += \
    Api/File.hpp \
    Api/Packet.hpp \
    MainFenetre.hpp \
    Ram.hpp \
    ConnectionWidget.hpp \
    DataWidget.hpp \
    CpuWidget.hpp \
    Cpu.hpp
