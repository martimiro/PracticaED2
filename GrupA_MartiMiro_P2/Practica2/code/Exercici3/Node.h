#ifndef NODE_H
#define NODE_H

#include <iostream>

using namespace std;

template <class Type>

class Node {
    public:
        Node(const Type& key) {
            this -> element = key;
            this -> next = nullptr;
        }

        Type getElement() const { return this -> element; }               // No es modifica cap atribut
        // Punter al següent node
        Node<Type>* getNext() const { return this -> next; }              // No es modifica cap atribut
        void setNext(Node<Type>* nextAdr) { this -> next = nextAdr; }     // Rep punter com a parametre i l'estableix com a next

    private:
        Type element;
        Node<Type>* next;
};

#endif /* NODE_H */