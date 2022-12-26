#include <iostream>
#include <string>
#include <unordered_map>
#include <chrono>

const int p = 31;
const int mod = 1e9 + 9;


int naiveSearch(const std::string& text, const std::string& pattern)
{
	int n = text.length();
	int m = pattern.length();

	for (int i = 0; i <= n - m; i++)
	{
		int j;
		for (j = 0; j < m; j++)
			if (text[i + j] != pattern[j])
				break;

		if (j == m)
			return i;
	}

	return -1;
}


int horspoolSearch(const std::string& text, const std::string& pattern)
{
	int n = text.length();
	int m = pattern.length();

	
	std::unordered_map<char, int> shift;
	for (int i = 0; i < m - 1; i++)
		shift[pattern[i]] = m - 1 - i;

	int i = m - 1;
	while (i < n)
	{
		int k = 0;
		while (k < m && pattern[m - 1 - k] == text[i - k])
			k++;

		if (k == m)
			return i - m + 1;

		i += shift[text[i]];
	}

	return -1;
}


int hash(std::string s)
{
	int h = 0;
	for (int i = 0; i < s.size(); i++)
		h = (h * p + s[i]) % mod;
	return h;
}

int rabinKarpSearch(const std::string& text, const std::string& pattern)
{
	int n = text.size();
	int m = pattern.size();
	int p_hash = hash(pattern); 
	int t_hash = hash(text.substr(0, m)); 

	for (int i = 0; i <= n - m; i++)
	{
		
		if (p_hash == t_hash)
		{
			
			bool match = true;
			for (int j = 0; j < m; j++)
			{
				if (text[i + j] != pattern[j])
				{
					match = false;
					break;
				}
			}

			if (match)
				std::cout << "Pattern found at index " << i << std::endl;
		}

		
		if (i < n - m)
		{
			t_hash = (t_hash - text[i] * p ^ (m - 1)) % m;
			t_hash = (t_hash * p + text[i + m]) % m;
			if (t_hash < 0) t_hash += m;
		}
	}
	return 1;
}

int main()
{
	std::string text;
	std::string pattern;

	std::cout << "Enter the text: ";
	std::getline(std::cin, text);

	std::cout << "Enter the pattern: ";
	std::getline(std::cin, pattern);

	
	auto start = std::chrono::high_resolution_clock::now();
	int index = naiveSearch(text, pattern);
	auto stop = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
	std::cout << "Naive algorithm: ";
	if (index == -1)
		std::cout << "Pattern not found" << std::endl;
	else
		std::cout << "Pattern found at index " << index << std::endl;
	std::cout << "Running time: " << duration.count() << " microseconds" << std::endl;

	
	start = std::chrono::high_resolution_clock::now();
	index = horspoolSearch(text, pattern);
	stop = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
	std::cout << "Horspool algorithm: ";
	if (index == -1)
		std::cout << "Pattern not found" << std::endl;
	else
		std::cout << "Pattern found at index " << index << std::endl;
	std::cout << "Running time: " << duration.count() << " microseconds" << std::endl;

	
	start = std::chrono::high_resolution_clock::now();
	index = rabinKarpSearch(text, pattern);
	stop = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
	std::cout << "Rabin-Karp algorithm: ";
	if (index == -1)
		std::cout << "Pattern not found" << std::endl;
	else
		std::cout << "Pattern found at index " << index << std::endl;
	std::cout << "Running time: " << duration.count() << " microseconds" << std::endl;

	return 0;
}



