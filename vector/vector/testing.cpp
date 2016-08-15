#include "Vec4f.h"
#include <iostream>
#include "Matrix44f.h"
using namespace std;

int main() {
	Vec4f myVec = { 1.0, 2.0, 3.0, 1.0 };
	cout << "length: " << myVec.length() << endl;
	cout << "normalized vector: " << myVec.normalize() << endl;
	
	Matrix44f mat;

	mat.printMatrix();
	float transScale[3] = { 1, 2, 3 };
	float rotator[4] = { 33, 7, 3, 2 };
	cout << mat(0,0) << endl;
	mat.setTranslate( transScale );
	mat.printMatrix();
	mat.setScale( transScale );
	mat.printMatrix();
	mat.setRotate( rotator );
	mat.printMatrix();
	(mat * mat).printMatrix();
	mat.printMatrix();

	Vec4f newVec = { 0, 1, 0 };
	float simpleRotator[4] = { 90, 1, 0, 0 };
	Matrix44f newMat;
	newMat.setRotate( simpleRotator );
	cout << "normalized vector: " << newVec.normalize() << endl;
	newVec * newMat;
	cout << "normalized vector: " << newVec.normalize() << endl;

	int input;
	cin >> input;
}