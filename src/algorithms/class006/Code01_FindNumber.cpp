#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <ctime>

using namespace std;

class Code01_FindNumber {
public:
    static void main() {
        int N = 100;
        int v = 1000;
        int testtimes = 500000;

        cout << "测试开始" << endl;

        for(int i = 0; i < testtimes; i++) {
            int n = rand() % N;
            vector<int> arr = randomArray(n, v);
            sort(arr.begin(), arr.end());
            int num = rand() % v;

            if(right(arr, num) != exit(arr, num)) {
                cout << "测试错误" << endl;
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

    static bool right(const vector<int>& arr, int num) {
        for(int cur : arr) {
            if (cur == num) {
                return true;
            }
        }

        return false;
    }

    static bool exit(const vector<int>& arr, int num) {
        if(arr.empty()) {
            return false;
        }

        int l = 0;
        int r = arr.size() - 1;
        int m = 0;

        while(l <= r) {
            m = l + ((r - l) >> 1);

            if(arr[m] == num) {
                return true;
            } else if(arr[m] > num) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }

        return false;
    }


};

int main() {
    srand(time(0));
    Code01_FindNumber::main();
    
    return 0;
}