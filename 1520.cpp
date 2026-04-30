
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

    vector<int> v;
    int N;

    while(cin>> N){
      int x,y,num;
      v.clear();

      for(int i=0; i < N;i++){
        cin >> x;
        cin >> y;

        for(int j=x;j <= y;j++){
          v.push_back(j);
        }
      }

      cin >> num;
      sort(v.begin(),v.end());

      bool found = false;
      int l = 0;
      int r = v.size()-1;
      int foundX,foundY,mid;
      while(l<=r){
        mid = l + (r-l) /2;
        if(v[mid] == num){
          found = true;
          break;
        }
        else if(v[mid] > num){
          r = mid - 1;
        }
        else if(v[mid] < num){
          l = mid + 1;
        }
      }

      foundX = mid;
      while(foundX-1 >=0 && v[foundX-1] == num){
        foundX--;
      }

      foundY = foundX;
      while(foundY+1 < v.size() && v[foundY+1] == num ){
        foundY++;
      }

      if(found){
        cout << num << " found from " << foundX << " to " << foundY << endl;
      }
      else{
        cout << num << " not found" << endl;
      }
      
      
      
    }
    return 0;
}
