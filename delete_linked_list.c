#include <stdio.h>
#include <stdlib.h>
#include "function.h"

Node* createList(){

    int tmp_data=0;
    Node *ptr_tail=(Node *)malloc(sizeof(Node));
    Node **ptr_head=(Node **)malloc(sizeof(Node*));
    Node * cur;
    (*ptr_head)=NULL;
    int seq=0;
    //printf("in create list now\n");
    while(1){
        
        //printf("give input: ");
        scanf("%d", &tmp_data);
        if(tmp_data>-1){
            
            cur=(Node *)malloc(sizeof(Node));
            if(seq==0){
               (*ptr_head)= cur;
               seq++;
            }
            ptr_tail->next=cur;
            cur->data=tmp_data;
            cur->next=NULL;
            ptr_tail=cur;
            
        }
        else 
        {
            //printf("finished creating list\n");
            break;
        }
    }
return (*ptr_head);
    
}

void deleteNode(Node ** nd, int data){

    Node ** del=(Node **)malloc(sizeof(Node*));
    Node ** prev=(Node **)malloc(sizeof(Node*));
    (*del)=(*nd);
    (*prev)=(*nd);
    for(int i=data;i>1;i--){

        if((*del)==NULL) break;
        (*prev)=(*del);
        (*del)=(*del)->next;
        
    }
    if((*del)!=NULL){
        if(data==1){
        (*nd)=(*del)->next;
        }
        (*prev)->next=(*del)->next;
    
    }
    free(del);
   

    return;
}
