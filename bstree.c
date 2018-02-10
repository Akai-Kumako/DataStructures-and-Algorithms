// e1433 藤本 恭子 「2分探索木」
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1

typedef struct node{
  int num;
  struct node *left;
  struct node *right;
} node_t;

node_t *root;

node_t *talloc(void){
  return((node_t *) malloc(sizeof(node_t)));
}

void search(int data, node_t *root){
  if(root == NULL)
    printf(" - The data does not exist\n");
  else if(data == root->num)
    printf(" - The data exists\n");
  else if(data < root->num)
    search(data, root->left);
  else
    search(data, root->right);
}

node_t *insert(int data, node_t *root){
  if(root == NULL){
    root = talloc();
    root->num = data;
    root->left = NULL;
    root->right = NULL;
    printf(" - Inserted\n");
  }
  else if(data == root->num)
    printf(" - Already inserted\n");
  else if(data < root->num)
    root->left = insert(data, root->left);
  else
    root->right = insert(data, root->right);
  return(root);
}

char children_type(node_t *ptr){
  if(ptr->left == NULL){
    if(ptr->right == NULL)
      return('n');
    else
      return('r');
  }
  else if(ptr->right == NULL)
    return('l');
  else
    return('b');
}

node_t *delete_node(node_t *ptr){
  char c;
  node_t *p, *parent_of_p;

  c = children_type(ptr);

  if(c == 'n')
    ptr = NULL;
  else if(c == 'l')
    ptr = ptr->left;
  else if(c == 'r')
    ptr = ptr->right;
  else{
    p = ptr->right;
    if((children_type(p) == 'r') || (children_type(p) == 'n')){
      p->left = ptr->left;
      ptr = p;
    }
    else{
      while(p->left != NULL){
        parent_of_p = p;
        p = p->left;
      }
      parent_of_p->left = p->right;
      p->left = ptr->left;
      p->right = ptr->right;
      ptr = p;
    }
  }
  return(ptr);
}

node_t *delete_item(int data, node_t *root){
  if(root == NULL)
    printf(" - The data does not exist\n");
  else if(data == root->num){
    root = delete_node(root);
    printf(" - Deleted\n");
  }else if(data < root->num)
    root->left = delete_item(data, root->left);
  else
    root->right = delete_item(data, root->right);
  return(root);
}

void print_inorder(node_t *root){
  if(root != NULL){
    print_inorder(root->left);
    printf("%d, ", root->num);
    print_inorder(root->right);
  }
}

int main(void){
  char c;
  int data;

  root = NULL;

  while(TRUE){
    printf("Please enter the command : ");
    scanf("%1s", &c);
    switch(c){
      case 's':
        printf(" - Please enter the data : ");
        scanf("%d", &data);
        search(data, root);
        break;
      case 'i':
        printf(" - Please enter the data : ");
        scanf("%d", &data);
        root = insert(data, root);
        break;
      case 'd':
        printf(" - Please enter the data : ");
        scanf("%d", &data);
        root = delete_item(data, root);
        break;
      case 'p':
        printf(" - ");
        print_inorder(root);
        printf("\n");
        break;
      case 'q':
        exit(0);
      default:
        printf(" - Please enter i, d, p or q\n");
    }
  }
}
