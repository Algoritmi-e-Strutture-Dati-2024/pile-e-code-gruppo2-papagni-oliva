#include <iostream>
#include <stdexcept>

// Implemento la classe Pila
template <typename T>
class Pila {
  private:
    ListaPuntatori<T> lista; // Uso la classe ListaPuntatori 
  public:
    // Aggiungo un elemento alla pila
    void push(T elem) {
        lista.inslista(elem, 1); // Inserisco l'elemento in cima alla lista
    }

    // elimino l'elemento in cima e lo visualizzo
    T pop() {
        if (isEmpty()) {
            throw std::out_of_range("C'è un errore: la pila è vuota.");
        }
        T topElem = lista.leggilista(1); // Leggo l'elemento in cima 
        lista.canclista(1);             // elimino l'elemento 
        return topElem;
    }

    // visualizzo l'elemento in cima alla pila senza rimuoverlo
    T top() const {
        if (isEmpty()) {
            throw std::out_of_range("C'è un errore: la  pila è vuota.");
        }
        return lista.leggilista(1); // Leggo l'elemento in cima
    }

    // Verifico se la pila è vuota
    bool isEmpty() const {
        return lista.listavuota(); // Uso il metodo listavuota() 
    }

    // Visualizzo il numero di elementi nella pila
    int size() const {
        return lista.lunghezza(); // Uso il metodo lunghezza() 
};

int main() {
    Pila<int> pila;

    // Per esempio utilizzo: 
    try {
        pila.push(1);
        pila.push(2);
        pila.push(3);

        std::cout << "Elemento in cima: " << pila.top() << std::endl; // 3
        std::cout << "Dimensione della pila: " << pila.size() << std::endl; // 3

        std::cout << "Rimuovo: " << pila.pop() << std::endl; // 3
        std::cout << "Rimuovo: " << pila.pop() << std::endl; // 2

        std::cout << "Elemento in cima: " << pila.top() << std::endl; // 1
        std::cout << "Dimensione della pila: " << pila.size() << std::endl; // 1

        pila.pop(); // Rimuovo l'ultimo elemento

        // Tentativo di pop su pila vuota
        pila.pop(); // Genera eccezione
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}

