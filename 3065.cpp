
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

    int m;

    int count =0;
    while(cin >> m && m !=0){
      int x;
      char op;

      ll val;
      cin >>val;

        // dbg(val);
      for(int i=1;i < m;i++){
        cin >> x;

        // dbg(val);
        val += x;
      }

      count++;
      cout << "Teste " << count << endl;
      cout << val << endl << endl;
    }
    
    return 0;
}
