
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
    
    int N;
    vector<int> hT;
    vector<int> hB;
    int tC = 0;
    int bC = 0;

    cin >> N;
    int x;
    for(int i=0; i < N;i++){
      cin >> x;
      hT.push_back(x);
    }

    for(int i=0; i < N;i++){
      cin >> x;
      hB.push_back(x);
    }

    int prev = INF;

    int state = 0;
    for(int i=0; i < N;i++){
      
      if(state == 0) {
        if(hB[i] > prev || hB[i]== 0){
          bC++;
          state = 1;
        }
      }
      else{
        if(hT[i] > prev || hT[i]== 0){
          bC++;
          state = 0;
        }
      }

      if(state == 0){
        prev= hB[i];
      }
      else {
        prev = hT[i];
      }
    }

    
    state = 1;
    for(int i=0; i < N;i++){
      
      if(state == 0) {
        if(hB[i] > prev || hB[i]== 0){
          tC++;
          state = 1;
        }
      }
      else{
        if(hT[i] > prev || hT[i]== 0){
          tC++;
          state = 0;
        }
      }

      
      if(state == 0){
        prev= hB[i];
      }
      else {
        prev = hT[i];
      }
    }

    if(tC < bC){
      cout << tC << endl;
    }
    else{
      cout << bC << endl;
    }
   
    
    return 0;
}
