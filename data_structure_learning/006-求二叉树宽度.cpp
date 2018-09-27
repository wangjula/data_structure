//定义一个数据结构，存储结点以及对应的层次号
stuct St {
	BTNode * tree;
	int lno;
};

//求二叉树宽度，即所有层次结点个数的最大值
int width(BTNode * root) {
	St Q[maxSize];
	int front = rear = 0;
	int curlno;                                   //当前层次号
	BTNode * p;
	int max, n, i, j;

	if (root != NULL) {
		++ rear;
		Q[rear].tree = root;                      //根结点入队
		Q[rear].lno = 1;
		
		while (rear != front) {                   //计算各个结点的层次号
			++ front;
			p = Q[front].tree;
			curlno = Q[front].lno;
			if (p -> lchild != NULL) {
				++ rear;
				Q[rear].tree = p -> lchild;
				Q[rear].lno = curlno + 1;
			}
			if (p -> rchild != NULL) {
				++ rear;
				Q[rear].tree = p -> rchild;
				Q[rear].lno = curlno + 1;
			}
		}

		max = 0;                                  //计算各个层次结点数的最大值
		for (i = 1; i <= curlno; ++ i) {          //一次计算每个层次的结点数
			n = 0;
			for (j = 1; j <= rear; ++ j) {
				if (Q[j].lno == i) {              //满足结点层次号相等，则计数加1
					++ n;
				}
			}
			if (max < n) {
				max = n;
			}
		}
		return max;
	}
	return 0;
}