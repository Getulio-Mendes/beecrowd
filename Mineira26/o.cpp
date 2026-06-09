
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


    int n;
    char op;
    ll x;

    cin >> n;
    ll a=1,b=0;
    ll final;

    for(int i=0; i < n;i++){
      cin >> op >> x;

      if(op == '+'){
        b = (b+x) % (1000000000 + 7);
      }
      else if(op == '*'){
        a = (x*a) % (1000000000 + 7);
        b = (x*b) % (1000000000 + 7);
      }
      else if (op == '?'){
        final = (a*x + b) % (1000000000 + 7);
        cout << final << endl;
      }

    }
    
    return 0;
}
