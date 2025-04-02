#ifndef QUEUELINKED_H
#define QUEUELINKED_H

#include <iostream>
#include "Node.h"

using namespace std;

template <class Type>

class QueueLinked {
    public:
        QueueLinked();
        QueueLinked(const QueueLinked<Type>& q);
        ~QueueLinked();
        
        bool isEmpty() const;
        void print();
        void enqueue(const Type key);
        void dequeue();
        const Type getFront() const;
        void printFrontRear();

    private:
        Node<Type>* _first;
        Node<Type>* _last;
};

#endif /* QUEUELINKED_H */


// Constructors
template <class Type>
QueueLinked<Type>::QueueLinked() {
    this -> _first = nullptr;
    this -> _last = nullptr;
}

template <class Type>
QueueLinked<Type>::QueueLinked(const QueueLinked<Type>& q):_first(nullptr), _last(nullptr){
    if(q.isEmpty()) {
        return;
    }

    _first = new Node<Type> (q._first -> getElement());
    _last = _first;

    Node<Type>* nodeActual = q._first->getNext();
    while (nodeActual != nullptr) {
        _last -> setNext(new Node<Type> (nodeActual -> getElement(), nullptr));
        _last = _last -> getNext();
        nodeActual = nodeActual -> getNext();
    }
    
}

template <class Type>
QueueLinked<Type>::~QueueLinked() {
    while (!isEmpty()) {
        dequeue();
    }
}

// Altres mètodes
template <class Type>
bool QueueLinked<Type>::isEmpty() const {
    return _first == nullptr;
}

template <class Type>
void QueueLinked <Type>::print() {
    if (!isEmpty()) {
        Node<Type>* nodeActual = this -> _first;            // Guardem l'adreça del primer.

        do {
            cout << nodeActual -> getElement() << " ";      // Fem print del element del node.
            nodeActual = nodeActual -> getNext();           // Agadem la adreça següent.
        } while (nodeActual != nullptr);

        cout << endl;
    } else {
        throw out_of_range("La llista està buida.");
    }
}

template <class Type>
void QueueLinked<Type>::enqueue(const Type key) {
    Node<Type>* node = new Node <Type>(key);

    if (isEmpty()) {
        // Assignem com a primer i ultim el nou node que em creat anteriorment.
        this -> _first = node;                              
        this -> _last = node;
    } else {
        this -> _last -> setNext(node);                     // A l'actual _last l'hi assignem un nou next que és el node creat anteriorment
        this -> _last = node;                               // Assignem el node creat com a _last
    }
}

template <class Type>
void QueueLinked<Type>::dequeue() {
    Node<Type>* nodePrimer = this -> _first;

    if (!isEmpty()) {
        this -> _first = this -> _first -> getNext();         // Assignem com a _first el node següent de l'actual.
        delete nodePrimer;
    } else {
        throw out_of_range("La llista està buida");
    }
}

template <class Type>
const Type QueueLinked<Type>::getFront() const{
    if (!isEmpty()) {
        return this -> _first -> getElement();
    } else {
        throw out_of_range("La llista està buida");
    }
}

template <class Type>
void QueueLinked<Type>::printFrontRear() {
    if (!isEmpty()) {
        cout << "Primer " << this -> _first -> getElement() << endl;
        cout << "Ultim " << this -> _last -> getElement() << endl;
    } else {
        throw out_of_range("La llista està buida");
    }
}