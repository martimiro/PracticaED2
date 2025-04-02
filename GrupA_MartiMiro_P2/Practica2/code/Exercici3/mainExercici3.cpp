#include "Node.h"
#include "LinkedQueue.h"
#include "Peli.h"

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

int main() {

    QueueLinked<Peli> queue;

    cout << " = MENU =" << endl;

    int entrada = -1;                                      // Valor per defecte

    string nom;
    string dades;

    int peliId;
    int directorId;
    string titol;
    int durada;
    float valoracio;

    nom = "incialitzaDades.txt";
    ifstream fitxer(nom);

    do {
        cout << "1. Llegir un fitxer amb les entrades de les pelis" << endl;
        cout << "2. Eliminar una peli" << endl;
        cout << "3. Inserir n entrades de pelis des de teclat (0 per finalitzar)" << endl;
        cout << "4. Imprimir per pantalla la cua de pelis" << endl;
        cout << "5. Sortir" << endl;

        cin >> entrada;

        switch (entrada) {
            case 1:
                while (getline(fitxer, dades)) {
                    stringstream scanner(dades);

                    char coma;

                    scanner >> peliId >> coma >> directorId >> coma;
                    getline(scanner, titol, ',');               // Com que titol te espais, ho hem de fer d'aquesta forma
                    scanner >> durada >> coma >> valoracio;

                    Peli peli(peliId, directorId, titol, durada, valoracio);
                    queue.enqueue(peli);
                }
                fitxer.close();
                
                break;
            
            case 2:
                try {
                    queue.dequeue();
                } catch (const exception &e) {
                    cout << "ERROR: " << e.what() << endl;
                }

                break;

            case 3:
                entrada = -1;                                  // Valor per defecte
                
                do {
                    cout << "Insereix la ID de la peli: ";
                    cin >> peliId;
                    
                    cout << "Insereix la ID del director: ";
                    cin >> directorId;

                    cout << "Insereix el titol de la peli: ";
                    cin >> titol;

                    cout << "Insereix la durada en minuts: ";
                    cin >> durada;

                    cout << "Insereix la valoracio de la peli (0-10): ";
                    cin >> valoracio;

                    Peli peli(peliId, directorId, titol, durada, valoracio);
                    queue.enqueue(peli);

                    cout << "Insereix 0 si vols sortir: ";
                    cin >> entrada;

                } while(entrada != 0);

                break;
            
            case 4: 
                try{
                    cout << "Llista de pelis:" << endl;
                    queue.print();
                } catch (const exception &e){
                    cout << "ERROR: " << e.what() << endl;
                }

                break;
            }
    } while (entrada != 5);
    
    return 0;
}