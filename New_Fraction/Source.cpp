#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#define delimiter "\n--------------------------------------------\n"
class Fraction;
Fraction operator*(Fraction left, Fraction right);
Fraction operator/(const Fraction& left, const Fraction& right);

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
		if (denominator == 0)denominator = 1;
		this->denominator = denominator;
	}

																//				Constructors:
	Fraction()
	{
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
		//cout << "DefaultConstructor:\t" << this << endl;
	}
	explicit Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		//cout << "1ArgConstructor:\t" << this << endl;
	}
	Fraction(double decimal)
	{
		decimal += 1e-10;       //-0.000 000 000 1
		integer = decimal;		//получаем целую часть дробного числа
		decimal -= integer;     //убираем целую часть из дробного числа
		denominator=1e+9;       //1 000 000 000
		numerator = decimal * denominator;
		reduce();

	}
	Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		set_denominator(denominator);
		//cout << "Constructor:\t\t" << this << endl;
	}
	Fraction(int integer, int numerator, int denominator)
	{
		this->integer = integer;
		this->numerator = numerator;
		this->set_denominator(denominator);
		//cout << "Constructor:\t\t" << this << endl;
	}
	Fraction(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		//cout << "CopyConstructor:\t" << this << endl;
	}
	~Fraction()
	{
		//cout << "Destructor:\t\t" << this << endl;
	}

																	//				Operator:
	Fraction& operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		//cout << "CopyAssignment:\t\t" << this << endl;
		return *this;
	}
	Fraction& operator*=(const Fraction& other)
	{
		int a = 2;
		return *this = *this*other;
	}
	Fraction& operator/=(const Fraction& other)
	{
		return *this = *this / other;
	}
													//    Increment/Decrement
	Fraction& operator++()
	{
		integer++;    //Prifex
		return *this;
	}
	Fraction& operator++(int)
	{
		Fraction old = *this;
		integer++;
		return old;
	}
	Fraction& operator--()
	{
		integer--;
		return *this;
	}
	Fraction& operator--(int)
	{
		Fraction old = *this;
		integer--;
		return old;
	}
													//      Type-cast operato
	operator int()
	{
		return integer;
	}
	operator double()
	{
		return integer + (double)numerator/denominator;
	}
													//		Methods:
	Fraction& to_improper()
	{
		numerator += integer * denominator;
		integer = 0;
		return *this;
	}
	Fraction& to_proper()
	{
		integer += numerator / denominator;
		numerator %= denominator;
		return *this;
	}
	Fraction inverted()const
	{
		Fraction inverted = *this;
		inverted.to_improper();
		inverted.numerator ^= inverted.denominator;
		inverted.denominator ^= inverted.numerator;
		inverted.numerator ^= inverted.denominator;
		return inverted;
	}
	Fraction& reduce()
	{
		to_proper();
		int more, less, rest;
		if (numerator > denominator)
		{
			more = numerator;
			less = denominator;
		}
		else
		{
			more = denominator;
			less = numerator;
		}
		do 
		{
			rest = more % less;
			more = less;
			less = rest;
		} while (rest);
		int GCD = more; //GCD- Greatest Common Division
		numerator /= GCD;
		denominator /= GCD;
		return *this;
	}
	void print()const
	{
		if (integer)cout << integer;
		if (numerator)
		{
			if (integer)cout << "(";
			cout << numerator << "/" << denominator;
			if (integer)cout << ")";
		}
		else if (integer == 0)cout << 0;
		cout << endl;
	}
};

Fraction operator*(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	/*Fraction product;
	product.set_numerator(left.get_numerator()*right.get_numerator());
	product.set_denominator(left.get_denominator()*right.get_denominator());*/
	/*Fraction product
	(
		left.get_numerator()*right.get_numerator(),
		left.get_denominator()*right.get_denominator()
	);
	product.to_proper();
	return product;*/
	return Fraction
	(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	).to_proper().reduce();
}
Fraction operator/(const Fraction& left, const Fraction& right)
{
	/*left.to_improper();
	right.to_improper();
	return Fraction
	(
		left.get_numerator()*right.get_denominator(),
		right.get_numerator()*left.get_denominator()
	).to_proper();*/
	return left * right.inverted().reduce();;
}

