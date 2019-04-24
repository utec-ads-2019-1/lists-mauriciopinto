#ifndef NODE_H
#define NODE_H

template <typename T>
struct Node {
    T data;
    Node<T>* next;
    Node<T>* prev;

    Node(T data) : data(data), next(nullptr), prev(nullptr) {};

    void killSelf() {
        // TODO
    }
};

#endif