#include <iostream>
#include <string>
#include "tlist.hpp" // Include the implementation

using namespace std;

template <typename T>
void PrintList(const TList<T>& L, string label) {
    cout << label << " size is: " << L.GetSize() << "\n"
         << label << " = "; 
    L.Print(cout);
    cout << "\n\n";
}

int main() {
    // Create an empty integer list (L1)
    TList<int> L1; 

    // Insert integers from 0 to 18 at the back of L1
    for (int i = 0; i < 10; i++)
        L1.InsertBack(i * 2);

    // Print the contents of L1
    PrintList(L1, "L1");

    // Insert integers from 100 to 700 at the front of L1
    for (int i = 0; i < 8; i++)
        L1.InsertFront((i + 1) * 100);

    // Print the contents of L1 again
    PrintList(L1, "L1");

    // Remove the last two elements from L1
    L1.RemoveBack();
    L1.RemoveBack();

    // Print L1 after removing the last two elements
    PrintList(L1, "L1");

    // Remove the first two elements from L1
    L1.RemoveFront();
    L1.RemoveFront();

    // Print L1 after removing the first two elements
    PrintList(L1, "L1");

    // Create an iterator and perform some inserts with it
    cout << "Testing some inserts with an iterator\n\n";
    TListIterator<int> itr = L1.GetIterator();
    L1.Insert(itr, 999);
    itr.Next();
    itr.Next();
    L1.Insert(itr, 888);
    itr.Next();
    itr.Next();
    itr.Next();
    L1.Insert(itr, 777);

    // Print L1 after the inserts
    PrintList(L1, "L1");

    // Testing some removes with the iterator
    cout << "Testing some removes (with iterator)\n\n";
    itr.Next();
    itr.Next();
    itr = L1.Remove(itr); // delete current item
    PrintList(L1, "L1");

    // Move the iterator back 5 spots
    for (int i = 0; i < 5; i++)
        itr.Previous();

    // Remove the item at the current iterator position
    itr = L1.Remove(itr); // delete current item
    PrintList(L1, "L1");

    // Create another integer list (L2) with elements from 1 to 29 (odd numbers)
    TList<int> L2;
    for (int i = 0; i < 10; i++)
        L2.InsertBack(i * 3 + 1);

    // Print the contents of L2
    PrintList(L2, "L2");

    // Testing the + operator overload
    TList<int> L3 = L1 + TList<int>(100, 7);
    TList<int> L4;
    L4 = L2 + L1;

    PrintList(L3, "L3");
    PrintList(L4, "L4");
    

    return 0;
}