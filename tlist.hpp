// **********************************************************
// * Name:  tlist.hpp                                       *
// * Description:   Starter file for doubly-linked list.    *
// *    This is a templated list class designed to use the. *
// *    node class to store multiple occurances of the data *
// *    of type T.                                          *
// * Last Modifed by: Ben Ashir Georges                     *
// * Date: 03/08/2024                                        *
// **********************************************************


#include <iostream>
using namespace std;

#ifndef _TLIST_HPP
#define _TLIST_HPP
#include "tlist.h"

// default constructor
template <typename T>
TList<T>::TList()
{
    first= nullptr;
    last = nullptr;
    size=0;
}

// Constructor with initial values
template <typename T>
TList<T>::TList(T val, int num){

    first= nullptr;
    last = nullptr;
    size=0;
    for (int i = 0; i < num; ++i) {
        InsertBack(val);
    }
}

// Destructor
template <typename T>
TList<T>::~TList() {
    Clear();
}

// Copy constructor
template <typename T>
TList<T>::TList(const TList& L){
     first= nullptr;
    last = nullptr;
    size=0;
    Node<T>* current = L.first;
    while (current) {
        InsertBack(current->data);
        current = current->next;
    }
}

// Copy assignment operator
template <typename T>
TList<T>& TList<T>::operator=(const TList& L) {
    if (this != &L) {
        Clear();
        Node<T>* current = L.first;
        while (current) {
            InsertBack(current->data);
            current = current->next;
        }
    }
    return *this;
}

// Move constructor
template <typename T>
TList<T>::TList(TList&& L){
    first = L.first;
    last = L.last;
    size = L.size;

    L.first = nullptr;
    L.last = nullptr;
    L.size = 0;
}

// Move assignment operator
template <typename T>
TList<T>& TList<T>::operator=(TList&& L) {
    if (this != &L) {
        Clear();
        first = L.first;
        last = L.last;
        size = L.size;
        L.first = nullptr;
        L.last = nullptr;
        L.size = 0;
    }
    return *this;
}

// Check if the list is empty
template <typename T>
bool TList<T>::IsEmpty() const {
    return size == 0;
}

// Clear the list
template <typename T>
void TList<T>::Clear() {
    while (!IsEmpty()) {
        RemoveFront();
    }
}

// Get the size of the list
template <typename T>
int TList<T>::GetSize() const {
    return size;
}

// Insert at the front
template <typename T>
void TList<T>::InsertFront(const T& d) {
    Node<T>* newNode = new Node<T>(d);
    newNode->next = first;
    if (IsEmpty()) {
        first = last = newNode;
    } else {
        first->prev = newNode;
        first = newNode;
    }
    ++size;
}

// Insert at the back
template <typename T>
void TList<T>::InsertBack(const T& d) {
    Node<T>* newNode = new Node<T>(d);
    newNode->prev = last;
    if (IsEmpty()) {
        first = last = newNode;
    } else {
        last->next = newNode;
        last = newNode;
    }
    ++size;
}

// Remove front element
template <typename T>
void TList<T>::RemoveFront() {
    if (!IsEmpty()) {
        Node<T>* temp = first;
        if (first == last) {
            first = last = nullptr;
        } else {
            first = first->next;
            first->prev = nullptr;
        }
        delete temp;
        --size;
    }
}

// Remove back element
template <typename T>
void TList<T>::RemoveBack() {
    if (!IsEmpty()) {
        Node<T>* temp = last;
        if (first == last) {
            first = last = nullptr;
        } else {
            last = last->prev;
            last->next = nullptr;
        }
        delete temp;
        --size;
    }
}

// Get the first element
template <typename T>
T& TList<T>::GetFirst() const {
    if (IsEmpty()) return dummy;
    return first->data;
}

// Get the last element
template <typename T>
T& TList<T>::GetLast() const {
    if (IsEmpty()) return dummy;
    return last->data;
}

// Get an iterator to the first item
template <typename T>
TListIterator<T> TList<T>::GetIterator() const {
    TListIterator<T> it;
    it.ptr = first;
    return it;
}

// Get an iterator to the last item
template <typename T>
TListIterator<T> TList<T>::GetIteratorEnd() const {
    TListIterator<T> it;
    it.ptr = last;
    return it;
}

// Insert at a specific position
template <typename T>
void TList<T>::Insert(TListIterator<T> pos, const T& d) {
    Node<T>* newNode = new Node<T>(d);
    if (pos.ptr == first) {
        InsertFront(d);
    } else if (pos.ptr == nullptr) {
        InsertBack(d);
    } else {
        newNode->next = pos.ptr;
        newNode->prev = pos.ptr->prev;
        pos.ptr->prev->next = newNode;
        pos.ptr->prev = newNode;
        ++size;
    }
}

// Remove at a specific position
template <typename T>
TListIterator<T> TList<T>::Remove(TListIterator<T> pos) {
    if (pos.ptr == nullptr) return pos;
    TListIterator<T> it;
    if (pos.ptr == first) {
        RemoveFront();
        it.ptr = first;
    } else if (pos.ptr == last) {
        RemoveBack();
        it.ptr = nullptr;
    } else {
        Node<T>* temp = pos.ptr;
        pos.ptr->prev->next = pos.ptr->next;
        pos.ptr->next->prev = pos.ptr->prev;
        it.ptr = pos.ptr->next;
        delete temp;
        --size;
    }
    return it;
}

// Print the list
template <typename T>
void TList<T>::Print(std::ostream& os, char delim) const {
    Node<T>* current = first;
    while (current) {
        os << current->data;
        current = current->next;
        if (current) os << delim;
    }
}

// overload the + operator
template <typename T>
TList<T> operator+(const TList<T>& t1, const TList<T>& t2) {
       TList<T> result = t1;
    TListIterator<T> it = t2.GetIterator(); // Get iterator for the second list
    while (it.HasNext()) {
        result.InsertBack(it.GetData()); // Insert data from the second list into the result list
        it.Next(); // Move to the next element in the second list
    }
    return result;
}

// TListIterator default constructor
template <typename T>
TListIterator<T>::TListIterator() : ptr(nullptr) {}

// Check if there is a next item
template <typename T>
bool TListIterator<T>::HasNext() const {
    return ptr && ptr->next;
}

// Check if there is a previous item
template <typename T>
bool TListIterator<T>::HasPrevious() const {
    return ptr && ptr->prev;
}

// Move to the next item
template <typename T>
TListIterator<T> TListIterator<T>::Next() {
    if (ptr) ptr = ptr->next;
    return *this;
}

// Move to the previous item
template <typename T>
TListIterator<T> TListIterator<T>::Previous() {
    if (ptr) ptr = ptr->prev;
    return *this;
}

// Get the data of the current item
template <typename T>
T& TListIterator<T>::GetData() const {
    if (ptr) return ptr->data;
    return TList<T>::dummy;
}


#endif //_TLIST_HPP




