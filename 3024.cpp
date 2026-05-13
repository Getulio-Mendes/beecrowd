
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

    int N,X;

    cin >> N;
    cin >> X;

    vector<int> views;

    for(int i=0; i < N;i++){
      int x;
      cin >> x;

      views.push_back(x);
    }

    int bestSeq = 0;

    for(int i=0; i < views.size();i++){
      int seq = 1;
      for(int j=i; j+1 < views.size();j++){
        if(views[j+1] - views[j] <= X){
          seq++;
        }
        else{
          break;
        }
      }
      if(seq > bestSeq){
        bestSeq = seq;
      }
    }

    cout << bestSeq << endl;
    
    return 0;
}
