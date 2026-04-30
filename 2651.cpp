
#include <bits/stdc++.h>
#include <cctype>

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

    getline(cin,s);

    for(auto & c : s){
      c = tolower(c);
    }
    if(s.find("zelda") != string::npos){
      cout << "Link Bolado" << endl;
    }
    else{
      cout << "Link Tranquilo" << endl;
    }
    return 0;
}
