#include<iostream>
#include<unordered_set>
#include<algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> occ;
        int n = s.size();
        int rhk = -1, ans = 0;
        for(int i = 0; i < n; ++i) {
            if(i != 0) {
                occ.erase(s[i - 1]);
            }
            while(rhk + 1 < n && !occ.count(s[rhk + 1])) {
                occ.insert(s[rhk + 1]);
                ++rhk;
            }
            ans = max(ans, rhk + 1 - i);
        }
        return ans;
    }
};

