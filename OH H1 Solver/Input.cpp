#include "Input.h"

void FileRead(std::vector<std::vector<int>>& Map)
{
	std::ifstream inp("Oh h1.in");
	if (inp.is_open())
	{
		std::string line;
		std::getline(inp, line);
		line.push_back(' ');
		int row_number = ExtractAndEraseNumberFromAString(line);
		int column_number = ExtractAndEraseNumberFromAString(line);
		if (row_number % 2 == 0 && column_number % 2 == 0)
		{
			int inc = 0;
			while (inc < row_number)
			{
				std::vector<int> row;
				std::getline(inp, line);
				line.push_back(' ');
				int inc_col = 0;
				while (!line.empty() || inc_col < column_number)
				{
					if (line[0] == ' ')
						line.erase(line.begin());
					else {
						row.push_back(ExtractAndEraseNumberFromAString(line));
						inc_col++;
					}
				}
				Map.push_back(row);
				inc++;
			}
		}
		else {
			std::cout << "Invalid inputs !";
			inp.close();
			exit(-3);
		}
		inp.close();
	}
	else exit(-2);
}

int ExtractAndEraseNumberFromAString(std::string& str)
{
	auto pos = str.find(" ");
	auto auxiliar_number = str.substr(0, pos);
	str.erase(0, pos + 1);
	return std::stoi(auxiliar_number);
}

void DisplayCurentState(std::vector<std::vector<int>> Map)
{
	std::cout << std::endl;
	for (int i = 0; i < Map.size(); i++)
	{
		for (int j = 0; j < Map[i].size(); j++)
		{
	/*		if (Map[i][j] >= 0)
				std::cout << ' ';*/

			std::cout << "  ";
			if (Map[i][j] == 1)
				std::cout << "A";
			else if (Map[i][j] == -1)
				std::cout << "G";
			else std::cout << ' ';
		}
		std::cout  << std::endl;
	}
	std::cout << "\n--------------------\n";
}

