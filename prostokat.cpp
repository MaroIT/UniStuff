#include <iostream>

using namespace std;

class Prostokat {
private:
    double dlugosc;    // Zmienna prywatna reprezentująca długość boku prostokąta
    double szerokosc;  // Zmienna prywatna reprezentująca szerokość boku prostokąta

public:
    // Konstruktor klasy Prostokat, inicjalizuje długość i szerokość na podstawie podanych argumentów
    Prostokat(double dlugosc, double szerokosc) {
        this->dlugosc = dlugosc;
        this->szerokosc = szerokosc;
    }

    // Funkcja publiczna obliczająca pole prostokąta
    double pole() {
        return dlugosc * szerokosc;
    }

    // Funkcja publiczna obliczająca obwód prostokąta
    double obwod() {
        return 2 * (dlugosc + szerokosc);
    }
};

int main() {
    double dlugosc, szerokosc;

    // Wprowadzenie długości prostokąta
    cout << "Podaj długość prostokąta: ";
    cin >> dlugosc;

    // Wprowadzenie szerokości prostokąta
    cout << "Podaj szerokość prostokąta: ";
    cin >> szerokosc;

    // Utworzenie obiektu klasy Prostokat o podanych wymiarach
    Prostokat prostokat(dlugosc, szerokosc);

    // Obliczenie pola prostokąta i wyświetlenie wyniku
    cout << "Pole prostokąta: " << prostokat.pole() << endl;

    // Obliczenie obwodu prostokąta i wyświetlenie wyniku
    cout << "Obwód prostokąta: " << prostokat.obwod() << endl;

    return 0;
}
