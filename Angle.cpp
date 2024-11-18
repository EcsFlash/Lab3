#include "Angle.h"
#include <iostream>
#define PI 3.14159265
constexpr float pi = 3.14;


Angle::Angle() {
	degree = new int(0);
	minutes = new int(0);
}
Angle::Angle(int degree, int minutes) {
	this->degree = new int(degree);
	this->minutes = new int(minutes);
}
//Angle::Angle(double a, double b, double c, double ab) {
//	degree = acos(((a * a) + (b * b) - (c * c)) / (2 * ab)) * 180.0 / PI;
//	cout << degree << endl;
//	minutes = 0;
//}
Angle::Angle(const Angle& a)
{
	degree = new int(*a.degree);
	minutes = new int(*a.minutes);
}
Angle::~Angle()
{
	delete degree;
	delete minutes;
	degree = minutes = nullptr;
}
double Angle::toRadians() {
	return  *degree * pi / 180 + *minutes / 3437.75;
}
Angle Angle::toRange() {
	return Angle(*degree - (int(*degree / 360) * 360), *minutes);
}
Angle Angle::operator+(const Angle& obj)
{
	return Angle(*degree+*obj.degree, *minutes + *obj.minutes);
}
Angle Angle::operator-(const Angle& obj)
{
	return Angle(*degree - *obj.degree, *minutes - *obj.minutes);
}
double Angle::sinus() {
	return sin(double(*degree + *minutes / 60));
}
const int Angle::compare(const Angle& angle2) {
	if (angle2.degree == degree) {
		if (angle2.minutes == minutes) {
			return 0;
		}
		else if (angle2.minutes < minutes) {
			return 1;
		}
		else {
			return -1;
		}
	}
	else if (angle2.degree < degree) {
		return 1;
	}
	else {
		return -1;
	}

}

Angle& Angle::operator=(const Angle& a)
{
	*degree = *a.degree;
	*minutes = *a.minutes;
	return *this;
	// TODO: insert return statement here
}

ostream& operator<<(std::ostream& os, Angle const& m)
{
	return os << *m.degree << "\t" << *m.minutes << endl;
}
