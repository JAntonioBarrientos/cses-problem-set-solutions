#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void gen_permutations(vector<bool> choosen, int n, const vector<char> &alp, vector<char> &word){
    if(word.size() == n){
        string w(word.begin(), word.end());
        cout << w << "\n";
        return;
    }
    for(int i = 0; i< alp.size(); i++){
        if(choosen[i] == true)
            continue;
        choosen[i] = true;
        word.push_back(alp[i]);
        gen_permutations(choosen, n, alp, word); 
        word.pop_back();
        choosen[i] = false;
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    string s;
    cin >> s;

    vector<char> alp(s.begin(), s.end());
    sort(alp.begin(), alp.end());
    vector<bool> choosen(s.size(), false);
    vector<char> word;
    gen_permutations(choosen, s.size(), alp, word);
    return 0;
}
