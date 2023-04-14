#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
class String;
String operator+(const String& left, const String& right);
class String
{
	int size;	
	char* str;
public:
	int get_size()const
	{
		return size;
	}
	const char* get_str()const
	{
		return str;
	}
	char* get_str()
	{
		return str;
	}
	void set_size(int size)
	{
		this->size = size;
	}
	void set_str(char* str) 
	{
		this->str = str;
	}
	
					//		Constructors:
	explicit String(int size=256)
	{
		this->size = size;
		this->str= new char[size]{};
		//cout << this << endl;
	}
	String(const char* str)
	{
		this->size = strlen(str)+1;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = str[i];
		//cout << this << endl;
	}
	String(const String& other)
	{
		//Deep Copy
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = other.str[i];
		//cout << this << endl;
	}
	String(String&& other)
	{
		//Shallow copy
		this->size = other.size;
		this->str = other.str;
		other.size = 0;
		other.str = nullptr;
		//cout << this << end;;
	}
	~String()
	{
		delete[]this->str;
	}
						//Operators:
	String& operator=(const String& other)
	{
		//Deep copy
		if (this == &other)return*this;
		delete[] this->str;  //удаление старой строки
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = other.str[i];
		cout << this << endl;
		return *this;
	}
	String& operator=(String&& other)
	{
		//Deep copy
		if (this == &other)return*this;
		delete[] this->str;  //удаление старой строки
		this->size = other.size;
		this->str = other.str;
		other.size = 0;
		other.str=nullptr;
		
	}
	String& operator+=(const String& other)
	{
		return *this = *this + other;
	}
	const char& operator[](int i)const
	{
		return str[i];
	}
	char& operator[](int i)
	{
		return str[i];
	}
						//Methods:
	void print()const
	{
		cout << "Size:\t"<<size << endl;
		cout << "Str:\t" <<str<< endl;
	}
};

String operator+(const String& left, const String& right)
{
	String cat(left.get_size() + right.get_size() - 1);
	for (int i = 0; i < left.get_size(); i++)
	{
		cat[i] = left[i];
	}
	for (int i = 0; i < right.get_size(); i++)
	{
		cat[i+left.get_size()-1] = right[i];
	}
	return cat;
}
std::ostream& operator <<(std::ostream& os, const String& obj)
{
	return os << obj.get_str();
}

void main()
{
	setlocale(LC_ALL, "");

	String str1 = "Hello";
	String str2 = "World";
	//String str3 = str1+str2;  //Move constructor
	String str3;
	str3 = str1 + str2; //Move assignment 
	cout << str1 << "+" << str2 << "=" << str3 << endl;
	str1 += str2;
	str3.print();
	String str4;
	
}