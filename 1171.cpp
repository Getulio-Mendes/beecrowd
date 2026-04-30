#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'

#define dbg(x) cout << #x << " = " << x << endl

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main() {
  int N,x;

  cin >> N;
  map<int,int> m;

  for(int i=0;i<N;i++){


    cin >> x;
    m[x]++;
  }

  for(auto p : m){
    cout << p.first << " aparece " << p.second << " vez(es)" << endl;
  }
    
    return 0;
}
