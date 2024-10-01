#include "UnsortedType.h"
#include "MyList.h"
#include <iostream>
using namespace std;

template <typename A> // Array-based list implementation
class AList
{
private:
    int capacity; // Maximum size of list
    int listSize; // Number of list items now
    int curr; // Position of current element
    A* listArray; // Array holding list elements
public:
    AList(int size)   // Constructor
    {
        capacity = size;
        listSize = curr = 0;
        listArray = new A[capacity];
    }
    /*~˜AList()
    {
        if(listSize<=capacity)
        delete [] listArray;    // Destructor
    }*/
    void clear()   // Reinitialize the list
    {
        delete [] listArray; // Remove the array
        listSize = curr = 0; // Reset the size
        listArray = new A[capacity]; // Recreate array
    }
// Insert "it" at current position
    void push(const A& item)
    {
        if(listSize > capacity)
        {
            cout<<"List capacity exceeded";
            capacity=2*capacity;
            listArray = new A[capacity];
        }

        for(int i=listSize; i>curr; i--)  // Shift elements up
        {
            listArray[i] = listArray[i-1];
        } // to make room
        listArray[curr] = item;
        listSize++;
    }
    void pushBack(const A& item)   // Append "it"
    {
        if(listSize > capacity)
        {
            cout<<"List capacity exceeded";
            capacity=2*capacity;
            listArray = new A[capacity];
        }
        listArray[listSize++] = item;
    }
// Remove and return the current element.
    A erase()
    {
        /*if((curr>=0) && (curr < listSize))
        {
            cout<<"No element";
        }*/
        A it = listArray[curr]; // Copy the element
        for(int i=curr; i<listSize-1; i++) // Shift them down
            listArray[i] = listArray[i+1];
        listSize--; // Decrement size
        return it;
    }

    void setToBegin()
    {
        curr = 0;    // Reset position
    }
    void setToEnd()
    {
        curr = listSize;    // Set at end
    }
    void prev()
    {
        if (curr != 0)
            curr--;    // Back up
    }
    void next()
    {
        if (curr < listSize)
            curr++;    // Next
    }
// Return list size
    int size() const
    {
        return listSize;
    }
// Return current position
    int currPos() const
    {
        return curr;
    }
// Set current list position to "pos"
    void setToPos(int pos)
    {
        if((pos>=0)&&(pos<=listSize))
        {
            cout<<"Pos is not within range";
        }

        curr = pos;
    }
    const A& getValue() const   // Return current element
    {
        /* if((curr>=0)&&(curr<listSize)){

                 cout<<"No current element is found within this scope";
         }*/
        return listArray[curr];
    }
    int find(const A& item)
    {
        setToBegin();
        for(int p=0; p<listSize; p++)
        {
            if (listArray[p]==item)
            {
                return p;
                break;
            }
            else if(p>=listSize)
            {
                return -1;
            }
        }


    }

};




