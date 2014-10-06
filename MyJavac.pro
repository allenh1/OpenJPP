QT += core
QT -= gui

TARGET = MyJavac
CONFIG += console c++11
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cc \
		   MainThread.cpp \
		   optimizer.cpp

HEADERS += optimizer.h \
		   MainThread.h
