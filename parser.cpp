//
// Created by Arin on 05/04/2020.
//

#include "parser.h"
#include <sstream>
#include <vector>

template <class Container>
static void strsplit(const std::string& str, Container& cont, char delim = ' ')
{
	std::stringstream ss(str);
	std::string token;
	while (std::getline(ss, token, delim)) {
		if (token != "")
			cont.push_back(token);
	}
}

int     Parser::parseFile(Map& map, const char * FilePath) {
	std::ifstream   input;
	input.open(FilePath, std::ios::in);
	int   maxZ = -INT32_MIN;
	int   maxY = -INT32_MIN;

	if (input) {
		std::string     raw;
		unsigned    rawNumber = 0;
		while (std::getline(input, raw)) {
			std::vector< std::string > raw_string;
			strsplit(raw, raw_string, ' ');
			map.parsedMap.emplace_back();
			maxY = std::max((int)raw_string.size(), maxY);
			for (auto & value : raw_string) {
				int   coordZ = std::atoi(value.c_str());
				map.parsedMap[rawNumber].emplace_back(coordZ);
				maxZ = std::max(coordZ, maxZ);
			}
			rawNumber++;
		}
		input.close();
		map.averageZ = maxZ / 2.f;
		map.averageY = maxY / 2.f;
		map.averageX = map.parsedMap.size() / 2.f;
	} else {
		std::perror(RED "File not found or coudn't be opened" COLOR_OFF);
		return 1;
	}
	return 0;
}

//test function
int     Parser::pasteToFile(const std::vector<std::vector<int>>& map, const char * FilePath) {
	std::ofstream   output;
	output.open(FilePath, std::ios::out);
	if (output) {
		for (auto& raw : map) {
			for (auto value : raw)
				output << value << ' ';
			output << '\n';
		}
		output << map.size() << '\n';
		output.close();
	} else {
		std::perror(RED "File not found or coudn't be opened" COLOR_OFF);
		return -1;
	}
	return 0;
}

int     Parser::convertDotToTriangles(
		const std::vector<std::vector<int>>& map,
		std::vector<Triangle>& triangles)
{
	for (int i = 0; i < (int)map.size() - 1; i++) {
		for (int j = 0; j < (int)map[i].size() - 1; j++) {
			if (j != (int)map[i + 1].size()) {
				triangles.push_back({
		                    vec4< float >(i, j, map[i][j], 1.f),
		                    vec4< float >(i, j + 1, map[i][j + 1], 1.f),
		                    vec4< float >(i + 1, j, map[i + 1][j], 1.f)
                });
				if (j + 1 != (int)map[i + 1].size()) {
					triangles.push_back({
						vec4< float >(i, j + 1, map[i][j + 1], 1.f),
						vec4< float >(i + 1, j, map[i + 1][j], 1.f),
						vec4< float >(i + 1, j + 1, map[i + 1][j + 1], 1.f)
					                    });
				}
			}
		}
	}
	return 0;
}