#include <iostream>
#include <deque>
#include <vector>

using namespace std;


// 设计循环双端队列
// 测试链接 : https://leetcode.cn/problems/design-circular-deque/
class CircularDeque {
public:
    class MyCircularDeque1 {
    public:
        deque<int> dq;
        int size, limit;

        MyCircularDeque1(int k) : size(0), limit(k) {}

        bool insertFront(int val) {
            if(isFull()) {
                return false;
            }
            dq.push_front(val);
            size++;
            return true;
        }

        bool insertLast(int val) {
            if(isFull()) {
                return false;
            }

            dq.push_back(val);
            size++;
            return true;
        }

        bool deleteFront() {
            if(isEmpty()) {
                return false;
            }

            dq.pop_front();
            size--;
            return true;
        }

        bool deleteLast() {
            if(isEmpty()) {
                return false;
            }

            dq.pop_back();
            size--;
            return true;
        }

        int getFront() {
            return isEmpty() ? -1 : dq.front();
        }

        int getRear() {
            return isEmpty() ? -1 : dq.back();
        }

        bool isEmpty() {
            return size == 0;
        }

        bool isFull() {
            return size == limit;
        }

    };

    class MyCircularDeque2 {
    public:
        vector<int> dq;
        int l, r, size, limit;

        MyCircularDeque2(int k) {
            dq.resize(k);
            l = r = size = 0;
            limit = k;
        }

        bool insertFront(int val) {
            if(isFull()) {
                return false;
            }

            if(size == 0) {
                l = r = 0;
                dq[0] = val;
            } else {
                l = (l == 0 ? limit -1 : l - 1);
                dq[l] = val;
            }
            size++;
            return true;
        }

        bool insertLast(int val) {
            if(isFull()) {
                return false;
            }

            if(size == 0) {
                l = r = 0;
                dq[0] = val;
            } else {
                r = (r == limit - 1 ? 0 : r + 1);
                dq[r] = val;
            }
            size++;
            return true;
        }

        bool deleteFront() {
            if(isEmpty()) {
                return false;
            }

            l = (l == limit - 1 ? 0 : l + 1);
            size--;
            return true;
        }

        bool deleteLast() {
            if(isEmpty()) {
                return false;
            }

            r = (r == 0 ? limit - 1 : r - 1);
            size--;
            return true;
        }

        int getFront() {
            return isEmpty() ? -1 : dq[l];
        }

        int getRear() {
            return isEmpty() ? -1 : dq[r];
        }

        bool isEmpty() {
            return size == 0;
        }

        bool isFull() {
            return size == limit;
        }
    };
};