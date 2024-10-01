#include<iostream>
#include<vector>
using namespace std;
ofstream fout("off2output.txt");
template <typename E> class Link
{
public:
    E element;
    Link *next;

    Link(const E& elemval, Link* nextval=NULL)
    {
        element = elemval;
        next = nextval;
    }
    Link(Link* nextval =NULL)
    {
        next = nextval;
    }
};


template <typename E> class LQueue
{
private:
    Link<E>* front;
    Link<E>* rear;
    Link<E>*curr;
    vector<int>v;
    int size;
public:
    LQueue(int m,int n) // Constructor
    {
        front = rear =curr= new Link<E>();
        size = 0;
    }

    /*~LQueue()
    {
        clear();
        delete front;
    }*/
    void clear()
    {
        while(front->next != NULL)
        {
            rear = front;
            front=front->next;
            delete rear;
        }
        rear = front ;
        size = 0;
    }
    void enqueue(const E& it)
    {
         Link<E>*ptr2= new Link<E>();
         ptr2->element=it;
         ptr2->next=NULL;
        if(size==0){
            front=rear=ptr2;
            size++;

        }
        else{
          rear->next = ptr2;
          rear = rear->next;
          size++;
        }
        //v.push_back(it);
    }
    E dequeue()
    {

        if(size>0){
        E it = front->element;

        front=front->next;
        size --;
        return it;
        }
        else{

            cout<<"size is empty"<<endl;
        }
    }
    const E& frontValue() const
    {
        if(size == 0)
        {
            cout<<"Queue is empty";
        }

        return front->element;
    }
     const E& rearValue() const
    {

        return rear->element;

    }
    E leaveQueue()
    {


        if(size>0)
        {
            return rear->element;
            size=size-1;


        }
        else
        {
            return -1;
        }

    }
    int length() const
    {
        return size;
    }
     void inprint()
    {

        fout<<"<";
        Link<E>*ptr= new Link<E>();
        ptr=front;

        for(int i=0; i<size; i++)
        {

            cout<<ptr->element;
             fout<<ptr->element<<' ';
            ptr=ptr->next;
            cout<<' ';
            cout<<"ami asi";

        }
        fout<<">"<<endl;
         fout<<endl;
        cout<<endl;


    }
    void print()
    {


        Link<E>*ptr= new Link<E>();
        ptr=front;
        //cout<<ptr->element;
        for(int i=0; i<size; i++)
        {
            fout<<ptr->element<<' ';
            cout<<ptr->element;
            ptr=ptr->next;
            cout<<' ';
            cout<<"ami asi";

        }
         fout<<endl;
        cout<<endl;


    }
    void print1(int k){

        fout<<k<<endl;
    }

};
