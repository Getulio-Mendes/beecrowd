
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

    
    string nome;
    int diaAtual, mesAtual, anoAtual;
    int diaNascimento, mesNascimento, anoNascimento;

    getline(cin, nome);

    cin >> diaAtual;
    cin.ignore(); 
    cin >> mesAtual;
    cin.ignore(); 
    cin >> anoAtual;

    cin >> diaNascimento;
    cin.ignore(); 
    cin >> mesNascimento;
    cin.ignore(); 
    cin >> anoNascimento;

    int idade = anoAtual - anoNascimento;
    if (mesAtual < mesNascimento || (mesAtual == mesNascimento && diaAtual < diaNascimento)) {
        idade--;
    }
    
    if (diaAtual == diaNascimento && mesAtual == mesNascimento) {
        cout << "Feliz aniversario!" << endl;
    }
    
    cout << "Voce tem " << idade << " anos " << nome << "." << endl;
    
    return 0;
}
