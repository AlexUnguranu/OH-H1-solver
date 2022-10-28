#include "Header.h"

bool Check3InARow(std::vector<std::vector<int>>& map)
{
	int moved = false;
	for (int i = 0; i < map[0].size(); i++)// COLUMNS
	{
		int cnt_A = 0;//rows
		int cnt_G = 0;//rows
		//
		int cnt_CA = 0;//col
		int cnt_CG = 0;//col
		for (int j = 0; j < map.size(); j++)// ROWS
		{
			//Rows
			if (j + 1 < map.size() && map[j][i] == map[j + 1][i] && map[j][i] != 0) // CASE 1 1 0
			{
				if (j > 0 && map[j - 1][i] == 0)
				{
					map[j - 1][i] = -map[j][i];
					moved = true;
				}
				if (j + 2 < map.size() && map[j + 2][i] == 0)
				{
					map[j + 2][i] = -map[j][i];
					moved = true;
				}

			}
			if (j + 2 < map.size() && map[j + 1][i] == 0 && map[j][i] == map[j + 2][i] && map[j][i] != 0)//Case 1 0 1
			{
				map[j + 1][i] = -map[j][i];
				moved = true;
			}

			//Column
			if (j + 1 < map.size() && map[i][j] == map[i][j + 1] && map[i][j] != 0)// Case 1 1 0 
			{
				if (j > 0 && map[i][j - 1] == 0)
				{
					map[i][j - 1] = -map[i][j];
					moved = true;
				}
				if (j + 2 < map[i].size() && map[i][j + 2] == 0)
				{
					map[i][j + 2] = -map[i][j];
					moved = true;
				}

			}
			if (j + 2 < map.size() && map[i][j + 1] == 0 && map[i][j] == map[i][j + 2] && map[i][j] != 0)//Case 1 0 1
			{
				map[i][j + 1] = -map[i][j];
				moved = true;
			}
			if (map[i][j] == 1)
				cnt_A++;
			else if (map[i][j] == -1)
				cnt_G++;
			if (map[j][i] == 1)
				cnt_CA++;
			else if (map[j][i] == -1)
				cnt_CG++;
		}
		if (cnt_A + cnt_G != map.size())
		{
			if (cnt_A == map.size() / 2)
			{
				ChangeEntireRow(map, i, -1);
				moved = true;
			}
			if (cnt_G == map.size() / 2)
			{
				ChangeEntireRow(map, i, 1);
				moved = true;
			}
		}
		if (cnt_CA + cnt_CG != map.size())
		{
			if (cnt_CA == map.size() / 2)
			{
				ChangeEntireColumn(map, i, -1);
				moved = true;
			}
			if (cnt_CG == map.size() / 2)
			{
				ChangeEntireColumn(map, i, 1);
				moved = true;
			}
		}
	}
	return moved;
}

void ChangeEntireRow(std::vector<std::vector<int>>& Map, int row, int value)
{
	for (int i = 0; i < Map[row].size(); i++)
	{
		if (Map[row][i] == 0)
			Map[row][i] = value;
	}
}

void ChangeEntireColumn(std::vector<std::vector<int>>& Map, int col, int value)
{
	for (int i = 0; i < Map.size(); i++)
	{
		if (Map[i][col] == 0)
			Map[i][col] = value;
	}
}

bool CompareRows(std::vector<std::vector<int>>& Map)// Can be optimized , probably
{
	bool moved = false;

	for (int i = 0; i < Map.size(); i++)//row1
	{

		for (int j = 0; j < Map.size(); j++)//row 2
		{
			auto check_i = CheckCompleteRow(Map, i);
			auto check_j = CheckCompleteRow(Map, j);
			if (check_i != check_j)
			{
				int same_A = -1;//pos A
				int Same_G = -1;//pos B
				for (int k = 0; k < Map[i].size(); k++)
				{
					if (Map[i][k] == -Map[j][k])
					{
						same_A = -2;
						Same_G = -2;
						break;
					}
					if (Map[i][k] == 1 && Map[j][k] == 0)
					{
						if (same_A != -1)
							same_A = -2;
						else same_A = k;
					}
					else if (Map[i][k] == -1 && Map[j][k] == 0)
					{
						if (Same_G != -1)
							Same_G = -2;
						else Same_G = k;
					}
				}
				if (same_A > 0)
				{
					Map[j][same_A] = -Map[i][same_A];
					moved = true;
				}
				if (Same_G > 0)
				{
					Map[j][Same_G] = -Map[i][Same_G];
					moved = true;
				}
			}
		}
	}
	return moved;
}

bool CompareColumns(std::vector<std::vector<int>>& Map)
{
	bool moved = false;

	for (int i = 0; i < Map.size(); i++)//row1
	{

		for (int j = 0; j < Map.size(); j++)//row 2
		{
			auto check_i = CheckCompleteCol(Map, i);
			auto check_j = CheckCompleteCol(Map, j);
			if (check_i != check_j)
			{
				int same_A = -1;//pos A
				int Same_G = -1;//pos B
				for (int k = 0; k < Map[i].size(); k++)
				{
					if (Map[k][i] == -Map[k][j])
					{
						same_A = -2;
						Same_G = -2;
						break;
					}
					if (Map[k][i] == 1 && Map[k][j] == 0)
					{
						if (same_A != -1)
							same_A = -2;
						else same_A = k;
					}
					else if (Map[k][i] == -1 && Map[k][j] == 0)
					{
						if (Same_G != -1)
							Same_G = -2;
						else Same_G = k;
					}
				}
				if (same_A > 0)
				{
					Map[same_A][j] = -Map[same_A][i];
					moved = true;
				}
				if (Same_G > 0)
				{
					Map[Same_G][j] = -Map[Same_G][i];
					moved = true;
				}
			}
		}
	}
	return moved;
}

bool CheckCompleteRow(std::vector<std::vector<int>> Map, int row)
{
	for (int i = 0; i < Map.size(); i++)
	{
		if (Map[row][i] == 0)
			return false;
	}
	return true;
}

bool CheckCompleteCol(std::vector<std::vector<int>> Map, int col)
{
	for (int i = 0; i < Map.size(); i++)
	{
		if (Map[i][col] == 0)
			return false;
	}
	return true;
}


void Solve(std::vector<std::vector<int>>& map)
{
	int cnt = 1;
	while (cnt != 0)
	{
		bool move_2 = Check3InARow(map);
		if (move_2 == true)
		{
			cnt = 1;
			std::cout << "\n3row\n";
			DisplayCurentState(map);
		}
		else cnt = 0;
		move_2 = CompareRows(map);
		if (move_2 == true)
		{
			cnt = 1;
			std::cout << "\ncompare row\n";
			DisplayCurentState(map);
		}
		move_2 = CompareColumns(map);
		if (move_2 == true)
		{
			cnt = 1;
			std::cout << "\ncompare col\n";
			DisplayCurentState(map);
		}
	}
	std::cout << "\n FIN\n";
	DisplayCurentState(map);
}
