#include <malloc.h>
#include <stdio.h>
#include <assert.h>
#include <unistd.h>

#include "ZyBinaryTree.h"
#include "ZyDynamicStack.h" 
#include "ZyDynamicQueue.h" 

//���������� 
//��㴴��һ����������������֤�����㷨 
pTreeNode create_binarytree(){
	pTreeNode pRoot = (pTreeNode)malloc(sizeof(TreeNode));
	pRoot->Data = 'A';
	
	pRoot->Left = (pTreeNode)malloc(sizeof(TreeNode));
	pRoot->Left->Data = 'B';
	
	pRoot->Right = (pTreeNode)malloc(sizeof(TreeNode));
	pRoot->Right->Data = 'C';
	
	pRoot->Left->Left = (pTreeNode)malloc(sizeof(TreeNode));
	pRoot->Left->Left->Data = 'D';
	pRoot->Left->Left->Left = NULL;
	pRoot->Left->Left->Right = NULL;
	pRoot->Left->Right = (pTreeNode)malloc(sizeof(TreeNode));
	pRoot->Left->Right->Data = 'E';
	pRoot->Left->Right->Left = NULL;
	pRoot->Left->Right->Right = NULL;
	
//	pRoot->Right->Left = (pTreeNode)malloc(sizeof(TreeNode));
//	pRoot->Right->Left->Data = 'F';
//	pRoot->Right->Left->Left = NULL;
//	pRoot->Right->Left->Right = NULL;
	pRoot->Right->Left = NULL;
	pRoot->Right->Right = NULL;
	
	return pRoot;
}

//ǰ����������������ݹ鷽ʽ
void pre_order_traverse_r(pTreeNode pRoot){
	if(NULL == pRoot){
		return;
	}
	
	//���ʸ��ڵ� 
	printf("%c\n",pRoot->Data);
	//���������� 
	pre_order_traverse_r(pRoot->Left);
	//����������
	pre_order_traverse_r(pRoot->Right);
}

//ǰ����������������ǵݹ鷽ʽ
void pre_order_traverse(pTreeNode pRoot){
	if(NULL == pRoot){
		return;
	}
	
	pStack TreeStack = create_stack();
	push_stack(TreeStack,pRoot);
	
	while(!is_empty_stack(TreeStack)){
		pTreeNode t1 = NULL;
		pop_stack(TreeStack, &t1);
		//���ʸ��ڵ�
		printf("%c\n",t1->Data);
		if(t1->Right != NULL){
			//��ѹջ����������Ϊ��һ��ѭ���ȷ����������ĸ��ڵ� 
			push_stack(TreeStack,t1->Right);
		}
		if(t1->Left != NULL){
			push_stack(TreeStack,t1->Left);
		}
	}
	//�ݻ�ջ���ͷ��ڴ� 
	destory_stack(&TreeStack); 
}


//������������������ݹ鷽ʽ
void in_order_traverse_r(pTreeNode pRoot){
	if(NULL == pRoot){
		return;
	}
	
	//���������� 
	in_order_traverse_r(pRoot->Left);
	//���ʸ��ڵ� 
	printf("%c\n",pRoot->Data);
	//����������
	in_order_traverse_r(pRoot->Right);
}

//������������������ǵݹ鷽ʽ
void in_order_traverse(pTreeNode pRoot){
	//����ջ 
	pStack TreeStack = create_stack();
	
	while(pRoot != NULL || !is_empty_stack(TreeStack)){
		while(pRoot != NULL){
			push_stack(TreeStack,pRoot);
			pRoot = pRoot->Left;
		}
		if(!is_empty_stack(TreeStack)){
			pop_stack(TreeStack, &pRoot);
			//���ʸ��ڵ�
			printf("%c\n",pRoot->Data);
			pRoot = pRoot->Right;
		}
	}
	//�ݻ�ջ���ͷ��ڴ� 
	destory_stack(&TreeStack);
}


//������������������ݹ鷽ʽ
void post_order_traverse_r(pTreeNode pRoot){
	if(NULL == pRoot){
		return;
	}
	
	//���������� 
	post_order_traverse_r(pRoot->Left);
	//����������
	post_order_traverse_r(pRoot->Right);
	//���ʸ��ڵ� 
	printf("%c\n",pRoot->Data);
}

