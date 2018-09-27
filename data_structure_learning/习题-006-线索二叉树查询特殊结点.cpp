//查找结点t的子树在中序下最后一个结点
//算法思想：最右结点只要往右查找即可，注意中序线索二叉树的最右结点判别条件是p -> rtag == 1
TBTNode * inLast(TBTNode * t) {
	TBTNode * p = t;
	while (p != NULL && t -> rtag == 0) {
		p = p -> rchild;
	}
	return p;
}

//查找中序二叉树下结点t的中序前驱
//算法思想：如果结点t被线索化，则lchild即为其中序前驱，否则其左子树的中序最后一个结点即为其中序前驱
TBTNode * inPrior(TBTNode * t) {
	TBTNode * p = t -> lchild;
	if (p != NULL && p -> ltag == 0) {
		p = inLast(t);
	}
	return p;
}

//查找中序二叉树下结点t的前序下后继
//算法思想：分3中情况讨论
//		1. 若t有左子女，前序后继为左子女
//		2. 若t只有右子女，前序后继为右子女
//      3. 若t没有子女，则沿着中序遍历，到下一个有右子女的结点，即为前序后继
TBTNode * treNext(TBTNode * t) {
	TBTNode * p = t;
	if (p != NULL && p -> ltag == 0) {              //情况1
		p = p -> lchild;
	} else if (p != NULL && p -> rtag == 0) {       //情况2
		p = p -> rchild;
	} else {
		while (p != NULL && p -> rtag == 1) {       //情况3
			p = p -> rchild;
		}
		if (p != NULL) {
			p = p -> rchild;
		}
	}
	return p;
}