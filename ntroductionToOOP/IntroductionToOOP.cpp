#include<iostream>
using namespace std;
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
	double distance(const Point& axis) const
	{
		double distance_X = this->x - axis.x;
		double distance_Y = this->y - axis.y;
		double distance = sqrt(distance_X * distance_X + distance_Y * distance_Y);  //Formula distance between two points
		return distance;
	}
};

double distance(const Point& A, Point& B);

//#define STRUCT_POINT

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

	Point A;
	A.set_x(5);
	A.set_y(8);
	Point B;
	B.set_x(2);
	B.set_y(4);
	cout << A.get_x() << "\t" << A.get_y() << endl;
	cout << B.get_x() << "\t" << B.get_y() << endl;

	cout << "Расстояние от точки А до точки В: " << A.distance(B) << endl;
	cout << "Расстояние между точками А и В: " << distance(A, B) << endl;

}

double distance(const Point& A, Point& B)
{
	double Xaxis = A.get_x() - B.get_x();
	double Yaxis = A.get_y() - B.get_y();
	double distance = sqrt(Xaxis * Xaxis + Yaxis * Yaxis);
	return distance;
}