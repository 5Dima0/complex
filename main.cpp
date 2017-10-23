#include <iostream>
#include <sstream>

using namespace std;

struct complex_t {
	float real;
	float imag;
};

complex_t add( complex_t lhs, complex_t rhs ) {
    complex_t a;
	a.real = lhs.real+rhs.real;
	a.imag = lhs.imag+rhs.imag;
	return a;
}

complex_t sub( complex_t lhs, complex_t rhs ) {
    complex_t a;
	a.real = lhs.real+rhs.real;
	a.imag = lhs.real+rhs.imag;
	return a;
}

complex_t mul( complex_t lhs, complex_t rhs ) {
	complex_t a;
	a.real = lhs.real * rhs.real - lhs.imag * rhs.imag;
	a.imag = lhs.imag * rhs.real + lhs.real * rhs.imag;
	return a;
}

complex_t div( complex_t lhs, complex_t rhs ) {
	complex_t a;
	a.real = ( lhs.real * rhs.real + lhs.imag * rhs.imag ) / ( rhs.real * rhs.real + rhs.imag * rhs.imag );
	a.imag = ( lhs.imag * rhs.real - lhs.real * rhs.imag ) / ( rhs.real * rhs.real + rhs.imag * rhs.imag );
	return a;
}

bool write( ostream &stream, complex_t &lhs ) {
	cout << "(" << lhs.real << ", " << lhs.imag << ")"  ;
	return true;
}

bool read( istream &stream, complex_t &complex ) {
	char ch;
	if ( ( stream >> ch ) && ( ch == '(' ) && ( stream >> complex.real ) && ( stream >> ch ) && ( ch == ',' ) && ( stream >> complex.imag ) && ( stream >>ch) && ( ch == ')' ) ) {
		return true;
	}
	else {
	    cout<<"an error hasoccured while reading input data";
		return false;
	}
}
int main()
{
	complex_t lhs, rhs;
	string str;
	char oper;
	bool result = true;
	getline(cin, str);
	istringstream stream(str);
    if ( ( read( stream, lhs ) ) && ( stream >> oper ) && ( read( stream, rhs ) ) ) {
		if ( oper == '+' ) {
			lhs = add( lhs, rhs );
		}
		else if ( oper == '-' ) {
			lhs = sub( lhs, rhs );
		}
		else if ( oper == '*' ) {
			lhs = mul( lhs, rhs );
		}
		else if ( oper == '/' ) {
			
				lhs = div( lhs, rhs );
			}
		
		else {
			result = false;
		}
	}
	else {
		result = false;
	}

	if ( result == true ) {
		write( cout, lhs );
	}

}
