#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'

#define dbg(x) cout << #x << " = " << x << endl

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAX = 5e5 + 5;

ll d[MAX][3];
vector<pair<int, ll>> C[MAX]; // {vizinho, peso}
vector<pair<int, ll>> P[MAX]; // {vizinho, peso}
int N;

void dijkstra(int origen,int destino) {
    for (int i = 0; i < N; i++){
      d[i][0] = LINF;
      d[i][1] = LINF;
      d[i][2] = LINF;
    }
    d[origen][0] = 0;
    d[origen][1] = 0;
    d[origen][2] = 0;

    priority_queue<tuple<ll, int,int>> pq;
    pq.emplace(0, origen,0);
    pq.emplace(1, origen,1);
    pq.emplace(2, origen,2);

    while (!pq.empty()) {
        auto [ndist, u,estado] = pq.top(); pq.pop();
        if (-ndist > d[u][estado]) continue;

        // 1. Mudar do estado 0 (A pé inicial) para 1 (Carro) 
        if (estado == 0 && d[u][1] > d[u][0]) {
            d[u][1] = d[u][0];
            pq.emplace(-d[u][1], u, 1);
        }
        // 2. Mudar do estado 1 (Carro) para 2 (A pé final) 
        if (estado == 1 && d[u][2] > d[u][1]) {
            d[u][2] = d[u][1];
            pq.emplace(-d[u][2], u, 2);
        }

        // Se estou a pé (início ou fim), só ando pelas calçadas (P)
        if (estado == 0 || estado == 2) {
            for (auto [idx, w] : P[u]) {
                if (d[idx][estado] > d[u][estado] + w) {
                    d[idx][estado] = d[u][estado] + w;
                    pq.emplace(-d[idx][estado], idx, estado);
                }
            }
        }

        // Se estou de carro, só ando pelas ruas (C)
        if (estado == 1) {
            for (auto [idx, w] : C[u]) {
                if (d[idx][estado] > d[u][estado] + w) {
                    d[idx][estado] = d[u][estado] + w;
                    pq.emplace(-d[idx][estado], idx, 1);
                }
            }
        }
    }
}

int main() {
    _;
    int m,c,p;
    int destino;
    cin >> N >> c >> p;
    destino = N-1;

    for (int i = 0; i < c; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;

        C[u].push_back({v, w});
    }

    for (int i = 0; i < p; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;

        P[u].push_back({v, w});
        P[v].push_back({u, w});
    }


    // for(int u=0; u < N;u++){
        
    //   for (auto [idx, w] : C[u]) {
    //       cout << u+1 << " " << idx+1 << " " << w << endl;
    //   }
    //   cout << endl;
    //   for (auto [idx, w] : P[u]) {
    //       cout << u+1 << " " << idx+1 << " " << w << endl;
    //   }
    // }

    dijkstra(0,destino);
    
    ll menor = LINF;
    for(int i=0;i < 3;i++){
        // dbg(d[destino][i]);
      if(d[destino][i] < menor){
        menor = d[destino][i];
      }
    }

    cout << menor << endl;

    return 0;
}
