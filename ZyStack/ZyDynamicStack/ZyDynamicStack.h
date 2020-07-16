#ifndef _ZYDYNAMICSTACK_H_
#define _ZYDYNAMICSTACK_H_

//C99之后，引入了bool变量，使用时需包含如下的stdbool.h库
//如果使用的C语言为C99之前的版本，可以自定义bool变量，也可以用int型的0和1代替 
#include <stdbool.h>

typedef int ElemType;

typedef struct Node{
	ElemType Data;
	struct Node *pNext; 
}Node, *pNode;

typedef struct Stack{
	pNode pTop;//栈顶指针 
	pNode pBottom;//栈底指针
	int ElemNum;//栈中已有元素个数 
}Stack, *pStack;

//创建一个动态栈，不需要指定大小 
pStack create_stack();

//摧毁动态栈
bool destory_stack(pStack *ppAddrStack); 

//压栈
bool push_stack(pStack pAddrStack, ElemType DataPush);

//弹栈
bool pop_stack(pStack pAddrStack, ElemType *DataPop);

//判断是否为空栈
bool is_empty_stack(pStack pAddrStack);

//返回当前栈中元素个数 
int len_stack(pStack pAddrStack);

//遍历当前栈
void traverse_stack(pStack pAddrStack); 




#endif

