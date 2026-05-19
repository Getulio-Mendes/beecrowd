
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
    
    string s;
    while(cin >> s){

      int val = 0;

      reverse(s.begin(),s.end());
      int count = 0;
      ll total =0;
      for(auto c : s){
        ll val = c - 'A' + 1;

        for(int i=0; i < count;i++){
          val *= 26;
        }
        count++;

        total+= val;
      }
      if(total > 16384){
        cout << "Essa coluna nao existe Tobias!" << endl;
      }
      else{
        cout << total << endl;
      }
    }
    return 0;
}
