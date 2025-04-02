#include "Peli.h"

using namespace std;

Peli::Peli() {}

Peli::Peli(int peliId, int directorId, string titol, int durada, float valoracio) {
    this -> peliId = peliId;
    this -> directorId = directorId;
    this -> titol = titol;
    this -> durada = durada;
    this -> valoracio = valoracio;
}

Peli::~Peli() {}

int Peli::getPeliId() {
    return this -> peliId;
}

int Peli::getDirectorId() {
    return this -> directorId;
}

string Peli::getTitol() {
    return this -> titol;
}

int Peli::getDurada() {
    return this -> durada;
}

float Peli::getValoracio() {
    return this -> valoracio;
}

void Peli::print() {
    cout << "ID de la peli: " << peliId << endl;
    cout << "ID del director: " << directorId << endl;
    cout << "Titol: " << titol << endl;
    cout << "Durada de la peli: " << durada << endl;
    cout << "Valoracio: " << valoracio << endl;
}

string Peli::toString() const{
    string resultat = "ID de la peli: " + to_string(peliId) + ", ID del director: " + to_string(directorId) + ", Titol: " + titol + ", Durada de la peli: " 
                    + to_string(durada) + " Valoracio: " + to_string(valoracio) + "\n";

    return resultat;
}

ostream& operator<<(std::ostream& os, const Peli& obj) {
    os << obj.toString();
    return os;
}