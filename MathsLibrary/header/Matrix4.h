#pragma once
#include "Vector4.h"
#include "dllmain.h"

/*
* Matrix4T
* template class
* 4x4 matrix structure
*
* author: Bradley Booth, Academy of Interactive Entertainment, 2017
*/
TEMPLATE
class Matrix4T
{
public:

	Vector4T<T> mat[4]; //rows of numbers

	/*
	* Matrix4T()
	* default constructor
	* fills matrix with zeroes
	*/
	MATHSLIBRARY_API Matrix4T();

	/*
	* Matrix4T()
	* argument constructor
	*
	* @param T - the 1st element of the 1st column
	* @param T - the 2nd element of the 1st column
	* @param T - the 3rd element of the 1st column
	* @param T - the 4th element of the 1st column
	*
	* @param T - the 1st element of the 2nd column
	* @param T - the 2nd element of the 2nd column
	* @param T - the 3rd element of the 2nd column
	* @param T - the 4th element of the 2nd column
	*
	* @param T - the 1st element of the 3rd column
	* @param T - the 2nd element of the 3rd column
	* @param T - the 3rd element of the 3rd column
	* @param T - the 4th element of the 3rd column
	*
	* @param T - the 1st element of the 4th column
	* @param T - the 2nd element of the 4th column
	* @param T - the 3rd element of the 4th column
	* @param T - the 4th element of the 4th column
	*/
	MATHSLIBRARY_API Matrix4T(T m11, T m12, T m13, T m14,
			T m21, T m22, T m23, T m24,
			T m31, T m32, T m33, T m34,
			T m41, T m42, T m43, T m44);
	/*
	* Matrix4T()
	* default destructor
	*/
	MATHSLIBRARY_API ~Matrix4T() {};

	/*
	* operator[]
	* subscript overload
	*
	* @param const int - the axis to access
	* @returns Vector4T& - the axis accessed
	*/
	MATHSLIBRARY_API Vector4T<T>& operator[](const int index);

	/*
	* operator T *
	* cast to T pointer overload
	*
	* @returns T * - the address of the first item in the matrix
	*/
	MATHSLIBRARY_API operator T *();

	/*
	* operator*
	* applys matrix multiplication to two Matrix4Ts
	*
	* @param const Matrix4T - the other matrix to use
	* @returns Matrix4T - the product of the matrices
	*/
	MATHSLIBRARY_API Matrix4T<T> operator*(const Matrix4T<T> other);

	/*
	* identity
	* converts the matrix to an identity matrix
	* 1 0 0...
	* 0 1 0...
	* 0 0 1...
	* . . .
	* . . .
	*
	* @returns void
	*/
	MATHSLIBRARY_API void identity();

	/*
	* setRotateX
	* generates a 3D homogeneous rotation matrix around the X axis given the amount of rotation in radians
	* https://en.wikipedia.org/wiki/Rotation_matrix
	*
	* @param T - the amount of radians the matrix will represent
	* @returns void
	*/
	MATHSLIBRARY_API void setRotateX(T radians);

	/*
	* setRotateY
	* generates a 3D homogeneous rotation matrix around the Y axis given the amount of rotation in radians
	* https://en.wikipedia.org/wiki/Rotation_matrix
	*
	* @param T - the amount of radians the matrix will represent
	* @returns void
	*/
	MATHSLIBRARY_API void setRotateY(T radians);

	/*
	* setRotateZ
	* generates a 3D homogeneous rotation matrix around the Z axis given the amount of rotation in radians
	* https://en.wikipedia.org/wiki/Rotation_matrix
	*
	* @param T - the amount of radians the matrix will represent
	* @returns void
	*/
	MATHSLIBRARY_API void setRotateZ(T radians);

	/*
	* determinant
	* calcualates the determinant of the matrix
	*
	* this process is massive for a 4x4 matrix, so
	* the calculation is broken down into 4 3x3 matrix determinants
	*
	* @returns T - the determinant of the matrix
	*/
	MATHSLIBRARY_API T determinant();

	/*
	* determinant
	* calcualates the determinant of the matrix
	*
	* this process is massive for a 4x4 matrix, so
	* the calculation is broken down into 4 3x3 matrix determinants
	*
	* @returns T - the determinant of the matrix
	*/
	T determinant();

	/*
	* invert
	* inverts the matrix
	* sometimes matrices aren't invertible
	*
	* @returns bool - indicating if the inversion worked or not
	*/
	bool invert();
};

using Matrix4 = Matrix4T<float>;