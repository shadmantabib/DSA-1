#include <iostream>
#include<vector>
#include<algorithm>
#include<fstream>
using namespace std;
ifstream fin("knapsack.txt");
ofstream fout("outknap.txt");
int n, W;
vector<int> w, v;
vector<vector<int>> dp;
int manualMax(int a, int b)
    {
        return a > b ? a : b;
    }

void knapsack()

{

    fin >> n;
    w.resize(n);
    v.resize(n);
    for (int i = 0; i < n; i++)
    {
        fin >> w[i] >> v[i];
    }
    fin>> W;

    dp.resize(n + 1);
    for (int i = 0; i <= n; i++)
    {
        dp[i].resize(W + 1);
        for (int j = 0; j <= W; j++)
        {
            dp[i][j] = 0;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            if (w[i - 1] <= j)
            {
                dp[i][j] = manualMax(dp[i - 1][j - w[i - 1]] + v[i - 1], dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    cout << dp[n][W] << endl;
    fout << dp[n][W] << endl;
    vector<int> result;
    int i = n, j = W;
    while (i > 0 && j > 0)
    {
        if (dp[i][j] != dp[i - 1][j])
        {
            result.push_back(w[i - 1]);
            j -= w[i - 1];
            i--;
        }
        else
        {
            i--;
        }
    }

    reverse(result.begin(), result.end());
      for (int i=0;i<result.size();i++)
     {
          cout << result[i] << " ";
         fout <<result[i] << " ";
     }
    /*for (int x: result)
    {
        cout << x << " ";
        fout << x << " ";
    }*/
    cout << endl;
    fout << endl;
}

int main()
{
    knapsack();

}
