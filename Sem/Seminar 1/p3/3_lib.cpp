#include <iostream>
#include "3_lib.h"

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
    
    Complex Complex::operator +(Complex b)
    {
	return Complex(this->_x + b.getReal(), this->_y + b.getImg());
    }
    
    Complex Complex::operator -(Complex b)
    {
	return Complex(this->_x - b.getReal(), this->_y - b.getImg());
    }
    
    float Complex::operator *(Complex b)
    {
	return this->_x * b.getReal() - this->_y * b.getImg();
    }
    
    bool Complex::operator ==(Complex b)
    {
	return (this->_x == b.getReal()) && (this->_y == b.getImg());
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