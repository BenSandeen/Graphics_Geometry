//#include <stdint.h>
//#include <iostream>
//using namespace std;
//
//template<typename T>
//class Matrix44 {
//public:
//	Matrix44() {}
//	const T* operator [] ( uint8_t i ) const { return m[i]; }
//	T* operator [] ( uint8_t i ) { return m[i]; }
//	// initialize the coefficients of the matrix with the coefficients of the identity matrix
//	T m[4][4] = { { 1, 0, 0, 0 }, { 0, 1, 0, 0 }, { 0, 0, 1, 0 }, { 0, 0, 0, 1 } };
//};
//
//typedef Matrix44<float> Matrix44F;
//
//int main()
//{
//	Matrix44F mat;
//	cout << mat[5] << endl;
//	int psd;
//	cin >> psd;
//}