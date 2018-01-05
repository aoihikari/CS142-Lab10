#include "Property.h"
//---------------------------------------------------------------------------------------
int Property::next_id;
//---------------------------------------------------------------------------------------
Property::Property(string _address)
{
	address = _address;
	rental = "";
	price = "";
	id = next_id;
	next_id++;
}
//---------------------------------------------------------------------------------------
Property::~Property()
{
}
//---------------------------------------------------------------------------------------
string Property::to_string()
{
	stringstream ss;
	ss << "Property id: " << id <<" Address: " << address << " " << get_rental(rental) << " Estimated value: " << price;
	
	return ss.str();
}
//---------------------------------------------------------------------------------------
string Property::get_rental(string _rental)
{
	if (_rental == "1"){
		
		return "Rental";
	}
	else{
		return "NOT rental";
	}
}
//---------------------------------------------------------------------------------------
string Property::get_rental_num()
{
	return rental;
}
//---------------------------------------------------------------------------------------
void Property::set_rental(string _rental)
{
	rental = _rental;
}
//---------------------------------------------------------------------------------------
void Property::set_price(string _price) 
{
	price = _price;
}
//---------------------------------------------------------------------------------------
double Property::get_price()
{
	double _price;
	stringstream ss;
	ss << price;
	ss >> _price;
	return _price;
}
//---------------------------------------------------------------------------------------
int Property::get_id() const
{
	return id;
}
//---------------------------------------------------------------------------------------
string Property::get_address() const
{
	return address;
}
//---------------------------------------------------------------------------------------
