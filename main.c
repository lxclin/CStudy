#include <stdio.h>
#include <stdlib.h>
/*
int main() {
    printf("Hello, World!\n");
    return 0;
}*/
/*int main() {
    int num1 = 1024;
    int num2 = 2048;
    int *ptr1;
    int *ptr2;
    ptr1 = &num1;
    ptr2 = &num2;
    printf("num1的值是:%d\t num1地址的值是:%p\n", num1, ptr1);
    printf("num2的值是:%d\t num2的地址是:%p\n", num2, ptr2);
    //将变量1的值，赋给变量2
    //num2=num1;
    //*ptr2 = *ptr1;等价于上边一个代码
    ptr2 = ptr1;
    printf("重新赋值后：\n");
    printf("num1的值是:%d\t num1地址的值是:%p\n", num1, ptr1);
    printf("num2的值是:%d\t num2的地址是:%p\n", num2, ptr2);

    *ptr2 = 1111;
    printf("重新赋值后：\n");
    printf("num1的值是:%d\t num1地址的值是:%p\n", num1, ptr1);
    printf("num2的值是:%d\t num2的地址是:%p\n", num2, ptr2);
    return 0;
}*/
/*void main()
{
    int a=5, b=10;
    printf("%d\n", (a+b)/2);
    system("pause");
}
*/
void main()
{
    int sum = 0;
    char ch;
    printf("enter:");
    while ((ch = getchar()) != '\n')
        switch (ch) {
            case 'A':case'E':case'I':case'L':case'N': case'O': case'R':case'S':case'T':case'U':
                sum = sum + 1;
                break;
            case'D':case'G':
                sum = sum + 2;
                break;
            case'B':case'C':case'M':case'P':
                sum = sum + 3;
                break;
            case'F':case'H':case'V':case'W':case'Y':
                sum = sum + 4;
                break;
            case'K':
                sum = sum + 5;
                break;
            case'J':case'X':
                sum = sum +8;
                break;
            case'Q':case'Z':
                sum = sum + 10;
                break;
        }
    printf("Scrabble value:%d\n", sum);
    printf("\n");
    system("pause");
}