//AOV网络：用结点表示图，用边表示活动发生的先后顺序
//拓扑排序：使顶点排列在一个线性序列中，且满足发生先后顺序
//时间复杂度：O(n + e)， 每个顶点入栈出栈一次，每个边入度减1操作一次
struct Vertex {
	char data;
	int inDegree;
	Edge * adj;
};

bool TopologicalSort(Graph & G) {
	int w, v, count;
	int stack[maxSize];
	int top = -1;

	int n = G.NumbersOfVertices();
	Vertex * vTable = G.getFirstVertex();
	count = 0;                                //参与删除的顶点计数，若不足n个，说明存在回路
	for (int i = 0; i < n; ++ i) {            //入度为0的顶点入栈
		if (vTable[i].inDegree == 0) {
			stack[++ top] = i;
		}
	}

	while (top != -1) {
		v = stack[top --];
		++ count;
		cout << G.getValue(v) << " ";
		w = G.getFirstNeighbor(v);            //相邻顶点入度减1，减到0的顶点继续入栈
		while (w = -1) {
			-- vTable[w].inDegree;
			if (vTable[w].inDegree == 0) {
				stack[++ top] = w;
			}
			v = G.getNextNeighbor(v, w);
		}
	}

	if (count < n) {                          //表示有回路，拓扑排序失败
		return false;
	} else {
		return true;
	}
}