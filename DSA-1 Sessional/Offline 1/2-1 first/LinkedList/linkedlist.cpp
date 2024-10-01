#include <iostream>
using namespace std;
template <typename E> class Link
{
public:
    E element; // Value for this node
    Link *next; // Pointer to next node in list
// Constructors
    Link(const E& elemval, Link* nextval =NULL)
    {
        element = elemval;
        next = nextval;
    }
    Link(Link* nextval =NULL)
    {
        next = nextval;
    }
};
template <typename E> class LList
{
private:
    Link<E>* head; // Pointer to list header
    Link<E>* tail; // Pointer to last element
    Link<E>* curr; // Access to current element
    int cnt; // Size of list
    void init()   // Intialization helper method
    {
        curr = tail = head = new Link<E>;
        cnt = 0;
    }
    void removeall()   // Return link nodes to free store
    {
        while(head != NULL)
        {
            curr = head;
            head = head->next;
            delete curr;
        }
    }
public:
    LList()
    {
        curr = tail = head = new Link<E>;
        cnt = 0;   // Constructor
    }
    void print() const; // Print list contents
    void clear()
    {
        removeall();    // Clear list
        init();
    }
// Insert "it" at current position
    void push(const E& it)
    {
        curr->next = new Link<E>(it, curr->next);
        if (tail == curr) tail = curr->next; // New tail
        cnt++;
    }
    void pushBack(const E& it)   // Append "it" to list
    {
        tail = tail->next = new Link<E>(it, NULL);
        cnt++;
    }
// Remove and return current element
    E erase()
    {
        if(curr->next == NULL)
        {
            return -1;
        }
        E it = curr->next->element; // Remember value
        Link<E>* ltemp = curr->next; // Remember link node
        if (tail == curr->next) tail = curr; // Reset tail
        curr->next = curr->next->next; // Remove from list
        delete ltemp; // Reclaim space
        cnt--; // Decrement the count
        return it;
    }

    void setToBegin() // Place curr at list start
    {
        curr = head;
    }
    void setToEnd() // Place curr at list end
    {
        curr = tail;
    }
// Move curr one step left; no change if already at front
    void prev()
    {
        if (curr == head) return; // No previous element
        Link<E>* temp = head;
// March down list until we find the previous element
        while (temp->next!=curr) temp=temp->next;
        curr = temp;
    }
// Move curr one step right; no change if already at end
    void next()
    {
        if (curr != tail) curr = curr->next;
    }
    int size() const
    {
        return cnt;    // Return length
    }
// Return the position of the current element
    int currPos() const
    {
        Link<E>* temp = head;
        int i;
        for (i=0; curr != temp; i++)
            temp = temp->next;
        return i;
    }
// Move down list to "pos" position
    void setToPos(int pos)
    {
        setToBegin();
        for(int i=0; i<pos; i++)
            curr = curr->next;
    }
    const E& getValue() const   // Return current element
    {
        // Assert(curr->next != NULL, "No value");
        return curr->next->element;
    }
    int find(const E& item)
    {
        setToBegin();
        cout<<currPos()<<getValue()<<endl;
        cout<<size()<<endl;
        int flag=0;
        //cout<<curr->element<<"YYYYYYY"<<endl;
        for(int p=0; p<size(); p++)
        {

            if ((getValue())==item )
            {

                return p;


            }
            cout<<getValue();
            curr=curr->next;
            flag++;

        }

        if(flag==size())
        {
            return -1;

        }
    }



};
