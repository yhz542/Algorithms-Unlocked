#include <iostream>
#include <vector>
#include <string>
enum oper { CC, CR, CD, CI };
using namespace std;
void ComputeTransformTables(const string &, const string &, vector<vector<int>> &, vector<vector<int>> &);
int main()
{
	string X, Y;
	getline(cin, X);
	getline(cin, Y);
	size_t m = X.size(), n = Y.size();
	vector<vector<int>> cost(m+1, vector<int>(n+1));
	vector<vector<int>> op(m+1, vector<int>(n+1));
	ComputeTransformTables(X, Y,cost,op);
	for (auto beg1 = cost.cbegin(); beg1 != cost.cend(); ++beg1)
	{
		for (auto beg2 = (*beg1).cbegin(); beg2 != (*beg1).cend(); ++beg2)
		{
			cout << *beg2 << ' ';
		}
		cout << endl;
	}
	
	for (auto beg1 = op.cbegin(); beg1 != op.cend(); ++beg1)
	{
		for (auto beg2 = (*beg1).cbegin(); beg2 != (*beg1).cend(); ++beg2)
		{
			cout << *beg2 << ' ';
		}
		cout << endl;
	}
}
void ComputeTransformTables(const string &X, const string &Y, vector<vector<int>> &cost, vector<vector<int>> &op)
{
	size_t m = X.size(), n = Y.size();
	int cc = -1, cr = 1, cd = 2, ci = 2;
	cost[0][0] = 0;
	for (size_t i = 1 ; i <= m; ++i)
	{
		cost[i][0] = i * cd;
		op[i][0] = CD;
	}
	for (size_t j = 1; j <= n; ++j)
	{
		cost[0][j] = j * ci;
		op[0][j] = CI;
	}
	for (size_t i = 1; i <= m; ++i)
	{
		for (size_t j = 1; j <= n; ++j)
		{
			if (X[i - 1] == Y[j - 1])
			{
				cost[i][j] = cost[i - 1][j - 1] + cc;
				op[i][j] = CC;
			}
			else
			{
				cost[i][j] = cost[i - 1][j - 1] + cr;
				op[i][j] = CR;
			}
			if (cost[i - 1][j] + cd < cost[i][j])
			{
				cost[i][j] = cost[i - 1][j] + cd;
				op[i][j] = CD;
			}
			if (cost[i][j - 1] + ci < cost[i][j])
			{
				cost[i][j] = cost[i][j - 1] + ci;
				op[i][j] = CI;
			}
		}
	}
}
