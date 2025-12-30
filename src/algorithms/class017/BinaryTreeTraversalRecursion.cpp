#include <iostream>
using namespace std;

class BinaryTreeTraversalRecursion {
public:
    struct TreeNode {
        int val;
        TreeNode* left;
        TreeNode* right;

        TreeNode(int v) : val(v), left(nullptr), right(nullptr) {} 
    };

    static void f(TreeNode* head) {
        if(head == nullptr) {
            return;
        }
        // 1
        f(head->left);
        // 2
        f(head->right);
        // 3
    }

    // 先序遍历（递归）
    static void preOrder(TreeNode* head) {
        if(head == nullptr) {
            return;
        }

        cout << head->val << " ";
        preOrder(head->left);
        preOrder(head->right);
    }

    // 中序遍历（递归）
    static void inOrder(TreeNode* head) {
        if(head == nullptr) {
            return;
        }

        inOrder(head->left);
        cout << head->val << " ";
        inOrder(head->right);
    }

    // 后序遍历（递归）
    static void posOrder(TreeNode* head) {
        if(head == nullptr) {
            return;
        }

        posOrder(head->left);
        posOrder(head->right);
        cout << head->val << " ";
    }

    static int main() {
        using TreeNode = BinaryTreeTraversalRecursion::TreeNode;

        TreeNode* head = new TreeNode(1);
        head->left = new TreeNode(2);
        head->right = new TreeNode(3);
        head->left->left = new TreeNode(4);
        head->left->right = new TreeNode(5);
        head->right->left = new TreeNode(6);
        head->right->right = new TreeNode(7);

        BinaryTreeTraversalRecursion::preOrder(head);
        cout << endl;
        cout << "先序遍历递归版" << endl;

        BinaryTreeTraversalRecursion::inOrder(head);
        cout << endl;
        cout << "中序遍历递归版" << endl;

        BinaryTreeTraversalRecursion::posOrder(head);
        cout << endl;
        cout << "后序遍历递归版" << endl;

        return 0;
    }
};

int main() {
    BinaryTreeTraversalRecursion::main();
    return 0;
}