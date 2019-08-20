#include<iostream>  
#include <vector> 
  
using namespace std; 
  
struct node
{
    struct node *right;
    struct node *left;
    int value;
    int level;
    int height;
};

struct nodeRBT
{
    struct nodeRBT *right;
    struct nodeRBT *left;
    struct nodeRBT *parent;
    int value;
    int level;
    char color;
    int height;
    int balancefactor;

    // Constructor 
    nodeRBT(int data) 
    { 
       this->value = data; 
       left = right = parent = NULL; 
       this->color = 'R'; 
       this->height = 1;
    } 
};

struct node *root = NULL;
struct nodeRBT *rootRBT = NULL;
struct nodeRBT *rootAVL = NULL;
int top,number;
int a=0;
int leve = 0;
vector<int> ino;

struct node* insertBST(struct node* node, int key);
void inorderTraversalBST(struct node* root);
void PrintallPathsBST(struct node* node);
void PrintBST(struct node* node);
void push(int val);
void pop();
void display(int m);
void insert(const int &data);
void inorderTraversalRBT(struct nodeRBT* root);
void PrintallPathsRBT(struct nodeRBT* node);
void PrintRBT(struct nodeRBT* node);
struct nodeRBT* BSTInsert(nodeRBT* root, nodeRBT *pt); 
void rotateLeft(nodeRBT *&root, nodeRBT *&pt);
void rotateRight(nodeRBT *&root, nodeRBT *&pt);
void fixViolation(nodeRBT *&root, nodeRBT *&pt); 
void getLevelRBT(struct nodeRBT* node);
int giveHeightBST(struct node* node);
int max(int a, int b) ;
int giveHeight(struct nodeRBT* node);
nodeRBT *rightRotate(nodeRBT *y);  
nodeRBT *leftRotate(nodeRBT *x);  
int getBalance(nodeRBT *N);
nodeRBT* insertAVL(nodeRBT* node, int key);
void PrintAVL(struct nodeRBT* node);

int main() 
{ 
    int choice,val,number; 
    do
    {
        cout<<"Enter your choice.\n";
        cout<<"1. Insert a new node in Binary Search Tree and Red Black Tree\n";
        cout<<"2. Print inorder traversal of Binary Search Tree and Red Black Tree\n";
        cout<<"3. Print all paths of Binary Search Tree and Red Black Tree\n";
        cout<<"4. Print the Binary Search Tree and Red Black Tree\n";
        cout<<"5. Make and print AVL Tree from inorder of Binary Search Tree\n";
        cout<<"6. Quit\n";
        cin>>choice;
        switch(choice)
        {
            case 1:
                cout<<"Enter value that you want to insert\n";
                cin>>val; 
                if(root==NULL)
                    {   root = insertBST(root, val);
                        root->level=0;  }
                else
                    insertBST(root, val);
                insert(val);
                break;
            case 2:
                if(root==NULL)
                    cout<<"No element in tree\n";
                else
                {
                    cout<<"Inorder traversal of Binary Search Tree is as follows : ";
                    inorderTraversalBST(root);
                    cout<<"\n";
                }
                if(rootRBT==NULL)
                    cout<<"No element in tree\n";
                else
                {
                    cout<<"Inorder traversal of Red Black Tree is as follows : ";
                    inorderTraversalRBT(rootRBT);
                    cout<<"\n";
                }
                break;
            case 3:
                cout<<"All Paths of Binary Search Tree are as follows : \n";
                top=-1;
                PrintallPathsBST(root);
                cout<<"All Paths of Red Black Tree are as follows : \n";
                top=-1;
                PrintallPathsRBT(rootRBT);
                break;
            case 4:
                cout<<"Binary Search tree : \n";
                PrintBST(root);
                cout<<"Red Black tree : \n";
                getLevelRBT(rootRBT);
                PrintRBT(rootRBT);
                break;
            case 5:
                cout<<"Inorder traversal of AVL Tree : ";
                inorderTraversalBST(root);
                cout<<endl;
                number = ino.size();
                for (int i=0;i<number;i++) 
                {
                    rootAVL = insertAVL(rootAVL, ino[i]);
                }
                getLevelRBT(rootAVL);
                cout<<"AVL Tree : \n";
                PrintAVL(rootAVL);
                cout<<"All Paths of AVL Tree are as follows : \n";
                top=-1;
                PrintallPathsRBT(rootAVL);
                break;
            case 6:
                break;
            default:
                cout<<"Wrong choice\n"; 
        }
    }while (choice!=6);
    
      
    return 0; 
} 
struct node* insertBST(struct node* node, int key) 
{ 
    if (node == NULL)
    {
        struct node *temp =  (struct node *)malloc(sizeof(struct node)); 
        temp->value = key; 
        temp->left = temp->right = NULL;
        return temp; 
    } 

