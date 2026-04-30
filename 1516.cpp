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
    int A,B;

    while(cin >> N >> M && N != 0 != M){
      vector<string> l(N);

      cin.ignore();
      for(int i=0; i < N;i++){
        getline(cin,l[i]);
      }
      cin >> A >> B;

      int f1 = A / N;
      int f2 = B / M;

      for(int i=0; i < N;i++){
        for(int j=0; j < f1;j++){
          for(char s : l[i]){
            for(int k=0;k < f2;k++){
              cout << s;
            }
          }
          cout << endl;
        }
      }

      cout << endl;
    }

    
    return 0;
}
