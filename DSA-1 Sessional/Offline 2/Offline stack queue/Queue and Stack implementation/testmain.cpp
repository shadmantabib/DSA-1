#include<iostream>
#include<fstream>
#include "LQueue.cpp"
#include "AQueue.cpp"
#include "LStack.cpp"
#include "AStack.cpp"
#include<vector>

using namespace std;
int main()
{

    ifstream fin("input.txt");
    ofstream fout("off2output.txt");

    if(!fin)
    {

        cout<<"Cannot open input"<<endl;
    }
    int k,x,k1,x1;
    fin>>k>>x;
    int araK[k];
    for (int i=0; i<k; i++)
    {

        fin>>araK[i];
    }
    fin>>k1>>x1;
    int araM[k1];
    for (int i=0; i<k1; i++)
    {

        fin>>araM[i];
    }
    int input;
    fin>>input;
    int araI[input][2];
    for(int i=0; i<input; i++)
    {
        for(int j=0; j<2; j++)
        {
            fin>>araI[i][j];

        }
    }
    int choice;
    // cin>>choice;
    /*cout<<k<<x;
     for(int i=0; i<input; i++)
    {
        for(int j=0; j<2; j++)
        {
            cout<<araI[i][j];

        }
    }*/

    LQueue<int> aqueue(k,x);
    AStack<int> astack(k1,x1);


    cout<<astack.length();
    for(int k=0;k<k1;k++){
        astack.push(araM[k]);
    }
    for(int k=0;k<k1;k++){
        aqueue.enqueue(araM[k]);
    }
    aqueue.inprint();
    astack.inprint();
    /*cout<<astack.length();
    cout<<astack.topValue();
    //astack.print();
    cout<<endl;
    cout<<astack.pop()<<endl;
    cout<<astack.length();
    //astack.print();

    /*astack.push(100);
    astack.push(200);
    astack.push(300);
    // cout<<astack.pop();

    astack.print();
    cout<<astack.pop();
    cout<<astack.pop();
    cout<<astack.length();
    cout<<astack.topValue();
    cout<<endl;*/

   /* aqueue.enqueue(3);
    aqueue.enqueue(4);
    aqueue.enqueue(5);
    //aqueue.enqueue(4);
    // aqueue.print();
    // cout<<'\n';
    //cout<<aqueue.dequeue();
    //cout<<aqueue.dequeue();
    //cout<<aqueue.dequeue();
    // aqueue.clear();
    // cout<<aqueue.length();
    cout<<endl;
    //aqueue.print();
    cout<<endl;
    cout<<aqueue.frontValue();
    cout<<endl;
    cout<<aqueue.dequeue();
    cout<<endl;
    aqueue.print();
    cout<<endl;
    aqueue.clear();
    cout<<aqueue.length()<<endl;

    aqueue.enqueue(3);
    aqueue.enqueue(4);
    aqueue.enqueue(5);

    /*for(int i=0; i<input; i++)
    {
        for(int j=0; j<2; j++)
        {
            cout<<araI[i][j]<<' ';

        }
        cout<<endl;
    }
    aqueue.print();
    cout<<aqueue.frontValue();
    cout<<aqueue.rearValue();
    aqueue.enqueue(36);
    aqueue.print();*/
    // cout<<aqueue.length();
    //cout<<aqueue.frontValue();

    //cout<<aqueue.dequeue();*/

    for(int i=0; i<input; i++)
    {

        switch(araI[i][0])
        {

        case 1:
            aqueue.clear();
            //aqueue.print();
            cout<<endl;

            for(int i=0; i<k; i++)
            {
                aqueue.enqueue(araK[i]);
            }
            break;

        case 2:

            aqueue.enqueue(araI[i][1]);
            aqueue.print();
            cout<<endl;
            fout<<endl;
            break;
        case 3:
            aqueue.dequeue();
            aqueue.print();
            cout<<endl;
            break;
        case 4:
            aqueue.length();
            aqueue.print();
            cout<<endl;
            break;
        case 5:
            aqueue.frontValue();
            aqueue.print();
            cout<<endl;
            break;
        case 6:
            int gg;
            gg=aqueue.rearValue();
            cout<<gg;
            //fout<<gg<<endl;
             aqueue.print1(gg);
            cout<<endl;
            break;

        case 7:
            aqueue.leaveQueue();
            aqueue.print();
            cout<<endl;
            break;
        case 8:
            astack.clear();
            //aqueue.print();
            cout<<endl;
            break;
        case 9:
            astack.push(araI[i][1]);
            astack.print();
            cout<<endl;
            break;

        case 10:
            int v;
            v=astack.pop();
            astack.print1(v);
            astack.print();
            cout<<endl;
            break;
        case 11:
            astack.length();
            astack.print();
            cout<<endl;
            break;
        case 12:
            int v1=astack.topValue();
            astack.print1(v1);
            //astack.print();
            cout<<endl;
            break;

        }

    }




}
