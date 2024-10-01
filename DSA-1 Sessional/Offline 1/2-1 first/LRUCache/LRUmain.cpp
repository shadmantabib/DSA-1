#include "lrucache.cpp"
#include<iostream>
#include<fstream>
using namespace std;


int main(){
    int cap,op;
    ifstream fin("lru_input.txt");
    ofstream fout("lru_output.txt");
    fin>>cap;fin>>op;
   // cout<<cap<<op;
    int skip,x,y;

    LRUCache<int> lru(cap);


    fin>>skip>>x>>y;
    lru.put(x,y);
     fin>>skip>>x>>y;
     lru.put(x,y);
      fin>>skip>>x>>y;

     lru.put(x,y);
    //lru.put(1,2);
    fin>>skip>>x;
    fout<<lru.get(x)<<endl;
    fin>>skip>>x;
    fout<<lru.get(x)<<endl;
    fin>>skip>>x>>y;
    lru.put(x,y);
    fin>>skip>>x;
    fout<<lru.get(x)<<endl;
    //lru.put(9,8);
    //fout<<lru.get(9);
    //fout<<lru.get(1);

    //cout<<lru.get(10);
    /* cout<<"Expected Output"<<lru.get(3);

      lru.put(4,4);

    cout<<"Expected Output"<<lru.get(3);
    cout<<"Expected Output"<<lru.get(4);
     lru.put(5,5);*/
    // cout<<"Expected Output"<<lru.get(3);




}
