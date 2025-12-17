#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

class Validator{
public:
    static void main() {
        srand(time(0));

        int N = 100;
        int V = 3000;
        int testtimes = 5000;

        cout << "测试开始!" << endl;

        for(int i = 0; i < testtimes; i++) {
            int n = rand() % N;

            vector<int> arr = randomArray(n, V);
            vector<int> arr1 = copyArray(arr);
            vector<int> arr2 = copyArray(arr);
            vector<int> arr3 = copyArray(arr);

            selectionSort(arr1);
            bubbleSort(arr2);
            insertionSort(arr3);

            if(!sameArray(arr1, arr2) || !sameArray(arr1, arr3)) {
                cout << "出错了" << endl;
                for(int i = 0; i < arr1.size(); i++) {
                    cout << arr1[i] << " ";
                }
                cout << endl;

                for(int i = 0; i < arr2.size(); i++) {
                    cout << arr2[i] << " ";
                }
                cout << endl;

                for(int i = 0; i < arr3.size(); i++) {
                    cout << arr3[i] << " ";
                }
                cout << endl;
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

    static vector<int> copyArray(const vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n);

        for(int i = 0; i < n; i++) {
            ans[i] = arr[i];
        }

        return ans;
    }

    static bool sameArray(const vector<int>& arr1, const vector<int>& arr2) {
        int n = arr1.size();

        for(int i = 0; i < n; i++) {
            if(arr1[i] != arr2[i]) {
                return false;
            }
        }

        return true;
    }

    static void swap(vector<int>& arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    static void selectionSort(vector<int>& arr) {
        if(arr.size() < 2) {
            return;
        }

        for(int i = 0; i < arr.size() - 1; i ++) {
            int minindex = i;

            for(int j = i + 1; j < arr.size(); ++j) {
                if(arr[minindex] > arr[j]) {
                    minindex = j;
                }
            }

            swap(arr, i, minindex);
        }
    }

    static void bubbleSort(vector<int>& arr) {
        if(arr.size() < 2) {
            return;
        }

        for(int end = arr.size() - 1; end > 0; end--) {
            for(int i = 0; i < end; i ++) {
                if(arr[i] > arr[i + 1]) {
                    swap(arr, i, i + 1);
                }
            }
        }
    }

    static void insertionSort(vector<int>& arr) {
        if(arr.size() < 2) {
            return;
        }

        for(int end = 1; end < arr.size(); ++end) {
            for(int i = end - 1; i >= 0 && arr[i] > arr[i + 1]; --i) {
                swap(arr, i, i + 1);
            }
        }
    }

};

int main() {
    cout << "Hello Word!" << endl;

    Validator::main();
    return 0;
}
