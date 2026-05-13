
#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'

#define dbg(x) cout << #x << " = " << x << endl

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main() {
    _;

    vector<int> posX(100005,0);
    vector<int> posY(100005,0);

    int x = 0;
    int y = 0;
    int n = 1;
    int layer = 0;

    while (n <= 100000) {
        layer++;
        y++;
        n++;
        if (n > 100000) break;
        posX[n] = x;
        posY[n] = y;

        for (int i = 0; i < layer - 1 && n <= 100000; i++) {
            x--; y++; n++;
            posX[n] = x;
             posY[n] = y;
        }
        for (int i = 0; i < layer && n <= 100000; i++) {
            x--; n++;
            posX[n] = x;
             posY[n] = y;
        }
        for (int i = 0; i < layer && n <= 100000; i++) {
            y--; n++;
            posX[n] = x;
             posY[n] = y;
        }
        for (int i = 0; i < layer && n <= 100000; i++) {
            x++; y--; n++;
            posX[n] = x;
             posY[n] = y;
        }
        for (int i = 0; i < layer && n <= 100000; i++) {
            x++; n++;
            posX[n] = x;
             posY[n] = y;
        }
        for (int i = 0; i < layer && n <= 100000; i++) {
            y++; n++;
            posX[n] = x;
             posY[n] = y;
        }
    }

    int query;
    while (cin >> query) {
        cout << posX[query] << " " << posY[query] << "\n";
    }

    return 0;
}
