//A[]只有一个元素，则直接返回
//若A[]中有多个元素，则划分为A[i], A[i+1...]两部分，用sum求A[i+1...]之和，再与A[i]相加即可
float sum(float A[], int i, int j) {
	if (i == j) {
		return A[i];
	} else {
		return A[i] + sum(A, i + 1, j);
	}
}