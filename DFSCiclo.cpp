#include<bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);

const int MAX = 1e3 + 10;
priority_queue<int> q; 

void print_ciclo(int atual, int inicio, vector<int> pai)
{
    int v = atual;
    
    while (v != inicio)
    {
        q.push(v + 1);
        v = pai[v];
    }
    
    q.push(inicio + 1);

}

void dfs(int v, int p, int d, int k, vector<vector<int>> &g, vector<bool> &vis, vector<int> &pai, vector<int> &dist)
{
    vis[v] = true;
    pai[v] = p;
    dist[v] = d;

    for (auto w : g[v])
    {
        if (w == p) continue;

        if (vis[w])
        {
            int tamanho = dist[v] - dist[w] + 1;
            
            if (tamanho > k)
            {
                print_ciclo(v, w, pai);
            }
        }
        else
        {
            dfs(w, v, d + 1, k, g, vis, pai, dist);
        }
    }
}

int main() {
    _;
    
    int n,m,k,a,b;
    
    while(cin>>n>>m>>k)
    {
        vector<bool> vis(MAX);
        vector<int> pai(MAX);
        vector<int> dist(MAX);
        vector<vector<int>> g(MAX);
        while(m--)
        {
            cin>>a>>b;
            g[a-1].push_back(b-1);
            g[b-1].push_back(a-1);
        }
        
        for (int i = 0; i < n; i++) if (!vis[i]) {
            dfs(i, -1, 0, k, g, vis, pai, dist);
        }
        
        if(q.size() == 0)
        {
            cout << "0" << endl;
        }
        else{
            while(!q.empty())
            {
                cout << q.top() << " ";
                q.pop();
            }
            cout << endl;
        }
    }
    
    return 0;
}
