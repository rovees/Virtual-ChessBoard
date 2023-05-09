#include "mainwindow.h"
#include "ui_Szachy.h"

Szachy::Szachy(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Szachy)
{
    ui->setupUi(this);
}

Szachy::~Szachy()
{
    delete ui;
}
