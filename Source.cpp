#include<iostream>

//Polymorphism: having many forms.
//Types:
//Compile Time (funtion/operator/constructor overloading)
//Run Time (function overiding)

//Operator Overloading: using functions to overload an operator
//Note: we can't overload conditional(?:), sizeof,
//scope(::), member selection(.) and member pointer selector(.*)

class Time {
	int m_hour;
	int m_min;
	int m_sec;
public:
	Time(int hour = 0, int min = 0, int sec = 0)
		: m_hour(hour), m_min(min), m_sec(sec){}

	//Copy Constructor
	Time(const Time &t)
		: m_hour(t.m_hour),m_min(t.m_min), m_sec(t.m_sec){}
	
	//[returntype] operator[symbol](arguments){ body}
	Time operator+(const Time& t) {
		Time sum;
		int carry=0;
		sum.m_sec = (this->m_sec + t.m_sec) % 60;
		carry = (this->m_sec + t.m_sec) / 60;
		sum.m_min = (this->m_min + t.m_min + carry) % 60;
		carry = (this->m_min + t.m_min) / 60;
		sum.m_hour = (this->m_hour + t.m_hour + carry);

		return sum;
	}

	//Binary Operator Overloading
	//Note: In case of no parameters, unary operator before
	void operator++() {
		int carry = 0;
		this->m_sec = (this->m_sec + 1) % 60;
		carry = (this->m_sec + 1) / 60;
		this->m_min = (this->m_min + 1) % 60;
		carry = (this->m_min + 1) / 60;
		this->m_hour = (this->m_min + 1);
	}

	//Overloading I/O operators
	friend std::ostream& operator<< (std::ostream& out, const Time& time);
};

std::ostream& operator<< (std::ostream& out, const Time &time) {
	out << time.m_hour << ":" << time.m_min << ":" << time.m_sec;
	return out;
}
int main() {
	Time midnight(12, 40, 10);
	Time morning(5, 30);
	Time total(midnight + morning);
	
	//Time total;
	//total = midnight + morning;
	
	std::cout << total;
}


