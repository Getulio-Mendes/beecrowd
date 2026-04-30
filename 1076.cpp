#include <bits/stdc++.h>
#include <vector>

using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'

#define dbg(x) cout << #x << " = " << x << endl

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void dfs(vector<vector<int>> &g, vector<int> &usada){
  
}

int main() {

  int T,V,A;
  int N;
  cin >> T;

  for(int i=0; i < T;i++){
    cin >> N;

    cin >> V;
    cin >> A;

    vector<vector<int>> g(V);
    vector<int> usada(A);
    int u,v;
    for(int  j=0; j < A;j++){

      cin >> u;
      cin >> v;

      g[u].push_back(v);
      g[v].push_back(u);

     
    }

  }
    
    return 0;
}
