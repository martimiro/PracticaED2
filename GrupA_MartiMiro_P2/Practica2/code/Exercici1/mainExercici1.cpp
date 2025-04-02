#include "QueueStatic.h"

#include <iostream>

using namespace std;

int main(){
    int size;
    cout << "Introdueix la mida maxima de la QueueStatic:";
    cin >> size;

    QueueStatic queue(size);

    cout << "Estructura creada de mida" << size << endl;

    int entrada;

    do {
        cout << "- MENÚ -" << endl;
        cout << "1. Inserir element a la QueueStatic." << endl;
        cout << "2. Treure element de la QueueStatic." << endl;
        cout << "3. Consultar el primer element de la QueueStatic." << endl;
        cout << "4. Imprimir tot el contingut de la QueueStatic." << endl;
        cout << "5. Imprimir les posicions del front i el rear." << endl;
        cout << "6. Sortir." << endl;

        cout << "Selecciona la opcio que vulguis fer:";
        cin >> entrada;

        switch (entrada) {
        case 1:
            int key;
            cout << "Insereix l'element que vulguis afegir a la QueueStatic: ";
            cin >> key;

            try {
                queue.enqueue(key);
                cout << "Element " << key << " agregat." << endl;
            } catch (const exception &e) {
                cout << "ERROR: " << e.what();
            }
        break;

        case 2:
            try {
                int first = queue.getFront();
                queue.dequeue();
                cout << "Element " << first << " eliminat." << endl;
            } catch (const exception &e) {
                cout << "ERROR: " << e.what();
            }            
        break;

        case 3:
            try {
                int front = queue.getFront();
                cout << "El primer és " << front << endl;
            } catch (const exception &e) {
                cout << "ERROR: " << e.what();
            } 
        break;

        case 4:
            try {
                queue.print();
            } catch (const exception &e) {
                cout << "ERROR: " << e.what();
            } 
        break;

        case 5:
            try {
                queue.printFrontRear();
            } catch (const exception &e) {
                cout << "ERROR: " << e.what();
            }
        break;
        }
    } while (entrada != 6);

    return 0;
}