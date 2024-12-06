#include <iostream>
#include <stdexcept>

template <typename T>
class Coda {
  private:
    ListaPuntatori<T> lista;

  public:
    void enqueue(T elem) {
        lista.inslista(elem, lista.lunghezza() + 1); // inserisco l'elemento in fondo alla lista
    }

    // elimino l'elemento in testa alla coda e lo visualizzo
    T dequeue() {
        if (isEmpty()) {
            throw std::out_of_range(" C'è un errore: la coda è vuota.");
        }
        T frontElem = lista.leggilista(1); // Leggo l'elemento in testa
        lista.canclista(1);               // Elimino l'elemento
        return frontElem;
    }

    // Visualizzo l'elemento in testa alla coda senza rimuoverlo
    T front() const {
        if (isEmpty()) {
            throw std::out_of_range("C'è un errore: la  coda è vuota.");
        }
        return lista.leggilista(1); // Leggo l'elemento in testa
    }

    // Controllo se la coda è vuota
    bool empty() const {
        return lista.listavuota(); 
    }

    // Visualizzo il numero di elementi della coda
    int size() const {
        return lista.lunghezza(); 
    }
};

int main() {
    Coda<int> coda;

    try {
        coda.enqueue(15);
        coda.enqueue(25);
        coda.enqueue(35);

        std::cout << "Elemento in testa: " << coda.front() << std::endl; // 15
        std::cout << "Dimensione della coda: " << coda.size() << std::endl; // 3

        std::cout << "Rimuovo: " << coda.dequeue() << std::endl; // 15
        std::cout << "Rimuovo: " << coda.dequeue() << std::endl; // 25

        std::cout << "Elemento in testa: " << coda.front() << std::endl; // 35
        std::cout << "Dimensione della coda: " << coda.size() << std::endl; // 1

        coda.dequeue(); // Elimino l'ultimo elemento
    }

    return 0;
}

