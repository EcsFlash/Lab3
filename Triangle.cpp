#include "Triangle.h"
#include "Angle.h"
#define PI 3.14159265
using namespace std;
#include <windows.h> 

const bool Triangle::validate(double a, double b, double c)
{
	if (a > 0 && b > 0 && c > 0) {
		if (a + b <= c || a + c <= b || b + c <= a) {
			return false;
		}
		else {
			return true;
		}
	}
	else {
		return false;
	}
}

Triangle::Triangle(double a, double b, double c)
{
	if (validate(a, b, c)) {
		this->a = a;
		this->b = b;
		this->c = c;
		int degree = acos(((a * a) + (b * b) - (c * c)) / (2 * a * b)) * 180.0 / PI;
		int minutes = 0;
		ab = Angle(degree, minutes);
		degree = acos(((a * a) + (c * c) - (b * b)) / (2 * a * c)) * 180.0 / PI;
		ac = Angle(degree, minutes);
		degree = acos(((b * b) + (c * c) - (a * a)) / (2 * b * c)) * 180.0 / PI;
		bc = Angle(degree, minutes);
	}
	else {
		throw invalid_argument("Invalid paramentrs! This is not triangle!!!");
	}
}

Triangle::Triangle(const Triangle& tr)
{
	a = tr.a;
	b = tr.b;
	c = tr.c;
	ab = tr.ab;
	ac = tr.ac;
	bc = tr.bc;
}

void Triangle::setA(double a)
{
	if (validate(a, b, c)) {
		this->a = a;
		int degree = acos(((a * a) + (b * b) - (c * c)) / (2 * a*b)) * 180.0 / PI;
		int minutes = 0;
		ab = Angle(degree, minutes );
		degree = acos(((a * a) + (c * c) - (b * b)) / (2 * a * c)) * 180.0 / PI;
		ac = Angle(degree, minutes);
		degree = acos(((b * b) + (c * c) - (a * a)) / (2 * b * c)) * 180.0 / PI;
		bc = Angle(degree, minutes);
	}
	else {
		throw invalid_argument("Invalid paramentrs! This is not triangle!!!");
	}
}

void Triangle::setB(double b)
{
	if (validate(a, b, c)) {
		this->b = b;
		int degree = acos(((a * a) + (b * b) - (c * c)) / (2 * a * b)) * 180.0 / PI;
		int minutes = 0;
		ab = Angle(degree, minutes);
		degree = acos(((a * a) + (c * c) - (b * b)) / (2 * a * c)) * 180.0 / PI;
		ac = Angle(degree, minutes);
		degree = acos(((b * b) + (c * c) - (a * a)) / (2 * b * c)) * 180.0 / PI;
		bc = Angle(degree, minutes);
	}
	else {
		throw invalid_argument("Invalid paramentrs! This is not triangle!!!");
	}
	
}

void Triangle::setC(double c)
{
	if (validate(a, b, c)) {
		this->c = c;
		int degree = acos(((a * a) + (b * b) - (c * c)) / (2 * a * b)) * 180.0 / PI;
		int minutes = 0;
		ab = Angle(degree, minutes);
		degree = acos(((a * a) + (c * c) - (b * b)) / (2 * a * c)) * 180.0 / PI;
		ac = Angle(degree, minutes);
		degree = acos(((b * b) + (c * c) - (a * a)) / (2 * b * c)) * 180.0 / PI;
		bc = Angle(degree, minutes);
	}
	else {
		throw invalid_argument("Invalid paramentrs! This is not triangle!!!");
	}
	
}

const double Triangle::getA()
{
	return a;
}

const double Triangle::getB()
{
	return b;
}

const double Triangle::getC()
{
	return c;
}

const Angle Triangle::getAC()
{
	return ac;
}

const Angle Triangle::getAB()
{
	return ab;
}

const Angle Triangle::getBC()
{
	return bc;
}

const double Triangle::square()
{
	double p = perimeter() / 2;

	return sqrt(p*(p-a)*(p-b)*(p-c));
}

const double Triangle::perimeter()
{
	return a+b+c;
}

const double Triangle::heightA()
{
	return square() / (0.5 * a);
}
const double Triangle::heightB()
{
	return square() / (0.5 * b);
}
const double Triangle::heightC()
{
	return square() / (0.5 * c);
}

const bool Triangle::isEuilateral()
{
	return a==b==c;
}

const bool Triangle::isIsosceles()
{
	if (a == b || a == c || b == c) {
		return true;
	}
	return false;
}

const bool Triangle::isRectangular()
{
	if (a * a + b * b == c * c || a * a + c * c == b * b || b * b + c * c == a * a) return true;
	return false;
}

Triangle& Triangle::operator=(const Triangle& tr)
{
	a = tr.a;
	b = tr.b;
	c = tr.c;
	ab = tr.ab;
	ac = tr.ac;
	bc = tr.bc;
	return *this;
	// TODO: insert return statement here
}

ostream& operator<<(ostream& os, Triangle const& tr)
{
	return os <<"A " << tr.a << "\t" << "B " << tr.b << "\t" << "C " << tr.c << "\n" << '\t' << "AB angle " << tr.ab << "\t" << "AC angle " << tr.ac << "\t" << "BC angle " << tr.bc;
}
