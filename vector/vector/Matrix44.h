// doesn't work, because you can't split a templated class into .h and .cpp files

//#ifndef MATRIX44_H
//#define MATRIX44_H
//
//template< typename T >
//class Matrix44 {
//public:
//	Matrix44();
//	const T* operator [] ( unsigned int i ) const;
//
//private:
//	T m[4][4] = { { 1, 0, 0, 0 }, { 0, 1, 0, 0 }, { 0, 0, 1, 0 }, { 0, 0, 0, 1 } };
//};
//#endif