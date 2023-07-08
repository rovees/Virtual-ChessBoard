QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Bishop.cpp \
    BishopGraphics.cpp \
    Button.cpp \
    ChessBoard.cpp \
    ChessSquare.cpp \
    ChessSquareGraphicsItem.cpp \
    Game.cpp \
    GameGraphics.cpp \
    King.cpp \
    KingGraphics.cpp \
    Knight.cpp \
    KnigthGraphics.cpp \
    Pawn.cpp \
    PawnGraphics.cpp \
    Piece.cpp \
    PieceGraphicsItem.cpp \
    Queen.cpp \
    QueenGraphics.cpp \
    Rook.cpp \
    RookGraphics.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    Bishop.h \
    Bishop.h \
    BishopGraphics.h \
    Button.h \
    ChessBoard.h \
    ChessSquare.h \
    ChessSquareGraphicsItem.h \
    Game.h \
    GameGraphics.h \
    King.h \
    King.h \
    KingGraphics.h \
    Knight.h \
    Knight.h \
    KnightGraphics.h \
    Pawn.h \
    Pawn.h \
    PawnGraphics.h \
    Piece.h \
    PieceGraphicsItem.h \
    Pieces.h \
    Queen.h \
    Queen.h \
    QueenGraphics.h \
    Rook.h \
    Rook.h \
    RookGraphics.h \
    mainwindow.h

FORMS += \
    Szachy.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
