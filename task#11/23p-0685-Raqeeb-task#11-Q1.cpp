#include<iostream>

using namespace std;


//It is code for printing tree to check my other functions are working correctly or not
struct Trunk
{
    Trunk *prev;
    string str;

    Trunk(Trunk *prev, string str)
    {
        this->prev = prev;
        this->str = str;
    }
};

// Helper function to print branches of the binary tree
void showTrunks(Trunk *p)
{
    if (p == NULL)
        return;

    showTrunks(p->prev);
    std::cout<< p->str;
}

class Node
{
    public:
    int info;
    Node *left;
    Node *right;

    Node(int value)
    {
        info = value;
        left=NULL;
        right=NULL;
    }
};

class BST
{
    public:
    Node *root;
    BST()
    {
        root = NULL;
    }

void Insertion(Node *root2, int value)
    {
        if(root == NULL)
        {
            root = new Node(value);
            return;
        }

        if(value < root2->info)
        {
            if(root2->left == NULL)
            {
                root2->left = new Node(value);
            }
            else
            {
                Insertion(root2->left, value);
            }
        }
        else
        {
            if(root2->right == NULL)
            {
                root2->right = new Node(value);
            }
            else
            {
                Insertion(root2->right, value);

            }
        }
        return;;
    }

int Check_AVL_or_Not(Node *passed_root)
    {
        if(root==NULL)
        {
            cout<<"The tree is empty"<<endl;
            return -1;
        }

        if(passed_root==NULL)
        {
            return 0;
        }
        int l=Check_AVL_or_Not(passed_root->left);
        int r=Check_AVL_or_Not(passed_root->right);

        if(l- r <=1 && r-l<=1)
        {
            if(l>=r)
                return l+1;
            else 
                return r+1;
        }
        else
            return 2;

    }
};

void printTree(Node *root, Trunk *prev, bool isRight)
{
    if (root == NULL)
        return;
    
    string prev_str = "    ";
    Trunk *trunk = new Trunk(prev, prev_str);

    printTree(root->right, trunk, true);

    if (!prev)
        trunk->str = "---";
    else if (isRight)
    {
        trunk->str = ".---";
        prev_str = "   |";
    }
    else
    {
        trunk->str = "`---";
        prev->str = prev_str;
    }

    showTrunks(trunk);
    cout<< root->info << endl;

    if (prev)
        prev->str = prev_str;
    trunk->str = "   |";

    printTree(root->left, trunk, false);
}


int main(void)
{
    BST Tree;
    while(1)
    {
        int user_input;
        cout<<"Enter Integer to form BST tree:";
        cin>>user_input;
        Tree.Insertion(Tree.root, user_input);
        cout<<"Press 0 to end the insertion:";
        cin>>user_input;
        if(user_input==0)
            break;
    
    }

    printTree(Tree.root,NULL,false);
    int condition=Tree.Check_AVL_or_Not(Tree.root);
    if(condition!=2)
    {
        cout<<"The tree is AVL";
    }
    else 
    {
        cout<<"The tree is not AVL";
    }


    return 0;
}