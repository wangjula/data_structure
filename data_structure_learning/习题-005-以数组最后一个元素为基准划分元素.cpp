//将A[0]与A[n-1]交换，从而使用快排的划分算法
void divide(int A[], int n) {
	int i = 0, j = n - 1;
	int temp;

	temp = A[i];
	A[i] = A[j];
	A[j] = temp;

	temp = A[0];
	while (i < j) {
		while (i < j && A[j] > temp) {
			-- j;
		}
		if (i < j) {
			A[i] = A[j];
			++ i;
		}
		
		while (i < j && A[i] < temp) {
			++ i;
		}
		if (i < j) {
			A[j] = A[i];
			-- j;
		}
	}
	A[i] = temp;
}