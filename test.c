#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define MaxSize 100
typedef int DataType;

typedef struct
{
    DataType data[MaxSize];
    int top;
} Stack;

// 初始化顺序栈
void InitStack(Stack *S)
{
    S->top = -1;
}

// 判断顺序栈是否为空
int EmptyStack(Stack *S)
{
    if (S->top == -1)
        return 1;
    else
        return 0;
}

// 入栈
int Push(Stack *S, DataType x)
{
    if (S->top == MaxSize - 1)
    {
        printf("\n 栈已满，无法入栈!");
        return 0;
    }
    S->top++;
    S->data[S->top] = x;
    return 1;
}

// 出栈
DataType Pop(Stack *S)
{
    DataType x;
    if (EmptyStack(S))
    {
        printf("\n 栈空，无法出栈!");
        exit(1);
    }
    x = S->data[S->top];
    S->top--;
    return x;
}

// 将十进制数转换为非十进制数
void DectoOthers(int n, int b)
{
    char B[] = "0123456789ABCDEF";
    int x;
    Stack st;
    InitStack(&st);
    do
    {
        Push(&st, n % b);
        n = n / b;
    } while (n != 0);
    while (!EmptyStack(&st))
    {
        x = Pop(&st);
        printf("%c", B[x]);
    }
}

// 主函数（带 B/O/H 后缀）
int main()
{
    int n;
    printf("请输入一个十进制数：");
    scanf("%d", &n);
    printf("将十进制数 %d 转换为二进制数的结果为：", n);
    DectoOthers(n, 2);
    printf("B"); // 加 B
    printf("\n将十进制数 %d 转换为八进制数的结果为：", n);
    DectoOthers(n, 8);
    printf("O"); // 加 O
    printf("\n将十进制数 %d 转换为十六进制数的结果为：", n);
    DectoOthers(n, 16);
    printf("H"); // 加 H
    printf("\n");
    return 0;
}