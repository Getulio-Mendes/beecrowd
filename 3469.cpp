
#include <bits/stdc++.h>
#include <vector>

using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'

#define dbg(x) cout << #x << " = " << x << endl

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main() {
    _;

    
    ll N;
    vector<int> cnt(1000000);

    cin >> N;

    int m;
    for(int i=0; i < N;i++){
      int x;
      cin >> x;
      cnt[x]++;
    }


    int met=0;
    if(N % 2 == 0){
      met = N/2;
    }else{
      met = (N+1)/2;
    }

    
    int sum = 0;
    int pos=0;
    for(int i = 1; i <= 1000000; i++){
      sum += cnt[i];
      if(sum >= met){
        m = i;
        break;
      }
    }

    cout << m << endl;
    return 0;
}
