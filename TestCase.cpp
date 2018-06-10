
#include "TestCase.hpp"

using namespace std;

TestCase& TestCase::print(){
	my_cerr<<name<<": "<<fails<<" failed, "<<success<<" passed, "<<fails+success<<" total."<<endl;
	my_cerr<<"---"<<endl;
	return (*this);
}


