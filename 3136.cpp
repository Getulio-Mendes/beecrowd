
#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'

#define dbg(x) cout << #x << " = " << x << endl

typedef long long ll;

const int INF = 0x3f3f3f3f;

const ll LINF = 0x3f3f3f3f3f3f3f3fll;

stack<int> st;
vector<int> ram(100);

int getVal(string s, bool reg){
  auto pos = s.find("_");
  auto ramI= s.find("R");
  if(ramI != string::npos){
    int x = stoi(s.substr(ramI+1));
    // dbg(ram[x]);
    if(reg){
      return x;
    }else{
      return ram[x];
    }
  }else{
    return stoi(s.substr(pos+1));
  }
  
}

int main() {
    // _;

    int N;

    cin >> N;

    string line;
    for(int i=0; i < N;i++){
      cin >> line;
      // dbg(line);

      if(line.find("print") != string::npos){

        cout << st.top() << endl;
        st.pop();
      }

      if(line.find("push") != string::npos){
        st.push(getVal(line,false));
      }
      if(line.find("pop") != string::npos){
        
        int x = st.top();
        ram[getVal(line,true)] = x;
        st.pop();
      }
      if(line.find("add") != string::npos){
        int x1=  st.top();
        st.pop();
        int x2=  st.top();
        st.pop();
        st.push(x1+x2);
      }
      if(line.find("mul") != string::npos){
        
        int x1=  st.top();
        st.pop();
        int x2=  st.top();
        st.pop();
        st.push(x1*x2);
      }
      if(line.find("div") != string::npos){
        
        int x1=  st.top();
        st.pop();
        int x2=  st.top();
        st.pop();
        st.push(x2/x1);
      }
      if(line.find("sub") != string::npos){
        
        int x1=  st.top();
        st.pop();
        int x2=  st.top();
        st.pop();
        st.push(x2-x1);
      }
    }
    
    return 0;
}
