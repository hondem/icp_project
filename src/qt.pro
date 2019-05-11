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
    Utils/Parser.cpp \
    Gui/Window.cpp \
    Gui/GBoard.cpp \
    Gui/GField.cpp \
    Gui/GFigure.cpp \

HEADERS += \
    Field.h \
    Utils/MoveRecord.h \
    Gui/Window.h \
    Gui/GBoard.h \
    Gui/GField.h \
    Gui/GFigure.h \

RESOURCES = Images/sources.qrc
