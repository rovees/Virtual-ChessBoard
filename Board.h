#ifndef BOARD_H
#define BOARD_H

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

class Board : public QMainWindow
{
    Q_OBJECT

public:
    Board(QWidget *parent = nullptr);
    void mousePressEvent(QMouseEvent *event);
    void dragEnterEvent(QDragEnterEvent *event);
    void dragMoveEvent(QDragMoveEvent *event);
    void ropEvent(QDropEvent *event);
    void createChessboard();
    ~Board();
};

#endif // BOARD_H
