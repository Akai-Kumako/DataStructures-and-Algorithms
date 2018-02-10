// e1433 藤本 恭子 「2分探索木」
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1

typedef struct node{
  char str[128];
  struct node *left;
  struct node *right;
} node_t;

node_t *root;

node_t *talloc(void){
  return((node_t *) malloc(sizeof(node_t)));
}

void search(char word[], node_t *root){
  if(root == NULL)
    printf("存在しません\n");
  else if(strncmp(word, root->str, 128) == 0)
    printf("存在します\n");
  else if(strncmp(word, root->str, 128) < 0)
    search(word, root->left);
  else
    search(word, root->right);
}

node_t *insert(char word[], node_t *root){
  if(root == NULL){
    root = talloc();
    strncpy(root->str, word, 128);
    root->left = NULL;
    root->right = NULL;
  }
  else if(strncmp(word, root->str, 128) == 0)
    printf("すでに挿入されています\n");
  else if(strncmp(word, root->str, 128) < 0)
    root->left = insert(word, root->left);
  else
    root->right = insert(word, root->right);
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

node_t *delete_item(char word[], node_t *root){
  if(root == NULL)
    printf("存在します\n");
  else if(strncmp(word, root->str, 128) == 0)
    root = delete_node(root);
  else if(strncmp(word, root->str, 128) < 0)
    root->left = delete_item(word, root->left);
  else
    root->right = delete_item(word, root->right);
  return(root);
}

void print_inorder(node_t *root){
  if(root != NULL){
    print_inorder(root->left);
    printf("%s\n", root->str);
    print_inorder(root->right);
  }
}

int main(void){
  char c;
  char word[128];

  root = NULL;

  while(TRUE){
    printf(">");
    scanf("%1s", &c);
    switch(c){
      case 's':
        scanf("%s", word);
        search(word, root);
        break;
      case 'i':
        scanf("%s", word);
        root = insert(word, root);
        break;
      case 'd':
        scanf("%s", word);
        root = delete_item(word, root);
        break;
      case 'p':
        print_inorder(root);
        break;
      case 'q':
        exit(0);
      default:
        printf("s, i, d, p, または q を入力してください\n");
    }
  }
}
