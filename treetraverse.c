

#include<stdio.h>
#include<stdlib.h>

struct abc
{
  int data;
  struct abc *left;
  struct abc *right;
  struct abc *next;
};

struct abc*top=NULL;

void push(struct abc*);
struct abc *pop();
struct abc *newnode(char);
void inorder (struct abc*);
void preorder (struct abc*);
void postorder (struct abc*);


struct abc *newnode(char a)
{
 struct abc *temp=(struct abc*)malloc(sizeof(struct abc));
  temp -> data = a;
  temp -> left = NULL;
  temp -> right = NULL;
  temp -> next = NULL;
  return(temp);
}

void inorder(struct abc*root)
{
  if(root==NULL)
  return;
  else
  {
    inorder(root->left);
    printf("%c\t",root->data);
    inorder(root->right);
  }
}


void preorder(struct abc*root)
{
  if(root==NULL)
  return;
  else
  {
    printf("%c\t",root->data);
    preorder(root->left);
    preorder(root->right);
  }
}

void postorder(struct abc*root)
{
  if(root==NULL)
  return;
  else
  {
    postorder(root->left);
    postorder(root->right);
    printf("%c\t",root->data);
  }
}


int main()
{
   struct abc *root,*p,*q;
   char a[]={'a','b','+','c','*'};
   int l=sizeof(a)/sizeof(a[0]);

    for(int i=0;i<l;i++)
    {
        if(a[i]=='+' || a[i]=='*')
        {
            root=newnode(a[i]);
            p=pop();
            q=pop();
            root->right=p;
            root->left=q;
            push(root);
        }
        else
        {
            root=newnode(a[i]);
            push(root);
        }
    }

    printf("Inorder traversal:\n");
    inorder(root);
    printf("\nPreorder traversal:\n");
    preorder(root);
    printf("\nPostorder traversal:\n");
    postorder(root);
    
    return 0;
}


void push(struct abc*root)
{
  if (top==NULL)
   top=root;
  else
  {
    root->next=top;
    top=root;
  }
}

struct abc*pop()
{
  struct abc*w;
  w=top;
  top=top->next;
  return(w);
}



