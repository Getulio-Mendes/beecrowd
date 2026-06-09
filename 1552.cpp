
#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'

#define dbg(x) cout << #x << " = " << x << endl

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;


vector<tuple<double, int, int>> edges;
vector<tuple<int, int,int>> pos;
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

double kruskal(int n)
{
    sort(edges.begin(), edges.end());
    parent.resize(n);
    iota(parent.begin(), parent.end(), 0);
    
    double mst = 0;
    
    for (auto [w, u, v] : edges)
    {
        if (unite(u, v))
            mst += w;
    }
    return mst;
}

int main() {
    _;

    int c;

    cin >> c;

    for(int i=0; i < c;i++){
      int n;
      cin >> n;

      edges.clear();
      pos.clear();
      parent.clear();
      for(int j=0; j < n;j++){
        int x,y;
        cin >> x >> y;
        pos.push_back({x,y,j});
      }

      for(auto const& [x,y,i] : pos){
        for(auto const& [x2,y2,i2] : pos){
          if(i != i2){
            double dist = sqrt(pow(x-x2,2) + pow(y-y2,2));
            edges.push_back({dist,i,i2});
          }
        }
      }

      double mst = kruskal(n);

      cout << fixed << setprecision(2) <<mst/100 << endl;
    }
    
    return 0;
}
