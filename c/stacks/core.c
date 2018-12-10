#include <stdio.h>
#include <stack.h>

void retrieve_cb(void *data, void *priv)
{
    int *t = data;

    printf("t %d\n", *t);
}

int main()
{
    int i;
    int array[20];
    int ret;

    for (i = 0; i < 20; i ++) {
        array[i] = i;

        stack_add(&array[i]);
    }

    while (1) {
        ret = stack_retrieve(NULL, retrieve_cb);
        if (ret < 0) {
            break;
        }
    }

    return 0;
}

