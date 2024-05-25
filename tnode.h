// **********************************************************
// * Name:  tnode.h.                                        *
// * Description:   Starter file for doubly-linked list.    *
// *    This is a templated Node class designed for         *
// *    each Node to store a single piece of data, along    *
// *    with prev and next pointers that point to the       *
// *    previous and next record in the list.               *
// * Last Modifed by: Dr. David A. Gaitros                  *
// * Date: 12/8/2019                                        *
// **********************************************************

#include <utility>

template <typename T>	class TList;		// forward declaration
template <typename T>	class TListIterator;	// forward declaration


template <typename T>
class Node
{
   friend class TList<T>;
   friend class TListIterator<T>;
public:
   Node(const T& d);
   Node(T && d);
 
private:
   T data;		// data element to store of type T
   Node<T> * prev;	// pointer to previous node
   Node<T> * next;	// pointer to next node
};



template <typename T>
// **********************************************************
// * Node Copy Constructor.   Pass a node of type T during  *
// * declaration of another Node to copy the contents of    *
// * the data passed in to the node declared.               *
// **********************************************************

Node<T>::Node(const T& d)

{
   data = d;				// set data
   prev = next = nullptr;		// null pointers to start
}
// **********************************************************
// * Basic constructor.  Creates a node with data of type T *
// **********************************************************

template <typename T>
Node<T>::Node(T && d)

{
   data = std::move(d);			// set data
   prev = next = nullptr;		// null pointers to start
}
