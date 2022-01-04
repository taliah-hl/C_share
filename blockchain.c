#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "function.h"

int hash(block* b)
{
    int txn1 = b->t[0].val;
    int txn2 = b->t[1].val;
    int sum = txn1 + txn2;
    return (((sum*sum)^(b->link)) + (b->link)*(b->link))%1000+1;

}

block* create_block(int currentTail, transaction t[2])
{
    block* new_block = (block*) calloc(1, sizeof(block));
    int i=0;
    for(i=0;i<2;i++)
    {
        new_block->t[i] = t[i];
    }
    new_block->link = currentTail;
    return new_block;
}

int query(block_chain *bc, char name[10], int initial_saving)
{
    
    int balance=initial_saving;
    int ptr = bc->tail; //block_data[ptr] is the block we are looking
    //ptr is idx of block_data
    int i=0;
    while (ptr != 0) 
    {
        for(i=0;i<2;i++)
        {
            if( strcmp( (bc->block_data[ptr]->t[i].from), name) ==0 )
            {
                balance -= bc->block_data[ptr]->t[i].val;
            }
            else if( strcmp( (bc->block_data[ptr]->t[i].to), name) ==0 )
            {
               balance += bc->block_data[ptr]->t[i].val; 
            }
            //bc->block_data[ptr] this is the block we are looking
        }

        ptr = bc->block_data[ptr]->link;

    }
    return balance;

}
