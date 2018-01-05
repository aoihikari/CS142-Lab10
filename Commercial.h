#include "Property.h"
//---------------------------------------------------------------------------------------
using namespace std;
//---------------------------------------------------------------------------------------
class Commercial : public Property
{
private:
	string discount_tf;
	string discount;

public:
	Commercial(string _address);
	virtual string to_string();
	string get_discount_tf(string _discount_tf);
	void set_discount_tf(string _discount_tf);
	void set_discount(string _discount);
	virtual double get_tax();
	~Commercial();
};
//---------------------------------------------------------------------------------------

