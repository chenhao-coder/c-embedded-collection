#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// 归并排序，填函数练习风格
// 测试链接 : https://leetcode.cn/problems/sort-an-array/
class Solution {
public:
    static const int MAXN = 50001;
    int help[MAXN];

    vector<int> sortArray(vector<int>& nums) {
        if(nums.size() > 1) {
            // MergeSort1(nums);

            MergeSort2(nums);
        }

        return nums;
    }

    void MergeSort1(vector<int>& arr) {
            sort(arr, 0, arr.size() - 1);
        }

    void sort(vector<int>& arr, int l, int r) {
        if(l == r) {
            return;
        }
        int m = l + ((r - l) >> 1);
        sort(arr, l, m);
        sort(arr, m + 1, r);
        merge(arr, l, m, r);
    }

    void MergeSort2(vector<int>& arr) {
        int n = arr.size();

        for(int step = 1; step < n; step <<= 1) {
            int l = 0;
            while(l < n) {
                int m = l + step - 1;
                if(m + 1 >= n) break;
                int r = min(l + (step << 1) - 1, n - 1);
                merge(arr, l, m, r);
                l = r + 1;
            }
        }
    }

    void merge(vector<int>& arr, int l, int m, int r) {
        int a = l;
        int b = m + 1;
        int i = l;
        while(a <= m && b <= r) {
            help[i++] = arr[a] <= arr[b] ? arr[a++] : arr[b++];
        }
        while(a <= m) {
            help[i++] = arr[a++];
        }
        while(b <= r) {
            help[i++] = arr[b++];
        }

        for(i = l; i <= r; i++) {
            arr[i] = help[i];
        }
    }
};