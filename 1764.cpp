
#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'

#define dbg(x) cout << #x << " = " << x << endl

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

vector<tuple<int, int, int>> edges;
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
        if (unite(u, v))
            mst += w;
    }
    return mst;
}

int main() {
    _;

    int M,N;


    while(cin >> M >> N && M!=0 && N!=0){
      edges.clear();
      int x,y,z;
      for(int i=0; i < N;i++){
        cin >> x >> y >> z;

        edges.push_back({z,x,y});
      }

      int mst = kruskal(M);

      cout << mst << endl;
    }

    
    return 0;
}
