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
        info=value;
        left=NULL;
        right=NULL;
    }
};


class  BST
{
    public:
    Node  *root;
    BST()
    {
        root=NULL;
    }

    Node* Value_and_Sub_tree(Node *n, int value)
    {
        if(n==NULL)
        {
            return NULL;
        }
        
        if(n->info==value)
        {
            return n;
        }
        
        Node *curr;
        curr=Value_and_Sub_tree(n->left,value);
        if(curr!=NULL)
            return curr;
        curr=Value_and_Sub_tree(n->right,value);
        if(curr!=NULL)
            return curr;
        
        return NULL;
  }
};

void printTree(Node *&root, Trunk *prev, bool isRight)
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
    BST obj;
    obj.root=new Node(10);
    obj.root->left=new Node(5);
    obj.root->right=new Node(20);
    obj.root->left->left=new Node(3);
    obj.root->left->right=new Node(7);
    obj.root->right->left=new Node(15);
    obj.root->right->right=new Node(25);

    cout<<"Whole tree is: \n";
    printTree(obj.root,NULL,false);
    // obj.root=obj.Value_and_Sub_tree(obj.root,20);
    obj.root=obj.Value_and_Sub_tree(obj.root,1);

    cout<<"After searching and Extraction of SubTree"<<endl;
    if(obj.root!=NULL)
         printTree(obj.root,NULL,false);
    else
        cout<<"Value not found in tree"<<endl;
    return 0;
}
