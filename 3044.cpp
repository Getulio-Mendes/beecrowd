
#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'

vector<pair<int, int>> edges;
vector<int> parent;

int find(int x)
{
    if (parent[x] != x) parent[x] = find(parent[x]);
    return parent[x];
}

int main() {
    _;

    int N, M;
    int count = 1;
    
    while(cin >> N >> M && (N != 0 || M != 0)){
        edges.clear();
        
        for(int i = 0; i < M; i++){
            int x, y;
            cin >> x >> y;
            edges.push_back({x - 1, y - 1});
        }

        cout << "Teste " << count << endl;
        
        bool flag = false;
        parent.resize(N);
        
        for(int i = 0; i < N; i++){
            iota(parent.begin(), parent.end(), 0);
            
            int componentes = N - 1;
            
            for (auto [u, v] : edges) {
                if (u == i || v == i) continue;
                
                int root_u = find(u);
                int root_v = find(v);
                
                if (root_u != root_v) {
                    parent[root_v] = root_u;
                    componentes--;
                }
            }

            if(componentes > 1){
                cout << i + 1 << " ";
                flag = true;
            }
        }

        if(!flag){
            cout << "nenhum";
        }
        
        cout << endl <<endl;
        count++;
    }
    
    return 0;
}
