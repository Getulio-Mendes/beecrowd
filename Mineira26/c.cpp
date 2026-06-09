
#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'

#define dbg(x) cout << #x << " = " << x << endl

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main() {
    _;

    int n;
    int c;

    vector<pair<int,int>> deck;
    pair<int,int> maior = {0,0};
    int dead_idx = 1;
    unordered_map<int,bool> card;

    for(int i=1; i <= n;i++){
      cin >> c;

      deck.push_back({c,i});

      if(card[c] == true){
        dead_idx = i;
        card[c] = false;
      }
      else{
        card[c] = true;
      }
      
      for(int j=dead_idx;j < i;j++){
        dbg(maior.first);
        dbg(maior.first);
        if(maior.first < deck[j].first){
          maior = deck[j];
        }
      }
      cout<< maior.first << maior.second << endl;
    }
    
    return 0;
}
