#include <iostream>
#include <functional>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct BSTNode {
    int val;
    BSTNode *left;
    BSTNode *right;
    BSTNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to create a BST from a binary tree
BSTNode* createBSTFromBinaryTree(TreeNode* root) {
    BSTNode* bstRoot = NULL;

    // Helper function to insert a value into the BST
    function<BSTNode*(BSTNode*, int)> insertIntoBST = [&](BSTNode* root, int val) -> BSTNode* {
        if (root == NULL) {
            return new BSTNode(val);
        }
        if (val < root->val) {
            root->left = insertIntoBST(root->left, val);
        } else {
            root->right = insertIntoBST(root->right, val);
        }
        return root;
    };

    // Helper function to perform inorder traversal of the binary tree and insert nodes into the BST
    function<void(TreeNode*, BSTNode*&)> inorderTraversal = [&](TreeNode* root, BSTNode*& bstRoot) {
        if (root == NULL) {
            return;
        }
        inorderTraversal(root->left, bstRoot);
        bstRoot = insertIntoBST(bstRoot, root->val);
        inorderTraversal(root->right, bstRoot);
    };

    inorderTraversal(root, bstRoot);
    return bstRoot;
}

// Function to print the BST inorder (for verification)
void printInorderBST(BSTNode* root) {
    if (root == NULL) {
        return;
    }
    printInorderBST(root->left);
    cout << root->val << " ";
    printInorderBST(root->right);
}

int main() {
    // Create an example binary tree
    TreeNode* root = new TreeNode(24);
    root->left = new TreeNode(15);
    root->right = new TreeNode(4);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(22);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(10);

    // Create a new BST from the binary tree
    BSTNode* bstRoot = createBSTFromBinaryTree(root);

    // Print the BST inorder to verify the result
    cout << "Inorder traversal of the BST: ";
    printInorderBST(bstRoot);
    cout << endl;

    return 0;
}