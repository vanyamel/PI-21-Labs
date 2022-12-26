#include<iostream>
#include<fstream>

using namespace std;

int main()
{
	
	std::ifstream file("input.txt");
	int n;
	file >> n;
	double** matrix = new double* [n];
	for (int i = 0; i < n; i++)
	{
		matrix[i] = new double[n];
		for (int j = 0; j < n; j++)
		{
			file >> matrix[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
	
	file.close();

	
	double** right = new double* [n];
	for (int i = 0; i < n; i++)
	{
		right[i] = new double[n];
		for (int j = 0; j < n; j++)
		{
			if (i == j)
				right[i][j] = 1;
			else
				right[i][j] = 0;
		}
	}
	

	
	for (int i = 0; i < n; i++)
	{
		double max = matrix[i][i];
		int maxIndex = i;
		for (int j = i + 1; j < n; j++)
		{
			if (matrix[j][i] > max)
			{
				max = matrix[j][i];
				maxIndex = j;
			}
		}
		if (maxIndex != i)
		{
			for (int j = 0; j < n; j++)
			{
				double temp = matrix[i][j];
				matrix[i][j] = matrix[maxIndex][j];
				matrix[maxIndex][j] = temp;
			}
			for (int j = 0; j < n; j++)
			{
				double temp = right[i][j];
				right[i][j] = right[maxIndex][j];
				right[maxIndex][j] = temp;
			}
		}
	}
	
	
	std::cout << "Pivoted Matrix" << std::endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
	
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i != j)
			{
				double ratio = matrix[j][i] / matrix[i][i];
				for (int k = 0; k < n; k++)
				{
					matrix[j][k] -= ratio * matrix[i][k];
					right[j][k] -= ratio * right[i][k];
				}
			}
		}
	}
	

	for (int i = 0; i < n; i++)
	{
		double temp = matrix[i][i];
		for (int j = 0; j < n; j++)
		{
			matrix[i][j] = matrix[i][j] / temp;
			right[i][j] = right[i][j] / temp;
		}
	}
	

	
	std::cout << "Inverse of the input matrix" << std::endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			std::cout << right[i][j] << " ";
		}
		std::cout << std::endl;
	}
	
	
	std::ofstream outfile("output.txt");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			outfile << right[i][j] << " ";
		}
		outfile << std::endl;
	}
	outfile.close();
	
	
	return 0;

}

