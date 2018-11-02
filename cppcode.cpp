
//提供给编译原理作业的样板：按照这个替代字符串，即可得到所要 解析的cpp代码
#include<iostream>
#include<string>
using namespace std;
    
    int table[6][4] = {{1, 6, 6, 6},{6, 2, 6, 6},{6, 6, 3, 6},{6, 6, 6, 4},{4, 5, 6, 6},{6, 6, 6, 6}};
int maxState = 6;
int cntValue = 4;
char values[] = {  'a', 'b', 'c', 'd'  };
string s= "abcd(a*b)" ;
int endStateList[] = { 5 };

    //根据二维转化数组和 values 和原本的字符串
//去判断是否
    bool accordToReExp(string temp)
{
	int rowInd = 0;
	int valuesSize =cntValue;
	for (int i = 0; i < temp.length(); i++) {
		
		int colInd = valuesSize;
		char ch = temp[i];


		for (int j = 0; j < valuesSize; j++) {
			if (ch == values[j])
				colInd = j;
		}

		//如果这个字母在所有查询表中没有
		if (colInd == valuesSize)
			return false;

		rowInd=table[rowInd][colInd];
		
		//如果去的节点是endState，那就不行了
		if (rowInd == maxState)
			return false;
	}
    for (int i = 0; i < sizeof(endStateList) / sizeof(int); i++)
		if (endStateList[i] == rowInd)
			return true;

	return false;
}


int main()
{
	cout << "你输入的正则表达式是" << s;
	string temp;
	while (cin >> temp)
	{
		if (accordToReExp(temp)) {
			cout << "这个字符串符合正则表达式" << s<<endl;
		}
		else
			cout << "不符合" << endl;
	}
}
    
    
    