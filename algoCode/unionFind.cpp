#include "algoString.h";
class UF
{
public:
	UF(int n) {
		this->count = n;
		parent.resize(n);
		Size.resize(n);
		for (int i = 0; i < n; i++)
		{
			parent[i] = i;
			Size[i] = 1;
		}

	}
	void Union(int p, int q) {
		int rootP = find(p);
		int rootQ = find(q);
		if (rootP == rootQ) {
			return;
		}
		if (Size[rootP] > Size[rootQ]) {
			parent[rootP] = rootQ;
			Size[rootP] += Size[rootQ];
		}
		else
		{

			parent[rootQ] = rootP;
			Size[rootQ] += Size[rootP];
		}

		count--;

	}
	int Count() {
		return count;
	}
	bool connected(int p, int q) {
		int rootP = find(p);
		int rootQ = find(q);
		return rootP == rootQ;
	}

private:
	int count;
	vector<int> Size;
	vector<int> parent;
	//寻找x的父节点
	int find(int x) {
		while (parent[x] != x)
		{
			parent[x] = parent[parent[x]];
			x = parent[x];
		}
		return x;

	}
};

