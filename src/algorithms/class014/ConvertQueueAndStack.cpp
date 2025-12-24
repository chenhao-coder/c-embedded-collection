#include <iostream>
#include <queue>
#include <stack>

using namespace std;

// 用栈实现队列
// 用队列实现栈
class ConvertQueueAndStack {
public:
    // 测试链接 : https://leetcode.cn/problems/implement-queue-using-stacks/
    class MyQueue {
    public:
        stack<int> in;
        stack<int> out;

        MyQueue() {}

        void inToOut() {
            if(out.empty()) {
                while(!in.empty()) {
                    out.push(in.top());
                    in.pop();
                }
            }
        }

        void push(int x) {
            in.push(x);
            inToOut();
        }

        int pop() {
            inToOut();
            int ans = out.top();
            out.pop();

            return ans;
        }

        int peek() {
            inToOut();
            return out.top();
        }

        bool empty() {
            return in.empty() && out.empty();
        }

    };

    // 测试链接 : https://leetcode.cn/problems/implement-stack-using-queues/
    class MyStack {
    public:
        queue<int> q;

        MyStack() {}

        void push(int x) {
            int n = q.size();
            q.push(x);
            for(int i = 0; i < n; i++) {
                q.push(q.front());
                q.pop();
            }
        }

        int pop() {
            int ans = q.front();
            q.pop();
            return ans;
        }

        int top() {
            return q.front();
        }

        bool empty() {
            return q.empty();
        }
    };
};