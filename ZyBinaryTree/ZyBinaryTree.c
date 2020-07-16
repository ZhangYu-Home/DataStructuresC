#include <malloc.h>
#include <stdio.h>
#include <assert.h>
#include <unistd.h>

#include "ZyBinaryTree.h"
#include "ZyDynamicStack.h" 
#include "ZyDynamicQueue.h" 

//创建二叉树 
//随便创建一个二叉树，用于验证后续算法 
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

//前序遍历二叉树——递归方式
void pre_order_traverse_r(pTreeNode pRoot){
	if(NULL == pRoot){
		return;
	}
	
	//访问根节点 
	printf("%c\n",pRoot->Data);
	//访问左子树 
	pre_order_traverse_r(pRoot->Left);
	//访问右子树
	pre_order_traverse_r(pRoot->Right);
}

//前序遍历二叉树——非递归方式
void pre_order_traverse(pTreeNode pRoot){
	if(NULL == pRoot){
		return;
	}
	
	pStack TreeStack = create_stack();
	push_stack(TreeStack,pRoot);
	
	while(!is_empty_stack(TreeStack)){
		pTreeNode t1 = NULL;
		pop_stack(TreeStack, &t1);
		//访问根节点
		printf("%c\n",t1->Data);
		if(t1->Right != NULL){
			//先压栈右子树，因为下一轮循环先访问左子树的根节点 
			push_stack(TreeStack,t1->Right);
		}
		if(t1->Left != NULL){
			push_stack(TreeStack,t1->Left);
		}
	}
	//摧毁栈，释放内存 
	destory_stack(&TreeStack); 
}


//中序遍历二叉树——递归方式
void in_order_traverse_r(pTreeNode pRoot){
	if(NULL == pRoot){
		return;
	}
	
	//访问左子树 
	in_order_traverse_r(pRoot->Left);
	//访问根节点 
	printf("%c\n",pRoot->Data);
	//访问右子树
	in_order_traverse_r(pRoot->Right);
}

//中序遍历二叉树——非递归方式
void in_order_traverse(pTreeNode pRoot){
	//创建栈 
	pStack TreeStack = create_stack();
	
	while(pRoot != NULL || !is_empty_stack(TreeStack)){
		while(pRoot != NULL){
			push_stack(TreeStack,pRoot);
			pRoot = pRoot->Left;
		}
		if(!is_empty_stack(TreeStack)){
			pop_stack(TreeStack, &pRoot);
			//访问根节点
			printf("%c\n",pRoot->Data);
			pRoot = pRoot->Right;
		}
	}
	//摧毁栈，释放内存 
	destory_stack(&TreeStack);
}


//后序遍历二叉树——递归方式
void post_order_traverse_r(pTreeNode pRoot){
	if(NULL == pRoot){
		return;
	}
	
	//访问左子树 
	post_order_traverse_r(pRoot->Left);
	//访问右子树
	post_order_traverse_r(pRoot->Right);
	//访问根节点 
	printf("%c\n",pRoot->Data);
}

//后序遍历二叉树——非递归方式
void post_order_traverse(pTreeNode pRoot){
	if(NULL == pRoot){
		return;
	}
	//利用两个栈进行访问 
	//创建栈 
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
	
	//摧毁栈，释放内存 
	destory_stack(&TreeStack1);
	destory_stack(&TreeStack2);
}

//层序遍历——非递归方式实现 
//广度优先搜索，需要利用队列实现
//此处不使用递归方式实现，递归方式反而更复杂。
void level_order_traverse(pTreeNode pRoot){
	if(NULL == pRoot){
		return;
	}
	//创建动态队列 
	pQueue pTreeQueue = create_queue();
	//根节点入队
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
	//摧毁队列，释放内存 
	destory_queue(&pTreeQueue);
}

//求二叉树的最大深度——递归方式 
int get_max_depth_r(pTreeNode pRoot){
	if(NULL == pRoot){
		return 0;
	}
	//左子树的最大深度 
	int max_left_depth = get_max_depth_r(pRoot->Left);
	//右子树的最大深度 
	int max_rigth_depth = get_max_depth_r(pRoot->Right);
	
	return (max_left_depth > max_rigth_depth)?max_left_depth+1:max_rigth_depth+1; 
} 

//求二叉树的最大深度——非递归方式 
//利用层序遍历方法 
int get_max_depth(pTreeNode pRoot){
	if(NULL == pRoot){
		return 0;
	}
	
	//创建动态队列 
	pQueue pTreeQueue = create_queue();
	//根节点入队
	push_queue(pTreeQueue,pRoot);
	int level = 0;
	while(!is_empty_queue(pTreeQueue)){
		level++;
		//当前层的元素个数 
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

//求二叉树的最小深度——递归方式 
//最小深度是从根节点到最近叶子节点的最短路径上的节点数量 
int get_min_depth_r(pTreeNode pRoot){
	if(NULL == pRoot){
		return 0;
	}
	//左子树的最小深度 
	int min_left_depth = get_min_depth_r(pRoot->Left);
	
	//右子树的最小深度
	int min_right_depth = get_min_depth_r(pRoot->Right);
	if (0 == min_left_depth){
		return min_right_depth + 1;
	}
	if (0 == min_right_depth){
		return min_left_depth + 1;
	}
	
	return (min_left_depth<min_right_depth)?min_left_depth+1:min_right_depth+1;
}

//求二叉树的最小深度——非递归方式 
//最小深度是从根节点到最近叶子节点的最短路径上的节点数量 
int get_min_depth(pTreeNode pRoot){
	if(NULL == pRoot){
		return 0;
	}
	
	//创建动态队列 
	pQueue pTreeQueue = create_queue();
	//根节点入队
	push_queue(pTreeQueue,pRoot);
	int level = 0;
	while(!is_empty_queue(pTreeQueue)){
		level++;
		//当前层的元素个数 
		int level_size = len_queue(pTreeQueue);
		int cnt;
		for(cnt = 0; cnt < level_size; ++cnt){
			pop_queue(pTreeQueue,&pRoot);	
			if(NULL == pRoot->Left && NULL == pRoot->Right){
				//摧毁队列，释放内存 
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
 



