//
// Created by Arin on 05/04/2020.
//

#ifndef FDFREMASTERED_PARSER_H
#define FDFREMASTERED_PARSER_H

#include <cstdio>
#include "etc/terminal-colors.h"
#include <vector>
#include <fstream>
#include <iostream>
#include "triangle.h"
#include "Map.h"

namespace Parser {
	int     parseFile(Map& map, const char * FilePath);
	int     pasteToFile(const std::vector<std::vector<int>>& map, const char * FilePath);
	//mb i will not use it
	int     convertDotToTriangles(const std::vector<std::vector<int>>& map, std::vector<Triangle>& triangles);
}

#endif //FDFREMASTERED_PARSER_H
