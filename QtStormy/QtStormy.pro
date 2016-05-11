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
    ConnectionPage.cpp \
    MainFenetre.cpp \
    Cpu.cpp \
    Ram.cpp

HEADERS  += \
    Api/File.hpp \
    Api/Packet.hpp \
    ConnectionPage.hpp \
    MainFenetre.hpp \
    Cpu.hpp \
    Ram.hpp
