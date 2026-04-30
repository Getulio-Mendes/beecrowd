#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'

#define dbg(x) cout << #x << " = " << x << endl

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main() {

  string line;
  int x1,y1,x2,y2;

  while(getline(cin,line)){
    auto s = stringstream(line);
    s >> x1;
    s >> y1;
    s >> x2;
    s >> y2;

 
    if(x1 == 0 && y1 == 0 && x2 == 0 && y2 == 0){
        break;
    }

    if((x1 == x2) && (y1 == y2)){
      cout << 0 << endl;
    }
    // mesma linha / coluna
    else if((x1 == x2) || (y1 == y2)){
      cout << 1 << endl;
    }

    // diagonal crescente
    else if((x1 - y1) == (x2 - y2)){
      cout << 1 << endl;
    }
    // diagonal decrescente
    else if((x1 + y1) == (x2 + y2)){
      cout << 1 << endl;
    }
    else{
      cout << 2 << endl;
    }

  }
    
    return 0;
}
