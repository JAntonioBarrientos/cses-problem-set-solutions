#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void gray_code(int id,int len,vector<char> &code){
    if(id == len){
        string s(code.begin(), code.end());
        cout << s << "\n";
        return;
    }
    for(int i = 0; i < 2; i++){
        code[id] = char(i+'0');
        gray_code(id+1, len, code);
    }

}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<char> code(n);
    gray_code(0, n, code);  
    return 0;
}
