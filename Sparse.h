#pragma once
#include <vector>
class Element
{
public:
	int alpha;
	int beta;
	int gamma;
};

class Sparse
{
public:
	int rows; 
	int columns;
	int num_val;
	std::vector <Element> elements;
};

