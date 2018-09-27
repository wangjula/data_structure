void printmax(int A[][], int m, int n) {
	int i, j, k, maxj, max;
	bool ismaxj;
	for (i = 0; i < m; ++ i) {
		max = A[i][0];
		maxj = 0;
		for (j = 1; j < n; ++ j) {                                      //找到第i行最大值
			if (max < A[i][j]) {
				max = A[i][j];
				maxj = j;
			}
		}
		ismaxj = true;
		for (k = 0; k < m; ++ k) {                                      //判断max是否也是第maxj列的最大值
			if (max < A[k][maxj]) {
				ismaxj = false;
			}
		}
		if (ismaxj) {                                                   //如果符合要求，则按格式“max, [i, j]”输出
			cout << max << ", [" << i << ", " << maxj << "]" << " ";
		}
	}
	cout << endl;
}

void printfmin(int A[][], int m, int n) {
	int i, j, k, min, minj;
	bool isminj;
	for (i = 0; i < m; ++ i) {
		min = A[i][0];
		minj = 0;
		for (j = 1; j < n; ++ j) {                                      //找到第i行最小值
			if (min > A[i][j]) {
				min = A[i][j];
				minj = j;
			}
		}
		isminj = true;
		for (k = 0; k < m; ++ k) {                                      //判断min是否也是第minj列的最小值
			if (min > A[k][minj]) {
				isminj = false;
			}
		}
		if (isminj) {                                                   //如果符合要求，则按格式“min, [i, j]”输出
			cout << min << ", [" << i << ", " << minj << "]" << " ";
		}
	}
	cout << endl;
}