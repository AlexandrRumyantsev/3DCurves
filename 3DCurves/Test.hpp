#pragma once
#include "Curves.hpp"
#include <vector>
using namespace std;
class Test
{
public:
	void test();
private:
	int32_t generateRandomNumber(int32_t, int32_t) const;
	double generateRandomRadius() const;
	double generateRandomStep() const;
		
	shared_ptr<Shape> generateRandomShape() const;
	inline shared_ptr<Shape> generateRandomEllipse() const;
	inline shared_ptr<Shape> generateRandomCircle() const;
	inline shared_ptr<Shape> generateRandomHelix() const;

	void fillFirstVector();
	void fillSecondVector();

	void sortCirclesByRadius();	
	double countSumOfRadii() const;
	
	void printSecondVector() const;
	void printPointsAndDerivatives() const;
private:
	vector<shared_ptr<Shape>> allShapes;
	vector<shared_ptr<Circle>> circleShapes;
};

