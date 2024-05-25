#include <iostream>
#include <utility>
#include "tnode.h"
// **********************************************************
// * Name:  tlist.h.                                        *
// * Description:   Starter file for doubly-linked list.    *
// *    This is a templated list class designed to use the. *
// *    node class to store multiple occurances of the data *
// *    of type T.                                          *
// * Last Modifed by: Dr. David A. Gaitros                  *
// * Date: 12/8/2019                                        *
// **********************************************************

template <typename T>
class TList
{
   friend class TListIterator<T>;


public:
   TList();				// Create empty linked list   
   TList(T val, int num);		// Create list with num copies of val
   ~TList();				// Destructor
   TList(const TList& L);		// Copy constructor
   TList& operator=(const TList& L);	// Copy assignment operator
   TList(TList && L);			// Move constructor
   TList& operator=(TList && L);	// Move assignment operator

   bool IsEmpty() const;		// Checks to see whether list is empty  
   void Clear();			// Clear out list, reset to empty
   int GetSize() const;			// Return the size of the list     

   void InsertFront(const T& d);	// Insert data d as first element
   void InsertBack(const T& d);		// Insert data d as last element
   void RemoveFront();			// Remove first element of list
   void RemoveBack();			// Remove last element of list

   T& GetFirst() const;			// Return first element of list
   T& GetLast() const;			// Return last element of list

   TListIterator<T> GetIterator() const;    // Return iterator to first item
   TListIterator<T> GetIteratorEnd() const; // Return iterator to last item
// **********************************************************
// * Insert data element d just before item at pos position *
// **********************************************************

   void Insert(TListIterator<T> pos, const T& d);
// **********************************************************
// * Remove data item at position pos. Return iterator      *
// *  to the item.                                          * 
// *  that comes after the one being deleted.               *
// **********************************************************

   TListIterator<T> Remove(TListIterator<T> pos);
// **********************************************************
// * Print list contents in order, separated by given       *
// * delimiter.                                             *
// **********************************************************

   void Print(std::ostream& os, char delim = ' ') const;

private:
   Node<T>* first;		// pointer to first node in list
   Node<T>* last;		// pointer to last node in list
   int size;			// number of nodes in the list
   static T dummy;		// dummy object, for empty list data returns
   				//  assuming type T has default construction

};

template <typename T>
T TList<T>::dummy;		// initialization of static member
// **********************************************************
// *. Stand-alone function for concatenating two TList      *
// *  objects                                               *
// **********************************************************

template <typename T>
TList<T> operator+(const TList<T>& t1, const TList<T>& t2);


// **********************************************************
// Declaration of class TListIterator                       *
// **********************************************************


template <typename T>
class TListIterator
{
   friend class TList<T>;

public:
   TListIterator();			// default constructor
   bool HasNext() const;		// next item available?
   bool HasPrevious() const;		// previous item available?
   TListIterator<T> Next();		// advance to next item
   TListIterator<T> Previous();		// move to previous item
   T& GetData() const;			// return data element of current node

private:
   Node<T>* ptr;		// pointer to current list item
};

#include "tlist.hpp"		// bring in definition file here

