
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
const int MAX = 4000 + 5;

ll d[MAX][27];
vector<tuple<int, int,char>> g[MAX]; // {vizinho, peso}
int M;

unordered_map<string,int> wordMap;
void dijkstra(int v,int n) {
    for (int i = 0; i < n; i++){
        for(int j=0; j < 27;j++){
            d[i][j] = LINF;
        }
    }

    d[v][0] = 0;
    priority_queue<tuple<ll, int,char>> pq;
    pq.emplace(0, v,'0');

    while (!pq.empty()) {
        auto [ndist, u,initialChar] = pq.top(); pq.pop();
        int u_estado = (initialChar == '0')? 0 : initialChar - 'a' + 1;

        if(-ndist > d[u][u_estado])
            continue;

        for (auto [idx, w,firstL] : g[u]) {

            int prox_estado = firstL - 'a' + 1;            

            if(initialChar == '0' || firstL != initialChar){
                if (d[idx][prox_estado] > d[u][u_estado] + w) {
                    d[idx][prox_estado] = d[u][u_estado] + w;
                    pq.emplace(-d[idx][prox_estado], idx,firstL);
                }
            }
        }
    }
}

int main() {
    _;

    int id=0;
    int origem,destino;

    while(cin >> M && M !=0){
      string idioma1,idioma2,p;

      cin >> idioma1;
      cin >> idioma2;

      wordMap[idioma1] = id;
      origem = id;
      id++;

      wordMap[idioma2] = id;
      destino = id;
      id++;

      for(int i=0; i < M;i++){
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

        g[wordMap[idioma1]].push_back({wordMap[idioma2],p.size(),p[0]});
        g[wordMap[idioma2]].push_back({wordMap[idioma1],p.size(),p[0]});
      }

      // for(auto const& [k,v] : map){
      //   cout << k <<" = " << v << endl;
      // }
      // for (int i = 0; i <= N; i++) {
      //   for (auto [v, w] : g[i]) {
      //     cout << i << " -> " << v << " (weight " << w << ")\n";
      //   }
      // }
      dijkstra(origem,id);

      // for(int i=0; i < N;i++){
      //   cout << i << " = "<< d[i] << endl;
      // }
      //
      ll val = LINF;
      for(int i=0; i < 27;i++){
          if(d[destino][i] < val){
              val = d[destino][i];
          }
      }

      if(val == LINF){
          cout << "impossivel" << endl;
      }
      else{
          cout << val << endl;
      }
      wordMap.clear();
      id = 0;
      
      for (int i = 0; i < MAX; i++) {
          g[i].clear();
      }
    }
    

    return 0;
}
