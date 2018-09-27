//AOE网络：边表示活动，有权值，顶点表示事件点
//只有一个源点，关键路径即最长路径，代表完成整个活动的所需最短时间，关键路径上的活动就叫关键活动
//计算关键路径：先计算每个事件点的最早开始时间ve[]，再计算各个事件点的最迟发生事件vl[]，对于关键路径上的顶点，ve[i] = vl[j]
void CriticalPath(LGraph & G) {
	int i, j, w, Ae, Al;
	int n = G.NumberOfVertices();

	int * ve = new int[n];
	for (i = 0; i < n; ++ i) {
		ve[i] = 0;
	}
	for (i = 0; i < n; ++ i) {                 //拓扑顺序计算ve[]
		j = G.getFirstNeighbor(i);
		while (j != -1) {
			w = G.getWeight(i, j);
			if (ve[i] + w > ve[j]) {
				ve[j] = ve[i] + w;
			}
			j = G.getNextNeighbor(i, j);
		}
	}

	int * vl = new int[n];
	vl[n - 1] = ve[n - 1];
	for (j = n - 2; j > 0; -- j) {            //逆拓扑顺序计算vl[]  
		k = G.getFirstNeighbor(j);
		while (k != -1) {
			w = G.getWeight(j, k);
			if (vl[k] - w < v[j]) {
				vl[j] = vl[k] - w;
			}
			k = G.getNextNeighbor(j, k);
		}
	}

	for (int i = 0; i < count; ++ i) {
		j = G.getFirstNeighbor(i);
		while (j = -1) {
			Ae = ve[i];
			Al = vl[i] - G.getWeight(i, j);
			if (Ae == Al) {
				cout << "<" << G.getValue(i) << ", " << G.getValue(j) << ">" << endl;
			}
			j = G.getNextNeighbor(i, j);
		}
	}
	delete [] ve;
	delete [] vl;
}