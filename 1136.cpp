#include <bits/stdc++.h>
#include <iosfwd>

using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'

#define dbg(x) cout << #x << " = " << x << endl

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main() {


  int N,B;
  while(cin >> N >> B){

    vector<int> balls;

    if(N == 0 && B == 0){
      break;
    }

    for(int i = 0; i < B; i++){
      int b;
      cin >> b;
      balls.push_back(b);
    }

    bool flag = true;
    for(int n = 0; n <= N;n++){
      bool found = false;

      for(int j=0; j < balls.size();j++){
        for(int k=0; k < balls.size();k++){
          if (abs(balls[j] - balls[k]) == n){
            found = true;
          }
        }
      }

      if(found == false){
        flag = false;
      }

    }

    
    if(flag){
      cout << "Y" << endl;
    }
    else {
      cout << "N" << endl;
    }

  }
    
  return 0;
}
