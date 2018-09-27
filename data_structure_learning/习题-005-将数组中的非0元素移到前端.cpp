//解法1:
//1、设计两个指针i，j，i为扫描指针, j指向最后一个非零元素位置。初始化i = 0; j = -1;
//2、如果A[i] == 0, ++i ,j不动
//3、如果A[i] != 0, ++j。此时若i==j，必有A[j]!=0，无需交换；若i!=j，必有A[j] == 0，交换A[i]和A[j]
void move1(int A[], int n) {
	int i = 0, j = -1;
	int temp;
	while (i < n) {
		if (A[i] != 0) {
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
//设置两个指针i, j。i从前往后扫描，j从后往前扫描，如果A[i]为0元素，A[j]为非0元素，则交换A[i]与A[j], ++ i, -- j
void move2(int A[], int n) {
	int i = 0, j = n - 1;
	int temp;
	while (i < j) {
		while (i < j && A[j] == 0) {
			-- j;
		}
		while (i < j && A[i] != 0) {
			++ i;
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