
#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'

#define dbg(x) cout << #x << " = " << x << endl

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main() {

  int N,M;
  int x;

  while(cin >> N >> M && N != 0 && M != 0){

    unordered_map<int, int> m;
    for(int i=0; i < M;i++){
      cin >> x;

      m[x]++;
    }

    int count = 0;
    for(auto const& [k,v] : m){
      if(v > 1){
        count++;
      }
    }


    cout << count << endl;
  }
    
    return 0;
}
