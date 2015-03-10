#include <iostream>
using namespace std;

class A{
public:
	A(int val):m_val(val) {
		cout << "A" << endl;
	}
	~A()
	{
		cout << "~A" << endl;
	}

	A(const A& other)
	{
		cout << "copy A" << endl;
		m_val = other.m_val;
	}

	A& operator=(const A& other)
	{
		if(this != &other){
			cout << "A operator=" << endl;
			m_val = other.m_val;
		}			

		return *this;
	}

private:
	int m_val;
};

class B : public A{
public:
	B(char c, int val)
		:A(val),m_char(c)
	{
		cout << "B" << endl;
	}

	~B()
	{
		cout << "~B" << endl;
	}

	B(const B& other)
		:A(other)
	{
		cout << "copy B" << endl;
		m_char = other.m_char;
	}

	B& operator=(const B& other)
	{
		cout << "B operator=" << endl;
		A::operator=(other);
		if(this != &other){
			m_char = other.m_char;
		}

		return *this;
	}

private:
	char m_char;
};

int main()
{
	B b1('c',1);
	B b2 = b1;
	b2 = b1;

	return 0;
}
