#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

// 展示acm风格的测试方式
// 子矩阵的最大累加和问题，不要求会解题思路，后面的课会讲
// 每一组测试都给定数据规模
// 需要任何空间都动态生成，在大厂笔试或者比赛中，这种方式并不推荐
// 测试链接 : https://www.nowcoder.com/practice/cb82a97dcd0d48a7b1f4ee917e2c0409?
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下的code，提交时请把类名改成"Main"，可以直接通过

// 求子数组的最大累加和（Kadane算法）
int maxSumSubarray(vector<int>& arr, int m) {
    int mx = INT_MIN;
    int cur = 0;
    for (int i = 0; i < m; i++) {
        cur += arr[i];
        mx = max(mx, cur);
        if (cur < 0) cur = 0;
    }
    return mx;
}

// 求子矩阵的最大累加和
int maxSumSubmatrix(vector<vector<int>>& mat, int n, int m) {
    int mx = INT_MIN;
    for (int i = 0; i < n; i++) {
        vector<int> arr(m, 0);  // 辅助数组
        for (int j = i; j < n; j++) {
            for (int k = 0; k < m; k++) {
                arr[k] += mat[j][k];
            }
            mx = max(mx, maxSumSubarray(arr, m));
        }
    }
    return mx;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b;
    while (cin >> a >> b) { // 注意 while 处理多个 case
        vector<vector<int>> mat(a, vector<int>(b));
        for (int i = 0; i < a; i++) {
            for (int j = 0; j < b; j++) {
                cin >> mat[i][j];
            }
        }
        cout << maxSumSubmatrix(mat, a, b) << "\n";
    }

    return 0;
}
// 64 位输出请用 printf("%lld")