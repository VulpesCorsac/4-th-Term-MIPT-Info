namespace Math
{
    class Complex
    {
	float _x, _y;
    
	public:
	Complex();
	Complex(float x, float y);
	Complex operator +(Complex b);
	Complex operator -(Complex b);
	float operator *(Complex b);
	bool operator ==(Complex b);
	void operator =(float b);
	
	void setReal(float x);
	void setImg(float y);
	float getReal();
	float getImg();
    };
}