#ifndef __LinkedList_h__
#define __LinkedList_h__

#include <cstdlib>
#include <iostream>
#include <stdexcept>


template<class T>
class LinkedList {
    template<class T2>
    class ListElement;

public:
    template<class T3>
    class ListIterator {
    private:
        LinkedList<T3> *backingList;
        ListElement<T3> *currentElement;
    public:
        inline ListIterator(LinkedList<T3> *list) {
            backingList = list;
            currentElement = NULL;
        }

        inline bool hasNext() {
            if (currentElement == NULL) {
                return backingList->first != NULL;
            }
            else {
                return currentElement->hasNext();
            }
        }

        inline T3 next() {
            if (currentElement == NULL) {
                currentElement = backingList->first;
            }
            else {
                currentElement = currentElement->next;
            }
            return currentElement->data;
        }
    };

private:
    template<class T2>
    class ListElement {
        friend class ListIterator<T2>;

    private:
        // Variablen
        T2 data;
        ListElement *next;
        ListElement *prev;

    public:
        // Konstruktor und Dekonstruktor
        inline ListElement() {
            this->next = NULL;
            this->prev = NULL;
            this->data = NULL;
        }

        inline ListElement(T2 data, ListElement *next,
                           ListElement *prev) {
            this->data = data;
            this->next = next;
            this->prev = prev;
        }

        inline ~ListElement() {
            if (next)
                delete next;
        }

        // Getter und Setter Methoden
        T2 getData() {
            return this->data;
        }

        void setData(T2 data) {
            this->data = data;
        }

        ListElement *getNext() {
            return this->next;
        }

        bool hasNext() {
            return next != NULL;
        }

        void setNext(ListElement *next) {
            this->next = next;
        }

        ListElement *getPrev() {
            return this->prev;
        }

        void setPrev(ListElement *prev) {
            this->prev = prev;
        }

    };

private:
    ListElement<T> *first;
    ListElement<T> *last;
    int size;

public:
    // Konstruktor und Destruktor
    inline LinkedList() {
        this->first = NULL;
        this->last = NULL;
        size = 0;
    }

    inline ~LinkedList() {
        delete this->first;
    }

    /**
     * Methode fuegt Element am Ende der Liste ein.
     */
    inline void put(T value) {
        if (size > 0) {
            ListElement<T> *element = new ListElement<T>(value, NULL,
                                                         this->last);
            this->last->setNext(element);
            this->last = element;
        }
        else {
            ListElement<T> *element = new ListElement<T>(value, NULL,
                                                         NULL);
            this->first = element;
            this->last = element;
        }
        size++;
    }

    inline ListIterator<T> *iterator() {
        return new ListIterator<T>(this);
    }

    /**
     * Methode gib Element an der Stelle des uebergebenen Index zurueck.
     */
    inline T get(int index) throw(std::out_of_range) {
        ListElement<T> *tmpElement;

        try {
            if (index >= 0 && index < size) {
                if (index < (size / 2)) {
                    tmpElement = first;
                    int currPos = 0;
                    while (currPos < index) {
                        tmpElement = tmpElement->getNext();
                        currPos++;
                    }
                }
                else {
                    tmpElement = last;
                    int currPos = size - 1;
                    while (currPos > index) {
                        tmpElement = tmpElement->getPrev();
                        currPos--;
                    }
                }
            }
            else {
                throw std::out_of_range("Index nicht vorhanden.");
            }
        } catch (std::out_of_range &errMsg) {
            std::cerr << "\nFEHLER: " << errMsg.what() << "\n"
                      << std::endl;
        }

        return tmpElement->getData();
    }

    /**
     * Methode gibt Pointer auf erstes Element zurueck.
     */
    T getFirst() {
        return this->first->getData();
    }

    /**
     * Methode gibt Pointer auf letztes Element zurueck.
     */
    T getLast() {
        return this->last->getData();
    }

    /**
     * Methode gibt Groesse der Liste zurueck.
     */
    int getSize() {
        return this->size;
    }

    /**
     * Methode prueft ob Element in Liste vorhanden.
     */
    inline bool contains(T value) {
        if (indexOf(value) != -1) {
            return true;
        }
        else {
            return false;
        }
    }

    /**
     * Methode gibt Index eines Elements in der Liste zurueck.
     * Falls Wert nicht in Liste wird -1 zurueckgegeben.
     */
    inline int indexOf(T value) {
        ListElement<T> *tmpElement = first;
        int currPos = 0;
        while (tmpElement != NULL && tmpElement->getData() != value
               && currPos < size) {
            tmpElement = tmpElement->getNext();
            currPos++;
        }

        if (tmpElement == NULL
            || (tmpElement->getData() != value && currPos == size)) {
            return -1;
        }
        else {
            return currPos;
        }
    }

};


#endif

