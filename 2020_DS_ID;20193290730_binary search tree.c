#include<stdlib.h>
#include<stdio.h>

struct bin_tree {
int data;
struct bin_tree * right, * left;
};
typedef struct bin_tree node;

void insert(node ** tree, int val)
{
    node *temp = NULL;
    if(!(*tree))
    {
        temp = (node *)malloc(sizeof(node));
        temp->left = temp->right = NULL;
        temp->data = val;
        *tree = temp;
        return;
    }

    if(val < (*tree)->data)
    {
        insert(&(*tree)->left, val);
    }
    else if(val > (*tree)->data)
    {
        insert(&(*tree)->right, val);
    }

}




node* search(node ** tree, int val)
{
    if(!(*tree))
    {
        return NULL;
    }

    if(val < (*tree)->data)
    {
        search(&((*tree)->left), val);
    }
    else if(val > (*tree)->data)
    {
        search(&((*tree)->right), val);
    }
    else if(val == (*tree)->data)
    {
        return *tree;
    }
}
int isBST( node* node)  
{  
  if (node == NULL)  
    return 1;  
     
  /* false if left is > than node */
  if (node->left != NULL && node->left->data > node->data)  
    return 0;  
     
  /* false if right is < than node */
  if (node->right != NULL && node->right->data < node->data)  
    return 0;  
   
  /* false if, recursively, the left or right is not a BST */
  if (!isBST(node->left) || !isBST(node->right))  
    return 0;  
     
  return 1;  
}

void main()
{
	printf("NAME:AIMAN AL-SUBARI\nID:20193290730\n");
    int searchno;
    node *root;
    node *tmp;

    root = NULL;
    insert(&root, 9);
    insert(&root, 4);
    insert(&root, 15);
    insert(&root, 6);
    insert(&root, 12);
    insert(&root, 17);
    insert(&root, 2);
if(isBST(root))
printf("correct binary search tree");
else
printf("wrong binary search tree");
    
    printf("\nEnter Number to search : ");
    scanf("%d",&searchno);
   tmp = search(&root, searchno);
    if (tmp)
   {
        printf("Searched found node=%d\n", tmp->data);
   }
    else
    {
        printf("NULL.\n");
    }

 ;
}