//������������������ǵݹ鷽ʽ
void post_order_traverse(pTreeNode pRoot){
	if(NULL == pRoot){
		return;
	}
	//��������ջ���з��� 
	//����ջ 
	pStack TreeStack1 = create_stack();
	pStack TreeStack2 = create_stack();
	push_stack(TreeStack1,pRoot);
	while(!is_empty_stack(TreeStack1)){
		pop_stack(TreeStack1, &pRoot);
		push_stack(TreeStack2,pRoot);
		if(pRoot->Left != NULL){
			push_stack(TreeStack1,pRoot->Left);
		}
		if(pRoot->Right != NULL){
			push_stack(TreeStack1,pRoot->Right);
		}		
	}
	while(!is_empty_stack(TreeStack2)){
		pop_stack(TreeStack2, &pRoot);
		printf("%c\n",pRoot->Data);
	}
	
	//�ݻ�ջ���ͷ��ڴ� 
	destory_stack(&TreeStack1);
	destory_stack(&TreeStack2);
}

//������������ǵݹ鷽ʽʵ�� 
//���������������Ҫ���ö���ʵ��
//�˴���ʹ�õݹ鷽ʽʵ�֣��ݹ鷽ʽ���������ӡ�
void level_order_traverse(pTreeNode pRoot){
	if(NULL == pRoot){
		return;
	}
	//������̬���� 
	pQueue pTreeQueue = create_queue();
	//���ڵ����
	push_queue(pTreeQueue,pRoot);
	while(!is_empty_queue(pTreeQueue)){
		pop_queue(pTreeQueue,&pRoot);
		printf("%c\n",pRoot->Data);
		if(NULL != pRoot->Left){
			push_queue(pTreeQueue,pRoot->Left);
		}
		if(NULL != pRoot->Right){
			push_queue(pTreeQueue,pRoot->Right);
		}	
	}
	//�ݻٶ��У��ͷ��ڴ� 
	destory_queue(&pTreeQueue);
}

//��������������ȡ����ݹ鷽ʽ 
int get_max_depth_r(pTreeNode pRoot){
	if(NULL == pRoot){
		return 0;
	}
	//�������������� 
	int max_left_depth = get_max_depth_r(pRoot->Left);
	//�������������� 
	int max_rigth_depth = get_max_depth_r(pRoot->Right);
	
	return (max_left_depth > max_rigth_depth)?max_left_depth+1:max_rigth_depth+1; 
} 

//��������������ȡ����ǵݹ鷽ʽ 
//���ò���������� 
int get_max_depth(pTreeNode pRoot){
	if(NULL == pRoot){
		return 0;
	}
	
	//������̬���� 
	pQueue pTreeQueue = create_queue();
	//���ڵ����
	push_queue(pTreeQueue,pRoot);
	int level = 0;
	while(!is_empty_queue(pTreeQueue)){
		level++;
		//��ǰ���Ԫ�ظ��� 
		int level_size = len_queue(pTreeQueue);
		int cnt;
		for(cnt = 0; cnt < level_size; ++cnt){
			pop_queue(pTreeQueue,&pRoot);	
			if(NULL != pRoot->Left){
				push_queue(pTreeQueue,pRoot->Left);
			}
			if(NULL != pRoot->Right){
				push_queue(pTreeQueue,pRoot->Right);
			}
		}	
	}
	return level;
}

//�����������С��ȡ����ݹ鷽ʽ 
//��С����ǴӸ��ڵ㵽���Ҷ�ӽڵ�����·���ϵĽڵ����� 
int get_min_depth_r(pTreeNode pRoot){
	if(NULL == pRoot){
		return 0;
	}
	//����������С��� 
	int min_left_depth = get_min_depth_r(pRoot->Left);
	
	//����������С���
	int min_right_depth = get_min_depth_r(pRoot->Right);
	if (0 == min_left_depth){
		return min_right_depth + 1;
	}
	if (0 == min_right_depth){
		return min_left_depth + 1;
	}
	
	return (min_left_depth<min_right_depth)?min_left_depth+1:min_right_depth+1;
}

//�����������С��ȡ����ǵݹ鷽ʽ 
//��С����ǴӸ��ڵ㵽���Ҷ�ӽڵ�����·���ϵĽڵ����� 
int get_min_depth(pTreeNode pRoot){
	if(NULL == pRoot){
		return 0;
	}
	
	//������̬���� 
	pQueue pTreeQueue = create_queue();
	//���ڵ����
	push_queue(pTreeQueue,pRoot);
	int level = 0;
	while(!is_empty_queue(pTreeQueue)){
		level++;
		//��ǰ���Ԫ�ظ��� 
		int level_size = len_queue(pTreeQueue);
		int cnt;
		for(cnt = 0; cnt < level_size; ++cnt){
			pop_queue(pTreeQueue,&pRoot);	
			if(NULL == pRoot->Left && NULL == pRoot->Right){
				//�ݻٶ��У��ͷ��ڴ� 
				destory_queue(&pTreeQueue);
				return level;
			}
			if(NULL != pRoot->Left){
				push_queue(pTreeQueue,pRoot->Left);
			}
			if(NULL != pRoot->Right){
				push_queue(pTreeQueue,pRoot->Right);
			}
		}	
	}
	
} 
 



