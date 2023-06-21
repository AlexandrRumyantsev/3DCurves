#pragma once
#include "Curves.hpp"
#include <vector>
class Test
{
public:
	void test();
private:
	int32_t generateRandomNumber(int32_t, int32_t) const;
	double generateRandomRadius() const;
	double generateRandomStep() const;
		
	std::shared_ptr<Shape> generateRandomShape() const;
	inline std::shared_ptr<Shape> generateRandomEllipse() const;
	inline std::shared_ptr<Shape> generateRandomCircle() const;
	inline std::shared_ptr<Shape> generateRandomHelix() const;

	void fillFirstVector();
	void fillSecondVector();

	void sortCirclesByRadius();	
	double countSumOfRadii() const;
	
	void printSecondVector() const;
	void printPointsAndDerivatives() const;
private:
	std::vector<std::shared_ptr<Shape>> allShapes;
	std::vector<std::shared_ptr<Circle>> circleShapes;
};

