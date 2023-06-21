#define _USE_MATH_DEFINES
#include "Test.hpp"
#include <random>
#include <cmath>
#include <iostream>

const double T = M_PI / 4;
const int32_t vectorSize = 15;
const int32_t minRadius = 1;
const int32_t maxRadius = 100;
const int32_t minStep = -5;
const int32_t maxStep = 5;

void Test::test()
{
	cout << "T = " << T / M_PI << "*PI" << endl;
	cout << "_________________________" << endl;

	//Task 2
	fillFirstVector();
	//Task 3
	cout << "First container:" << endl;
	printPointsAndDerivatives();
	//Task 4
	fillSecondVector();
	cout << "_________________________" << endl;
	cout << "Second container:" << endl;
	printSecondVector();
	//Task 5
	sortCirclesByRadius();
	cout << "_________________________" << endl;
	cout << "Second container after sorting:" << endl;
	printSecondVector();
	//Task 6
	cout << "_________________________" << endl;
	cout << "Sum of radii is: " << countSumOfRadii();
}

int32_t Test::generateRandomNumber (int32_t from, int32_t to) const {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(from, to);
	return dist(rd);
}

double Test::generateRandomRadius() const {
	return generateRandomNumber(minRadius, maxRadius);
}

double Test::generateRandomStep() const {
	return generateRandomNumber(minStep, maxStep);
}

std::shared_ptr<Shape> Test::generateRandomShape() const
{
	switch (generateRandomNumber(1,3)) {
	case 1:
		return generateRandomEllipse();
		break;
	case 2:
		return generateRandomCircle();
		break;
	case 3:
		return generateRandomHelix();
		break;
	}
}

std::shared_ptr<Shape> Test::generateRandomEllipse() const {
	return std::make_shared<Ellipse>(Ellipse(generateRandomRadius(), generateRandomRadius()));
}

std::shared_ptr<Shape> Test::generateRandomCircle() const {
	return std::make_shared<Circle>(Circle(generateRandomRadius()));
}

std::shared_ptr<Shape> Test::generateRandomHelix() const {
	return std::make_shared<Helix>(Helix(generateRandomRadius(), generateRandomStep()));
}

void Test::fillFirstVector() {
	for (int32_t i = 0; i < vectorSize; ++i) {
		allShapes.push_back(generateRandomShape());
	}
}

void Test::fillSecondVector() {
	for (auto& shape : allShapes) {
		if (typeid(*shape) == typeid(Circle)) {
			circleShapes.push_back(dynamic_pointer_cast<Circle>(shape));
		}
	}
}

void Test::sortCirclesByRadius() {
	std::sort(circleShapes.begin(), circleShapes.end(),
		[](shared_ptr<Circle> const& a, shared_ptr<Circle> const& b) { return a->getRadius() < b->getRadius(); });
}

double Test::countSumOfRadii() const {
	double totalSumOfRadii = 0.0;
	for (auto& shape : circleShapes) {
		totalSumOfRadii += shape->getRadius();
	}
	return totalSumOfRadii;
}

void Test::printPointsAndDerivatives() const {
	for (auto& shape : allShapes) {
		cout << typeid(*shape).name() << endl
			<< "Point: " << shape->getPoint(T) << endl
			<< "Derivative: " << shape->getDerivative(T) << endl;
	}
}

void Test::printSecondVector() const {
	for (auto& shape : circleShapes) {
		cout << typeid(*shape).name() << " with radius " << shape->getRadius() << endl;
	}
}