#ifndef LINKED_H
#define LINKED_H

#include "list.h"
#include "iterators/bidirectional_iterator.h"

template <typename T>
class LinkedList : public List<T> {
    public:
        LinkedList() : List<T>() {}

        T front() {
                if(head){
                        return this->head->data;
                }
                else{
                        throw out_of_range("List is empty");
                }
        }

        T back() {
                if(tail){
                        return this->tail->data;
                }
                else{
                        throw out_of_range("List is empty");
                }
        }

        void push_front(T value) {
            auto* newHead = new Node<T>(value);
            if(head){
                newHead->next = this->head;
                newHead->prev = this->tail;
                this->head->prev = newHead;
                this->tail->next = newHead;
                this->head = newHead;
            }
            else{
                this->head = this->tail = newHead;
                newHead->next = newHead->prev = nullptr;
            }
            this->nodes++;
        }

        void push_back(T value) {
            auto* newTail = new Node<T>(value);
            if(tail){
                newTail->prev = this->tail;
                this->tail->next = newTail;
                this->tail = newTail;
            }
            else{
                this->head = this->tail = newTail;
                newTail->next = newTail->prev = nullptr;
            }
            this->nodes++;
        }

        void pop_front() {
            Node<T>* tempNode;
            tempNode = this->head;
            this->head = this->head->next;
            this->head->prev = this->tail;
            this->tail->next = this->head;
            delete tempNode;
            this->nodes--;
        }

        void pop_back() {
            Node<T>* tempNode;
            tempNode = this->tail;
            this->tail = this->tail->prev;
            this->tail->next = this->head;
            this->head->prev = this->tail;
            delete tempNode;
            this->nodes--;
        }

        T operator[](int index) {
            Node<T>* current;
            current = this->head;
            if(index > nodes || index < 0) {
                throw out_of_range("Index value is higher than total nodes");
            }
            else {
                for (int i = 0; i <= index; i++) {
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
            return nodes;
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
            int t;
            for(int i = 0; i < nodes; i++){          //SE CREA EL VECTOR
                temp.push_back(current->data);
                current = current->next;
            }
            int n = temp.size();
            for(int i = 0; i < n-1; i++){            //BUBBLE SORT
                bool swap = false;
                for(int j = 0; j < n-i-1; j++){
                    if(temp.at(j) > temp.at(j+1)){
                        t = temp.at(j);
                        temp.at(j) = temp.at(j+1);
                        temp.at(j+1) = t;
                        swap = true;
                    }
                }
                if(!swap){
                    break;
                }
            }

            for(int i = 0; i < nodes; i++){         //SE ACTUALIZA LA LISTA
                current->data = temp.at(i);
                current = current->next;
            }
        }
    
        void reverse() {
            vector<T> temp;
            Node<T>* current;
            current = this->head;
            for(int i = 0; i < this->nodes; i++){
                temp.push_back(current->data);
                current = current->next;
            }
            current = this->head;
            for(int i = this->nodes; i >= 0; i--){
                current->data = temp.at(i);
                current = current->next;
            }
        }

        string name() {
            return "Linked List";
        }

        BidirectionalIterator<T> begin() {
            return BidirectionalIterator<T>(this->head);
        }

	    BidirectionalIterator<T> end() {
            return BidirectionalIterator<T>(this->tail);
        }

        void merge(LinkedList<T> list) {
            Node<T>* current;
            current = list.head;
            for(int i = 0; list.nodes; i++){
                this->push_back(current->data);
                current = current->next;
            }
        }
};

#endif