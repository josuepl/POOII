#include <iostream>
using namespace std;

struct Nodo {
    int data;
    Nodo* next;

    Nodo(int val) : data(val), next(nullptr) {}
};

class ListaLigada {
public:
    Nodo* head;

    ListaLigada() : head(nullptr) {}

    void insertAtHead(int value) {
        Nodo* newNodo = new Nodo(value);
        newNodo->next = head;
        head = newNodo;
    }

    void deleteNodo(int value) {
        if (!head) return;  // Si la lista está vacía, no hacemos nada
        
        // Si el nodo a eliminar es el primero
        if (head->data == value) {
            Nodo* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        // Buscamos el nodo a eliminar
        Nodo* current = head;
        while (current->next && current->next->data != value) {
            current = current->next;
        }

        // Si encontramos el nodo
        if (current->next) {
            Nodo* temp = current->next;
            current->next = current->next->next;
            delete temp;
        }
    }

    void printList() {
        Nodo* current = head;
        while (current != nullptr) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "nullptr" << endl;
    }

    ~ListaLigada() {
        Nodo* current = head;
        while (current != nullptr) {
            Nodo* nextNodo = current->next;
            delete current;
            current = nextNodo;
        }
    }
};

int main() {
    ListaLigada list;

    // Insertamos elementos
    list.insertAtHead(10);
    list.insertAtHead(20);
    list.insertAtHead(30);

    // Imprimimos la lista
    list.printList();  // Salida: 30 -> 20 -> 10 -> nullptr

    // Eliminamos un nodo
    list.deleteNodo(20);

    // Imprimimos la lista después de eliminar un nodo
    list.printList();  // Salida: 30 -> 10 -> nullptr

    return 0;
}
