
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

    ll N,K;
    bitset<32> b;
    unsigned long long int min;
    unsigned long long int max;

    while(cin >> N >> K && N != 0 && K!= 0){
      b = N;
      min = N;
      max = N;

      int A,B;
      for(int i=0; i < K;i++){
        cin >> A;
        cin >> B;

        int swap = b[A];
        b[A] = b[B];
        b[B] = swap;

        if(b.to_ulong() < min){
          min = b.to_ulong();
        }
        if(b.to_ulong() > max){
          max = b.to_ulong();
        }
      }

      cout << b.to_ullong() << " " << max << " " << min << endl;
    }

    
    return 0;
}
