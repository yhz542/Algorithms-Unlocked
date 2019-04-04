#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<vector<int>> ComputeLcsTable(string &, string &);
string AssembleLcs(string &, string &, vector<vector<int>>&, int, int);
int main()
{
	string a, b;
	getline(cin, a);
	getline(cin, b);
	vector<vector<int>> Lcs=ComputeLcsTable(a,b);
	for (auto beg1 = Lcs.begin(); beg1 != Lcs.end(); beg1++)
	{
		for (auto beg2 = (*beg1).begin(); beg2 != (*beg1).end(); beg2++)
		{
			cout << *beg2 << ' ';
		}
		cout << '\n';
	}
	cout << AssembleLcs(a, b, Lcs, a.size(), b.size());
}
vector<vector<int>> ComputeLcsTable(string &X, string &Y)
{
	unsigned m = X.size();
	unsigned n = Y.size();
	vector<vector<int>> Lcs(m + 1, vector<int>(n + 1, 0));
	for (size_t i = 1; i <= m; ++i)
	{
		for (size_t j = 1; j <= n; ++j)
		{
			if (X[i - 1] == Y[j - 1])
				Lcs[i][j] = Lcs[i - 1][j - 1] + 1;
			else
			{
				if (Lcs[i][j - 1] > Lcs[i - 1][j])
					Lcs[i][j] = Lcs[i][j - 1];
				else
					Lcs[i][j] = Lcs[i - 1][j];
			}
		}
	}
	return Lcs;
}
string AssembleLcs(string &X, string &Y, vector<vector<int>>&Lcs, int i, int j)
{
	if (!Lcs[i][j])
		return "";
	else if (X[i - 1] == Y[j - 1])
		return AssembleLcs(X, Y, Lcs, i - 1, j - 1) + X[i - 1];
	else if (Lcs[i][j - 1] > Lcs[i - 1][j])
		return AssembleLcs(X, Y, Lcs, i, j - 1);
	else
		return AssembleLcs(X, Y, Lcs, i - 1, j);
}
