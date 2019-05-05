QT += widgets core gui

QMAKE_CXXFLAGS += -std=c++14 -Wunused-parameter -g

CONFIG += debug

TARGET = ../chess

SOURCES += \
    *.cpp \
    FigureType/Bishop.cpp \
    FigureType/King.cpp \
    FigureType/Knight.cpp \
    FigureType/Pawn.cpp \
    FigureType/Queen.cpp \
    FigureType/Rook.cpp \

HEADERS += \
    Field.h
