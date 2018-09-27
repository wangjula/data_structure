//算法思想：采用先序遍历，利用一个栈保存遍历过的结点，往下访问时结点入栈，往上层访问时结点出栈，碰到叶子结点就读取栈中内容输出
char stack[maxSize];                    //记录访问结点的栈
int top = -1;                           //栈顶
int i;
void printleaves(BTNode * p) {
	if (p != NULL) {
		stack[++ top] = p -> data;                             //首次访问结点入栈
		if (p -> lchild == NULL && p -> rchild == NULL) {      //打印根结点到叶子结点的路径
			for (i = 0; i <= top; ++ i) {
				cout << stack[i] << " ";
			}
			cout << endl;
		}

		printleaves(p -> lchild);
		printleaves(p -> rchild);
		-- top;                                                //由下层结点向上访问时，栈中结点出栈
	}
}