#include <iostream>
#include <stack>

using namespace std;

// 最小栈
// 测试链接 : https://leetcode.cn/problems/min-stack/
class GetMinStack {
public:
    class MinStack1 {
    public:
        stack<int> data;
        stack<int> min;

        MinStack1() {}

        void push(int val) {
            data.push(val);
            if(min.empty() || val <= min.top()) {
                min.push(val);
            } else {
                min.push(min.top());
            }
        }

        void pop() {
            data.pop();
            min.pop();
        }

        int top() {
            return data.top();
        }

        int getMin() {
            return min.top();
        }
    };

    class MinStack2 {
    public:
        int data[8001];
        int min[8001];
        int size;

        MinStack2() : size(0) {}

        void push(int val) {
            data[size] = val;
            if(size == 0 || val <= min[size - 1]) {
                min[size] = val;
            } else {
                min[size] = min[size - 1];
            }
            size++;
        }

        void pop() {
            size--;
        }

        int top() {
            return data[size - 1];
        }

        int getMin() {
            return min[size - 1];
        }
    };
};