//explicit_specialization1.cpp
#include <iostream>
using namespace std;

//Template class declaration and definition
template<typename T> 
class Formatter
{
public:
	Formatter(T* t) 
		:m_t(t)
		{
			
		}
	void print()
	{
		cout << *m_t << endl;
	}
private:
	T *m_t;
};

//Specialization of template class for type char *
template<> class Formatter<char*>
{
public:
	Formatter(char **t) : m_t(t) {}
	void print()
	{
		cout << "char value: " << **m_t << endl;
	}
private:
	char **m_t;
};

int main()
{
    int i = 157;
    // Use the generic template with int as the argument.
    Formatter<int> formatter1(&i);

    char str[10] = "string1";
    char* str1 = str;
    // Use the specialized template.
    Formatter<char*> formatter2(&str1);

    formatter1.print(); // 157
    formatter2.print(); // Char value : s
}

