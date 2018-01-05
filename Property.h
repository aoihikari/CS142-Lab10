#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
//---------------------------------------------------------------------------------------
using namespace std;
//---------------------------------------------------------------------------------------
class Property
{
private:
	string address;
	string rental;
	string price;
	int id;
	static int next_id;
	
public:
	Property(string _address);
	virtual string to_string() ;
	void set_rental(string _rental) ;
	string get_rental(string _rental);
	string get_rental_num();
	void set_price(string _price) ; 
	double get_price();
	virtual double get_tax() = 0;
	int get_id() const;
	string get_address() const;
	~Property();
};
//---------------------------------------------------------------------------------------

