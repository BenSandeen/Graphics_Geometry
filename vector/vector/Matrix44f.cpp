#include "Matrix44f.h"
#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

Matrix44f::Matrix44f() {
	// should change m from matrix of all 0.0 to identity matrix
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (i == j) {
				m[i][j] = 1.0;
			}
			else m[i][j] = 0.0;
		}
	}
}

Matrix44f::~Matrix44f() {
	
}

// these work, but are hideous.  We must instead overload `()` operator
const float Matrix44f::operator[]( array< int, 2 > indxs) const {
	const float elem = m[indxs[0]][indxs[1]];
	return elem;
}

float &Matrix44f::operator[]( array< int, 2 > indxs ) {
	return m[indxs[0]][indxs[1]];
}

const float Matrix44f::operator()( int i, int j ) const {
	const float elem = m[i][j];
	return elem;
}

float &Matrix44f::operator()( int i, int j ) {
	return m[i][j];
}

void Matrix44f::printMatrix() const {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cout << setw( 10 ) << m[i][j] << ",";
		}
		cout << endl;
	}
	cout << endl;
}

Matrix44f& Matrix44f::setTranslate( float translate[3] ) {
	//for (int i = 0; i < 4; i++) {
	//	for (int j = 0; j < 4; j++) {
	//		m[i][j] = matrix[i][j];
	//	}
	//}
	for (int i = 0; i < 3; i++) {
		m[i][3] = translate[i];
	}

	return *this;
}

Matrix44f& Matrix44f::setRotate( float rotate[4] ) {
	// rotate = { angle, x, y, z };
	float cosTheta = cos( rotate[0] );
	float sinTheta = sin( rotate[0] );
	m[0][0] = rotate[1] * rotate[1] * (1 - cosTheta) + cosTheta;
	m[0][1] = rotate[1] * rotate[2] * (1 - cosTheta) - rotate[3] * sinTheta;
	m[0][2] = rotate[1] * rotate[3] * (1 - cosTheta) + rotate[2] * sinTheta;
	m[0][3] = 0.0;
	m[1][0] = rotate[1] * rotate[2] * (1 - cosTheta) + rotate[3] * sinTheta;
	m[1][1] = rotate[2] * rotate[2] * (1 - cosTheta) + cosTheta;
	m[1][2] = rotate[2] * rotate[3] * (1 - cosTheta) - rotate[1] * cosTheta;
	m[1][3] = 0.0;
	m[2][0] = rotate[1] * rotate[3] * (1 - cosTheta) - rotate[2] * sinTheta;
	m[2][1] = rotate[2] * rotate[3] * (1 - cosTheta) + rotate[1] * sinTheta;
	m[2][2] = rotate[3] * rotate[3] * (1 - cosTheta) + cosTheta;
	m[2][3] = 0.0;
	m[3][0] = 0.0;
	m[3][1] = 0.0;
	m[3][2] = 0.0;
	m[3][3] = 1.0;
	return *this;
}

Matrix44f& Matrix44f::setScale( float scale[3] ) {
	for (int i = 0; i < 3; i++) {
		m[i][i] *= scale[i];
	}

	return *this;
}

//Matrix44f& Matrix44f::operator=(const Matrix44f& rhs) {
//	for (int i = 0; i < 4; i++) {
//		for (int j = 0; j < 4; j++) {
//			m[i][j] = rhs( i, j );
//		}
//	}
//	return *this;
//}

void Matrix44f::operator=(const Matrix44f &right) {
	int rowSize = 4;
	int columnSize = 4;
	for (int i = 0; i<rowSize; i++) {
		for (int j = 0; j<columnSize; j++)
			m[i][j] = right(i,j);
	}
}

Matrix44f& Matrix44f::operator*( const Matrix44f& rhs) {
	Matrix44f mat;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			mat(i,j) = m[i][0] * rhs( 0, j ) + // we must use `()` operator because
					  m[i][1] * rhs( 1, j ) + // `[]` can't be overloaded to take
					  m[i][2] * rhs( 2, j ) + // 2 arguments, and making it behave
					  m[i][3] * rhs( 3, j ); // like m[i][j] is too complicated to help
		}
	}

	// in order to have this modify the matrix in place (i.e.: `myMatrix * otherMatrix`
	// instead of `myMatrix = myMatrix * otherMatrix`), we have to use the `this` pointer
	// and the overloaded `=` operator; using `m = mat;` doesn't work, because `m` is a
	// simple 4x4 array, rather than a Matrix44f object like `mat` is
	*this = mat;
	return *this;
}


