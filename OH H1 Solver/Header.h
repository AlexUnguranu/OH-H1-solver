#pragma once
#include "Input.h"

bool Check3InARow(std::vector<std::vector<int>>& Map);
void ChangeEntireRow(std::vector<std::vector<int>>& Map, int row, int value);
void ChangeEntireColumn(std::vector<std::vector<int>>& Map, int col, int value);
bool CompareRows(std::vector<std::vector<int>>& Map);
bool CompareColumns(std::vector<std::vector<int>>& Map);
bool CheckCompleteRow(std::vector<std::vector<int>> Map, int row);
bool CheckCompleteCol(std::vector<std::vector<int>>Map, int col);
void Solve(std::vector<std::vector<int>>& map);