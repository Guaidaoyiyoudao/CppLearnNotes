

class Complex
{
	
public:
	Complex(double r,double i):re{r},im{i}{}
	Complex(double r):re{r},im{0}{}		
	Complex():re{0},im{0}{}
	Complex& operator +=(const Complex& r)
	{
		this->re += r.re;
		this->im += r.im;
		return *this;
	}
	Complex& operator -=(const Complex& r)
	{
		this->re -= r.re;
		this->im -= r.im;
		return *this;
	}
	double real()const
	{
		return this->re;
	}

	double imag()const
	{
		return this->im;
	}
private:
	double re,im;

};

bool operator ==(Complex a,Complex b)
{
	return a.real()==b.real()&&a.imag()==b.imag();
}
bool operator !=(Complex a,Complex b)
{
	return !(a==b);
}