    if (key < node->value)
    { 
        node->left  = insertBST(node->left, key);
        node->left->level = node->level+1;
    } 
    else if (key > node->value)
    {
        node->right = insertBST(node->right, key); 
        node->right->level = node->level+1;
    }   
    return node; 
}
void inorderTraversalBST(struct node* root)
{
    if(root!=NULL)
    {
        inorderTraversalBST(root->left);
        ino.push_back(root->value);
        //a++;
        cout<<root->value;
        cout<<" ";
        inorderTraversalBST(root->right);
    }
}
void PrintallPathsBST(struct node* node)
{
    push(node->value);
    if(node->left!=NULL)
    {
        PrintallPathsBST(node->left);
    }
    if(node->right!=NULL)
    {
        PrintallPathsBST(node->right);
    }
    if(node->left==NULL&&node->right==NULL)
    {
        for(int j=0;j<top+1;j++)
            display(j);
    }
    pop();
} 

int stack[100], n=100;
void push(int val) {
   if(top>=n-1)
      cout<<"Stack Overflow"<<endl; 
   else {
      top++;
      stack[top]=val;
   }
}
void pop() {
   if(top<=-1)
      cout<<"Stack Underflow"<<endl;
   else {
      top--;
   }
}
void display(int m) {
   if(top>=0) {
      cout<<stack[m];
      for(int i=m+1; i<=top; i++)
         cout<<"->"<<stack[i];
         cout<<endl;
   } else
      cout<<"Stack is empty";
}

int giveHeightBST(struct node* node)
{
    if(node)
    {
        return (max(giveHeightBST(node->right), giveHeightBST(node->left)) + 1);
    }
    else 
        return 0;
}

void PrintBST(struct node* node)
{
    if(node)
    {
        for(int i=0;i<node->level;i++)
            cout<<"\t";
        if(giveHeightBST(node->right)>=giveHeightBST(node->left))
            cout<<node->value<<"["<<(giveHeightBST(node->right)-giveHeightBST(node->left))<<"]"<<endl;
        else
            cout<<node->value<<"["<<(giveHeightBST(node->left)-giveHeightBST(node->right))<<"]"<<endl;
        PrintBST(node->left);
        PrintBST(node->right);
    }
    if(root==NULL)
        cout<<"Binary search tree is empty";
}








// Function to insert a new node with given data 
void insert(const int &data) 
{ 
    nodeRBT *pt = new nodeRBT(data); 
  
    // Do a normal BST insert 
    rootRBT = BSTInsert(rootRBT, pt); 
  
    // fix Red Black Tree violations 
    fixViolation(rootRBT, pt); 
} 

void inorderTraversalRBT(struct nodeRBT* root)
{
    if(root!=NULL)
    {
        inorderTraversalRBT(root->left);
        cout<<root->value;
        cout<<" ";
        inorderTraversalRBT(root->right);
    }
}

void PrintallPathsRBT(struct nodeRBT* node)
{
    push(node->value);
    if(node->left!=NULL)
    {
        PrintallPathsRBT(node->left);
    }
    if(node->right!=NULL)
    {
        PrintallPathsRBT(node->right);
    }
    if(node->left==NULL&&node->right==NULL)
    {
        for(int j=0;j<top+1;j++)
            display(j);
    }
    pop();
}

int max(int a, int b)  
{  
    return (a > b)? a : b;  
}   

void getLevelRBT(struct nodeRBT* node)
{
    if(node)
    {
        node->level = leve;
        leve++;
        //cout<<leve;
        getLevelRBT(node->left);
        getLevelRBT(node->right);
        leve--;
    }
}

int giveHeight(struct nodeRBT* node)
{
    if(node)
    {
        return (max(giveHeight(node->right), giveHeight(node->left)) + 1);
    }
    else 
        return 0;
}

