
#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'

#define dbg(x) cout << #x << " = " << x << endl

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main() {
    //_;

    string cifra;
    string crib;

    cin >> cifra;
    cin >> crib;

    int len = crib.length();

    int count =0;
    for(int i=0; i + len <= cifra.length();i++){
       bool found = false;
       for(int j=i; j < i + len;j++){
         //cout <<  " cifra: " << cifra[j] << " crib: " << crib[j-i];
           if(cifra[j] == crib[j-i]){
             found = true;
           }
       }
       //cout << endl;
       if(!found){
         count++;
       }
    }

    cout << count << endl;
    
    return 0;
}
