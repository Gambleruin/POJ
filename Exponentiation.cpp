#include <iostream>  
#include <string>  
#include <vector>
using namespace std;

vector<int> Multi(vector<int> v1,vector<int> v2)
{
  	vector<int> result;
	for (int i = 0; i < v1.size() + v2.size() + 1; i++)
	{
		result.push_back(0);
	}
	for (int i = 0; i < v1.size(); i++)
	{
		for (int j = 0; j < v2.size(); j++)
		{
			result[i + j] += v1[i] * v2[j];
			result[i + j + 1] += result[i + j] / 10;
			result[i + j] %= 10;
		}
	}
	return result;
}

int main()  
{
	string str;
	int n;
	while(cin >> str >> n){
		vector<int> numArray;
		vector<int> resultArray;
		int dotPos = 0, IndexLen = str.length() - 1;
		for (int i = str.length() - 1; i >= 0; i--)
		{
			if(str[i] != '0')
			{
				IndexLen = i;
				break;
			}
		}
		
        for (int i = IndexLen; i >= 0; i--)
        {
		if (str[i] != '.')
			{
				numArray.push_back(str[i] - '0');
			}
			else
			{
				dotPos = IndexLen - i;
			}
        }
        
		for (int i = 0; i < numArray.size(); i++)
		{
			resultArray.push_back(numArray[i]);
		}
		
		for (int j = 0; j < n-1; j++)
		{
            resultArray = Multi(resultArray, numArray);
			int len = resultArray.size();
			
			while (resultArray[len-1] == 0)
			{
				resultArray.pop_back();
				len--;
			}

		}
		
		if(n * dotPos >= resultArray.size())
		{
			cout << ".";
			for(int k = 0; k < n * dotPos - resultArray.size(); k++)
			{
				cout << "0";
			}
		}
		for (int k = resultArray.size() - 1; k >= 0; k--)
		{
			if (k == n * dotPos - 1)
			{
				if (k != 0)
				{
	                cout << ".";
				}
			}
			cout << resultArray[k];
		}
		cout << endl;
	}
	return 0;
}
