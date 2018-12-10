#ifndef __C_CPP_QUEUE_H__
#define __C_CPP_QUEUE_H__

int queue_add(void *data);

int queue_get(void *priv, void (*retrieve)(void *data, void *priv));

#endif

