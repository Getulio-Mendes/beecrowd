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

    int N;
    string line;

    cin >> N;
    vector<vector<int>> cubo(N, vector<int>(N));
    vector<int> freq(N*N, 0);


    for(int i=0; i < N;i++){
        for(int j=0; j < N;j++){
            cin >> cubo[i][j];
            
            if (cubo[i][j] < 1 || cubo[i][j] > N*N) {
                cout << 0 << endl;
                return 0;
            }
            freq[cubo[i][j]]++;
        }
        
    }


    for(int i=1; i < N*N;i++){
        if(freq[i] != 1){
            cout << 0 << endl;
            return 0;
        }
    }
       
    int sum =0;
    int sum2 =0;

    // diagonal
    for(int i=0; i < N;i++){
        sum += cubo[i][i];
    }
    
    // diagonal neg
    for(int i=N-1; i >= 0;i--){
        sum2 += cubo[i][(N-1) - i];
    }

    if(sum != sum2){
        cout << 0 << endl;
        return 0;
    }

    sum2 = 0;
    for(int i=0; i < N;i++){

        // linhas
        for(int j=0; j < N;j++){
            sum2 += cubo[i][j];
        }
        if(sum2 != sum){
            cout << 0 << endl;
            return 0;
        }
        sum2 = 0;

        //colunas
        for(int j=0; j < N;j++){
            sum2 += cubo[j][i];
        }

        if(sum2 != sum){
            cout << 0 << endl;

            return 0;
        }
        sum2 = 0;

    }

    cout << sum << endl;

    
    return 0;
}
