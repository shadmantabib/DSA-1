#include<iostream>
using namespace std;
template <typename E> class AQueue
{
private:
    int maxSize;
    int front;
    int rear;
    E *listArray;
    int size;
public:
    AQueue(int s,int max)
    {

        maxSize = max;
        rear = -1;
        front = 0;
        listArray = new E[maxSize];
        size=0;
    }
    AQueue(int max)
    {

        maxSize = max;
        rear = -1;
        front = 0;
        listArray = new E[maxSize];
    }
    /*~˜AQueue()
    {
        delete [] listArray;    // Destructor
    }*/
    void clear()
    {
        rear = -1;
        front = 0;
    }
    void enqueue(const E& it)
    {
        if(/*((rear+1) % maxSize) != front*/rear>maxSize)
        {
            cout<<"The array is full";
            E listArray2[2*maxSize];
            for(int i=0; i<rear; i++)
            {
                listArray2[i]=listArray[i];
            }

            listArray=new E[2*maxSize];
            for(int i=0; i<rear; i++)
            {
                listArray[i]=listArray2[i];

            }

            rear = (rear+1) % maxSize;
            listArray[rear] = it;
        }
        else
        {
            rear++;
            listArray[rear] = it;
             cout<<listArray[rear];
             size++;
            rear++;



        }
    }
    E dequeue()
    {
       if(length() == 0){

        cout<<"List is empty"<<endl;

       }
       else{
        E it = listArray[front];
        front = (front+1) % maxSize;
        size--;
        return it;
       }
    }
    E leaveQueue()
    {


        if(rear>0)
        {
            return listArray[rear];

            rear=rear-1;
        }
        else
        {
            return -1;
        }

    }
    const E& frontValue() const
    {

        return listArray[front];
    }
    const E& rearValue() const
    {

        return listArray[rear];
    }
    int length() const // Return length
    {

        return size;
    }
    void print()
    {
        cout<<"hello";
        for(int i=0; i<size; i++)
        {

            cout<<listArray[i]<<' ';
        }

    }
};



