#include <iostream>
#include "1_lib.h"

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
}