#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;

	for (int q = 0; q < n; q++)
	{
		string str;
		cin >> str;

		vector<int> v;

		for (int i = 0; i < str.size(); i++)
		{
			v.push_back(str[i] - 48);
		}

		while (v.size() > 1)
		{
			for (int i = 0; i < v.size(); i++)
				cout << v[i];
			cout << "\n";
			int temp = v[v.size() - 1];
			v.erase(v.begin() + v.size() - 1);



			int pos = v.size() - 1;
			while (temp > 0)
			{
				v[pos] -= temp;
				if (v[pos] < 0)
				{
					temp = 1;
					pos--;
					v.erase(v.begin() + v.size() - 1);
				}
				else
				{
					temp = 0;
				}
			}
		}
		if (v[0] == 0)
		{
			cout << "true";
		}
		else
		{
			cout << "0";
		}
	}
}

/*

4
964197531
1358024679
1
1222222222222222222222222222221

*/