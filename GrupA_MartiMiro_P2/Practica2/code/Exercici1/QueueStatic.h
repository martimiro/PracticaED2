#ifndef QUEUESTATIC_H
#define QUEUESTATIC_H



class QueueStatic {
public:
    QueueStatic();

    QueueStatic(const int max_size);
    virtual ~QueueStatic();
    void enqueue(const int key);
    void dequeue();
    bool isFull();
    bool isEmpty();
    void print();
    const int getFront();
    void printFrontRear();

private:
    int _max_elements;
    int _num_elements;
    int _first;
    int _last;
    int* _content;
};

#endif /* QUEUESTATIC_H */

/**
 * Resposta a les preguntes:
 * 
 * Per una cua no cirucular la condicio es:
 *  _num_elements == _max_elements
 * 
 * Aquesta no és suficient per les cues circulars.
 * 
 * Tot i això la variable _max_elements es necessària a les cues circulars. Ja que quan fem 
 * queue o enqueue ens garanateix que el _first i el _last es quedin als limits de la memoria maxima.
 */