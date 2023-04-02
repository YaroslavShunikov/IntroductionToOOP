#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define delimiter "\n--------------------------------------------\n"
class Point
{
	double x;
	double y;
public:
	double get_x()const
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}
	// Constructors
	Point()
	{
		x = y = 0;
		cout << "Constructor:\t" << this << endl;
	}
	Point(double x)
	{
		this->x = x;
		y = 0;
		cout << "1ArgConstructor:" << this << endl;
	}
	Point(double x, double y)
	{
		this->x = x;
		this->y = y;
		cout << "Constructor:\t" << this << endl;
	}
	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyConstructor:" << this << endl;
	}
	~Point()
	{
		cout << "Destructor:\t" << this << endl;
	}

	// Operators:
	Point& operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAsignment:" << this << endl;
		return *this;
	}
	
	// Methods: 
	double distance(const Point& dot) const
	{
		double distance_X = this->x - dot.x;
		double distance_Y = this->y - dot.y;
		double distance = sqrt(distance_X * distance_X + distance_Y * distance_Y);  //Formula distance between two points
		return distance;
	}
	void print()
	{
		cout << "X = " << x << "\tY = " << y << endl;
	}
};

//#define STRUCT_POINT
//#define Distance_check
//#define CONSTRUCTORS_CHECK
//#define ASSIGNMENT_OPERATOR
double distance(const Point& A,const Point& B);


void main()
{
	setlocale(LC_ALL, "");
#ifdef STRUCT_POINT
	Point A;
	A.x = 2;
	A.y = 3;
	cout << A.x << "\t" << A.y << endl;

	Point* pA = &A;
	cout << pA->x << "\t" << pA->y << endl;
#endif
#ifdef Distance_check
	Point A;
	A.set_x(5);
	A.set_y(8);
	Point B;
	B.set_x(2);
	B.set_y(4);

	A.print();
	B.print();

	cout << delimiter << endl;
	cout << "Расстояние между точками А и В: " << A.distance(B) << endl;
	cout << delimiter << endl;
	cout << "Расстояние между точками А и В: " << distance(A, B) << endl;
	cout << delimiter << endl;

#endif 
#ifdef CONSTRUCTORS_CHECK

	Point A;    //Вызывается конструктор по умолчанию 
	A.print();

	Point B = 5;
	B.print();

	Point C(3, 5);
	C.print();

	Point D = C;    //Copy constructor
	D.print();

	Point E;        //Assignment operator
	E = D;
	E.print();
#endif 
#ifdef ASSIGNMENT_OPERATOR
	int a, b, c;
	a = b = c = 0;
	cout << a << "\t" << b << "\t" << c << endl;
	Point A, B, C;
	cout << delimiter << endl;
	A = B = C = Point(2, 3);
	cout << delimiter << endl;
	A.print();
	B.print();
	C.print();
#endif 


}

double distance(const Point& A,const Point& B)
{
	double Xdot = A.get_x() - B.get_x();
	double Ydot = A.get_y() - B.get_y();
	double distance = sqrt(Xdot * Xdot + Ydot * Ydot);
	return distance;
}