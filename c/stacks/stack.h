#ifndef __C_CPP_STACK_H__
#define __C_CPP_STACK_H__

// add an element to the stack
int stack_add(void *elem);

// retrieve the top element from the stack
// priv is a private pointer of the caller
// retrieve_cb is a retrieve callback called from the stack_retreive if an element is available
// the data contains the element at the top of the stack and priv is the private pointer of the caller
//
int stack_retrieve(void *priv, void (*retrieve_cb)(void *data, void *priv));

#endif

