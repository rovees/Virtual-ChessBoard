QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Bishop.cpp \
    ChessBoard.cpp \
    ChessBoardWindow.cpp \
    ChessGame.cpp \
    King.cpp \
    Knight.cpp \
    Pawn.cpp \
    Piece.cpp \
    Queen.cpp \
    Rook.cpp \
    Szachy.cpp \
    main.cpp

HEADERS += \
    Bishop.h \
    Bishop.h \
    ChessBoard.h \
    ChessBoardWindow.h \
    ChessGame.h \
    King.h \
    King.h \
    Knight.h \
    Knight.h \
    Pawn.h \
    Pawn.h \
    Piece.h \
    Pieces.h \
    Queen.h \
    Queen.h \
    Rook.h \
    Rook.h \
    Structures.h \
    Szachy.h

FORMS += \
    Szachy.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
