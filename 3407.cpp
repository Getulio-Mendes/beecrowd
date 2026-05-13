
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

    int N,M;

    cin >> N;
    cin >> M;

    int nc=0;
    int sc=0;
    for(int i=0; i < N;i++){
      int x;
      cin >> x;

      if(x == 1){
        nc++;
      }
    }
    for(int i=0; i < N;i++){
      int x;
      cin >> x;

      if(x == 1){
        sc++;
      }
    }

    if(nc == M){
      cout << "Tudo certo." << endl;
    }
    else if(nc != M && sc == M){
      cout << "Pegou de Samuel." << endl;
    }
    else if(nc != M && sc != M ){
      cout << "Pegou de um estranho." << endl;
    }
    
    return 0;
}
