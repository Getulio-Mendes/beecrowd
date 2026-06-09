
#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'

#define dbg(x) cout << #x << " = " << x << endl

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;


vector<tuple<int, int, int>> edges;
vector<pair<int, int>> final;
vector<int> parent;

int find(int x)
{
    if (parent[x] != x) parent[x] = find(parent[x]);
    
    return parent[x];
}

bool unite(int x, int y)
{
    x = find(x);
    y = find(y);
    
    if (x == y) return false;
    
    parent[y] = x;
    
    return true;
}

int kruskal(int n)
{
    sort(edges.begin(), edges.end());
    parent.resize(n);
    iota(parent.begin(), parent.end(), 0);
    
    int mst = 0;
    
    for (auto [w, u, v] : edges)
    {
        if (unite(u, v)){
          final.push_back({u,v});
          mst += w;
        }
    }
    return mst;
}

int main() {
    _;

    int n,m;    

    int count = 1;
    while(cin >> n >> m && (n != 0 && m != 0)){
      edges.clear();
      final.clear();
      parent.clear();
      for(int i=0; i < m;i++){
        int x,y,w;
        cin >> x >> y >> w;

        edges.push_back({w,x-1,y-1});
      }

      int mst = kruskal(n);

      cout << "Teste " << count << endl;
      for(auto const &p : final){
        cout << p.first+1 << " " << p.second+1 << endl;
      }
      cout << endl;
      
    count++;
    }
    
    return 0;
}
