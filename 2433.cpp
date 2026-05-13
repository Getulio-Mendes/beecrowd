
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

    int N,K;

    cin >> N;
    cin >> K;

    vector<int> v(N);

      int x;
    for(int i=0; i < N;i++){
      cin >> x;
      v[i] = x;
    }

    sort(v.begin(),v.end());

    int menor = INF;

    // remove do comeco
    for(int i=0; i <= K;i++){
      int final = K-i;

      int dist = v[N-final-1]  - v[i];

      if(dist < menor){
        menor = dist;
      }
    }

    
    cout << menor << endl;
    
    return 0;
}
