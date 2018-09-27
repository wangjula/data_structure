// void printhouse(int n, int k) {
// 	int space_size = n - k;
// 	int max, min;
// 	//最小可能必为0
// 	min = 0;
// 	//计算最大可能数：考虑空房子数为n-k，最大可能分布为#-#-#
// 	max = space_size > (k - 1) ? k - 1 : space_size;
// 	printf("%d %d\n", min, max);
// }

// int main() {
// 	int t, n, k, i;
// 	scanf("%d", &t);
// 	for (i = 0; i < t; ++ i) {
// 		scanf("%d %d", &n, &k);
// 		printhouse(n, k);
// 	}
// }

//n:层数 m:指令条数
//n个塔容量
void dopour(int n, int m, int caps[]) {
	int vols[1000];
	int i, j;
	int t, k, c;                     //t指令类型，k层次， c处理量
	for (i = 0; i < n; ++ n) {
		vols[i] = 0;
	}
	for (j = 0; j < m, ++ j) {
		scanf("%d %d %d", &t, &k, &c);
		-- k;
		if (t == 1) {
			printf("%d\n", vols[k]);
		} else {
			while (c > 0 && k < n) {
				vols[k] += c;
				c -= vols[k] - caps[k];
				if (vols > caps[k]) {
					vols[k] = caps[k];
					k ++;
				}
			}
		}
	}
}

int main() {
	int n, m, i;
	int caps[1000];
	scanf("%d %d", &n, &m);           //层数， 指令条数
	for (i = 0; i < n; ++ i) {        //每层容量
		scanf("%d", caps[i]);
	}
	dopour(n, m, vols);
	return 0;
}