namespace Math
{
    class Complex
    {
	float _x, _y;
    
	public:
	Complex();
	Complex(float x, float y);
	friend Complex operator +(Complex a, Complex b);
	friend Complex operator -(Complex a, Complex b);
	friend float operator *(Complex a, Complex b);
	friend bool operator ==(Complex a, Complex b);
	void operator =(float b);
	
	void setReal(float x);
	void setImg(float y);
	float getReal();
	float getImg();
    };
}