#include "Residential.h"
//---------------------------------------------------------------------------------------
Residential::Residential(string _address) : Property(_address)
{
	occupied = "";
}
//---------------------------------------------------------------------------------------
Residential::~Residential()
{
}
//---------------------------------------------------------------------------------------
string Residential::to_string()
{
	stringstream ss;
	ss << Property::to_string();
	ss << " "<< get_occupied(occupied) << endl;
	return ss.str();
}
//---------------------------------------------------------------------------------------
void Residential::set_occupied(string _occupied)
{
	occupied = _occupied;
}
//---------------------------------------------------------------------------------------
string Residential::get_occupied(string _occupied)
{
	if (_occupied == "1"){

		return "Occupied";
	}
	else{
		return "NOT occupied";
	}
}
//---------------------------------------------------------------------------------------
double Residential::get_tax()
{
	const double PERCENT1 = 0.006;
	const double PERCENT2 = 0.009;
	double tax;
	if (occupied == "1"){

		tax = get_price()*PERCENT1;
		return tax;
	}
	else{
		tax = get_price()*PERCENT2;
		return tax;
	}
}
//---------------------------------------------------------------------------------------

