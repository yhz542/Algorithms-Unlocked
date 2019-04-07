#include <iostream>//关于字符串比较部分可优化
#include <vector>
#include <string>
using namespace std;
void FaStaringMatcher(const string &, const vector<vector<int>> &, int);
void MakingNextState(string &, vector<vector<int>> &);
int main()
{
	string t, p;
	getline(cin, t);//文本串
	getline(cin, p);//模式串
	int length = p.size();
	vector<vector<int>> nextState(length , vector<int>(26, 0));
	MakingNextState(p, nextState);
	//for (auto beg1 = nextState.cbegin(); beg1 != nextState.cend(); ++beg1)
	//{
	//	for (auto beg2 = (*beg1).cbegin(); beg2 != (*beg1).cend(); ++beg2)
	//	{
	//		cout << *beg2 << ' ';
	//	}
	//	cout << endl;
	//}
	FaStaringMatcher(t, nextState, length);
}
void MakingNextState(string &str, vector<vector<int>> &nextState)
{
	int m = str.size();
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < 26; ++j)
		{
			char c = 'A' + j;
			string tem = str.substr(0, i )+c;//建立当前字符串
			//int flag = 0;
			for (int length = tem.size(); length > 0; --length)
			{
				if (tem.substr(i + 1 - length, length) == str.substr(0, length))//后缀等于前缀
				{
					nextState[i][j] = length;
					break;
				}
			}
		}
	}
}
void FaStaringMatcher(const string &text, const vector<vector<int>> &nextState, int m )
{
	int state = 0;
	int n = text.size();
	for (int i = 0 ; i < n ; ++i)
	{
		state = nextState[state][text[i] - 'A'];
		if (state == m)
		{
			cout << "The pattern occurs with shift " << i - m+1 << endl;
			state = 0;
		}
	}
}
