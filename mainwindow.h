#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Szachy; }
QT_END_NAMESPACE

/**
  * \mainpage
  * Wirtualna szachownica
  * \author Radosław Polak
  * \par Kontakt:
  * \a radoslaw.polak.stud@pw.edu.pl
  *
  * O projekcie:
  * \n
  * Opis działania aplikacji (z interfejsem graficznym:
  * Aplikacja po uruchomieniu będzie generowała szachownicę z odpowiednio  ustawionymi figurami, figury białe u dołu,
  * figury czarne u góry. Białe rozpoczynają partię (potem ruchy wykonywane na zmiane).
  *
  * Wykonywanie ruchów działa na zasadzie:
  * - kliknięcie na figurę pokazuje wszystkie możliwe do wykonania w danej pozycji
  * ruchy po szachownicy dla danej figury (zgodnie z zasadami poruszania się po
  * szachownicy poszczególnych figur szachowych), pola te będą zaznaczone
  * pewnym kolorem (np. zielonym), będzie to wyglądało tak, że pole na którym
  * znajduje się figura będzie ciemniejsze (w przypadku zielonego, ciemny zielony) a
  * pola, do których możemy się przesunąć będą jaśniejsze (w przypadku zielonego,
  * jasny zielony)
  * - jeżeli na polu do którego chcemy się przemieścić znajduje się figura
  * przeciwnika, to następuje bicie tej figury
  * - jeżeli figura zaatakuje króla, to pole, na którym stoi król będzie podświetlone
  * na kolor czerwony oraz jeżeli będziemy chcieli poruszyć się tym królem to
  * odpowiednim kolorem zostaną oznaczone pola, które są niebezpieczne (pola, w
  * których król dalej będzie szachowany), pozostałe (bezpieczne) pola będą
  * oznaczane tak jak dla wszystkich pozostałych figur (w projekcie postaram się
  * zrealizować to tak aby w ogóle nie było możliwości przesunięcia króla w
  * niebezpieczne pola)
  * - po obu stronach szachownicy są dodawane ikony figur które zostały zbite, tzn.
  * po lewej stronie będą wyświetlane białe figury, które zostały zbite a po prawej
  * analogicznie zbite czarne figury
  * - nad szachownicą będzie wyświetlana aktualna tura (ruch białych czy czarnych)
  * - jeśli chodzi o kontrolę ruchu króla to przy kliknięciu na figurę króla na czerwono
  * wyświetlane są niebezpieczne pola dla niego (pola w które teoretycznie król może się
  * poruszyć ale są one pod biciem innej figury przeciwnego koloru)
  *
  */

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
