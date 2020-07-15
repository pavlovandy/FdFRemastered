//
// Created by Arin on 09/04/2020.
//

#ifndef FDFREMASTERED_MAP_H
#define FDFREMASTERED_MAP_H

#include <vector>

struct Map {
	std::vector<std::vector<int>>   parsedMap;
	float           averageX;
	float           averageY;
	float           averageZ;
};

#endif //FDFREMASTERED_MAP_H
