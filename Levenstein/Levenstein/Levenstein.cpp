#include <iostream>
#include <string>


void levenstein(std::string s1, std::string s2)
{
	int n = s1.length();
	int m = s2.length();
	int** d = new int* [n + 1];
	for (int i = 0; i <= n; i++)
		d[i] = new int[m + 1];
	for (int i = 0; i <= n; i++)
		d[i][0] = i;
	for (int j = 0; j <= m; j++)
		d[0][j] = j;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1;
			d[i][j] = std::min(std::min(d[i - 1][j] + 1, d[i][j - 1] + 1), d[i - 1][j - 1] + cost);
		}
	int i = n;
	int j = m;
	while (i > 0 || j > 0)
	{
		if (i > 0 && j > 0 && d[i][j] == d[i - 1][j - 1] && s1[i - 1] == s2[j - 1])
		{
			std::cout << "copy " << s1[i - 1] << std::endl;
			i--;
			j--;
		}
		else if (i > 0 && j > 0 && d[i][j] == d[i - 1][j - 1] + 1 && s1[i - 1] != s2[j - 1])
		{
			std::cout << "replace " << s1[i - 1] << " to " << s2[j - 1] << std::endl;
			i--;
			j--;
		}
		else if (i > 0 && d[i][j] == d[i - 1][j] + 1)
		{
			std::cout << "delete " << s1[i - 1] << std::endl;
			i--;
		}
		else if (j > 0 && d[i][j] == d[i][j - 1] + 1)
		{
			std::cout << "insert " << s2[j - 1] << std::endl;
			j--;
		}
	}
	for (int i = 0; i <= n; i++)
		delete[] d[i];
	delete[] d;
}





int main()
{
	std::string s1, s2;
	std::cin >> s1 >> s2;
	levenstein(s1, s2);
	return 0;
    
}

