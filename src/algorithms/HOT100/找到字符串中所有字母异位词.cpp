#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int slength = s.size(), plength = p.size();

        vector<int> ans;
        vector<int> sCount(26);
        vector<int> pCount(26);

        if(slength < plength) {
            return vector<int>();
        }

        for(int i = 0; i < plength; ++i) {
            ++sCount[s[i] - 'a'];
            ++pCount[p[i] - 'a'];
        }

        if(sCount == pCount) {
            ans.emplace_back(0);
        }

        for(int i = 0; i < slength - plength; ++i) {
            --sCount[s[i] - 'a'];
            ++sCount[s[i + plength] - 'a'];

            if(sCount == pCount) {
                ans.emplace_back(i + 1);
            }
        }
        return ans;
    }
};