#include <stdint.h>
#ifndef MATRIX44F_H
#define MATRIX44F_H
#include <array>

class Matrix44f {
public:
	explicit Matrix44f();
	~Matrix44f();
	// overload accessor so we can, for example, use m[15] instead of
	// m[4][4] to access matrix elements
	const float operator[]( std::array< int, 2 > poop ) const;
	float &operator[]( std::array< int, 2 > poop );
	const float operator()( int, int ) const;
	float &operator()( int, int );
	Matrix44f& operator*(const Matrix44f& rhs);
	//Matrix44f operator * ( Matrix44f rhs) const;
	//Matrix44f& operator=(const Matrix44f& rhs);
	//const Matrix44f& operator=(const Matrix44f &right);
	void operator=(const Matrix44f &right);

	void printMatrix() const;
	Matrix44f& setTranslate( float translate[3] );
	Matrix44f& setRotate( float rotate[4] );
	Matrix44f& setScale( float scale[3] );

private:
	float m[4][4];// = { { 1, 0, 0, 0 }, { 0, 1, 0, 0 }, { 0, 0, 1, 0 }, { 0, 0, 0, 1 } };//{ { 0 } };
};

#endif