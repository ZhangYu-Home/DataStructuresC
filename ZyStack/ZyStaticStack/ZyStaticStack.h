#ifndef _ZYSTATICSTACK_H_
#define _ZYSTATICSTACK_H_

//C99之后，引入了bool变量，使用时需包含如下的stdbool.h库
//如果使用的C语言为C99之前的版本，可以自定义bool变量，也可以用int型的0和1代替 
#include <stdbool.h> 

typedef int ElemType;

typedef struct Stack{
	ElemType* pData; //静态栈指针
	int Top; //栈顶序号，指向栈顶元素的上方 
	int SizeStack; //栈的大小  
	int RemSize; //栈剩余的大小 
	
}Stack, *pStack;

//创建一个大小为Size的栈
pStack create_stack(int Size);

//摧毁静态栈
bool destory_stack(pStack *ppAddrStack); 

//判断是否为空栈 
bool is_empty_stack(pStack pAddrStack);

//判断栈是否已满  
bool is_full_stack(pStack pAddrStack); 

//压栈
//返回值表示是否压栈成功 
bool push_stack(pStack pAddrStack, ElemType Data);

//弹栈
//返回值表示是否弹栈成功 
bool pop_stack(pStack pAddrStack, ElemType *pData); 

//从栈底开始遍历栈，到栈顶结束 
void traverse_stack(pStack pAddrStack);

//返回当前栈可用空间大小 
int remain_size(pStack pAddrStack);


#endif

