#pragma once

#include <iostream>
#include <vector>

using namespace std;

vector<vector<char>> sheetGenerator(string);
vector<pair<char, char>> bigramsGenerator(vector<char>);
vector<char> textParse(string);
pair<pair<int, int>, pair<int, int>> findPositions(pair<char, char>, vector<vector<char>>);
int chooseRule(pair<pair<int, int>, pair<int, int>>);
pair<char, char> bigramTransform(pair<char, char>, vector<vector<char>>, pair<pair<int, int>, pair<int, int>>, int);
int inputOption();
void playfair();