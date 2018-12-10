#include <stdio.h>
#include <queue.h>

void retrieve(void *data, void *priv)
{
    int *t = data;

    printf("%d\n", *t);
}

int main()
{
    int array[20];
    int i;
    int ret;

    for (i = 0; i < 20; i ++) {
        array[i] = i;

        queue_add(&array[i]);
    }

    while (1) {
        ret = queue_get(NULL, retrieve);
        if (ret < 0) {
            break;
        }
    }

    return 0;
}

