
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

    int N;

    while(cin >> N && N != 0){
      int f=0,p=0;

      while(f+p < N){
        p++;
        int c = p;
        for(int i=0; i < c;i++){
          if(f+p >= N){
            p--;
          }
          f++;
        }
      }
      
      cout << f << " " << p << endl;
    }
    
    return 0;
}
