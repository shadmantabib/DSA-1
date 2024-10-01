#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include "ArrayList.cpp"
#include "linkedlist.cpp"

using namespace std;

/*void work(int f,int p){

    switch(f){
    case 1:
        a.size();
    /*case 1:
    case 1:
    case 1:
    case 1:
    case 1:
    case 1:
    case 1:
    case 1:
    case 1:
    case 1:
    case 1:
    case 1:
    }



}*/

int main()
{
    //int k,x;

    ifstream fin("list_input.txt");

    if(!fin)
    {

        cout<<"Cannot open input"<<endl;
    }

    int k,x;
    fin>>k>>x;
    //cout<<k<<x<<endl;
    int arra[x];
    //llist<int>llist(5);
    //int p=llist.length();
    //cout<<p;
    int choice;
    cout<<"choose :1.to implement with arraylist"<<endl;

    cout<<"choose :2.to implement with linkedlist"<<endl;

    cin>>choice;


    for(int i=0; i<k; i++)
    {
        int p;
        fin>>p;
        arra[i]=p;


    }
    /*for(int i=0;i<k;i++){
        cout<<arra[i]<<endl;
    }*/
    int val;
    fin>>val;
    //cout<<val;
    //cout<<endl;
    int ara2[val][2];
    for(int i=0; i<val; i++)
    {
        for(int j=0; j<2; j++)
        {
            fin>>ara2[i][j];
        }
    }


    LList<int> llist;


    //llist.pushBack(1);
    //cout<<llist.getValue();
    llist.setToBegin();
    for(int i=0; i<k; i++)
    {
        llist.pushBack(arra[i]);
    }
    llist.setToBegin();
    for(int i=0; i<k; i++)
    {
        cout<<llist.getValue();
        llist.next();
    }
    llist.setToBegin();
    llist.next();
    llist.next();
    int pr=llist.currPos();
    llist.setToBegin();
    //ofstream fout2("list_output2.txt");
    ofstream fout2("listoutputllist.txt");

    for(int i=0; i<llist.size(); i++)
    {

        if(i==pr)
        {
            fout2<<'|';
        }
        fout2<<llist.getValue()<<' ';
        llist.next();

    }

    fout2<<endl;
    llist.setToBegin();



    for(int i=0; i<llist.size(); i++)
    {

        if(i==pr)
        {
            fout2<<'|';
        }
        fout2<<llist.getValue()<<' ';
        llist.next();

    }
    fout2<<endl;
    //fout2<<val;

    AList<int> alist(x);


    //alist.pushBack(1);
    //cout<<alist.getValue();
    alist.setToBegin();
    for(int i=0; i<k; i++)
    {
        alist.pushBack(arra[i]);
    }
    alist.setToBegin();
    for(int i=0; i<k; i++)
    {
        cout<<alist.getValue();
        alist.next();
    }
    alist.setToBegin();
    alist.next();
    alist.next();
    int pr2=alist.currPos();
    alist.setToBegin();
    ofstream fout("arrayoutput.txt");
    //ofstream fout("list_output2.txt");
    //ofstream fout2("listoutputllist.txt");

    for(int i=0; i<alist.size(); i++)
    {

        if(i==pr2)
        {
            fout<<'|';
        }
        fout<<alist.getValue()<<' ';
        alist.next();

    }

    fout<<endl;
    alist.setToBegin();



    for(int i=0; i<alist.size(); i++)
    {

        if(i==pr2)
        {
            fout<<'|';
        }
        fout<<alist.getValue()<<' ';
        alist.next();

    }
    fout<<endl;
    //fout<<val;

    for(int i=0; i<val; i++)
    {
        if(choice==1){
        switch(ara2[i][0])
        {

        case 1:
            fout<<alist.size()<<endl;
            break;
        case 2:
            alist.push(ara2[i][1]);
            alist.setToBegin();
            for(int i=0; i<alist.size(); i++)
            {
                if(alist.currPos()==0)
                {
                    fout<<"<";
                }
                if(alist.currPos()==pr2)
                {
                    fout<<'|';
                }

                fout<<alist.getValue()<<' ';
                if(alist.currPos()==alist.size()-1)
                {
                    fout<<">"<<endl;
                }
                // cout<<alist.currPos()<<endl;
                alist.next();
            }
            fout<<endl;
            break;
        case 3:
            alist.pushBack(ara2[i][1]);
            break;
        case 4:


            alist.setToBegin();
            alist.next();
            alist.next();
            int eraser;
            eraser=alist.erase();
            alist.setToBegin();
            for(int i=0; i<alist.size(); i++)
            {
                if(alist.currPos()==0)
                {
                    fout<<"<";
                }
                 if(alist.currPos()==pr2)
                {
                    fout<<'|';
                }
                fout<<alist.getValue()<<' ';
                // cout<<alist.currPos()<<endl;
                if(alist.currPos()==alist.size()-1)
                {
                    fout<<">"<<endl;
                }
                alist.next();
            }
            fout<<endl;
            //fout<< eraser<<endl;
            //fout<<endl;
            break;


        case 5:
            alist.setToBegin();

            for(int i=0; i<alist.size(); i++)
            {
                if(alist.currPos()==0)
                {
                    fout<<"<"<<'|';
                }

                fout<<alist.getValue()<<' ';

                // cout<<alist.currPos()<<endl;
                if(alist.currPos()==alist.size()-1)
                {
                    fout<<">"<<endl;
                }
                alist.next();
            }
            fout<<endl;
            alist.setToBegin();
            if(alist.currPos()==0)
            {
                fout<<-1<<endl;

            };
            break;
        case 6:
            alist.setToEnd();
            break;
        case 7:
            alist.prev();
            break;
        case 8:
            alist.next();
            break;
        case 9:
            fout<<alist.currPos()<<endl;
            break;
        case 10:
            alist.setToPos(ara2[i][1]);
            break;
        case 11:
            fout<<alist.getValue()<<endl;
            break;
        case 12:
            fout<<alist.find(ara2[i][1])<<endl;
            break;
        case 13:
            alist.clear();
            break;
        }

        }
    }

    for(int i=0; i<val; i++)
    {
        if(choice==2){
        switch(ara2[i][0])
        {

        case 1:
            fout2<<llist.size()<<endl;
            break;
        case 2:
            llist.push(ara2[i][1]);
            llist.setToBegin();
            for(int i=0; i<llist.size(); i++)
            {
                if(llist.currPos()==0)
                {
                    fout2<<"<";
                }
                if(llist.currPos()==pr2)
                {
                    fout2<<'|';
                }

                fout2<<llist.getValue()<<' ';
                if(llist.currPos()==llist.size()-1)
                {
                    fout2<<">"<<endl;
                }
                // cout<<llist.currPos()<<endl;
                llist.next();
            }
            fout2<<-1;
            fout2<<endl;
            break;
        case 3:
            llist.pushBack(ara2[i][1]);
            break;
        case 4:


            llist.setToBegin();
            llist.next();
            llist.next();
            int eraser;
            eraser=llist.erase();
            llist.setToBegin();
            for(int i=0; i<llist.size(); i++)
            {
                if(llist.currPos()==0)
                {
                    fout2<<"<";
                }
                 if(llist.currPos()==pr2)
                {
                    fout2<<'|';
                }
                fout2<<llist.getValue()<<' ';
                // cout<<llist.currPos()<<endl;
                if(llist.currPos()==llist.size()-1)
                {
                    fout2<<">"<<endl;
                }
                llist.next();
            }
            fout2<<endl;
            fout2<< eraser<<endl;
            fout2<<endl;
            break;


        case 5:
            llist.setToBegin();

            for(int i=0; i<llist.size(); i++)
            {
                if(llist.currPos()==0)
                {
                    fout2<<"<"<<'|';
                }

                fout2<<llist.getValue()<<' ';

                // cout<<llist.currPos()<<endl;
                if(llist.currPos()==llist.size()-1)
                {
                    fout2<<">"<<endl;
                }
                llist.next();
            }
            fout2<<endl;
            llist.setToBegin();
            if(llist.currPos()==0)
            {
                fout2<<-1<<endl;

            };
            break;
        case 6:
            llist.setToEnd();
            break;
        case 7:
            llist.prev();
            break;
        case 8:
            llist.next();
            break;
        case 9:
            fout2<<llist.currPos()<<endl;
            break;
        case 10:
            llist.setToPos(ara2[i][1]);
            break;
        case 11:
            fout2<<llist.getValue()<<endl;
            break;
        case 12:
            fout2<<llist.find(ara2[i][1])<<endl;
            break;
        case 13:
            llist.clear();
            break;
        }

    }
    }

    /*int op ;
    fin>>op;
    work(1,5);*/
    /*for(int q=0;q<op;q++){


    }*/
    fin.close();

    /*char buffer[1000];
    char*pbuff;
    fgets(buffer,sizeof(buffer),fp);
    pbuff=buffer;
    int value=strtol(pbuff,&pbuff,10);
    cout<<value;
    FILE*fp = fopen("list_input.txt", "r");*/
    /* char buffer[128];
     int a[100];
     int i = 0;
     freopen("26.txt","r",fp);

     while(scanf("%i",&a[i])==1 && buffer[i] != EOF)
         ++i;

     //print values parsed to int array.
     for(int j=0; j<i; ++j)
         printf("[%i]: %i\n",j,a[j]);*/
    /*fstream myFile;
    myFile.open("list_input.txt",ios::in);
        vector<std::vector<double> > numbers;

    string temp;

    while (std::getline(myFile, temp)) {
    istringstream buffer(temp);
    vector<double> line((istream_iterator<double>(buffer)),
                             istream_iterator<double>());

    numbers.push_back(line);
    }*/

}
