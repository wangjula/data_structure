//三元组结构
struct Trituple {
	int val;
	int i, j;
};

//用三元组表示的稀疏矩阵类
class SparseMatrix {
private:
	int Trituple * elem;
	int maxsize, rows, cols;
public:
	SparseMatrix(int sz);
	~SparseMatrix();
};

SparseMatrix::SparseMatrix(int sz) {
	maxsize = sz;
	rows = cols = 0;
	elem = new Trituple[maxsize];
}