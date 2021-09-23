#include<bits/stdc++.h>
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode *root = bthelper(preorder, inorder, 0, inorder.size()-1, 0, preorder.size()-1);
        return root;
    }

    TreeNode* bthelper(vector<int> pre, vector<int> in, int inS, int inE, int preS, int preE){
        if (inS > inE){
            return nullptr;
        }

        TreeNode *root = new TreeNode(pre[preS]);
        int rootIdx = -1;
        int rootVal = pre[preS];
        for (int i=inS; i<=inE; i++){
            if (rootVal == in[i]){
                rootIdx = i;
                break;
            }
        }
        if (rootIdx == -1){
            return nullptr;
        }

        //inorder ka game
       int leftInS=inS;
        int leftInE=rootIdx-1;
        int rightInS=rootIdx+1;
        int rightInE=inE;
        
        int leftPreS=preS+1;
        int leftPreE=leftInE-leftInS+leftPreS;
        int rightPreS=leftPreE+1;
        int rightPreE=preE;

        root->left = bthelper(pre, in, leftInS, leftInE, leftPreS, leftPreE);
        root->right = bthelper(pre, in, rightInS, rightInE, rightPreS, rightPreE);

        return root; 
    
    }
};



int main(){
    
}

