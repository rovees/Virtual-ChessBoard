#ifndef CHESSBOARDWINDOW_H
#define CHESSBOARDWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QMouseEvent>
#include <QDropEvent>
#include <QDrag>
#include <QDragEnterEvent>
#include <QMimeData>
#include <QPixmap>
#include <QGridLayout>
#include <QWidget>



class ChessBoardWindow : public QMainWindow
{
    Q_OBJECT

    int selectedPieceRow;
    int selectedPieceCol;
    bool isPieceSelected;
public:
    // figury będą przesuwane poprzez kliknięcie na figure i potem na wybrane pole
    ChessBoardWindow(QWidget *parent = nullptr);
    void mousePressEvent(QMouseEvent *event);
    void dragEnterEvent(QDragEnterEvent *event);
    void dragMoveEvent(QDragMoveEvent *event);
    void dropEvent(QDropEvent *event);
    void createChessboard();
    ~ChessBoardWindow();

signals:
    // void movePiece();
};

#endif // CHESSBOARDWINDOW_H
