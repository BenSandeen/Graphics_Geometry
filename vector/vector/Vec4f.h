#ifndef VEC4F_H
#define VEC4F_H
#include <iostream>
#include "Matrix44f.h"

class Vec4f {
	friend std::ostream &operator<<( std::ostream &, const Vec4f& );
public:
	Vec4f( float, float, float, float = 1.0 );
	float length() const;
	float dot() const; // dot prod. with self
	Vec4f normalize();
	//float dot( Vec4f ) const; // dot prod. with other vector

	Vec4f& operator*( const Matrix44f& );

private:
	float x, y, z, w;
};
#endif