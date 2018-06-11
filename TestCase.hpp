#pragma once
#include <iostream>
#include <sstream>
#include <string>
using namespace std;


class TestCase{
 	int fails=0;
	int success=0;
	ostream& my_cerr;
	string name;
	public:
	
		TestCase(string s, ostream& c):my_cerr(c){
			name=s;
		}
		
		TestCase& print();


		template <typename T> TestCase& check_equal(T r1,T r2){
			if(r1==r2)
				success++;
			else{
				fails++;
				my_cerr<<name<<":Failureintest#"<< fails+success<<""<<r1<<"shouldequal"<<r2<<"!"<<endl;
			}		
			return (*this);
		}

		template <typename T>  TestCase& check_different(T r1,T r2){
			if(r1!=r2)
				success++;
			else{
				fails++;
				my_cerr<<name<<":Failureintest#"<< fails+success<<""<<r1<<"isequal"<<r2<<"!"<<endl;
			}		
			return (*this);
			
		}

		template <typename T> TestCase& check_output(T r, string s){
			stringstream buf;
			buf<<r;
			if(buf.str().compare(s)==0)
				success++;
			else{
				fails++;
				my_cerr<<name<<":Failureintest#"<< fails+success<<"stringvalueshouldbe "<<s<<"butis"<<buf.str()<<endl;
			}		
			return (*this);
		}

		
		template <typename T1,typename T2,typename Fun> TestCase& check_function(Fun f, T1 input, T2 output){
			if((*f)(input)==output)
				success++;
			else{
				fails++;
				my_cerr<<name<<":Failureintest#"<< fails+success<<"Functionshouldreturn"<<output<<"butreturned"<<(*f)(input)<<"!"<<endl;
			}		
			return (*this);
			
		}
		
};
