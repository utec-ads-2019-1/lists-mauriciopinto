#ifndef BIDIRECTIONAL_ITERATOR_H
#define BIDIRECTIONAL_ITERATOR_H

#include "../iterator.h"

template <typename T> 
class BidirectionalIterator : public Iterator<T> {
    public:
        BidirectionalIterator() : Iterator<T>() {};
        BidirectionalIterator(Node<T> *node) : Iterator<T>(node) {};

        BidirectionalIterator<T> operator=(BidirectionalIterator<T> other) {
                this->current = other.current;
                return (*this);
        }

        bool operator!=(BidirectionalIterator<T> other) {
            if(this->current == other.current) {
                    return false;
            }
            else{
                    return true;
            }
        }

        BidirectionalIterator<T> operator++() {
                // Estás creando nuevos iteradores con cada ++
            return BidirectionalIterator<T>(current->next);
        }

        BidirectionalIterator<T> operator--() {
                // Estás creando nuevos iteradores con cada --
                return BidirectionalIterator<T>(current->prev);
        }

        T operator*() {
            return this->current->data;
        }
};

#endif