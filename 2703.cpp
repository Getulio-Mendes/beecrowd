#include <bits/stdc++.h>

#include <unordered_map>

using namespace std;

#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define endl '\n'

#define dbg(x) cout << #x << " = " << x << endl

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

struct hash_pair {
    size_t operator()(const pair<int, int>& p) const {
        return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
    }
};
vector<tuple<int, int, int>> edges;
unordered_map<pair<int, int>, int, hash_pair> tree;
vector<int> parent;

int find(int x) {
    if (parent[x] != x) parent[x] = find(parent[x]);

    return parent[x];
}

bool unite(int x, int y) {
    x = find(x);
    y = find(y);

    if (x == y) return false;

    parent[y] = x;

    return true;
}

bool isciclo(int u,int v){
    if(find(u) == find(v)){
        return true;
    }
    else{
        return false;
    }
}

int main() {
    _;

    int n, r;

    cin >> n >> r;
    int q;
    for (int i = 0; i < r; i++) {
        int x, y, w;
        cin >> x >> y >> w;

        edges.push_back({w, x - 1, y - 1});
    }

    cin >> q;

    sort(edges.begin(), edges.end());
    parent.resize(n);
    iota(parent.begin(), parent.end(), 0);

    int Omst = 0;

    for (auto [w, u, v] : edges) {
        if (unite(u, v)) {
            Omst += w;
            tree[{u, v}] = w;
        }
    }

    cout << "tree " << endl;
    for (auto const& [p, v] : tree)
    {
        cout << p.first << " " << p.second << endl;
    }

    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;

        if (tree.find({x, y}) != tree.end()) {
            // cout << "Tree" << x << " "<< y << " " << tree[{x,y}] << endl;
            cout << Omst << endl;
        } else {

            pair<int,int> add = {x,y};
            for(auto const &[w,u,v] : edges){
                if(u == x && v == y){
                    tree[add] = w;
                }
            }
            dbg(Omst);
            int mst = Omst + tree[add];

            int cost = 0;
            pair<int,int> rev;
            for(auto const & [p,v] : tree){
                if(isciclo(p.first,p.second) && p != add){
                    if(v > cost){
                        cost = v;
                        rev = p;
                    }
                }
            }

            dbg(mst);

            
            cout << "tree " << endl;
            for (auto const& [p, v] : tree)
            {
                cout << p.first+1 << " " << p.second+1 << endl;
            }


            cout << "Rev: ";
            cout << rev.first+1 << " " << rev.second+1 << endl;
            
            for(auto const & [p,v] : tree){
                if(p == rev){
                    mst = mst - v;
                }
            }

            dbg(mst);

            cout << mst << endl;
        }
    }

    return 0;
}
