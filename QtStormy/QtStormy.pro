#-------------------------------------------------
#
# Project created by QtCreator 2016-05-10T10:56:17
#
#-------------------------------------------------

QT += core gui widgets network charts

greaterThan(QT_MAJOR_VERSION, 4): QT += core gui widgets network

TARGET = QtStormy
TEMPLATE = app


SOURCES += main.cpp\
    Api/File.cpp \
    Api/Packet.cpp \
    Api/UDPSocket.cpp \
    ConnectionPage.cpp \
    MainFenetre.cpp

HEADERS  += \
    Api/File.hpp \
    Api/Packet.hpp \
    Api/UDPSocket.hpp \
    ConnectionPage.hpp \
    MainFenetre.hpp
