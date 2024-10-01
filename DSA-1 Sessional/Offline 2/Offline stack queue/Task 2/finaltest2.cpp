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
    vector <int> v1;
    vector <int> v2;
    LQueue<int> l1(0,3);
    // LQueue<int> lq2(0,3);
    LQueue<int> l11(0,3);

    AStack<int> l2(0,3);
     AStack<int> l22(0,3);
    //AStack<int> la2(0,3);

    AStack<int> as1(0,1);

    AStack<int> as2(0,1);

    // AStack<int> as3(0,1);

    //AStack<int> as4(0,1);

    ifstream fin("task2.txt");
    ofstream fout("task2out.txt");

    int cus,time,finish,finish2;
    fin>>cus>>time;


   // cout<<finish;




    cout<<cus<<' '<<time<<endl;
    int cust[cus][2];
    for(int i=0; i<cus; i++)
    {
        fin>>cust[i][0];
        fin>>cust[i][1];

    }
    int leave[cus];
    //cout<<cus<<endl;
    //cout<<cust[7][1];
    int flag1=0;
    int flag2=1;
    //static int stop=0;
    for(int i=0; i<cus; i++)
    {
        leave[i]=cust[i][1];

    }
    int finishline=0,finishline2=0;


    for(int i=1; i<=time; i++)
    {
        if(finishline==i)
        {
            if(i<=cust[cus-1][0]){
            cout<<i<<' ';
            as1.clear();
            //l1.dequeue();
            //cout<<as1.length();
             cout<<l1.length()<<' ';
            }
            else if(i>=21 && l1.length()!=0){

                int a=l1.dequeue();
                int b=l11.dequeue();
                v1.push_back(a);
                cout<<finishline;
                finishline=finishline+b;


                v2.push_back(finishline);
            }


        }
        else if(finishline2==i)
        {

            if(i<=cust[cus-1][0]){
            as2.clear();
            cout<<i<<' ';
            cout<<l1.length();
            cout<<l2.length();
            cout<<as1.length();
            cout<<as2.length();
            }
            else if(i>=21 && l2.length()!=0){

                int a=l2.pop();
                int b=l22.pop();
                v1.push_back(a);

                cout<<a<<' '<<b<<endl;
                cout<<finishline2;
                finishline2=finishline2+b;
                v2.push_back(finishline2);


            }

              else if(i>=21 && l2.length()==0){

                cout<<"last finishing time in console "<<i<<endl;


            }

             //l2.pop();
        }




        for(int k=0; k<cus; k++)
        {

            if(cust[k][0]==i)
            //{


                if(l1.length()==0 && as1.length()==0)
                {
                    as1.push(cust[k][0]);
                    finishline=cust[k][1]+i;
                    v1.push_back(cust[k][0]);
                    v2.push_back(finishline);
                    cout<<  finishline<<endl;
                    flag1=1;

                    cout<<"ami1"<<endl;

                }
                else if(l1.length()<3 && l1.length()!=0 && as1.length()==0)
                {
                    int a=l1.dequeue();
                    int b=l11.dequeue();
                     v1.push_back(a);
                    finishline=finishline+b;
                    v2.push_back(finishline);
                    l1.enqueue(cust[k][0]);
                    l11.enqueue(cust[k][1]);
                    //finishline=cust[k][1]+i;
                    flag1=1;

                    cout<<"ami"<<endl;

                }
                else if(l1.length()<3 && as1.length()!=0)
                {
                    l1.enqueue(cust[k][0]);
                    l11.enqueue(cust[k][1]);
                    //finishline=cust[k][1]+i;
                    flag1=1;

                    cout<<"ami"<<endl;

                }
                 /*else if(l1.length()==0 && as1.length() && as1.length()==0)
                {

                    l1.enqueue(cust[k][0]);

                     l11.enqueue(cust[k][1]);
                    as1.push(cust[k][0]);
                     cout<<"size"<<l1.length();

                    flag1=1;
                    cout<<"ami2"<<endl;

                }*/
                 /*else if(l1.length()<3 && l.length()!=0 && as1.length()!=0)
                {

                    l1.enqueue(cust[k][0]);
                    l11.enqueue(cust[k][1]);
                     cout<<"size"<<l1.length();

                    flag1=1;
                    cout<<"ami2"<<endl;

                }*/

               /*else if(l1.length()>=3 && as1.length()!=0 && l2.length()<3 &&  as2.length()!=0)
                {
                    l2.push(cust[k][0]);
                    l22.push(cust[k][1]);
                     finishline2=cust[k][1]+i;
                    flag2=1;

                }*/
                 else if(l1.length()>=3 && as1.length()!=0 && l2.length()>=3 &&  as2.length()==0)
                {

                    int a=l2.pop();
                    int b=l22.pop();
                    as2.push(a);
                    v1.push_back(a);
                    finishline2=cust[k][1]+i;
                    v2.push_back(finishline2);
                    flag2=1;
                    cout<<"ami4"<<endl;

                }
                  else if(l1.length()>=3 && as1.length()!=0 && l2.length()==0 &&  as2.length()==0)
                {
                    as2.push(cust[k][0]);
                     v1.push_back(cust[k][0]);
                    finishline2=cust[k][1]+i;
                    v2.push_back(finishline2);
                    cout<<finishline2<<endl;
                    flag2=1;
                    cout<<"ami5"<<endl;

                }
                 else if(l1.length()>=3 && as1.length()!=0 && l2.length()<3 &&  as2.length()!=0)
                {
                    l2.push(cust[k][0]);
                    l22.push(cust[k][1]);
                     //finishline=cust[k][1]+i;
                     cout<<"Length is:"<<l2.length()<<endl;
                    flag2=1;
                    cout<<"ami3"<<endl;

                }

                else if(l1.length()==3 && as1.length()==0){
                    cout<<as1.length();
                    int a=l1.dequeue();

                    int b=l11.dequeue();

                    //cout<<"ffffff"<<ff<<endl;
                    as1.push(a);
                    v1.push_back(a);
                    int rtn;
                    cout<<cus<<endl;

                    for(int p=0;p<cus;p++){
                            //cout<<cust[p][0];

                       if(cust[p][0]==a){

                            rtn=cust[p][1];
                            break;
                        }
                    }
                    rtn=i+rtn-1;
                    l1.enqueue(cust[k][0]);
                     l11.enqueue(cust[k][1]);
                    cout<<i<<endl;
                    cout<<"afsddsfa"<<a<<"tabib"<<rtn<<endl;
                    finishline=rtn;
                    v2.push_back(finishline);

                }




            //}





        }
        if(i==time){
            cout<<"Notice Here"<<finishline<<' '<<l2.length()<<' '<<as2.length()<<' '<<endl;
        }

        cout<<i<<endl;


    }
    if(finishline>time){
        cout<<"Console habijabi prints at :"<<time<<endl;
    }
     if(finishline2>time){
        cout<<"Console habijabi prints at :"<<time<<endl;
    }
    for(int i=0;i<v1.size();i++){
        cout<<v1[i]<<' ';
    }
    cout<<endl;
    for(int i=0;i<v2.size();i++){
        cout<<v2[i]<<' ';
    }
    cout<<endl;
    vector<int>::iterator p=v2.begin();
    while(p!=v2.end()){

        if(*p>=time){
            *p=time;
        }
        p++;
    }
     for(int i=0;i<v2.size();i++){
        cout<<v2[i]<<' ';
    }
    cout<<cus;
   for(int i=0;i<cus;i++){
    for(int j=0;j<v1.size();j++){
        if(cust[i][0]==v1[j]){
            v1[j]=i+1;
        }
    }
   }
    cout<<endl<<endl<<endl;
    for(int i=0;i<v1.size();i++){
        cout<<v1[i]<<' ';
    }
    cout<<endl;
     for(int i=0;i<v2.size();i++){
        cout<<v2[i]<<' ';
    }
    for(int i=0;i<cus;i++){
        fout<<v1[i]<<"->"<<v2[i]<<endl;

    }




}
