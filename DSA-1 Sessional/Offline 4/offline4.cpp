#include<iostream>
#include<fstream>
#include<string>
#include<math.h>

using namespace std;

ifstream fin("off4input.txt");
//ifstream fin("off2input.txt");
ofstream fout("off4output.txt");


// A utility function to swap two elements
void swap(int & x, int & y)
{
    int temp = x;
    x = y;
    y = temp;
}

class MinHeap
{
public:
    int * harr; // pointer to array of elements in heap
    int capacity; // maximum possible size of min heap
    int heap_size; // Current number of elements in min heap

    MinHeap(int cap)
    {
        heap_size = 0;
        capacity = cap;
        harr = new int[cap];
    }
    int parent(int i)
    {
        return (i - 1) / 2;
    }

    int left(int i)
    {
        return (2 * i + 1);
    }

    int right(int i)
    {
        return (2 * i + 2);
    }

    int getMin()
    {

        return harr[0];
    }
    void printGivenLevel( int root,int level)
    {
        int i;
        for (int j = 0; j < heap_size; j++)
        {
            if (harr[j] == root)
            {
                i=j;
                //printf("%d\n",i);
                break;
            }
        }
        if (root==NULL)
        {
            return;
        }

        if (level == 1)
        {
            printf("%d ", root);
        }
        else if (level > 1 && harr[left(i)]!=NULL && harr[right(i)]!=NULL)
        {
            printGivenLevel(harr[left(i)], level - 1);
            printGivenLevel(harr[right(i)], level - 1);
        }
    }
    int height()
    {
        return ceil(log2(heap_size + 1)) - 1;
    }
    void printLevelOrder()
    {
        int h = height();
        int i;
        int root=harr[0];
        printf("%d\n",h);
        for (i = 1; i <= (h+1); i++)
        {
            printf("Level: %d\n",i);
            printGivenLevel(root,i);
            printf("\n");
        }
    }
    void insertKey(int k)
    {
        if (heap_size == capacity)
        {
            fout << "\nOverflow: Could not insert Key\n";
            return;
        }

        // First insert the new key at the end
        heap_size++;
        int i = heap_size - 1;
        harr[i] = k;

        // Fix the min heap property if it is violated
        while (i != 0 && harr[parent(i)] > harr[i])
        {
            swap(harr[i], harr[parent(i)]);
            i = parent(i);
        }
        fout<<"INSERTED "<<k<<endl;
    }
    void decreaseKey(int prev, int new_val)
    {
        int i;
        for (int j = 0; j < heap_size; j++)
        {
            if (harr[j] == prev)
            {
                i=j;
                //printf("%d\n",i);
                break;
            }
        }
        harr[i] = new_val;
        while (i != 0 && harr[parent(i)] > harr[i])
        {
            swap(harr[i],harr[parent(i)]);
            i = parent(i);
        }
        fout<<prev<<' '<<"decreased to "<<new_val<<endl;
    }

    /*void linearSearch(int val)
    {
        for (int i = 0; i < heap_size; i++)
        {
            if (harr[i] == val)
            {
                cout << "Value Found!";
                return;
            }
        }
        cout << "Value NOT Found!";
    }*/


    int extractMin()
    {
        if (heap_size <= 0)
            return -1;
        if (heap_size == 1)
        {
            heap_size--;
            return harr[0];
        }


        int root = harr[0];
        harr[0] = harr[heap_size - 1];
        heap_size--;
        MinHeapify(0);
        //cout<<"ExtractMin returned"<<' '<<root<<endl;
        return root;
    }


    void MinHeapify(int i)
    {
        int l = left(i);
        int r = right(i);
        int smallest = i;
        if (l < heap_size && harr[l] < harr[i])
            smallest = l;
        if (r < heap_size && harr[r] < harr[smallest])
            smallest = r;
        if (smallest != i)
        {
            swap(  harr[i], harr[smallest]);
            MinHeapify(smallest);
        }
    }

    /*void printArray()
    {
        for (int i = 0; i < heap_size; i++)
            cout << harr[i] << " ";
        cout << endl;
    }*/
    void PrintByLevel(){

    for(int i=0;i<heap_size;i++){
        int flag=1;
        for(int j=0;j<pow(2,i)&&j+pow(2,i)<=heap_size;j++){
            if(flag){
            fout<<"Level "<<i<<':'<<" ";
            }
            //printf("%d",harr[j+(int)pow(2,i)-1]);
            int p=harr[j+(int)pow(2,i)-1];
            fout<<p;
            fout<<" ";
            flag=0;

        }
        //printf("\n");
        fout<<endl;
    }
    }


};

int main()
{
    int s;
    //cout << "Enter Size of Min Heap" << endl;
    //cin >> s;


    cout << "Min Heap Created" << endl;
    MinHeap obj(1000);
    int option, val,vall;
    string line;



    //Node * new_node = new Node();
    while (!fin.eof())
    {
        // Increment the current line number being read as we are reading in the
        // next line now


        // Read the next line from the 'file' into the 'line' string

        string str;
        fin>>str;
        //printf("%s\n",str);

        if(str=="INS")
        {
            int a;
            fin>>a;
            obj.insertKey(a);

        }
        if(str=="PRI")
        {
            fout<<"PRINTING THE BINARY HEAP"<<endl;
            obj.PrintByLevel();
        }
        if(str=="EXT")
        {

             fout<<"ExtractMin returned "<<obj.extractMin()<<endl;
        }
        if(str=="DEC")
        {
            int a,b;
            fin>>a>>b;
            obj.decreaseKey(a,b);

        }
        if(str=="FIN")
        {
            fout<<"FindMin returned "<<obj.getMin()<<endl;
            //cout<<obj.getMin()<<endl;
        }


        /* else
         {
             cout << "Invalid Operation" << endl;
             fout << "Invalid Operation" << endl;
         }*/





    }

    return 0;
}
