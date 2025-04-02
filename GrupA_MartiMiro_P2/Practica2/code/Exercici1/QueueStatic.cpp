#include "QueueStatic.h"

#include <iostream>

using namespace std;

QueueStatic::QueueStatic() {}

QueueStatic::QueueStatic(const int max_size) {
    // Assignem valor default als atributs corresponents
    this -> _max_elements = max_size;
    this -> _num_elements = 0;
    this -> _first = 0;
    this -> _last = 0;
    this -> _content = new int[max_size];
}

QueueStatic::~QueueStatic() {}

void QueueStatic::enqueue(const int key) {
    if (isFull()) {
        throw out_of_range("Ja hi ha el nombre maxim d'elements"); // Tirem la excepció en cas que es compleixi la condicio incial
    }
    // Com que volem que sigui circular, és necessari que el modul sigui 0, i com que dividim el valor per si mateix, la condició inicial es compleix.
    _content[_last] = key;
    _last = (_last + 1) % _max_elements; 
    _num_elements = _num_elements + 1;
}

void QueueStatic::dequeue() {
    if (isEmpty()) {
        throw out_of_range("Queue buida. Afegeixi com a minim un nombre"); // Tirem la excepció en cas que es compleixi la condició incial
    }
    _first = (_first + 1) % _max_elements; // PREGUNTAR SI PASSA ALGO SEMBLANT QUE EL ENQUEUE!!!
    _num_elements = _num_elements - 1;
}

bool QueueStatic::isFull() {
    return _num_elements == _max_elements;
}

bool QueueStatic::isEmpty() {
    return _num_elements == 0;
}

void QueueStatic::print() {
    if(isEmpty()) {
        throw out_of_range("Queue buida. Afegeixi com a mínim un nombre");
    }
    int comptador = _first;
    for(int i = 0; i < _num_elements; i++) {
        cout << _content[comptador] << " ";
        comptador = (comptador + 1) % _max_elements; // Ens assegura que la llista sigui ciruclar. Ja que quan arribi al ultim index -> (n + 1) == max_size el modul serà 0.
    }
    cout << endl;
}

const int QueueStatic::getFront() {
    if(isEmpty()) {
        throw out_of_range("Queue buida. Afegeixi com a mínim un nombre");
    }
    return _content[_first];
}

void QueueStatic::printFrontRear() {
    if(isEmpty()) {
        throw out_of_range("Queue buida. Afegeixi com a mínim un nombre");
    }
    cout << "Front:" << _first << endl;
    cout << "Rear: " << _last << endl;
}