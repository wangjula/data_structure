//二叉树先序遍历序列pre[], 中序遍历in[]
//算法思想：从pre取第一个元素a，在in中查找a，a左侧即为左子树序列，右侧为右子树序列，
//依次取pre下个元素继续划分，至只剩最后一个元素，则二叉树构造完毕
BTNode * createBT(char pre[], char in[], int l1, int r1, int l2, int r2) {
	BTNode * s;
	int lsize;                      //左子树序列长度

	if (l1 > r1) {
		return NULL;
	}

	//在in[]查找pre[]中第一个元素，作为左、右子序列的分界点
	for (int i = l2; i < r2; ++ i) {
		if (in[i] == pre[l1]) {
			lsize = i - l2;
			break;
		}
	}

	s = new BTNode(pre[l1]);
	//计算左子树在pre[]和in[]中的范围
	//pre[]中：pre[l1]为父结点，左子树范围从l1+1开始，计算lsize个元素
	//in[]中：in[i]为父结点，左子树范围为从l2开始，到i-1为为止
	s -> lchild = createBT(pre, in, l1 + 1, l1 + lsize, l2, i - 1);
	//计算右子树在pre[]和in[]中的范围
	//与上述计算左子树序列范围的方法类似
	s -> rchild = createBT(pre, in, l1 + lsize + 1, r1, i + 1, r2);

	return s;
}