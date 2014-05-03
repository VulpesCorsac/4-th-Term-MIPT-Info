#include <iostream>
#include "2_lib.h"

namespace Math
{
    Complex::Complex()
    {
	Complex(0, 0);
    }
    
    Complex::Complex(float x, float y)
    {
	this->_x = x;
	this->_y = y;
    }
    
    Complex operator +(Complex a, Complex b)
    {
	return Complex(a._x + b._x, b._y + b._x);
    }
    
    Complex operator -(Complex a, Complex b)
    {
	return Complex(a._x - b._x, a._y - b._y);
    }
    
    float operator *(Complex a, Complex b)
    {
	return a._x * b._x - a._y * b._y;
    }
    
    bool operator ==(Complex a, Complex b)
    {
	return (a._x == b._x) && (a._y == b._y);
    }
    
    void Complex::operator =(float b)
    {
	this->_x = b;
	this->_y = 0;
    }
    
    void Complex::setReal(float x)
    {
	this->_x = x;
    }
    
    void Complex::setImg(float y)
    {
	this->_y = y;
    }
    
    float Complex::getReal()
    {
	return this->_x;
    }
    
    float Complex::getImg()
    {
	return this->_y;
    }
    
    Vector2::Vector2()
    {
	Vector2(0, 0);
    }
    
    Vector2::Vector2(float x, float y)
    {
	_x = x;
	_y = y;
    }
    
    float Vector2::getX()
    {
	return _x;
    }
    
    float Vector2::getY()
    {
	return _y;
    }
    
    Matrix22::Matrix22()
    {
	Matrix22(0, 0, 0, 0);
    }
    
    Matrix22::Matrix22(float x1, float x2, float y1, float y2)
    {
	_x1 = x1;
	_x2 = x2;
	_y1 = y1;
	_y2 = y2;
    }
    
    Vector2 operator * (Matrix22 a, Vector2 b)
    {
	return Vector2(a._x1 * b._x + a._y1 * b._y, a._x2 * b._x + a._y2 * b._y);
    }
}