void PrintRBT(struct nodeRBT* node)
{
    if(node)
    {
        for(int i=0;i<node->level;i++)
            cout<<"\t";
        if(getBalance(node)<0)
            cout<<node->value<<"["<<(getBalance(node)*(-1))<<"]"<<"["<<node->color<<"]"<<endl;
        else
            cout<<node->value<<"["<<getBalance(node)<<"]"<<"["<<node->color<<"]"<<endl;
        PrintRBT(node->left);
        PrintRBT(node->right);
    }
    if(root==NULL)
        cout<<"Red Black tree is empty";
}

struct nodeRBT* BSTInsert(nodeRBT* root, nodeRBT *pt) 
{ 
    /* If the tree is empty, return a new node */
    if (root == NULL) 
       return pt; 
  
    /* Otherwise, recur down the tree */
    if (pt->value < root->value) 
    { 
        root->left  = BSTInsert(root->left, pt); 
        root->left->parent = root; 
    } 
    else if (pt->value > root->value) 
    { 
        root->right = BSTInsert(root->right, pt); 
        root->right->parent = root; 
    } 
  
    /* return the (unchanged) node pointer */
    return root; 
} 

void rotateLeft(nodeRBT *&root, nodeRBT *&pt) 
{ 
    nodeRBT *pt_right = pt->right; 
  
    pt->right = pt_right->left; 
  
    if (pt->right != NULL) 
        pt->right->parent = pt; 
  
    pt_right->parent = pt->parent; 
  
    if (pt->parent == NULL) 
        root = pt_right; 
  
    else if (pt == pt->parent->left) 
        pt->parent->left = pt_right; 
  
    else
        pt->parent->right = pt_right; 
  
    pt_right->left = pt; 
    pt->parent = pt_right; 
} 
  
void rotateRight(nodeRBT *&root, nodeRBT *&pt) 
{ 
    nodeRBT *pt_left = pt->left; 
  
    pt->left = pt_left->right; 
  
    if (pt->left != NULL) 
        pt->left->parent = pt; 
  
    pt_left->parent = pt->parent; 
  
    if (pt->parent == NULL) 
        root = pt_left; 
  
    else if (pt == pt->parent->left) 
        pt->parent->left = pt_left; 
  
    else
        pt->parent->right = pt_left; 
  
    pt_left->right = pt; 
    pt->parent = pt_left; 
} 

void fixViolation(nodeRBT *&root, nodeRBT *&pt) 
{ 
    nodeRBT *parent_pt = NULL; 
    nodeRBT *grand_parent_pt = NULL; 
  
    while ((pt != root) && (pt->color != 'B') && 
           (pt->parent->color == 'R')) 
    { 
  
        parent_pt = pt->parent; 
        grand_parent_pt = pt->parent->parent; 
  
        /*  Case : A 
            Parent of pt is left child of Grand-parent of pt */
        if (parent_pt == grand_parent_pt->left) 
        { 
  
            nodeRBT *uncle_pt = grand_parent_pt->right; 
  
            /* Case : 1 
               The uncle of pt is also red 
               Only Recoloring required */
            if (uncle_pt != NULL && uncle_pt->color == 'R') 
            { 
                grand_parent_pt->color = 'R'; 
                parent_pt->color = 'B'; 
                uncle_pt->color = 'B'; 
                pt = grand_parent_pt; 
            } 
  
            else
            { 
                /* Case : 2 
                   pt is right child of its parent 
                   Left-rotation required */
                if (pt == parent_pt->right) 
                { 
                    rotateLeft(root, parent_pt); 
                    pt = parent_pt; 
                    parent_pt = pt->parent; 
                } 
  
                /* Case : 3 
                   pt is left child of its parent 
                   Right-rotation required */
                rotateRight(root, grand_parent_pt); 
                //swap(parent_pt->color, grand_parent_pt->color);
                char temp ; 
                temp = parent_pt->color;
                parent_pt->color = grand_parent_pt->color;
                grand_parent_pt->color = temp;
                pt = parent_pt; 
            } 
        } 
  
        /* Case : B 
           Parent of pt is right child of Grand-parent of pt */
        else
        { 
            nodeRBT *uncle_pt = grand_parent_pt->left; 
  
            /*  Case : 1 
                The uncle of pt is also red 
                Only Recoloring required */
            if ((uncle_pt != NULL) && (uncle_pt->color == 'R')) 
            { 
                grand_parent_pt->color = 'R'; 
                parent_pt->color = 'B'; 
                uncle_pt->color = 'B'; 
                pt = grand_parent_pt; 
            } 
            else
            { 
                /* Case : 2 
                   pt is left child of its parent 
                   Right-rotation required */
                if (pt == parent_pt->left) 
                { 
                    rotateRight(root, parent_pt); 
                    pt = parent_pt; 
                    parent_pt = pt->parent; 
                } 
  
                /* Case : 3 
                   pt is right child of its parent 
                   Left-rotation required */
                rotateLeft(root, grand_parent_pt); 
                //swap(parent_pt->color, grand_parent_pt->color); 
                char temp1 ; 
                temp1 = parent_pt->color;
                parent_pt->color = grand_parent_pt->color;
                grand_parent_pt->color = temp1;
                pt = parent_pt; 
            } 
        } 
    } 
  
    root->color = 'B'; 
} 







