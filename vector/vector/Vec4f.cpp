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

Vec4f& Vec4f::operator*(const Matrix44f& matrix) {
	this->x = x * matrix( 0, 0 ) + y * matrix( 1, 0 ) + z * matrix( 2, 0 ) + w * matrix( 3, 0 );
	this->y = x * matrix( 0, 1 ) + y * matrix( 1, 1 ) + z * matrix( 2, 1 ) + w * matrix( 3, 1 );
	this->z = x * matrix( 0, 2 ) + y * matrix( 1, 2 ) + z * matrix( 2, 2 ) + w * matrix( 3, 2 );
	this->w = x * matrix( 0, 3 ) + y * matrix( 1, 3 ) + z * matrix( 2, 3 ) + w * matrix( 3, 3 );

	return *this;
}
