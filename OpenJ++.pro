QT += core
QT -= gui

TARGET = OpenJ++
CONFIG += console c++11
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cc \
		   MainThread.cpp \
		   compiler.cpp

HEADERS += compiler.h \
		   MainThread.h
