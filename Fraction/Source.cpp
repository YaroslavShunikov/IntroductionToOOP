#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;
#define delimiter "\n--------------------------------------------\n"

class Fraction
{
	int integer;
	int numerator;
	int denominator;

public:
	int get_integer()const
	{
		return integer;
	}
	int get_numerator()const
	{
		return numerator;
	}
	int get_denominator()const
	{
		return denominator;
	}
	void set_integer(int integer)
	{
		this->integer = integer;
	}
	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(int denominator)
	{
		this->denominator = denominator;
	}
	// Constructors
	Fraction()
	{
		integer = numerator=denominator = 0;

	}
	Fraction(int numerator,int denominator)
	{
		integer = 0;
		this->numerator = numerator;
		this->denominator = denominator;

	}
	Fraction(int integer,int numerator, int denominator)
	{
		this->integer = integer;
		this->numerator = numerator;
		this->denominator = denominator;

	}
	Fraction(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;

	}
	~Fraction()
	{
	
	}
	// Methods: 
	Fraction operator +(const Fraction& other) const      //not completed
	{
		return Fraction(integer + other.integer, numerator + other.numerator, denominator + other.denominator);
	}
	Fraction operator -(const Fraction& other) const   //not completed
	{
		return Fraction(integer - other.integer, numerator - other.numerator, denominator - other.denominator);
	}
	Fraction operator *(const Fraction& other) const
	{

		int numerator_mult = (this->integer * this->denominator + this->numerator)*(other.integer * other.denominator + other.numerator);
		int denominator_mult = this->denominator * other.denominator;
		return Fraction(0, numerator_mult, denominator_mult);
	}
	Fraction operator /(const Fraction& other) const
	{
		int numerator_div = (this->integer * this->denominator + this->numerator) * other.denominator;
		int denominator_div = (other.integer * other.denominator + other.numerator) * this->denominator;
		return Fraction(0, numerator_div, denominator_div);
	}

	void print()
	{
		if (numerator == 0 || denominator == 0)
		{
			return;
		}
		if (numerator < denominator)cout << integer << "(" << numerator << "/" << denominator << ")" << endl;
		if (numerator>denominator)
		{
			while (numerator > denominator)
			{
				numerator=numerator - denominator;
				integer++;
			}
			cout << integer << "(" << numerator << "/" << denominator << ")" << endl;
			
		}
		
		
	}
};

void main()
{
	Fraction A(5,4,10);
	Fraction B(7,13,4);
	A.print();
	B.print();
	Fraction C = A+B;
	C.print();
	Fraction D = A-B;
	D.print();
	Fraction E = A * B;
	E.print();
	Fraction F = A / B;
	F.print();
}