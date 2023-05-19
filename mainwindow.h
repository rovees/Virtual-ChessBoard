#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Szachy; }
QT_END_NAMESPACE

class Szachy : public QMainWindow
{
    Q_OBJECT

public:
    Szachy(QWidget *parent = nullptr);
    ~Szachy();

private:
    Ui::Szachy *ui;
};
#endif // MAINWINDOW_H
