/* HW 1- 	12680 - Card Magic */
/* Task:
create stack of numbers using ReadOneList (partial judge)
Cut x y = 截斷stack x, 由第y+1張卡起變成新stack,放在x後
Merge x y = 把x搬到y stack,疊上後面,原本的stack x消失 */

#include<stdio.h>
#include<stdlib.h>

typedef struct _Node{
    int size;
    int* data;
    struct _Node* next;
} Node;

Node* ReadOneList();
void PrintList(Node*);
void Merge(Node* dumhead, int x, int y);
void Cut(Node*, int, int);

int main(){
    Node* dummy_head;
    Node* tail;

    dummy_head = (Node*) malloc( sizeof(Node) );
    dummy_head->data = NULL;
    dummy_head->size = -1;

    tail = dummy_head;

    int N, M;   //N: no, of stack, M: no. of action
    
    scanf("%d %d", &N, &M);
    for(int i=0; i<N; i++){
        tail->next = ReadOneList();
        tail = tail->next;   
    }
    
    char act[10];
    int x, y;
    for(int i=0; i<M; i++){
        scanf("%s %d %d", act, &x, &y);
        if( act[0] == 'M' ){
            Merge(dummy_head, x, y);
        }
        else{
            Cut(dummy_head, x, y);
        }
    }
    
    
    PrintList(dummy_head);
    return 0;
}

Node* ReadOneList()
{
    Node * head=(Node *)malloc(sizeof(Node));
    
    scanf("%d:", &(head->size));
    head->data=(int *)calloc(head->size, sizeof(int));
    for(int i=0;i<(head->size);i++) scanf("%d", &(head->data[i]));
    head->next=NULL;
    return head;

}

void Merge(Node* dumhead, int x, int y)
{
    //from x to y
    Node *stack_x=(Node *)malloc(sizeof(Node));
    Node *stack_y=(Node *)malloc(sizeof(Node));
    stack_x=dumhead;
    stack_y=dumhead;
    for(int i=0;i<x-1;i++) stack_x=stack_x->next; //stack x 的前一個
    for(int i=0;i<y;i++) stack_y=stack_y->next;
    int size_x=stack_x->next->size;

    int * new_stack=(int *)calloc((size_x+stack_y->size),sizeof(int));

    for(int i=0;i<stack_y->size;i++)
    {
        new_stack[i]=stack_y->data[i];
    }
    for(int i=0;i<size_x;i++)
    {
        new_stack[i+stack_y->size]=stack_x->next->data[i];
    }
    
    
    stack_y->data=new_stack;
    stack_y->size=size_x+stack_y->size;
    stack_x->next=stack_x->next->next;
    return;

}

void Cut(Node* dumhead, int x, int y)
{
    Node *stack_x=(Node *)malloc(sizeof(Node));
    
    stack_x=dumhead;
    
    for(int i=0;i<x;i++) stack_x=stack_x->next; //stack x 的前一個
    

    //int * new_stack_x=(int *)calloc(y, sizeof(int));
    //for(int i=0;i<y;i++) new_stack_x[i]=stack_x->data[i]; //題目的1 to y即arr的0 to y-1

    Node *stack_y=(Node *)malloc(sizeof(Node));
    int *new_stack_y=(int *)calloc((stack_x->size)-y, sizeof(int));
    for(int i=0;i<(stack_x->size)-y;i++) new_stack_y[i]=stack_x->data[i+y];

    stack_y->size=(stack_x->size)-y;
    stack_y->data=new_stack_y;
    stack_y->next=stack_x->next;
    stack_x->size=y;
    //stack_x->data=new_stack_x;
    stack_x->next=stack_y;

    return;
}

void PrintList(Node* dumhead)
{

    Node * tmp=(Node*)malloc(sizeof(Node));
    tmp=dumhead->next;
    while(tmp !=NULL)
    {
        int i;
        for(i=0;i<tmp->size-1;i++)
        {
            printf("%d ", tmp->data[i]);
        }
        printf("%d\n", tmp->data[i]);
        tmp=tmp->next;
    }
    //last stack
    
    
    return;

}

