#include <stdio.h>
#include <stdlib.h>

#include "ZyBinaryTree.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	pTreeNode pRoot = create_binarytree();
	//前序递归遍历
	printf("递归前序遍历：\n"); 
	pre_order_traverse_r(pRoot);
	//中序递归遍历 
	printf("递归中序遍历：\n");
	in_order_traverse_r(pRoot);
	//后序递归遍历
	printf("递归后序遍历：\n");
	post_order_traverse_r(pRoot);
	//前序非递归遍历
	printf("非递归前序遍历：\n");
	pre_order_traverse(pRoot);
	//中序非递归遍历 
	printf("非递归中序遍历：\n");
	in_order_traverse(pRoot);
	//后序非递归遍历
	printf("非递归后序遍历：\n");
	post_order_traverse(pRoot);
	//层序非递归遍历 
	printf("非递归层序遍历：\n");
	level_order_traverse(pRoot); 
	//递归获取二叉树最大深度
	printf("递归获取二叉树最大深度：%d\n",get_max_depth_r(pRoot)); 
	//非递归获取二叉树最大深度
	printf("非递归获取二叉树最大深度：%d\n",get_max_depth(pRoot)); 
	//递归获取二叉树最小深度
	printf("递归获取二叉树最小深度：%d\n",get_min_depth_r(pRoot)); 
	//非递归获取二叉树最小深度
	printf("非递归获取二叉树最小深度：%d\n",get_min_depth(pRoot)); 
	
	
	
	return 0;
}
