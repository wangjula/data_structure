struct BTNode {
	char data;
	BTNode * lchild;
	BTNode * rchild;
	explicit BTNode(char da, BTNode * lc = NULL, BTNode * rc = NULL) {
		data = da;
		lchild = lc;
		rchild = rc;
	}
};

//递归实现
//先序遍历
void preorder(BTNode * subTree, void (* visit)(BTNode * p)) {
	if (subTree != NULL) {
		visit(subTree);
		preorder(subTree -> lchild);
		preorder(subTree -> rchild);
	}
}

//后序遍历
void postorder(BTNode * subTree, void (* visit)(BTNode * p) {
	if (subTree != NULL) {
		postorder(subTree -> lchild, visit);
		postorder(subTree -> rchild, visit);
		visit(subTree);
	}
}

//中序遍历
void inorder(BTNode * subTree, void (* visit)(BTNode * p)) {
	if (subTree != NULL) {
		inorder(subTree -> lchild, visit);
		visit(subTree);
		inorder(subTree -> rchild, visit);
	}
}

//层次遍历
//使用循环队列存储待访问的结点
void level(BTNode * subTree, void (* visit)(BTNode * p)) {
	BTNode * Q[maxSize];
	int front = rear = 0;                         //头指针指向附加头，尾指针指向最后一个元素
	BTNode * q = NULL;

	if (subTree != NULL) {
		rear = (rear + 1) % maxSize;              //根结点入队  
		Q[rear] = subTree;
		while (rear != front) {                   //队列只判空
			front = (front + 1) % maxSize;        //头结点出队
			q = Q[front];
			visit(q);

			if (q -> lchild != NULL) {            //访问父结点后，将子女结点加入队列
				rear = (rear + 1) % maxSize;
				Q[rear] = q -> lchild;
			}
			if (q -> rchild != NULL) {
				rear = (rear + 1) % maxSize;
				Q[rear] = q -> rchild;
			}
		}
	}
}

//非递归实现
//先序遍历
void preorderNonrecursion(BTNode * root, void (* visit)(BTNode * p)) {
	if (root != NULL) {
		BTNode * Stack[maxSize];
		int top = -1;
		BTNode * q;

		Stack[++ top] = root;
		while (top != -1) {
			q = Stack[top --];
			visit(q);
			if (q -> rchild != NULL) {              //右子女先入栈，因为左子女先访问，应后入栈
				Stack[++ top] = q -> rchild;
			}
			if (q -> lchild != NULL) {
				Stack[++ top] = q -> lchild;
			}
		}
	}
}

//后序遍历
void postorderNonrecursion(BTNode * root, void (* visit)(BTNode * p)) {
	if (root != NULL) {
		BTNode * Stack1[maxSize]; int top1 = -1;   //Stack1用于得到逆后序序列
		BTNode * Stack2[maxSize]; int top2 = -1;   //Stack2转换逆后序序列
		BTNode * q;

		Stack1[++ top] = root;
		while (top != -1) {                        //计算逆后序序列
			q = Stack[top --];
			Stack2[++ top2] = q;
			if (q -> lchild) {
				Stack1[++ top1] = q -> lchild;
			}
			if (q -> rchild) {
				Stack1[++ top1] = q -> rchild;
			}
		}

		while (top2 != -1) {                      //将逆后序序列转换成后序序列
			q = Stack2[top2 --];
			visit(q);
		}
	}
}

//中序遍历
void inorderNonrecursion(BTNode * root, void (* visit)(BTNode * p)) {
	if (root != NULL) {
		BTNode * Stack[maxSize]; int top = -1;    //Stack保存扫描左子女的痕迹
		BTNode * q = root;

		while (top != -1 || q != NULL) {
			while (q != NULL) {                   //存在左子女就保存在栈中，继续沿左子女扫描
				Stack[++ top] = q;
				q = q -> lchild;
			}
			if (top != -1) {                      //不存在左子女则出栈一个结点访问，并转向扫描右子女
				q = Stack[top --];
				visit(p);
				q = q -> rchild;
			}
		}
	}
}