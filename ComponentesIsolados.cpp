
#include <bits/stdc++.h>
using namespace std;


#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'


const int MAX = 100005;  // Defina o limite máximo de vértices do problema
int pai[MAX];
int sz[MAX];  // Guarda o tamanho de cada conjunto

// reseta o DSU entre casos de teste
void init(int n) {
  for (int i = 0; i <= n; i++) {
    pai[i] = i;
    sz[i] = 1;  // Inicialmente, todo conjunto tem tamanho 1
  }
}

// Find com Path Compression (Compressão de Caminho)
int find(int x) {
  if (pai[x] == x) return x;
  return pai[x] = find(pai[x]);  // Achata a árvore
}

// Unite com Union by Size
bool unite(int x, int y) {
  x = find(x);
  y = find(y);

  if (x == y) return false;  // Já estão conectados (CICLO!)

  //Garante que 'x' sempre seja a maior árvore
  if (sz[x] < sz[y]) swap(x, y);

  pai[y] = x;      // Pendura a menor na maior
  sz[x] += sz[y];  // Atualiza o tamanho da nova raiz

  return true;
}

int main() {
    _;
    int n, m;
    cin >> n >> m;
    
    init(n); 
    
    int componentes = n; // 1. Começamos com N componentes isolados
    
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        
        // 2. Se a união juntou dois grupos diferentes, subtraímos 1
        if (unite(u, v)) {
            componentes--; 
        }
    }
    
    cout << "O grafo possui " << componentes << " componentes conexos.\n";
    
    return 0;
}
