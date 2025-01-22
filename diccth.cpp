#include <iostream>
#include <vector>
#include <list>
#include <string>

using namespace std;

class HashTable {
private:
    static const int TABLE_SIZE = 26;  // 26 letras del alfabeto
    vector<list<string>> table;

    int hashFunction(char key) {
        return tolower(key) - 'a';  // Función hash: mapea letras a índices de 0 a 25
    }

public:
    HashTable() {
        table.resize(TABLE_SIZE);
    }

    void insert(const string& str) {
        char initial = tolower(str[0]);
        if (initial >= 'a' && initial <= 'z') {
            int index = hashFunction(initial);
            table[index].push_back(str);
        }
    }

    void del(const string& str){
        char initial = tolower(str[0]);
        int index = hashFunction(initial);
        //auto& ix = table[index];
        auto ix = find(table[index].begin(), table[index].end(), str);
        if(ix){
            table[index].erase(ix);
        }
        else{
            cout<<"La palabra no esta registrada \n";
        }
        
    }
    void display() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            if (!table[i].empty()) {
                cout << "Letra " << char('a' + i) << ": ";
                for (const string& str : table[i]) {
                    cout << str << " ";
                }
                cout << endl;
            }
        }
    }
};
int menu(){
    int opc;
    cout<<"Programa que permite insertar palabras aplicando Tablas Hash \n";
    cout<<"----- Menu ------\n";
    cout<<"<1>) Agregar palabra ------\n";
    cout<<"<2>) Eliminar palabra ------\n";
    cout<<"<3>) Ver diccionario ------\n";
    cout<<"<4>) Salir ------\n";
    cout<<"Ingresa la opción deseada: ";
    cin>>opc;
    return opc;
}

int main() {
    HashTable ht;
    string palabra;
    int opc=0;
    ht.insert("Manzana");
    ht.insert("Mango");
    ht.insert("Perro");
    ht.insert("Gato");
    ht.insert("Globo");
    ht.insert("Cebra");
    ht.insert("Cerro");
    while(opc!= 4){
        opc = menu();
        switch (opc)
        {
        case 1:
            cout<<"Ingresa la palabra al diccionario: ";
            cin>>palabra;
            ht.insert(palabra);
            /* code */
            break;
        case 2:
            cout<<"Ingresa la palabra a eliminar del diccionario: ";
            cin>>palabra;
            ht.del(palabra);
            break;
        case 3:
            cout << "Contenido de la tabla hash:\n";
            ht.display();
            break;
        default:
            break;
        }
    }
 

    return 0;
}