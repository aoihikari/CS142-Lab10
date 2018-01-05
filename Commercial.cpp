#include "Commercial.h"
//---------------------------------------------------------------------------------------
Commercial::Commercial(string _address) : Property(_address)
{
	discount_tf = "";
	discount = "";
}
//---------------------------------------------------------------------------------------
Commercial::~Commercial()
{
}
//---------------------------------------------------------------------------------------
string Commercial::to_string()
{
	stringstream ss;
	ss << Property::to_string();
	ss << " " << get_discount_tf(discount_tf);
	if (discount_tf == "1"){
		ss << " " << discount;
	}
	ss << endl;
	
	return ss.str();
}
//---------------------------------------------------------------------------------------
string Commercial::get_discount_tf(string _discount_tf)
{
	if (_discount_tf == "1"){

		return "Discounted";
	}
	else{
		return "NOT discounted";
	}
}
//---------------------------------------------------------------------------------------
void Commercial::set_discount_tf(string _discount_tf)
{	
	discount_tf = _discount_tf;
}
//---------------------------------------------------------------------------------------
void Commercial::set_discount(string _discount)
{
	discount = _discount;
}
//---------------------------------------------------------------------------------------
double Commercial::get_tax()
{
	const double PERCENT1 = 0.012;
	const double PERCENT2 = 0.01;
	const double CENT = 100;
	stringstream ss;
	ss << discount;
	double _discount;
	ss >> _discount;
	double tax;
	if (discount_tf == "1"){
		if (get_rental_num() == "1"){
			tax = get_price()*(PERCENT1-(_discount/CENT));
		}
		else{
			tax = get_price()*(PERCENT2 - (_discount/CENT));
		}		
		return tax;
	}
	else{
		if (get_rental_num() == "1"){
			tax = get_price()*(PERCENT1);
		}
		else{
			tax = get_price()*(PERCENT2);
		}
		return tax;
	}
}
//---------------------------------------------------------------------------------------

