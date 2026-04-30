#include <bits/stdc++.h>
#include <sstream>
#include <string>

using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'

#define dbg(x) cout << #x << " = " << x << endl

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main() {
        
  string line;
  unsigned int a,b;

  while(getline(cin,line)){
    auto s = stringstream(line);
    s >> a;
    s >> b;

    cout << (a ^ b) << endl;
  }
  return 0;
}
