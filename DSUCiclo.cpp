
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

// Exemplo de uso
int main() {
  _;

  
    int n, m;
    cin >> n >> m;

    init(n);  // Reseta o DSU O(N) de forma limpa

    bool tem_ciclo = false;
    // loop entre as arestas
    for (int j = 0; j < m; j++) {
      int u, v;
      cin >> u >> v;
      // Se a aresta fechar um ciclo, a gente marca a flag
      if (!unite(u, v)) {
        tem_ciclo = true;
      }
    }

    if (tem_ciclo)
      cout << "Tem ciclo!\n";
    else
      cout << "Nao tem ciclo.\n";

  return 0;
}
