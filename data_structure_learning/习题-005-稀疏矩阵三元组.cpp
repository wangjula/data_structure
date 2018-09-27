//由于A[][]中元素类型也是int
//使用B[][3]作为三元组
//B的第0行存储非零元素个数，矩阵行数，矩阵列数
void create(int A[][], int m, int n, int B[][3]) {
	int i, j, k = 1;
	for (i = 0; i < m; ++ i) {
		for (j = 0; j < n; ++ j) {
			if (A[i][j] != 0) {
				B[k][0] = A[i][j];
				B[k][1] = i;
				B[k][2] = j;
				++ k;
			}
		}
	}

	B[0][0] = k - 1;
	B[0][1] = m;
	B[0][2] = n;

}

bool find(int B[][3], int x) {
	int i, num, m, n;
	i = 1;
	num = B[0][0];
	m = B[0][1];
	n = B[0][2];

	if (x == 0 && num < m * n) {
		return true;
	}

	while (i < num) {
		if (x == B[i][0]) {
			return true;
		}
	}
	return false;
}