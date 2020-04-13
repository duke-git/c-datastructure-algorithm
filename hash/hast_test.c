#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

void do_command();

int main()
{
    do_command();
    return 0;
}

void do_command()
{
    int choice;

    HashTable ht;

    do {
        printf("\n==============================操作选择==============================\n");
        printf("1.初始化hash表\t2.插入hash表元素\t3.查找hash表元素\t4.删除hash表元素\n");
        printf("==============================操作选择==============================\n");

        printf("请输入你的选择:");
        scanf("%d", &choice);

        switch(choice) {
            case 0:
                printf("程序退出\n");
                return;
            case 1:
            {
                init(&ht, NULL);
                print_hashtable(&ht);
                break;
            }
            case 2:
            {
                int key, value;
                printf("请输入插入key : \n");
                scanf("%d", &key);
                printf("请输入插入的值: \n");
                scanf("%d", &value);
                insert(&ht, key, value);
                print_hashtable(&ht);

                break;
            }
            case 3:
            {
                print_hashtable(&ht);
                KeyType key;
                ValueType value;
                printf("请输入查找元素key: \n");
                scanf("%d", &key);
                int ret = find(&ht, key, &value);
                printf("result: key=%d , value=%d\n", key, value);
                break;
            }
            case 4:
            {
                print_hashtable(&ht);
                KeyType key;
                printf("请输入删除元素的key: \n");
                scanf("%d", &key);
                remove_element(&ht, key);
                print_hashtable(&ht);
                break;
            }
            default: printf("输入错误，请重新输入\n");
                break;
        }

    }while (choice != 0);

}



