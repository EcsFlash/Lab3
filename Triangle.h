#pragma once
#include "Angle.h"


class Triangle {
	double a, b, c;
	Angle ab, bc, ac;
	const bool validate(double a, double b, double c);

public:
	Triangle(double a, double b, double c);
	void setA(double a);
	void setB(double b);
	void setC(double c);
	const double getA();
	const double getB();
	const double getC();
	const Angle getAC();
	const Angle getAB();
	const Angle getBC();
	//геты для углов
	const double square();
	const double perimeter();
	const double heightA();
	const double heightB();
	const double heightC();
	const bool isEuilateral();
	const bool isIsosceles();
	const bool isRectangular();
	Triangle(const Triangle& tr);
	Triangle& operator=(const Triangle& tr);
	friend ostream& operator<<(ostream& os, Triangle const& tr);
};