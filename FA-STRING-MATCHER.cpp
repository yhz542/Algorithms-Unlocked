#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;
class FSM_String
{
	string pattern;//模式匹配串
	string text;//待检测字符串
	vector<vector<int>> FSM;//有穷状态机
	unsigned numOfState;//总状态数
	unsigned numOfUsedWord;//使用的总字符数
	unordered_map<char,unsigned int> wordsUsed;//使用的字符在字符表中的位置
	vector<char> wordList;//字符表
	unsigned cnt;//检测字符串中模式匹配串出现的总次数
	void GenerateFsm()
	{
		FSM.resize(numOfState, vector<int>(numOfUsedWord, 0));
		string tem ;
		for (size_t i = 0; i < numOfState; ++i)
		{
			for (size_t j = 0; j < numOfUsedWord; ++j)
			{
				tem = pattern.substr(0, i)+wordList[j];
				FSM[i][j] = stateByCmp(tem);
			}
		}
	}
	unsigned stateByCmp(const string& cur)//通过比较当前串的后缀和模式串的前缀来返回状态
	{
		for (size_t beg = 0,length = cur.size(); beg < cur.size(); ++beg,--length)
		{
			if(cur.substr(beg,length)==pattern.substr(0,length))
				return (unsigned)length;
		}
		return 0;
	}
public:
	FSM_String(istream& in):cnt(0)
	{
		cout << "please input the pattern string:" << endl;
		in >> pattern;
		cout << "please input the text string:" << endl;
		in >> text;
		numOfState = (unsigned)pattern.size();
		unsigned pos = 0;
		for (auto elem : pattern)
		{
			if (wordsUsed.find(elem) == wordsUsed.end())
			{
				wordsUsed.insert(make_pair(elem, pos++));
				wordList.push_back(elem);
			}
		}
		numOfUsedWord = (unsigned)wordsUsed.size();
	}
	void Solve()
	{
		GenerateFsm();
		unsigned state = 0;
		for (auto elem : text)
		{
			if (wordsUsed.find(elem) != wordsUsed.end())
			{
				unsigned wordIndex = wordsUsed[elem];
				state = FSM[state][wordIndex];
				if (state == (unsigned)pattern.size())
				{
					++cnt;
					state = 0;
				}
			}
			else
				state = 0;
		}
	}
	void Print()
	{
		cout << cnt << endl;
	}
};
int main()
{
	FSM_String test(cin);
	test.Solve();
	test.Print();
}
