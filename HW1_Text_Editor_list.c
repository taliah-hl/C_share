/* 12668 - Text Editor - Linked List Version  */
/* HW1 (week 2) */
/*
指令: 在原本為空的string裡整cursor,
根據指令把cursor move左右,在cursor前增刪char
方法: doubly link list + dummy head, tail + Node ** cursor

*/

#include<stdio.h>
#include<stdlib.h>

typedef struct _Node{
    /*doubly link*/
    char content;
    struct _Node * next;
    struct _Node * prev;
}Node;

Node * add_to_end(char ch, Node * head, Node * tail);
//add to end of list (did not used)
void insert_after(char ch, Node ** cur);
//insert after node curson
void delete(Node ** cur);
//delete the node before cursor

void delete(Node ** cur);
void curs_to_right(Node ** cur);
void curs_to_left(Node ** cur);
void print_text(Node * head, Node * tail);


int main(void){

    Node * head= (Node * )malloc(sizeof(Node));
    Node * tail= (Node * )malloc(sizeof(Node));
    
    int T=0;

    //printf("give no. of line: ");
    scanf("%d", &T);
    while(T--)
    {
        head->prev=NULL;
        head->next=tail;
        head->content='\0';
        tail->prev=head;
        tail->content='\0';
        tail->next=NULL;

        Node ** cursor=(Node **)malloc(sizeof(Node*));
        (*cursor)=head;
        
        int ops=0;
        //printf("give no. of op: ");
        scanf("%d", &ops);
        getchar();
        while(ops--)
        {
            char ch='\0';
            scanf("%c", &ch);
            if(ch>='a' && ch<='z')
            {
                insert_after(ch, cursor);
            }
            else if(ch=='L')
            {
                curs_to_left(cursor);
            }
            else if(ch=='R') curs_to_right(cursor);
            else if(ch=='B') delete(cursor);
            else
            {
                printf("wrong input!\n");
            }
        }
        //printf("finish getting input\n");
        print_text(head, tail);

    }


    return 0;
}


Node * add_to_end(char ch, Node * head, Node * tail)
{
    Node * tmp = (Node *)malloc(sizeof(Node));
    tmp->content=ch;
    tail->next=tmp;
    tmp->next=head;
    tail=tmp;
    
}

void insert_after(char ch, Node ** cur)
{
    Node * tmp= (Node *)malloc(sizeof(Node));
    
    tmp->next=(*cur)->next;
   
    (*cur)->next->prev=tmp;

    (*cur)->next=tmp;

    tmp->prev=(*cur);
    tmp->content=ch;
    (*cur)=tmp;
}

void delete(Node ** cur)
{

    Node * tmp=(*cur);
    (*cur)->prev->next=(*cur)->next;
    (*cur)->next->prev=(*cur)->prev;
    (*cur)=(*cur)->prev;
    free(tmp);

}

void curs_to_right(Node ** cur)
{
    (*cur)=(*cur)->next;
}

void curs_to_left(Node ** cur)
{
    (*cur)=(*cur)->prev;
}

void print_text(Node * head, Node * tail)
{
    
    Node ** tmp=malloc(sizeof(Node **));
    
    (*tmp)=head->next;
    
    
    while((*tmp) != tail)
    {
        printf("%c", (*tmp)->content);
        Node *tmp2=(*tmp);
        (*tmp)=(*tmp)->next;
        free(tmp2);
        // printf("next addr is %p\n", (*tmp));
        
    }
    
    printf("\n");

}
