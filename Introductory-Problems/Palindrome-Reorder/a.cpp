#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    unordered_map<char, int> freq;
    for(int i = 0; i < s.size(); i++){
        freq[s[i]]++;
    }
    int odd_count = 0;
    char odd_char = '.';
    for(auto &[key, value]: freq){
        if(value % 2 == 1){
            odd_count++;
            odd_char = key;
        }
    }
    if(odd_count >= 2){
        cout << "NO SOLUTION" << "\n";
        return 0;
    }
    string ans = "";
    for(auto &[key, value]: freq){
        ans.append(int(value/2), key);
    }
    string rev = ans;
    reverse(rev.begin(), rev.end());
    if(odd_count == 1)
        ans += odd_char;
    ans += rev;
    cout << ans << endl;
    return 0;
}
