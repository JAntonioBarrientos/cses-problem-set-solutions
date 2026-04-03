#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    unordered_map<int,int> nums;
    int n;
    cin >> n;
    int x;
    int max_val = 1;
    for(int i = 0; i < n; i++){
        cin >> x;
        nums[x]++;
        max_val = max(max_val, x);
    }
    int max_com_div = 1;
    int counter;
    for(int i = 2; i <= N; i++){
        int curr_div = i;
        counter = 0;
        while( curr_div <= N){
            if(nums.count(curr_div) > 0){
                counter += nums[curr_div];
                if(counter > 1){
                    max_com_div = max(max_com_div, i); 
                    break;
                }
            }
            curr_div += i;
        }
    }

    cout << max_com_div << endl;

   
    return 0;
}
