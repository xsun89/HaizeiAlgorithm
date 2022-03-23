//
// Created by Xin Sun on 2022-03-22.
//
#include <iostream>
#include <vector>

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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if(preorder.size() == 0 || inorder.size() == 0){
            return nullptr;
        }
        int rootVal = preorder[0];
        int idx;
        for(int i = 0; i < inorder.size(); i++){
            if(inorder[i] == rootVal){
                idx = i;
                break;
            }
        }
        TreeNode *root = new TreeNode(rootVal);
        vector<int> inLeft;
        vector<int> inRight;
        for(int i = 0; i < idx; i++){
            inLeft.push_back(inorder[i]);
        }
        for(int i = idx + 1; i < inorder.size(); i++){
            inRight.push_back(inorder[i]);
        }
        vector<int> preLeft;
        vector<int> preRight;
        for(int i = 1; i <= idx; i++){
            inLeft.push_back(preorder[i]);
        }
        for(int i = idx + 1; i < preorder.size(); i++){
            inRight.push_back(preorder[i]);
        }
        root->left = buildTree(preLeft, inLeft);
        root->right = buildTree(preRight, inRight);

        return root;

    }
};