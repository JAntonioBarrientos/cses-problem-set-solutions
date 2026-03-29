#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    int n, x;
    cin >> n >> x;
    vector<pair<int,int>> nums;
    int a;
    for (int i = 0; i < n; i++) {
        cin >> a;
        nums.emplace_back(a, i);
    }
    if (n < 4)
    {
      cout << "IMPOSSIBLE\n";
      return 0;
    }
    int p1, p2, p3, p4;
    ll sum;
    p1 = 0;
    p2 = 1;
    p3 = n-2;
    p4 = n-1;
    sort(nums.begin(), nums.end());

    while(p1 < p2 and p2 < p3 and p3 < p4){
        sum = nums[p1].first;
        sum += nums[p2].first;
        sum += nums[p3].first;
        sum += nums[p4].first;

        if (sum > x)
        {
          p3--;
        }
        else if (sum < x)
        {
          p2++;
        }
        else{
          // ganamos
          cout << nums[p1].second+1 << " ";
          cout << nums[p2].second+1 << " ";
          cout << nums[p3].second+1 << " ";
          cout << nums[p4].second+1 << " ";
          cout << "\n";
          return 0;
        }
        if(sum > x and p3 == p2){
          p4--;
          p2 = p1+1;
          p3 = p4-1;
        }
        else if(sum < x and p3 == p2){
          p1++;
          p2 = p1+1;
          p3 = p4-1;
        }
    }

    cout << "IMPOSSIBLE" << endl;
    return 0;
}
