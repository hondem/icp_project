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
    Utils/MoveRecord.cpp \
    Gui/Window.cpp \
    Gui/GBoard.cpp \
    Gui/GField.cpp \
    Gui/GFigure.cpp \
    Gui/GTabBtn.cpp \
    Gui/GUndoButton.cpp \
    Gui/GRedoButton.cpp \
    Gui/GMoveList.cpp \
    Gui/GInterval.cpp \
    Gui/GPlayButton.cpp \
    Gui/GPauseButton.cpp \
    Gui/GFileOpenButton.cpp \
    Gui/GFileSaveAsButton.cpp \
    Gui/GBoardAxis.cpp \

HEADERS += \
    Field.h \
    Coords.h \
    Utils/MoveRecord.h \
    Utils/MoveRecord.h \
    Gui/Window.h \
    Gui/GBoard.h \
    Gui/GField.h \
    Gui/GFigure.h \
    Gui/GTabBtn.h \
    Gui/GUndoButton.h \
    Gui/GRedoButton.h \
    Gui/GPlayButton.h \
    Gui/GPauseButton.h \
    Gui/GFileOpenButton.h \
    Gui/GFileSaveAsButton.h \
    Gui/GBoardAxis.h \

RESOURCES = Images/sources.qrc
