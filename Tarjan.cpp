
#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
const int MAX = 100005;

vector<int> g[MAX];
stack<int> s;
int vis[MAX], comp[MAX];
int id[MAX];

// Função DFS do Tarjan
int dfs(int i, int &t) {
    int lo = id[i] = t++;
    s.push(i);
    vis[i] = 2; // 2 significa que está na pilha atual (visitando)
    
    for (int j : g[i]) {
        if (!vis[j]) {
            lo = min(lo, dfs(j, t));
        } else if (vis[j] == 2) {
            lo = min(lo, id[j]);
        }
    }
    
    // Se 'lo' for igual ao 'id', encontramos a raiz de um componente
    if (lo == id[i]) {
        while (1) {
            int u = s.top(); 
            s.pop();
            vis[u] = 1; // 1 significa totalmente processado
            comp[u] = i; // Define a qual componente 'u' pertence
            if (u == i) break;
        }
    }
    
    return lo;
}

void tarjan(int n) {
    int t = 0;
    for (int i = 0; i < n; i++) vis[i] = 0;
    for (int i = 0; i < n; i++) {
        if (!vis[i]) dfs(i, t);
    }
}

int main() {
    _;

    int n, m;
    // Lê número de vértices e arestas
    if (cin >> n >> m) {
        
        // Limpa o grafo caso haja múltiplos casos de teste
        for(int i = 0; i < n; i++) {
            g[i].clear();
        }
        
        // Lê as arestas (direcionadas)
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--; v--; // Convertendo para 0-indexado
            
            g[u].push_back(v);
        }

        tarjan(n);

        
        // O vetor 'comp' já diz quem está com quem.
        for (int i = 0; i < n; i++) {
            cout << "Vertice " << i + 1 << " esta no componente do lider " << comp[i] + 1 << "\n";
        }
    }

    return 0;
}
