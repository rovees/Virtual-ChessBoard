#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Szachy; }
QT_END_NAMESPACE

/**
 * @brief Klasa reprezentująca główne okno aplikacji Szachy.
 */
class Szachy : public QMainWindow
{
    Q_OBJECT

public:

    /**
     * @brief Konstruktor klasy Szachy.
     * \param parent Wskaźnik na obiekt rodzica (QWidget).
     */
    Szachy(QWidget *parent = nullptr);

    /**
     * @brief Destruktor klasy Szachy.
     */
    ~Szachy();

private:
    Ui::Szachy *ui; /**< Wskaźnik na obiekt interfejsu użytkownika (Ui::Szachy). */

};

#endif // MAINWINDOW_H
