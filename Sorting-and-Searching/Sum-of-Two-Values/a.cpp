#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int search(int i, int j, int x, const vector<pair<int,int>> &nums){
    if(i > j){
        return -1;
    }
    int m = (i+j)/2;
    if(nums[m].first == x){
        return nums[m].second;
    }
    if(x < nums[m].first){
       return search(i, m-1, x, nums);
    }
    else{
       return search(m+1, j, x, nums);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, sum;
    cin >> n >> sum;
    vector<pair<int, int>> nums;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        nums.emplace_back(x, i);
    }

    sort(nums.begin(), nums.end());
    int res;
    int l;
    for(l = 0; l < n-1; l++){
        int x = sum - nums[l].first;
        res = search(l+1, n-1, x, nums);
        if(res != -1)
            break;
    }
    if(res == -1){
        cout << "IMPOSSIBLE";
    }
    else{
        cout << nums[l].second+1 << " " << res + 1 << endl;
    }
    return 0;
}
