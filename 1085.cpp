
#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'

#define dbg(x) cout << #x << " = " << x << endl

typedef long long ll;

const int INF = 0x3f3f3f3f;

// Algoritmo de Dijkstra
typedef long long ll;
const ll LINF = 1e18;
const int MAX = 1e5 + 5;

ll d[MAX];
vector<tuple<int, int>> g[MAX]; // {vizinho, peso}
int N;

unordered_map<string,int> wordMap;
void dijkstra(int v) {
    for (int i = 0; i < N; i++)
        d[i] = LINF;

    d[v] = 0;
    priority_queue<pair<ll, int>> pq;
    pq.emplace(0, v);

    while (!pq.empty()) {
        auto [ndist, u] = pq.top(); pq.pop();
        if (-ndist > d[u]) continue;
        int wordIndex=0;

        for (auto [idx, w] : g[u]) {
            
            string word1,word2;
            for (const auto& [key, value] : wordMap){
                if (value == u){
                    word1 = key;
                }
                else if (value == idx){
                    word2 = key;
                }
            }
            if (d[idx] > d[u] + w && word1[0] != word2[0]) {
                d[idx] = d[u] + w;
                pq.emplace(-d[idx], idx);
            }
        }
    }
}

int main() {
    _;

    int id=0;
    int origem,destino;

    while(cin >> N && N !=0){
      string idioma1,idioma2,p;

      cin >> idioma1;
      cin >> idioma2;

      wordMap[idioma1] = id;
      origem = id;
      id++;

      wordMap[idioma2] = id;
      destino = id;
      id++;

      for(int i=0; i < N;i++){
        cin >> idioma1;
        cin >> idioma2;
        cin >> p;

        if(wordMap.count(idioma1) == 0){
          wordMap[idioma1] = id;
          id++;
        }

        if(wordMap.count(idioma2) == 0){
          wordMap[idioma2] = id;
          id++;
        }

        g[wordMap[idioma1]].push_back({wordMap[idioma2],p.size()});
        g[wordMap[idioma2]].push_back({wordMap[idioma1],p.size()});
      }

      // for(auto const& [k,v] : map){
      //   cout << k <<" = " << v << endl;
      // }
      // for (int i = 0; i <= N; i++) {
      //   for (auto [v, w] : g[i]) {
      //     cout << i << " -> " << v << " (weight " << w << ")\n";
      //   }
      // }
      dijkstra(origem);

      // for(int i=0; i < N;i++){
      //   cout << i << " = "<< d[i] << endl;
      // }

      if(d[destino] == LINF){
          cout << "impossivel" << endl;
      }
      else{
          cout << d[destino] << endl;
      }
      wordMap.clear();
      id = 0;
      
      for (int i = 0; i < MAX; i++) {
          g[i].clear();
      }
    }
    

    return 0;
}
