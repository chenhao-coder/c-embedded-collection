#include <iostream>
#include <cstdlib>
#include <vector>
#include <chrono>
#include <ctime>

using namespace std;

class Complexity {
public:
    static void bubbleSort(vector<int>& arr) {
        if(arr.size() < 2) {
            return;
        }

        int end = arr.size() - 1, i = 0;
        
        while(end > 0) {
            if(arr[i] > arr[i + 1]) {
                swap(arr, i, i + 1);
            }

            if(i < end - 1) {
                i++;
            } else {
                end--;
                i = 0;
            }
        }
    }

    static void swap(vector<int>& arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp; 
    }

    static void testONLogN(int N) {
        cout << "测试开始" << endl;
        auto start = chrono:: high_resolution_clock::now();

        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= N; j += i) {
                // cout << "i = " << i << " j = " << j << endl;
            }
        }

        auto end = chrono:: high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
        cout << "测试结束，运行时间: " << duration.count() << "毫秒" << endl;
    }

    static void testON2(int N) {
        cout << "测试开始" << endl;
        auto start = chrono:: high_resolution_clock::now();

        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= N; j++) {
                // cout << "i = " << i << " j = " << j << endl;
            }
        }

        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
        cout << "测试结束，运行时间: " << duration.count() << "毫秒" << endl;
    }
    static void printArray(const vector<int>& arr) {
        for(int num : arr) {
            cout << num << " ";
        }
        cout << endl;
    }
};

int main() {
    vector<int> arr = {64, 31, 78, 0, 5, 7, 103};
    Complexity::bubbleSort(arr);
    Complexity::printArray(arr);
    cout << "============" << endl;

    int N = 200;
    Complexity::testONLogN(N);
    Complexity::testON2(N);

    return 0;
}