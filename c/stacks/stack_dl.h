#ifndef __STACK_DL_H__
#define __STACK_DL_H__

struct stack_dl {
    void *data;
    struct stack_dl *prev;
    struct stack_dl *next;
};

int stack_push(void *data);
void *stack_pop();


#endif