nodeRBT *rightRotate(nodeRBT *y)  
{  
    nodeRBT *x = y->left;  
    nodeRBT *T2 = x->right;  
  
    // Perform rotation  
    x->right = y;  
    y->left = T2;  
  
    // Update heights  
    y->height = max(giveHeight(y->left), 
                    giveHeight(y->right)) + 1;  
    x->height = max(giveHeight(x->left), 
                    giveHeight(x->right)) + 1;  
  
    // Return new root  
    return x;  
}  
  
// A utility function to left  
// rotate subtree rooted with x  
// See the diagram given above.  
nodeRBT *leftRotate(nodeRBT *x)  
{  
    nodeRBT *y = x->right;  
    nodeRBT *T2 = y->left;  
  
    // Perform rotation  
    y->left = x;  
    x->right = T2;  
  
    // Update heights  
    x->height = max(giveHeight(x->left),     
                    giveHeight(x->right)) + 1;  
    y->height = max(giveHeight(y->left),  
                    giveHeight(y->right)) + 1;  
  
    // Return new root  
    return y;  
}  
  
// Get Balance factor of node N  
int getBalance(nodeRBT *N)  
{  
    if (N == NULL)  
        return 0;  
    return giveHeight(N->left) - giveHeight(N->right);  
}  
  
// Recursive function to insert a key 
// in the subtree rooted with node and 
// returns the new root of the subtree.  
nodeRBT* insertAVL(nodeRBT* node, int key)  
{  
    /* 1. Perform the normal BST insertion */
    if (node == NULL) 
    {
        // struct nodeRBT *temp =  (struct nodeRBT *)malloc(sizeof(struct nodeRBT)); 
        // temp->value = key; 
        // temp->left = temp->right = temp->parent = NULL;
        // return temp;
        node = new nodeRBT(key); 
        return node; 
    }  
  
    if (key < node->value)  
        node->left = insertAVL(node->left, key);  
    else if (key > node->value)  
        node->right = insertAVL(node->right, key);  
    else // Equal keys are not allowed in BST  
        return node;  
  
    /* 2. Update height of this ancestor node */
    node->height = 1 + max(giveHeight(node->left),  
                        giveHeight(node->right));  
  
    /* 3. Get the balance factor of this ancestor  
        node to check whether this node became  
        unbalanced */
    int balance = getBalance(node);  
  
    // If this node becomes unbalanced, then  
    // there are 4 cases  
  
    // Left Left Case  
    if (balance > 1 && key < node->left->value)  
        return rightRotate(node);  
  
    // Right Right Case  
    if (balance < -1 && key > node->right->value)  
        return leftRotate(node);  
  
    // Left Right Case  
    if (balance > 1 && key > node->left->value)  
    {  
        node->left = leftRotate(node->left);  
        return rightRotate(node);  
    }  
  
    // Right Left Case  
    if (balance < -1 && key < node->right->value)  
    {  
        node->right = rightRotate(node->right);  
        return leftRotate(node);  
    }  
  
    /* return the (unchanged) node pointer */
    return node;  
}  

void PrintAVL(struct nodeRBT* node)
{
    if(node)
    {
        for(int i=0;i<node->level;i++)
            cout<<"\t";
        if(getBalance(node)<0)
            cout<<node->value<<"["<<(getBalance(node)*(-1))<<"]"<<endl;
        else
            cout<<node->value<<"["<<getBalance(node)<<"]"<<endl;
        PrintAVL(node->left);
        PrintAVL(node->right);
    }
    if(rootAVL==NULL)
        cout<<"AVL tree is empty";
}