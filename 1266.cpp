#include <bits/stdc++.h>
#include <string>

using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'

#define dbg(x) cout << #x << " = " << x << endl

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main() {

  int N;

  while(cin >> N && N!=0){
    int count = 0;
    int fst_seq=0;
    bool jumped = false;
    bool find_i = false;
    vector<int> postes(N,0);

    for(int i=0; i < N;i++){
      cin >> postes[i];
      if(postes[i] == 1){
        find_i = true;
      }
    }

    if(!find_i){
      cout << (N+1)/2 << endl;
      continue;
    }

    for(int i=0; i < N;i++){
      if(postes[i] == 1 && jumped == true){
        break;
      }
      else if (postes[i] == 1){
        continue;
      }
      else{
        int j=i;
        int seq = 0;

        while(j < N && postes[j] == 0){

          if(j == N-1 && postes[j] == 0 && fst_seq > 0){
            // remove the value from the first sequence
            count -= fst_seq/2;
            fst_seq = 0;
            j = 0;
            jumped = true;
            seq++;
            continue;
          }
          seq++;
          j++;
        }
        
        if(i == 0){
          fst_seq = seq;
          seq = 0;
          count += fst_seq/2;
        }
        count += seq/2;

        i = j - 1;
      }
          

    }

    cout << count << endl;
    
  }  
  return 0;
}
