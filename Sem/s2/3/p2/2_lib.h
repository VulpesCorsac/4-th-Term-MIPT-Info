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
    
    class Matrix22;
    
    class Vector2
    {
	float _x, _y;
	
	public:
	Vector2();
	Vector2(float x, float y);
	float getX();
	float getY();
		
	friend Vector2 operator * (Matrix22 a, Vector2 b);
    };
    
    class Matrix22
    {
	float _x1, _x2, _y1, _y2;
	
	public:
	Matrix22();
	Matrix22(float x1, float x2, float y1, float y2);
	
	friend Vector2 operator * (Matrix22 a, Vector2 b);
    };
}