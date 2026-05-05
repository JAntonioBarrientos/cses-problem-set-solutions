#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n, k;
vector<int> nums;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    nums.resize(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    map<int, int> m;
    for(int i = 0; i < k; i++){
        m[nums[i]]++;
    }
    cout << m.size() << " ";
    for(int i = k; i < n; i++){
        m[nums[i]]++;
        m[nums[i-k]]--;
        if(m[nums[i-k]] == 0)
            m.erase(nums[i-k]);
        cout << m.size() << " ";
    }
    cout << "\n";
    return 0;
}
