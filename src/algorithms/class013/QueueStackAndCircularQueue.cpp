#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

class QueueStackAndCircularQueue {
public:
    
    class Queue1 {
    public:
        queue<int> q;

        bool isEmpty() {
            return q.empty();
        }

        void offer(int num) {
            q.push(num);
        }
        int poll() {
            int ans = q.front();
            q.pop();
            return ans;
        }

        int peek() {
            return q.front();
        }
        
        int size() {
            return q.size();
        }
    };

    class Queue2 {
    public:
        vector<int> q;
        int l, r;

        Queue2(int n) : q(n), l(0), r(0) {}

        bool isEmpty() {
            return l == r;
        }

        void offer(int num) {
            q[r++] = num;
        }

        int poll() {
            return q[l++];
        }

        int head() {
            return q[l];
        }

        int tail() {
            return q[r - 1];
        }

        int size() {
            return r - l;
        }
    };

    class Stack1 {
    public:
        stack<int> st;

        bool isEmpty() {
            return st.empty();
        }

        void push(int num) {
            st.push(num);
        }

        int pop() {
            int ans = st.top();
            st.pop();
            return ans;
        }

        int peek() {
            return st.top();
        }

        int size() {
            return st.size();
        }
    };

    class Stack2 {
    public:
        vector<int> st;
        int sz;

        Stack2(int n) : st(n), sz(0) {}

        bool isEmpty() {
            return sz == 0;
        }

        void push(int num) {
            st[sz++] = num;
        }

        int pop() {
            return st[--sz];
        }

        int peek() {
            return st[sz - 1];
        }

        int size() {
            return sz;
        }
    };

    // 设计循环队列
	// 测试链接 : https://leetcode.cn/problems/design-circular-queue/
    class MyCircularQueue {
    public:
        vector<int> q;
        int l, r, size, limit;
        MyCircularQueue(int k) : 
            q(k), l(0), r(0), size(0), limit(k) {}
        
        bool enQueue(int value) {
            if(isFull()) {
                return false;
            }

            q[r] = value;
            r = (r == limit - 1) ? 0 : (r + 1);
            size++;
            return true;
        }
        
        bool deQueue() {
            if(isEmpty()) {
                return false;
            }
            l = (l == limit - 1) ? 0 : (l + 1);
            size--;
            return true;
        }
        
        int Front() {
            return isEmpty() ? -1 : q[l];
        }
        
        int Rear() {
            if(isEmpty()) return -1;
            int last = (r == 0) ? (limit - 1) : (r - 1);
            return q[last];
        }
        
        bool isEmpty() {
            return size == 0;
        }
        
        bool isFull() {
            return size == limit;
        }
    };
};
