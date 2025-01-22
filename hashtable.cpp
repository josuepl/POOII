#include <iostream>
#include <list>
#include <vector>

using namespace std;

// Clase que representa una tabla hash
class HashTable {
private:
    // Número de "buckets" en la tabla hash
    int capacity;
    // Vector de listas para manejar las colisiones
    vector<list<int>> table;

    // Función hash: usa el operador módulo para distribuir las claves
    int hashFunction(int key) {
        return key % capacity;
    }

public:
    // Constructor
    HashTable(int size) {
        capacity = size;
        table.resize(capacity); // Redimensionar la tabla para contener "size" listas
    }

    // Insertar un valor en la tabla hash
    void insert(int key) {
        int index = hashFunction(key);
        table[index].push_back(key);  // Añadir el valor a la lista correspondiente
    }

    // Buscar si un valor está en la tabla hash
    bool search(int key) {
        int index = hashFunction(key);
        for (int element : table[index]) {
            if (element == key) {
                return true;  // Si encontramos el valor, retornar true
            }
        }
        return false;  // Si no lo encontramos, retornar false
    }

    // Eliminar un valor de la tabla hash
    void remove(int key) {
        int index = hashFunction(key);
        table[index].remove(key);  // Eliminar el valor de la lista correspondiente
    }

    // Imprimir la tabla hash (para fines de depuración)
    void display() {
        for (int i = 0; i < capacity; i++) {
            cout << "Bucket " << i << ": ";
            for (int element : table[i]) {
                cout << element << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    // Crear una tabla hash con capacidad de 10
    HashTable ht(10);

    // Insertar algunos valores
    ht.insert(15);
    ht.insert(25);
    ht.insert(35);
    ht.insert(45);

    // Mostrar la tabla hash
    ht.display();

    // Buscar elementos
    cout << "Buscar 25: " << (ht.search(25) ? "Encontrado" : "No encontrado") << endl;
    cout << "Buscar 40: " << (ht.search(40) ? "Encontrado" : "No encontrado") << endl;

    // Eliminar un valor
    ht.remove(25);
    cout << "Despues de eliminar 25:" << endl;
    ht.display();

    return 0;
}
