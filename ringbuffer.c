// e1433 藤本恭子 「リングバッファ」

#include <stdio.h>

#define QUEUE 6

int head = 0;
int tail = 0;
int queue[QUEUE] = {0};

int queue_next(int i){
  return(((i) + 1) % QUEUE);
}

void push(int data){
  if(queue_next(tail) != head){
    queue[tail] = data;
    tail = queue_next(tail);
    printf(" - Pushed\n");
  }else{ 
    printf(" - Queue is full\n");
  }
}

void pop(){
  if(head != tail){
    head = queue_next(head);
    printf(" - Poped\n");
  }else{
    printf(" - Queue is empty\n");
  }
}

void queue_print(){
  printf(" - ");
  for(int i = head; i != tail; i = queue_next(i))
    printf("%d ", queue[i]);
  printf("\n");
}

int main(void){
  char com;
  int n;

  while(1){
    printf("Please enter the command : ");
    scanf("%1s", &com);
    if(com == 'i'){ 
      printf(" - Please enter the data : ");
      scanf("%d", &n);
      push(n);
    }else if(com == 'd'){
      pop();
    }else if(com == 'p'){
      queue_print();
    }else if(com == 'q'){
      break;
    }else{
      printf(" - Please enter i, d, p or q\n");
    }
  }
}  
