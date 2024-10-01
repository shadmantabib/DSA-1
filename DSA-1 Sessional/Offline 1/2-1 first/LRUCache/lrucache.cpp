#include "MyList.h"
#include "linkedlist.cpp"
#include <iostream>
using namespace std;
 static int count=0;
template <typename A>
class LRUCache: public LList<A>
{
         int cap;
         LList<int> llist1;
         LList<int> llist2;



    public:

        LRUCache(int capacity)
        {
             cap=capacity;



        }
        A get(A key)
        {
            /*if(m.find(key)!=m.end()){
                A ans=m[key]->value;
                erase(m[key]);
                Link* cur=add(key,ans);
                m[key]=cur;
                return ans;

            }
            else{
                return -1;
            }*/

            int p=llist1.find(key);
            if(p==-1){


                return -1;
            }
           // cout<<p<<' '<<"This is key value posn";
            llist2.setToPos(p);
            int q=llist2.getValue();



                llist1.setToBegin();
                llist2.setToBegin();
                //llist1.setToPos(p);
                //llist2.setToPos(p);
                int chunk=llist1.erase();
                int chunk2=llist2.erase();

                llist1.pushBack(key);
                llist2.pushBack(q);


            return q;
            //cout<<a;


        }
        void put(A key,A value)
        {

            count++;

           if(count<=cap){

            llist1.setToBegin();

            llist2.setToBegin();
            llist1.pushBack(key);
            llist2.pushBack(value);
            llist1.setToEnd();
             llist2.setToEnd();
            llist1.prev();
            llist2.prev();

           // cout<<llist1.getValue()<<endl;
           //  cout<<llist2.getValue()<<endl;

            //cout<<llist1.currPos()<<endl;
           // cout<<llist2.currPos()<<endl;
            //cout<<count<<endl;
           // cout<<cap<<endl;

           }

            else{

                //cout<<-1<<endl;

                llist1.setToBegin();

                llist2.setToBegin();
                llist1.pushBack(key);
                llist2.pushBack(value);
                llist1.setToBegin();
                llist2.setToBegin();

                int chunk=llist1.erase();
                int chunk2=llist2.erase();
                //cout<<"The chunks are"<<chunk<<chunk2<<endl;
                llist1.setToEnd();
                llist1.prev();
                  llist1.prev();
                //cout<<llist1.currPos()<<endl;
                //cout<<llist1.getValue()<<endl;

                llist2.setToEnd();
                llist2.prev();
                llist2.prev();
               // cout<<llist2.currPos()<<endl;
                //cout<<llist2.getValue()<<endl;
                llist1.setToBegin();
                llist2.setToBegin();


            }

            /*if(m.find(key)!=m.end())
            {
                //llist.find(m[key])
                xy[count++].setxy(key,value);
                //erase(m[key]);
                Link* cur=new Link();
                cur.pushBack();
                m[key]=cur;
            }
            else
            {
                if(count==cap)
                {
                    A key=tail->prev->key;
                    erase(m[key]);
                    m.erase(key);
                }
                Node* cur=add(key,value);
                m[key]=cur;
                count=min(count+1,cap);


            }*/
        }

    };
