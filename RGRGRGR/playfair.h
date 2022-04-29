#pragma once

#include <iostream>
#include <vector>

using namespace std;

vector<string> sheetGenerator(string);
vector<pair<char, char>> bigramsGenerator(string);
string textParse(string);
pair<pair<int, int>, pair<int, int>> findPositions(pair<char, char>, vector<string>);
int chooseRule(pair<pair<int, int>, pair<int, int>>);
pair<char, char> bigramTransform(pair<char, char>, vector<string>, pair<pair<int, int>, pair<int, int>>, int);
void playfair(int);