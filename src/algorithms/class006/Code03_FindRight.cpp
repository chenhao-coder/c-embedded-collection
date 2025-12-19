#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

class Code02_FindRight {
public:
    static void main() {
        int N = 1000;
        int V = 1000;
        int testtimes = 500000;

        srand(time(0));

        cout << "测试开始" << endl;

        for(int i = 0; i < testtimes; i++) {
            int n = rand() % N;
            vector<int> arr = randomArray(n, V);
            sort(arr.begin(), arr.end());
            int num = rand() % V;
            if(right(arr, num) != FindRight(arr, num)) {
                cout << "测试出错" << endl;
            }
        }

        cout << "测试结束" << endl;
    }

    static vector<int> randomArray(int n, int v) {
        vector<int> arr(n);

        for(int i = 0; i < n; i++) {
            arr[i] = rand() % v + 1;
        }

        return arr;
    }

    static int right(const vector<int>& arr, int num) {
        for(int i = arr.size() - 1; i >= 0; i--) {
            if(arr[i] <= num) {
                return i;
            }
        }

        return -1;
    }

    static int FindRight(const vector<int>& arr, int num) {
        if(arr.empty()) {
            return -1;
        }

        int l = 0, r = arr.size() - 1, ans = -1;

        while(l <= r) {
            int m = l + ((r - l) >> 1);
            if(arr[m] <= num) {
                ans = m;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

        return ans;
    }
};

int main() {
    Code02_FindRight::main();
    return 0;
}