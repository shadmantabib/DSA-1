#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<fstream>

using namespace std;
ifstream fin("off5i.txt");
ofstream fout("off5output.txt");
int pred[1001];
//vector<int>pred1[1001];

void edge(vector<int>adj[],int u,int v){
  adj[u].push_back(v);
}

void bfs(int s,vector<int>adj[],bool visit[]){
  queue<int>q;
  q.push(s);
  visit[s]=true;
  for(int i=0;i<1001;i++){
    pred[i]=-1;
}

  //pred[s]=-1;
  //pred1.push_back()
  while(!q.empty()){
    int u=q.front();
    cout<<u<<" ";
    fout<<u<<" ";
    q.pop();

    for(int i=0;i<adj[u].size();i++){
            int next=adj[u][i];
      if(!visit[adj[u][i]]){
        q.push(adj[u][i]);
        visit[adj[u][i]]=true;
        pred[next]=u;
       // pred1
      }
    }
  }
  cout<<endl;
}

void dfs(int s,vector<int>adj[],bool visit[]){
  stack<int>stk;
  stk.push(s);
  visit[s]=true;
  while(!stk.empty()){
    int u=stk.top();
    cout<<u<<" ";
    fout<<u<<" ";
    stk.pop();

    for(int i=0;i<adj[u].size();i++){
            int next=adj[u][i];
      if(!visit[adj[u][i]]){
        stk.push(adj[u][i]);

        visit[adj[u][i]]=true;
        pred[next]=u;
      }
    }
  }
   cout<<endl;
   fout<<endl;
}

int main(){
  /*vector<int>adj[5];
  bool visit[5];

  for(int i=0;i<5;i++){
    visit[i]=false;
  }

  /*edge(adj,1,2);
  edge(adj,1,3);
  edge(adj,3,2);
  edge(adj,4,3);
  edge(adj,2,4);
  edge(adj,5,4);
  edge(adj,5,6);
  edge(adj,6,6);*/

  /*edge(adj,0,2);
  edge(adj,0,1);
  edge(adj,1,3);
  edge(adj,2,0);
  edge(adj,2,3);
  edge(adj,2,4);
  cout<<"BFS traversal is"<<"  ";

  bfs(0,adj,visit);
  cout<<endl;

  for(int i=0;i<5;i++){
    visit[i]=false;
  }
  cout<<"DFS traversal is"<<"  ";

  dfs(0,adj,visit);*/
  vector<int>adj[1001];
  bool visit[1001];
      int n, m, u, v, s;
      fin>>n>>m;
       for (int i = 0; i < m; i++) {
        fin >> u >> v;
        //adj[u].push_back(v);
        edge(adj,u,v);
    }
    /*cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        //adj[u].push_back(v);
        edge(adj,u,v);
    }*/
    fin >> s;
    cout<<"BFS output is:"<<endl;
    fout<<"BFS output is:"<<endl;
    bfs(s,adj,visit);
    cout<<"Visited edges are:"<<endl;
    for (int i =1 ; i <=n; i++) {
        if (pred[i] != -1) {
            cout << "(" << pred[i] << "->" << i << ")" << endl;
            fout << "(" << pred[i] << "->" << i << ")" << endl;
           // cout<<"Notice"<<pred[n-2]<<endl;
        }
    }
    cout << endl;
    fout << endl;
    for (int i = 1; i <= n; i++) {
        visit[i] = false;
    }
    cout<<"DFS output is"<<endl;
    fout<<"DFS output is"<<endl;
    dfs(s,adj,visit);
    cout<<"Visited edges are:"<<endl;
    for (int i = 1; i <= n; i++) {
        if (pred[i] != -1) {
            cout << "(" << pred[i] << "->" << i<< ")" << endl;
             fout << "(" << pred[i] << "->" << i<< ")" << endl;
             //cout<<"Notice"<<pred[4]<<n<<endl;
        }
    }
    return 0;

}
