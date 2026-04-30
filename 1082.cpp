
#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'

#define dbg(x) cout << #x << " = " << x << endl

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

vector<tuple<int,int, int>> edges;
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
            mst += w;
        }
    }

    return mst;
}

int main() {
    _;
    // 

    int N,E,V;
    char x,y;

    cin >> N;


    for(int i=0; i < N;i++){
      edges.clear();
      parent.clear();
      cin >> V >> E;


      for(int j=0; j < E;j++){
        cin >> x >> y;

        edges.push_back({1,x-'a',y-'a'});
      }


      kruskal(V);
      vector<char> uniques;
      int count = 0;
      for(int j=0; j < parent.size();j++){
        int p = find(j);
        if(find(uniques.begin(),uniques.end(),p) == uniques.end()){
          count++;
          uniques.push_back(parent[j]);
        }       
      }

      cout << "Case #" << i+1 << ":" << endl;
      for(int j=0; j < uniques.size();j++){
        for(int k=0; k < parent.size();k++){
          if(parent[k] == uniques[j]){
            cout << char(k+'a') << ",";
          }
        }
        cout << endl;
      }

      cout << count << " connected components" << endl;
      cout << endl;
    }
    
    return 0;
}
