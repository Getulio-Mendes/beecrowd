
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
    
    int C;

    cin >> C;
    string p1,p2,p3;

    for(int i=0; i < C;i++){
      cin >> p1;
      cin >> p2;
      cin >> p3;

      int idx1 = 0, idx2 =0;
      for(int j=0; j < p3.size();j++){
        if(p3[j] == '_'){
          if(idx1 == 0){
            idx1 = j;
          }
          else{
            idx2= j;
          }
        }
      }

      if(p1[idx1] == p2[idx2] || p2[idx1] == p1[idx2]){
        cout << "Y" << endl;
      }
      else{
        cout << "N" << endl;
      }
    }
    return 0;
}
