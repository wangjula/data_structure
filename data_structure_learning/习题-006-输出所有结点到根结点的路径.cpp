stuct BTNode {
	int data;
	BTNode * lchild, * rchild;
	BTNode * parent = NULL;
}

//算法思想：parent默认为NULL，使用先序遍历，遍历时，若左右子女结点不为空，直接设置为当前root值
void setparent(BTNode * root) {
	if (root != NULL) {
		if (root -> lchild != NULL) {
			root -> lchild -> parent = root;
		}
		if (root -> rchild != NULL) {
			root -> rchild -> parent = root;
		}
		setparent(root -> lchild);
		setparent(root -> rchild);
	}
}

//算法2: s使用先序遍历，设置两个指针，p为扫描指针，q记录其parent
void setparent2(BTNode * p, BTNode * q) {
	if (p != NULL) {
		p -> parent = q;
		q = p;                //p的子女的parent必为p，故q = p
		setparent2(p -> lchild, q);
		setparent2(p -> rchild, q);
	}
}

//沿着parent逆向打印即可
void printPath(BTNode * p) {
	while (p -> parent != NULL) {
		cout << p -> data << " ";
		p = p -> data;
	}
}

//先序遍历依次打印
void path(BTNode * root) {
	if (root != NULL) {
		printPath(root);
		path(root -> lchild);
		path(root -> rchild);
	}
}