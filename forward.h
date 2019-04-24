#ifndef FORWARD_H
#define FORWARD_H

#include "list.h"
#include "iterators/forward_iterator.h"

template <typename T>
class ForwardList : public List<T> {
public:
    ForwardList() : List<T>() {}

    T front() {
            if(this->head == nullptr){
                    throw out_of_range("No elements in list");
            }
            else{
                    return this->head->data;
            }
    }

    T back() {
            return this->tail->data;
    }

    void push_front(T value) {
            Node<T>* newHead = new Node<T>(value);
            newHead->next = nullptr;
            if(!empty()){
                    newHead->next = this->head;
                    this->head = newHead;
            }
            else{
                    this->head = this->tail = newHead;
                    newHead->next = nullptr;
            }
            this->nodes++;
    }

    void push_back(T value) {
            Node<T>* newTail = new Node<T>(value);
            if(!empty()){
                    this->tail->next = newTail;
                    this->tail = newTail;
            }
            else{
                    this->head = this->tail = newTail;
                    newTail->next = nullptr;
            }
            this->nodes++;
    }

    void pop_front() {
            Node<T>* tempNode;
            tempNode = this->head;
            this->head = this->head->next;
            delete tempNode;
            this->nodes--;
    }

    void pop_back() {
            Node<T>* current;
            current = this->head;
            while(current->next != this->tail){
                    current = current->next;
            }
            delete this->tail;
            current->next = nullptr;
            this->tail = current;
            this->nodes--;
    }

    T operator[](int index) {
            Node<T>* current;
            current = this->head;
            if(index > nodes || index < 0) {
                    throw out_of_range("Index value is higher than total nodes");
            }
            else {
                    for (int i = 0; i < index; i++) {
                            current = current->next;
                    }
            }
            return current->data;
    }

    bool empty() {
            if(head){
                    return false;
            }
            else{
                    return true;
            }
    }

    int size() {
            return this->nodes;
    }

    void clear() {
            Node<T>* current;
            current = this->head;
            for(int i = 0; i < this->nodes; i++){
                    delete this->head;
                    current = current->next;
                    this->head = current;
            }
            delete current;
            this->nodes = 0;
    }

    void sort() {
            vector<T> temp;
            Node<T>* current;
            current = this->head;
            for(int i = 0; i < this->size(); i++){          //SE CREA EL VECTOR
                    temp.push_back(current->data);
                    current = current->next;
            }
            int n = this->size();
            for(int i = 0; i < n-1; i++){            //BUBBLE SORT
                bool swap = false;
                    for(int j = 0; j < n-i-1; j++){
                            if(temp.at(j) > temp.at(j+1)){
                                auto t = temp.at(j);
                                temp.at(j) = temp.at(j+1);
                                temp.at(j+1) = t;
                                swap = true;
                            }
                    }
                    if(!swap){
                            break;
                    }
            }
            current = this->head;
            for(int i = 0; i < temp.size(); i++){         //SE ACTUALIZA LA LISTA
                current->data = temp.at(i);
                current = current->next;
            }
    }

    void reverse() {
        vector<T> temp;
        Node<T>* current;
        current = this->head;
        for(int i = 0; i < this->size(); i++){
            temp.push_back(current->data);
            current = current->next;
        }
        current = this->head;
        for(int i = temp.size() - 1; i >= 0; i--){
                current->data = temp.at(i);
                current = current->next;
        }
    }

string name() {
        return "Forward List";
}

ForwardIterator<T> begin() {
        return ForwardIterator<T>(this->head);
}

ForwardIterator<T> end() {
        return ForwardIterator<T>(this->tail);
}

void merge(ForwardList<T> list) {
    Node<T>* current;
    current = list.head;
    for(int i = 0; list.nodes; i++){
        this->push_back(current->data);
        current = current->next;
    }
}
};

#endif