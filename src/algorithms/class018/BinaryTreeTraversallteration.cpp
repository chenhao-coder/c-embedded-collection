#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class BInaryTreeTraversallteration {
public:
    struct TreeNode {
        int val;
        TreeNode* left;
        TreeNode* right;

        TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
    };

    // 先序遍历（非递归，打印）
    static void preOrder(TreeNode* head) {
        if(head != nullptr) {
            stack<TreeNode*> st;
            st.push(head);
            
            while(!st.empty()) {
                head = st.top();
                st.pop();
                cout << head->val << " ";
                if(head->right != nullptr) {
                    st.push(head->right);
                }
                
                if(head->left != nullptr) {
                    st.push(head->left);
                }
            }
            cout << endl;
        }
    }

    static void inOrder(TreeNode* head) {
        if(head != nullptr) {
            stack<TreeNode*> st;

            while(!st.empty() || head != nullptr) {
                if(head != nullptr) {
                    st.push(head);
                    head = head->left;
                } else {
                    head = st.top();
                    st.pop();
                    cout << head->val << " ";
                    head = head->right;
                }
            }
            cout << endl;
        }
    }

    // 后序遍历（非递归，双栈，打印）
    static void posOrderTwoStacks(TreeNode* head) {
        if(head != nullptr) {
            stack<TreeNode*> st;
            stack<TreeNode*> collect;
            st.push(head);
            
            while(!st.empty()) {
                head = st.top();
                st.pop();
                collect.push(head);

                if(head->left != nullptr) {
                    st.push(head->left);
                }

                if(head->right != nullptr) {
                    st.push(head->right);
                }
            }

            while(!collect.empty()) {
                cout << collect.top()->val << " ";
                collect.pop();
            }
            cout << endl;
        }
    }

    // 后序遍历（非递归，单栈，打印）
    static void posOrderOneStack(TreeNode* head) {
        if(head != nullptr) {
            stack<TreeNode*> st;
            st.push(head);

            while(!st.empty()) {
                TreeNode* cur = st.top();
                if(cur->left != nullptr 
                    && head != cur->left 
                    && head != cur->right) {
                    st.push(cur->left);
                } else if(cur->right != nullptr && head != cur->right) {
                    st.push(cur->right);
                } else {
                    cout << cur->val << " ";
                    head = st.top();
                    st.pop();
                }
            }
            cout << endl;
        }
    }

    // ===== LeetCode 风格：返回 vector =====

    // 用一个栈完成先序遍历
	// 测试链接 : https://leetcode.cn/problems/binary-tree-preorder-traversal/
    static vector<int> preorderTraversal(TreeNode* head) {
        vector<int> ans;

        if(head != nullptr) {
            stack<TreeNode*> st;
            st.push(head);
            
            while(!st.empty()) {
                head = st.top();
                st.pop();
                ans.push_back(head->val);

                if(head->right != nullptr) {
                    st.push(head->right);
                }

                if(head->left != nullptr) {
                    st.push(head->left);
                }
            }
        }
        return ans;
    }

    // 用一个栈完成中序遍历
	// 测试链接 : https://leetcode.cn/problems/binary-tree-inorder-traversal/
    static vector<int> inorderTraversal(TreeNode* head) {
        vector<int> ans;
        if(head != nullptr) {
            stack<TreeNode*> st;
            while(!st.empty() || head != nullptr) {
                if(head != nullptr) {
                    st.push(head);
                    head = head->left;
                } else {
                    head = st.top();
                    st.pop();
                    ans.push_back(head->val);
                    head = head->right;
                }
            }
        }
        return ans;
    }

    // 用两个栈完成后序遍历
	// 提交时函数名改为postorderTraversal
	// 测试链接 : https://leetcode.cn/problems/binary-tree-postorder-traversal/
    static vector<int> posorderTraversalTwoStacks(TreeNode *head) {
        vector<int> ans;
        if(head != nullptr) {
            stack<TreeNode*> st;
            stack<TreeNode*> collect;
            st.push(head);
            
            while(!st.empty()) {
                head = st.top();
                st.pop();
                collect.push(head);

                if(head->left != nullptr) {
                    st.push(head->left);
                }

                if(head->right != nullptr) {
                    st.push(head->right);
                }
            }

            while(!collect.empty()) {
                ans.push_back(collect.top()->val);
                collect.pop();
            }
        }
        return ans;
    }

    // TODO: 没有完全理解
    // 用一个栈完成后序遍历
	// 提交时函数名改为postorderTraversal
	// 测试链接 : https://leetcode.cn/problems/binary-tree-postorder-traversal/
    static vector<int> posorderTraversalOneStack(TreeNode* head) {
        vector<int> ans;

        if(head != nullptr) {
            stack<TreeNode*> st;
            st.push(head);

            while(!st.empty()) {
                TreeNode* cur = st.top();
                if(cur->left != nullptr && head != cur->left && head != cur->right) {
                    st.push(cur->left);
                } else if(cur->right != nullptr && head != cur->right) {
                    st.push(cur->right);
                } else {
                    ans.push_back(cur->val);
                    head = st.top();
                    st.pop();
                }
            }
        }
        return ans;
    }
};

int main() {
    using BT = BInaryTreeTraversallteration;

    BT::TreeNode* head = new BT::TreeNode(1);
    head->left = new BT::TreeNode(2);
    head->right = new BT::TreeNode(3);
    head->left->left = new BT::TreeNode(4);
    head->left->right = new BT::TreeNode(5);
    head->right->left = new BT::TreeNode(6);
    head->right->right = new BT::TreeNode(7);
    // head->left->left->right = new BT::TreeNode(8);
    // head->left->left->right->left = new BT::TreeNode(9);
    // head->left->left->right->right = new BT::TreeNode(10);

    BT::preOrder(head);
    cout << "先序遍历非递归版" << endl;

    BT::inOrder(head);
    cout << "中序遍历非递归版" << endl;

    BT::posOrderTwoStacks(head);
    cout << "后序遍历非递归版-2个栈实现" << endl;

    BT::posOrderOneStack(head);
    cout << "后序遍历非递归版-1个栈实现" << endl;
}