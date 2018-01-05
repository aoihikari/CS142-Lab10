#include "Property.h"
//---------------------------------------------------------------------------------------
using namespace std;
//---------------------------------------------------------------------------------------
class Residential : public Property
{
private:
	string occupied;

public:
	Residential(string _address);
	virtual string to_string();
	void set_occupied(string _occupied);
	string get_occupied(string _occupied);
	virtual double get_tax();
	~Residential();
};
//---------------------------------------------------------------------------------------

