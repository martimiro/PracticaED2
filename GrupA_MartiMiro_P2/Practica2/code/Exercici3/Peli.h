#ifndef PELI_H
#define PELI_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Peli {
    private:
        int peliId;
        int directorId;
        string titol;
        int durada;
        float valoracio;

    public:
        Peli(int peliId, int directorId, string titol, int durada, float valoracio);
        Peli ();
        ~Peli();

        int getPeliId();
        int getDirectorId();
        string getTitol();
        int getDurada();
        float getValoracio();
        void print();
        string toString() const;
        friend::ostream& operator<<(std::ostream& os, const Peli& obj);
};

#endif /* PELI_H */