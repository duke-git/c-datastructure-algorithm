#include <stdio.h>
#include "queue.h"

void do_command();

int main()
{
    do_command();
    return 0;
}

void do_command()
{
    ArrayQueue queue = NULL;

    int choice;
    do {
        printf("\n==============================操作选择==============================\n");
        printf("1.创建队列\t2.元素入队列\t3.元素出队列\n4.遍历队列\n");
        printf("==============================操作选择==============================\n");

        printf("请输入你的选择:");
        scanf("%d", &choice);

        switch(choice) {
            case 0:
                printf("程序退出\n");
                return;
                break;
            case 1:
            {
                int size;
                printf("输入队列容量(不可超过队列最大容量16): ");
                scanf("%d", &size);
                queue = create_queue(size);
                printf("创建队列成功\n");
                break;
            }
            case 2:
            {
                DataType data;
                printf("输入入队列元素: ");
                scanf("%d", &data);
                enqueue(queue, data);
                traverse_queue(queue);
                break;
            }
            case 3:
            {
                DataType data = dequeue(queue);
                printf("出队列元素: %d\n", data);
                traverse_queue(queue);
                break;
            }
            case 4:
            {
                traverse_queue(queue);
                break;
            }
            default: printf("输入错误，请重新输入\n");
                break;
        }

    }while (choice != 0);

}
