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
        printf("1.创建栈\t2.元素入栈\t3.元素出栈\n4.获取栈顶元素\t5.清空栈内数据\t6.查看栈元素\t7.删除栈\n");
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
                break;
            }
            case 2:
            {
                DataType data;
                printf("输入入栈元素：");
                scanf("%d", &data);
                push(s, data);
                traverse_stack(s);
                break;
            }
            case 3:
            {
                DataType data = pop(s);
                printf("出栈元素：%d\n", data);
                traverse_stack(s);
                break;
            }
            case 4:
            {
                DataType data = get_top_element(s);
                printf("栈顶元素：%d\n", data);
                traverse_stack(s);
                break;
            }
            case 5:
            {
                empty_stack(s);
                traverse_stack(s);
                break;
            }
            case 6:
            {
                traverse_stack(s);
                break;
            }
            case 7:
            {
                delete_stack(s);
                break;
            }
            default: printf("输入错误，请重新输入\n");
                break;
        }

    }while (choice != 0);

}