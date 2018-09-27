//解法1:
//设置两个指针i,j。i为扫描指针，j指向已经排序的最后一个奇数。初始化i = 0, j = -1。
//若A[i]为偶数，i继续扫描，j不动
//若A[i]为奇数，++ j。如果i==j则A[j]必为奇数，无需交换；如果i!=j, 则A[j]必为偶数，需要交换
void move1(int A[], int n) {
	int i = 0, j = -1;
	int temp;
	while (i < n) {
		if (A[i] % 2 == 1) {
			++ j;
			if (i != j) {
				temp = A[i];
				A[i] = A[j];
				A[j] = temp;
			}
		}
		++ i;
	}
}

//解法2:
//设置两个指针i，j。i从前往后扫描，j从后往前扫描，当A[i]为偶数，A[j]为奇数时，交换，++ i, --j
void move2(int A[], int n) {
	int i = 0, j = n - 1;
	int temp;
	while (i < j) {
		while (i < j && A[i] % 2 == 1) {
			++ i;
		}
		while (i < j && A[j] % 2 == 0) {
			-- j;
		}
		if (i < j) {
			temp = A[i]; 
			A[i] = A[j];
			A[j] = temp;
			++ i;
			-- j;
		}
	}
}