bool operator==(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return(left.get_numerator() * right.get_denominator() == right.get_numerator() * left.get_denominator());
	/*if (left.get_numerator() * right.get_denominator() == right.get_numerator() * left.get_denominator())
		return true;
	else
		return false;*/
}
bool operator !=(Fraction left, Fraction right)
{
	return!(left == right);
}
bool operator>(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return (left.get_numerator() * right.get_denominator() > right.get_numerator() * left.get_denominator());
}
bool operator<(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return (left.get_numerator() * right.get_denominator() < right.get_numerator() * left.get_denominator());
}
bool operator>=(const Fraction& left, const Fraction& right)
{
	return!(left < right);
	//return left > right || left == right;
}
bool operator<=(const Fraction& left, const Fraction& right)
{
	return!(left > right);
	//return left < right || left == right;
}
std::ostream& operator<<(std::ostream& os, const Fraction&obj)
{
	if (obj.get_integer())os << obj.get_integer();
	if (obj.get_numerator())
	{
		if (obj.get_integer())os << "(";
		cout << obj.get_numerator() << "/" << obj.get_denominator();
		if (obj.get_integer())os << ")";
	}
	else if (obj.get_integer() == 0)os << 0;
	return os;
}
std::istream& operator>>(std::istream& is, Fraction& obj)
{
	const int SIZE = 256;
	char buffer[SIZE] = {};
	//is >> buffer;
	is.getline(buffer, SIZE);   //сохраняем введённое в буффер в типе char
	int number[3] = {};			//здесь будут храниться числа, введённые с клавиатуры 
	int n = 0;					//счётчик чисел
	const char delimiters[] = "( /)"; //строка разделителей 
	for (char* pch = strtok(buffer, delimiters); pch; pch = strtok(NULL, delimiters))   //(strtok)
	{
		//указатель 'pch' хранит адрес начала токена
		//в ф-ю strtok() только первый раз передаётся делимая строка, при всех последующих вызовах, на место делимой строки нужно передавать 'NULL', это показывает ф-ии strtok() что она работает с ранее переданной строкой.
		//Если делимую строку передать ещё раз, то strtok() начнёт обрабатывать её сначала 
		number[n++] = atoi(pch);
		//atoi()-ASCII-string to Integer(преобразует строку в значение типа int)
	}
	obj = Fraction();
	switch (n)
	{
	case 1: 
	obj.set_integer(number[0]); break;
	case 2: 
	obj.set_numerator(number[0]); 
	obj.set_denominator(number[1]); break;
	case 3: 
	obj.set_integer(number[0]); 
	obj.set_numerator(number[1]); 
	obj.set_denominator(number[2]); break;
	}
	return is;
}

//#define CONSTRUCTORS_CHECK
//#define Arithmetical_operators_check
//#define ISTREAM_OPERATOR_CHECK
//#define CONVERSION_FROM_OTHER_TO_CLASS
//#define CONVERSION_FROM_CLASS_TO_OTHER

void main()
{
	setlocale(LC_ALL, "");

#ifdef CONSTRUCTORS_CHECK
	Fraction A;
	A.print();

	Fraction B = 3;
	B.print();

	Fraction C(1, 2);
	C.print();

	Fraction D(2, 3, 4);
	D.print();

	Fraction E = D;
	E.print();

	A = E;
	A.print();
#endif 
#ifdef Arithmetical_operators_check

	Fraction A(2, 3, 4);
	A.print();

	Fraction B(3, 4, 5);
	B.print();

	double a = 2.5;
	double b = 3.14;
	double c = a * b;

	Fraction C = A * B;
	C.print();

	Fraction D = A / B;
	D.print();

	A *= B;
	A.print();
	A /= B;
	A.print();
	cout << delimiter << endl;
	for (Fraction i(3, 4); i.get_integer() < 10; i++)
	{
		i.print();
	}
#endif 
#ifdef ISTREAM_OPERATOR_CHECK
	cout << (Fraction(1, 2) == Fraction(5, 10)) << endl;
	cout << (Fraction(1, 2) != Fraction(5, 10)) << endl;
	cout << (Fraction(1, 2) > Fraction(5, 11)) << endl;
	cout << (Fraction(1, 2) < Fraction(5, 11)) << endl;
	cout << (Fraction(1, 2) >= Fraction(5, 10)) << endl;
	cout << (Fraction(1, 3) <= Fraction(5, 10)) << endl;
	Fraction A(123, 32, 45);
	cout << "Введите простую дробь: "; cin >> A;
	cout << A << endl;
#endif 
#ifdef CONVERSION_FROM_OTHER_TO_CLASS
	Fraction A = (Fraction)5;
	cout << A << endl;
	Fraction B;
	B = Fraction(8);       //conversion from other to class
	cout << B << endl;

#endif 
	Fraction A(2, 3, 4);
	A = 22.56;
	cout << A << endl;

	int a = A;
	cout << a << endl;

	double b = A;
	cout << b << endl;

}