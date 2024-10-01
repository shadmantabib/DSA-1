#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


vector<pair<int, int>> invertedpairs;


void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l+(r-l)/2;

        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        //merge(arr, l, m, r);
        int i, j, k;
        int n1 = m - l + 1;
        int n2 = r - m;
        vector<int> L, R;

        for (i = 0; i < n1; i++)
            L.push_back(arr[l + i]);
        for (j = 0; j < n2; j++)
            R.push_back(arr[m + 1+ j]);

        i = 0;
        j = 0;
        k = l;
        while (i < n1 && j < n2)
        {
            if (L[i] <= R[j])
            {
                arr[k] = L[i];
                i++;
            }
            else
            {
                arr[k] = R[j];
                j++;
                for(int p=i; p<n1; p++)
                    invertedpairs.push_back(make_pair(L[p], R[j-1]));
            }
            k++;
        }

        while (i < n1)
        {
            arr[k] = L[i];
            i++;
            k++;
        }

        while (j < n2)
        {
            arr[k] = R[j];
            j++;
            k++;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++)
        cin >> arr[i];
    mergeSort(arr, 0, n - 1);
    cout << invertedpairs.size() << endl;
    cout << "The inverted pairs are ";
    for(auto pair: invertedpairs)
    {
        cout << "(" << pair.first << "," << pair.second << ") ";
    }
    return 0;
}

