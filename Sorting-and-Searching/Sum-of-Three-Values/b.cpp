#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
pair<int, int> sum_of_two(const vector<pair<int,int>> &nums, int target, int l){
    int n = nums.size();
    int i = l;
    int j = n-1;
    while(i < j){
        int sum = nums[i].first + nums[j].first;
        if(sum == target){
            return {i, j};
        }
        if(sum < target){
            i++;
        }
        else{
            j--;
        }
    }
    return {-1, -1};
}
 
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, target;
    cin >> n >> target;
    vector<pair<int,int>> nums;
    int x;
    for(int i = 1; i <= n; i++){
        cin >> x;
        nums.emplace_back(x, i);
    }
    sort(nums.begin(), nums.end());
 
    for(int i = 0; i <n; i++){
        int x = target- nums[i].first;
        auto [j, k] = sum_of_two(nums, x, i+1);
        if( j != -1){
            cout << nums[i].second << " ";
            cout << nums[j].second << " ";
            cout << nums[k].second << endl;
            return 0;
        }
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}
