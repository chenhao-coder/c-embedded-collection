#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

class Code02_FindLeft {
public:
    static void main() {
        int N = 1000;
        int V = 1000;
        int testtimes = 500000;

        srand(time(0));
        
        cout << "测试开始" << endl;

        for(int i = 0; i < testtimes; i++) {
            int n = rand() % N;
            vector<int>arr = ramdomArray(n, V);
            sort(arr.begin(), arr.end());
            int num = rand() % V;

            if(right(arr, num) != findLeft(arr, num)) {
                cout << "测试出错" << endl;

                for(int i = 0; i < arr.size(); i++) {
                    cout << arr[i] << " ";
                }
                cout << endl;
                cout << num << endl;
                cout << right(arr, num) << " ";
                cout << findLeft(arr, num) << " ";
                cout << endl;
            }
        }

        cout << "测试结束" << endl;
    }

    static vector<int> ramdomArray(int n, int v) {
        vector<int> arr(n);

        for(int i = 0; i < n; i++) {
            arr[i] = rand() % v + 1;
        }

        return arr;
    }

    static int right(const vector<int>& arr, int num) {
        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] >= num) {
                return i;
            }
        }
        return -1;
    }

    static int findLeft(const vector<int>& arr, int num) {
        if(arr.empty()) {
            return -1;
        }

        int l = 0, r = arr.size() - 1, m = 0; 
        int ans = -1;
        
        while(l <= r) {
            m = l + ((r - l) >> 1);

            if(arr[m] >= num) {
                ans = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return ans;
    }
};

int main() {
    Code02_FindLeft::main();

    return 0;
}
