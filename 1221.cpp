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

  for(int i=0;i<N;i++){
    bool prime = true;

    cin >> x;

    for(int j=2;j < sqrt(x);j++){
      if(x % j == 0){
        prime = false;
      }
    }

    if(x == 1 || x == 0){
      prime = false;
    }
    
    if(prime){
      cout << "Prime" << endl;
    }
    else{
      cout << "Not Prime" << endl;
    }
  }

    
    return 0;
}
