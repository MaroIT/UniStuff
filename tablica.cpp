#include <iostream>

using namespace std;

class Tablica {
private:
    int* dane;   // Wskaźnik na dynamicznie alokowaną tablicę
    int rozmiar; // Rozmiar tablicy

public:
    // Konstruktor - tworzy nową tablicę o podanym rozmiarze
    Tablica(int rozmiar) {
        this->rozmiar = rozmiar;
        dane = new int[rozmiar];
        cout << "Konstruktor" << endl;
    }

    // Konstruktor kopiujący - tworzy kopię tablicy
    Tablica(const Tablica& other) {
        rozmiar = other.rozmiar;
        dane = new int[rozmiar];
        for (int i = 0; i < rozmiar; i++) {
            dane[i] = other.dane[i];
        }
        cout << "Konstruktor kopiujący" << endl;
    }

    // Destruktor - zwalnia pamięć zajmowaną przez tablicę
    ~Tablica() {
        delete[] dane;
        cout << "Destruktor" << endl;
    }

    // Operator przypisania - przypisuje wartości z jednej tablicy do drugiej
    Tablica& operator=(const Tablica& other) {
        if (this != &other) {
            delete[] dane;
            rozmiar = other.rozmiar;
            dane = new int[rozmiar];
            for (int i = 0; i < rozmiar; i++) {
                dane[i] = other.dane[i];
            }
        }
        cout << "Operator przypisania" << endl;
        return *this;
    }
};
