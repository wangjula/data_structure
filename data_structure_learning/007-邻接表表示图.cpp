//边结点
struct Edge {
	int dest;
	int cost;
	Edge * next;
};

//顶点结点
struct Vertex {
	char data;
	Edge * adj;
};

class LGraph {
public:
	LGraph();
	~LGraph();
	int NumberOfVertices();
	int getVertexPos(char key);
	int getFirstNeighbor(int v);
	int getNextNeighbor(int v, int w);
	char getValue(int v);
private:
	Vertex vTable[maxSize];
	int n, e;
};

int LGraph::NumberOfVertices() {
	return n;
}

int LGraph::getVertexPos(char key) {
	for (int i = 0; i < n; ++ i) {
		if (vTable[i].data == key) {
			return i;
		}
	}
	return -1;
}

//获取顶点v的第一个邻接顶点位置
int LGraph::getFirstNeighbor(int v) {
	if (v != -1) {
		Edge * p = vTable[v].adj;
		if (p != NULL) {
			return p -> dest;
		}
	}
	return -1;
}

//在顶点v的邻接顶点列表中，获取w的下一个结点位置
int LGraph::getNextNeighbor(int v, int w) {
	if (v != -1) {
		Edge * p = vTable[v].adj;
		while (p != NULL && p -> dest != w) {
			p = p -> next;
		}
		if (p != NULL && p -> next != NULL) {
			return p -> next -> dest;
		}
	}
	return -1;
}