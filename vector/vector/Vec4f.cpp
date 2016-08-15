#include <math.h>
#include <iostream>
#include "Vec4f.h"
#include <iomanip>
using namespace std;

ostream &operator<<( ostream &output, const Vec4f &vector ) {
	output << vector.x << ", " << vector.y << ", " << vector.z << ", " << vector.w << endl;
	return output;
}

Vec4f::Vec4f(float a, float b, float c, float d)
	: x(a), y(b), z(c), w(d)
{
	cout << "x = " << x << endl;
	cout << "y = " << y << endl;
	cout << "z = " << z << endl;
	cout << "w = " << w << endl;
}

float Vec4f::length() const {
	return sqrt( this->dot() );
}

float Vec4f::dot() const {
	return (x*x + y*y + z*z);
}

Vec4f Vec4f::normalize() {
	float len = this->length();
	this->x /= len;
	this->y /= len;
	this->z /= len;

	return *this;
}