#include<iostream>
using namespace std;

template <typename E> class AStack
{
private:
    int maxSize;
    int top;
    E *listArray;
public:
    AStack(int size,int max)
    {
        maxSize = max;
        top = 0;
        listArray = new E[maxSize];
    }
    /*~˜AStack()
    {
        delete [] listArray;
    }*/
    void clear()
    {
        top = 0;
    }
    void push(const E& it)
    {



        if(top>=maxSize)
        {
            E listArray2[2*maxSize];
            //for(int i=0; i<top; i++)



            for(int i=0; i<top; i++)
            {
                listArray2[i]=listArray[i];

            }
            listArray=new E[2*maxSize];
            for(int i=0; i<top; i++)
            {
                listArray[i]=listArray2[i];

            }

        }
        else
        {
            listArray[top++] = it;
        }

    }
    E pop()
    {

        return listArray[--top];
    }
    const E& topValue() const
    {

        return listArray[top-1];
    }
    int length() const
    {
        return top;
    }
    void inprint(){

         E testArray[maxSize];
         fout<<"<";
        for(int i=top-1, k=0; i>=0,k<top; i--,k++)
        {

            testArray[k]=listArray[i];
        }
        for(int k=top-1; k>=0; k--)
        {

            fout<<testArray[k]<<' ';
        }
        fout<<">"<<endl;
        fout<<endl;


    }
    void print()
    {
        E testArray[maxSize];
        for(int i=top-1, k=0; i>=0,k<top; i--,k++)
        {

            testArray[k]=listArray[i];
        }
        for(int k=top-1; k>=0; k--)
        {

            fout<<testArray[k]<<' ';
        }
        fout<<endl;

    }
    void print1(E it){
        fout<<it<<endl;
    }
};
