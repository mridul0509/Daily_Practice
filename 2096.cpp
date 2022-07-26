#include<iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    TreeNode* LCA(TreeNode* root, int startValue, int destValue) {
        if (root == NULL)
            return NULL;
        if (root->val == startValue or root->val == destValue) {
            return root;
        }
        TreeNode* Left = LCA(root->left, startValue, destValue);
        TreeNode* Right = LCA(root->right, startValue, destValue);
        if (Left and Right) {
            return root;
        }
        return Left == NULL ? Right : Left;
    }

    int path(TreeNode* root, int destination, string& pathd) {
        if (root == NULL)
            return 0;
        if (root->val == destination)
            return 1;
        pathd += 'L';
        auto res = path(root->left, destination, pathd);
        if (res) {
            return 1;
        }
        pathd.pop_back();
        pathd += 'R';
        res = path(root->right, destination, pathd);
        if (res)
            return 1;
        pathd.pop_back();
        return 0;
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        root = LCA(root, startValue, destValue);
        string p1 = "", p2 = "";
        path(root, startValue, p1);
        path(root, destValue, p2);
        for (int i = 0; i < p1.length(); i++) {
            p1[i] = 'U';
        }
        return p1 + p2;

    }
};

