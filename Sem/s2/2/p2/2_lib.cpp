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
	_x = x;
	_y = y;
    }
    
    Complex Complex::operator +(Complex b)
    {
	return Complex(_x + b.getReal(), _y + b.getImg());
    }
    
    Complex Complex::operator -(Complex b)
    {
	return Complex(_x - b.getReal(), _y - b.getImg());
    }
    
    float Complex::operator *(Complex b)
    {
	return _x * b.getReal() - _y * b.getImg();
    }
    
    bool Complex::operator ==(Complex b)
    {
	return (_x == b.getReal()) && (_y == b.getImg());
    }
    
    void Complex::setReal(float x)
    {
	_x = x;
    }
    
    void Complex::setImg(float y)
    {
	_y = y;
    }
    
    float Complex::getReal()
    {
	return _x;
    }
    
    float Complex::getImg()
    {
	return _y;
    }
}