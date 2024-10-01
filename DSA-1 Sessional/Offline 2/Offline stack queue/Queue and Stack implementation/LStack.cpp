#include<iostream>
#include<vector>
using namespace std;
template <typename E> class Link2
{
public:
    E element;
    Link2 *next;

    Link2(const E& elemval, Link2* nextval=NULL)
    {
        element = elemval;
        next = nextval;
    }
    Link2(Link2* nextval =NULL)
    {
        next = nextval;
    }
};
template <typename E> class LStack
{
private:
    Link2<E>* top;

    Link2<E>*curr;
    int size;
    vector<int>v;
public:
    LStack(int m,int n )
    {
        top= curr= NULL;
        size = 0;
    }
    /*~LStack()
    {
        clear();    // Destructor
    }*/
    void clear()
    {
        while (top != NULL)
        {
            Link2<E>* temp = top;
            top = top->next;
            delete temp;
        }
        size = 0;
    }
    void push(const E& it)
    {
        top = new Link2<E>(it, top);
        v.push_back(it);
        size++;
    }
    E pop(){
        if(top == NULL)
            cout<< "Stack is empty";
        E it = top->element;
        Link2<E>* ltemp = top->next;
        delete top;
        top = ltemp;
        size--;
        return it;
    }
    const E& topValue() const
    {
        Assert(top != 0, "Stack is empty");
        return top->element;
    }
    int length() const
    {
        return size;
    }
    void print(){
       for(int i=0;i<v.size();i++){
        cout<<v[i];
       }

    }
};
