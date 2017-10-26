// e1433 藤本恭子 「構造体とポインタによるスタック」

#include <stdio.h>
#include <stdlib.h>

typedef struct cell{ //cell_t(= struct cell)構造体
  int item;
  struct cell *next;
} cell_t;

cell_t *listhead; //stackの先頭を表すcell_tのポインタ

cell_t *lalloc(void){ //メモリを確保する関数 構造体のポインタを返す
  return((cell_t *)malloc(sizeof(cell_t)));
}

//cell_t *initlist(void){ //stackを初期化する関数
//  cell_t *p;
//  p = lalloc();
//  p->next = NULL;
//  return(p);
//}

cell_t *top = NULL; //stackの最上層を表すcell_tのポインタ

cell_t *push(int x, cell_t *top){ //push関数
  cell_t *p;
  p = lalloc();
  p->item = x;
  p->next = top;
  printf(" - Pushed\n");
  return(p); //最新の最上層のデータを返す
}

cell_t *pop(cell_t *top){ //pop関数
  int x;
  if(top != NULL){
    x = top->item;
    top = top->next;
    printf(" - %d Poped\n", x);
  }else
    printf(" - the stack is empty\n");
  return(top); //最新の最上層のデータを返す
}

int main(void){ //メイン関数
 // listhead = initlist();

  cell_t *ref;
  char com;
  int n;

  while(1){
    printf("Please enter the command : ");
    scanf("%1s", &com);
    if(com == 'i'){ 
      printf(" - Please enter the data : ");
      scanf("%d", &n);
      top = push(n, top);
    }else if(com == 'd'){
      top = pop(top);
    }else if(com == 'm'){
      printf(" - Please enter the amount of erase : ");
      scanf("%d", &n);
      while(n > 0){
        if(top != NULL){
          top = pop(top);
          n--;
        }else{
          printf(" - the stack is empty\n");
          break;         
        }
      }
    }else if(com == 'p'){
      ref->next = top;     
      while(ref->next != NULL){
        printf(" - %d\n", ref->next->item);
        ref->next = ref->next->next;
      }
    }else if(com == 'q'){
      break;
    }else{
      printf(" - Please enter i, d, m, p, q or q\n");
    }
  }  

  return(0);
}
