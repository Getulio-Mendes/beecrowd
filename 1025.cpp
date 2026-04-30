#include <algorithm>
#include <bits/stdc++.h>
#include <functional>

using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'

#define dbg(x) cout << #x << " = " << x << endl

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main() {

   int N,Q; 


   vector<int> v;
   int x;
   int c = 1;

   while(cin >> N && cin >> Q && Q != 0 && N != 0){
     cout << "CASE# " << c << ":" << endl;
     for(int i=0; i < N;i++){
       cin >> x;
       v.push_back(x);
     }

     sort(v.begin(),v.end());

     for(int i=0; i < Q;i++){
       cin >> x;

       bool found = false;
       for(int j=0; j < v.size();j++){
         if(v[j]==x){
           cout << x << " found at " << j+1 << endl;
           found = true;
           break;
         }
       }

      if(!found){
        cout << x << " not found" << endl;
      }
     }
     c++;
     v.clear();
   }
    
    return 0;
}
