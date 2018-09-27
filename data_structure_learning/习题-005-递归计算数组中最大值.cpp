//A[]只有一个元素，直接返回该值
//若A[]有多个元素，分为A[i]与A[i...]两部分，递归调用findmax找到A[i+1...]中最大值，并与A[i]比较，即可得出原数组的最大值
float findmax(float A[], int i, int j) {
	int max;
	if (i == j) {
		return A[i];
	} else {
		max = findmax(A, i + 1, j);
		return A[i] > max ? A[i] : max;
	}
}