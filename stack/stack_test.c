#include <stdio.h>
#include "stack.h"

void do_command();

int main()
{
    do_command();
    return 0;
}

void do_command()
{
    Stack s = NULL;

    int choice;
    do {
        printf("==============================操作选择==============================\n");
        printf("1.创建栈\t2.元素入栈\t3.元素出栈\n4.获取栈顶元素\t5.清空栈\t6.删除栈\n");
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
                s = create_stack();
                printf("创建栈成功\n");
//                traverse_stack(s);
                break;
            }

            case 2:
            {
                DataType data;
                printf("输入入栈元素：\n");
                scanf("%d", &data);
                push(s, data);
                traverse_stack(s);
                break;
            }
            case 3:
                break;
            case 4:
                break;
            default: printf("输入错误，请重新输入\n");
                break;
        }

    }while (choice != 0);

}