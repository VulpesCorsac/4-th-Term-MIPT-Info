namespace Math
{
    class Complex
    {
	float _x, _y;
    
	public:
	Complex();
	Complex(float x, float y);
	Complex add(Complex b);
	void add(Complex a, Complex b);
	
	void setReal(float x);
	void setImg(float y);
	float getReal();
	float getImg();
    };
}