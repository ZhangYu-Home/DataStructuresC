#ifndef _ZYLIST_H_
#define _ZYLIST_H_ 

//C99以后可以使用stdbool.h；否则可以选择自定义bool类型 
#include <stdbool.h> 

//定义节点中数据域元素的类型，方便之后创建其他类型的链表时进行修改；
typedef int ElemType;
//定义节点类型
typedef struct LinkNode
{
    ElemType Data;
    struct LinkNode *pNext;

} Node, *pNode;

//该函数用于创建链表，返回值为当前链表的头指针
pNode create_list();

//此函数用于遍历链表
void traverse_list(pNode pHead);

//获取链表中位置为pos处的数据
bool get_elem_list(pNode pHead, int pos, ElemType* DataGet); 

//链表插入的头插法
bool front_insert_list(pNode pHead, ElemType Data);

//链表插入的尾插法
bool back_insert_list(pNode pHead, ElemType Data);

//链表的头部删除
bool front_pop_list(pNode pHead, ElemType* pRetVal); 

//链表的尾部删除
bool back_pop_list(pNode pHead, ElemType* pRetVal);

//判断是否为空链表
//返回1表示为空，0为非空 
bool is_empty_list(pNode pHead);

//求取链表长度
int len_list(pNode pHead);

//对链表进行排序：从小到大
bool sort_list(pNode pHead);

//在链表的pos位置插入值
bool insert_list(pNode pHead, int pos, ElemType DataInsert);

//删除链表pos位置的节点 
bool pop_list(pNode pHead, int pos, ElemType* DataInsert);

//销毁链表
bool destory_list(pNode *ppHead); 

#endif 


