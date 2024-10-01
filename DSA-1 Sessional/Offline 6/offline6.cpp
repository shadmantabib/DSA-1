#include <iostream>
#include<fstream>
using namespace std;
ifstream fin("greedy.txt");
ofstream fout("greedyoutput.txt");

int main()
{
    int n;
    fin >> n;
    int arrival[n], departure[n];
    for(int i = 0; i < n; i++)
    {
        fin >> arrival[i] >> departure[i];
    }
    // Sort customers by their departure time
    for(int i = 0; i < n; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            if(departure[j] < departure[i])
            {
                swap(arrival[i], arrival[j]);
                swap(departure[i], departure[j]);
            }
        }
    }

    int count = 0;
    int customer[n][2];
    int last = -1;
    for(int i = 0; i < n; i++)
    {
        if(arrival[i] >= last)
        {
            customer[count][0] = arrival[i];
            customer[count][1] = departure[i];
            count++;
            last = departure[i];
        }
    }
    fout<< count << endl;
    //cout << "customer customers: " << endl;
    for(int i = 0; i < count; i++)
    {
        fout << customer[i][0] << " " << customer[i][1] << endl;
    }
    return 0;
}
