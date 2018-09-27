struct TBTNode{
	char data;
	int ltag, rtag;
	TBTNode * lchild;
	TBTNode * rchild;
};

//=====================================begin 中序二叉树==============================================
//二叉树中序线索化
void InThread(TBTNode * p, TBTNode *& pre) {
	if (p != NULL) {
		InThread(p -> lchild, pre);                          //线索化左子树
		if (p -> lchild == NULL) {                           //左子女为空，则将lchild指向前驱
			p -> lchild = pre;
			p -> ltag = 1;
		}
		if (pre != NULL && pre -> lchild == NULL) {          //左子女的前驱若存在，且右子女为空，用其rchild指向当前结点
			pre -> rchild = p;
			pre -> rtag = 1;
		}
		pre = p;
		InThread(p -> rchild, pre);                          //线索化右子树
	}
}

//建立线索二叉树子程序
void createInThread(TBTNode * root) {
	TBTNode * pre = NULL;
	if (root != NULL) {
		InThread(root, pre);
		pre -> rchild = NULL;                               //线索化后处理中序最后一个结点
		pre -> rtag = 1;
	}
}

//遍历中序二叉树
TBTNode * First(TBTNode * p) {
	while (p -> lchild == 0) {
		p = p -> lchild;
	}
	return p;
}

TBTNode * Next(TBTNode * p) {
	if (p -> rtag == 0) {
		return First(p);
	} else {
		return p -> rchild;
	}
}

void Inorder(TBTNode * root, void (* visit) (TBTNode * q)) {
	for (TBTNode * p = First(root); p != NULL; p = Next(p)) {
		visit(p);
	}
}
//==================================end 中序二叉树================================================

//==================================begin 前序二叉树==============================================
void preThread(TBTNode * p, TBTNode *& pre) {
	if (p != NULL) {
		if (p -> lchild == NULL) {
			p -> lchild = pre;
			p -> ltag = 1;
		}
		if (pre != NULL && pre -> rchild == NULL) {
			pre -> rchild = p;
			pre -> rtag = 1;
		}
		pre = p;

		//限制左右子女tag不是0才允许递归(左子女可能已经线索化过)
		if (p -> ltag == 0) {
			preThread(p -> lchild);
		}
		if (p -> rtag == 0) {
			preThread(p -> rchild);
		}
	}
}

void preorder(TBTNode * root, void (* visit)(TBTNode * q)) {
	if (root != NULL) {
		TBTNode * p  = root;
		while (p != NULL) {                       
			while (p -> ltag == 0) {                        //线索二叉树左子女不为线索，边访问边向左；否则直接访问后继即可
				visit(p);
				p = p -> lchild;
			}
			visit(p);
			p = p -> rchild;
		}
	}
}
//==================================end 前序二叉树================================================

//==================================begin 后序二叉树==============================================
void postThread(TBTNode * p, TBTNode *& pre) {
	if (p != NULL) {
		postThread(p -> lchild, pre);
		postThread(p -> rchild, pre);
		if (p -> lchild == NULL) {
			p -> lchild = pre;
			p -> ltag = 1;
		}
		if (pre != NULL && pre -> rchild == NULL) {
			pre -> rchild = p;
			pre -> rtag = 1;
		}
		pre = p;
	}
}