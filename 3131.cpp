
#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'

#define dbg(x) cout << #x << " = " << x << endl

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main() {
    _;

    vector<int> grau;
    vector<int> ranks;
    vector<pair<int,int>> g;
    int P,L;

    cin >> P;
    cin >> L;

    ranks.resize(P,0);
    grau.resize(P,0);

    int x1,x2;
    for(int i=0; i < L;i++){
      cin >> x1;
      cin >> x2;
      x1--;
      x2--;

      grau[x2]++;
      ranks[x2]++;
      g.push_back({x1,x2});
    }

    for(auto const& p : g){
      ranks[p.second] += grau[p.first];
    }
    
    for(int i=0; i < P;i++){
      cout << i+1 << ": " << ranks[i] << endl;
    }

    
    return 0;
}
