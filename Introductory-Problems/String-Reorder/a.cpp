#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    int freq[26] = {0};
    for(char c: s){
        freq[c-'A']++;
        if(freq[c-'A'] > (n+1)/2){
            cout << -1 << endl;
            return 0;
        }
    }
    string ans = "";
    int l = n;
    while(l > 0){
        int critical = -1;
        int min_alp = -1;
        for(int i = 0; i < 26; i++){
            if(min_alp == -1 and freq[i] > 0 and (i+'A') != ans[ans.size()-1]){
                min_alp = i;
            }
            if( 2*freq[i] -1== l){
                critical = i;
                break;
            }
        }
        if(critical != -1){
            ans += ('A' +critical);
            freq[critical]--;
        }
        else{
            ans += ('A' + min_alp);
            freq[min_alp]--;
        }
        l--;
    }

    cout << ans << endl;
    return 0;
}
