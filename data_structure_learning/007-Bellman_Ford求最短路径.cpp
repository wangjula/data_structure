//dist1[u] = edges[u][v]
//distk[u] = min { distk-1[u], min {distk-1[j] + edges[j][u]}} 
//distk[u]表示v到u最多经过k条边的最短路径长度
void Bellman_Ford(LGraph & G, int v, int dist[], int path[]) {
	int n = G.NumberOfVertices();
	int i, k, u, w;
	for (i = 0; i < n; ++ i) {                         //dist[]初始化存储的是dist[]，最后计算得的是distk-1[]
		dist[i] = G.getWeight(v, i);
		if (i != v && dist[i] < maxValue) {
			path[i] = v;
		} else {
			path[i] = -1;
		}
	}

	for (k = 2; k < n; ++ k) {                        //迭代n-2次(2 - n-2条边)
		for (u = 0; u < n; ++ u) {
			if (u != v) {
				for (i = 0; i < n; ++ i) {            //分别计算u到i经过k条边的最短路径
					w = G.getWeight(i, u);
					if (w > 0 && w < maxValue && dist[u] > dist[i] + w) {
						dist[u] = dist[i] + w;
						path[u] = i;
					}
				}
			}
		}
	}
}