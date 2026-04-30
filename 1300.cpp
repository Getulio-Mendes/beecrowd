#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'

#define dbg(x) cout << #x << " = " << x << endl

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main() {

  int n;

  while(cin >> n){

    bool found = false;

    int hptr = 0;
    int mptr = 0;

    int dif = 0;
    int ang = 0;

    for(int i=0; i < 360;i++){
      hptr = i / 12;
      mptr = i;

      dif = mptr - hptr;
      ang = dif * 180/30;
      if(ang == n){
        found = true;
        break;
      }
    }

    if(found)
      cout << "Y" << endl;
    else
      cout << "N" << endl;
  }
    
    return 0;
}
