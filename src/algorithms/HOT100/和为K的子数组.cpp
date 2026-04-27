#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        const int n = nums.size();
        int count = 0;
        int arr[n];
        for(int i = 0; i < n; ++i) {
            arr[i] = nums[i];
        }

        for(int start = 0; start < nums.size(); ++start) {
            int ans = 0;
            for(int end = start; end >= 0; --end) {
                ans += arr[end];
                if(ans == k) {
                    count++;
                }
            }
        }

        return count;
    }

    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int pre = 0, count = 0;
        for(auto& x: nums) {
            pre += x;
            if(mp.find(pre - k) != mp.end()) {
                count += mp[pre - k];
            }
            mp[pre]++;
        }
        return count;
    }
};