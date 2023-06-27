#include <iostream>

using namespace std;

class Mnozenie {
private:
    double liczba1; // Prywatna zmienna reprezentująca pierwszą liczbę
    double liczba2; // Prywatna zmienna reprezentująca drugą liczbę

public:
    Mnozenie(double a, double b) {
        liczba1 = a; 
        liczba2 = b; 
    }

    double wynik() {
        return liczba1 * liczba2; // Zwracanie wyniku mnożenia
    }
};

int main() {
    double a, b;
    cout << "Podaj pierwszą liczbę: ";
    cin >> a; 
    cout << "Podaj drugą liczbę: "; 
    cin >> b; 

    Mnozenie mnozenie(a, b); // Utworzenie obiektu klasy Mnozenie
    double wynik = mnozenie.wynik(); // Wywołanie metody wynik()

    cout << "Wynik mnożenia: " << wynik << endl; 

    return 0;
}
