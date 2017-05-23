#include <iostream>
#include <string>

using std::endl;
using std::cout;
using std::string;
using std::cin;
using std::size_t;

//计算一个 UTF-8 字符占用的字节数
//即获取一个字节高位开头为 1 的个数
size_t nBytesCode(const char ch)
{
	if(ch & (1 << 7))
	{
		int nBytes = 1;
		for(int idx = 0; idx != 6; ++idx)
		{
			if(ch & (1 << (6 - idx)))
				++nBytes;
			else
				break;
		}
		return nBytes;
	}
	return 1;
}

//获取一个string中的字符个数

//即string.size()方法在string中的元素是多字节编码时，
//返回值是string中存储的二进制长度

size_t length(const string & str)
{
	size_t ilen = 0;
	size_t nBytes = 0;
	for(size_t idx = 0; idx != str.size(); ++idx)
	{
		nBytes = nBytesCode(str[idx]);
		idx += (nBytes - 1);
		++ilen;
	}
	return ilen;
}

//返回三个int数据中最小的一个
int triple_min(const int & a, const int & b, const int & c)
{
	return a < b ? (a < c ? a : c) : (b < c ? b : c);
}

//计算最小编辑距离，包括中英文
int distance(const string & lhs, const string & rhs)
{	
	size_t lhs_len = length(lhs);
	size_t rhs_len = length(rhs);
	int editDist[lhs_len + 1][rhs_len + 1];//创建矩阵
	for(size_t idx = 0; idx <= lhs_len; ++idx)
	{
		editDist[idx][0] = idx;
	}
	for(size_t idx = 0; idx <= rhs_len; ++idx)
	{
		editDist[0][idx] = idx;
	}
	string sublhs, subrhs;
	for(size_t dist_i = 1, lhs_idx = 0; dist_i <= lhs_len; ++dist_i, ++lhs_idx)
	{
		size_t nBytes = nBytesCode(lhs[lhs_idx]);
		sublhs = lhs.substr(lhs_idx, nBytes);
		lhs_idx += (nBytes - 1);

		for(size_t dist_j = 1, rhs_idx = 0; dist_j <= rhs_len; ++dist_j, ++rhs_idx)
		{
			nBytes = nBytesCode(rhs[rhs_idx]);
			subrhs = rhs.substr(rhs_idx, nBytes);
			rhs_idx += (nBytes - 1);
			if(sublhs == subrhs)
			{
				editDist[dist_i][dist_j] = editDist[dist_i - 1][dist_j - 1];
			}
			else
			{
				editDist[dist_i][dist_j] = triple_min(
					editDist[dist_i][dist_j - 1] + 1,
					editDist[dist_i - 1][dist_j] + 1,
					editDist[dist_i - 1][dist_j - 1] + 1);
			}
		}
	}
	return editDist[lhs_len][rhs_len];
}

int main(void)
{
	string s1 = "中国人";
	string s2 = "abc中国";
	cin >> s1;
	cout << s1 << endl;
	cout << "s1's size   = " << s1.size() << endl;
	cout << "s1's length = " << length(s1) << endl; 
	cin >> s2; 
	cout << s2 << endl;
	cout << "s2's length = " << length(s2) << endl; 
	cout << "s1与s2的最小编辑距离 = " << ::distance(s1, s2) << endl;

	return 0;
}
