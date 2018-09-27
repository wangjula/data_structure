//若A[]只有一个元素，直接返回
//否则，划分为A[i]与A[i++...]两部分，计算平均值=(A[i] + (j-i) * avg(A, i + 1, j)) / (j - i + 1)
float avg(float A[], int i, int j) {
	if (i == j) {
		return A[i];
	} else {
		return (A[i] + (j - i) * avg(A, i + 1, j)) / (j - i + 1);
	}
}