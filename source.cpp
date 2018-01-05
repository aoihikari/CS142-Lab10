#include "Residential.h"
#include "Commercial.h"
#include "Property.h"
#include <fstream>
//---------------------------------------------------------------------------------------
//Read the file
void read_file(vector<Property*> &house, string all_line){
	string type;
	string occupied;
	string rental;
	string price;
	stringstream ss;
	int wrong = 0;
	string address;
	string discount;
	size_t found;

	ss << all_line;

	ss >> type;
	if ((type != "Residential") && (type != "Commercial")) {
		getline(ss, address);
		cout << "Ignoring unknown types of properties appearing in the input file : " << type <<address << endl;
	} 
	else{
		if (type == "Residential"){
			ss >> rental;
			if ((rental != "0") && (rental != "1")){
			
				wrong = 1;
			}
			ss >> price;
			size_t found = price.find_first_not_of("1234567890");

			if (found != string::npos)
			{
				wrong = 1;
			}
			ss >> occupied;
			if ((occupied != "0") && (occupied != "1")){
				wrong = 1;
			}
			getline(ss, address);
		}
		else{
			ss >> rental;
			if ((rental != "0") && (rental != "1")){
				wrong = 1;
			}
			ss >> price;
			found = price.find_first_not_of("1234567890");

			if (found != string::npos)
			{
				wrong = 1;
			}
			ss >> occupied;
			if ((occupied != "0") && (occupied != "1")){
				wrong = 1;
			}
			ss >> discount;
			found = discount.find_first_not_of("1234567890");
			if (found != string::npos){
				string substring = discount.substr(found);
				size_t parcial = substring.find_first_not_of(".");
				if (parcial != 1)
				{
					wrong = 1;
				}
			}
			else{
				wrong = 1;
			}
			getline(ss, address);
		}
	}
	//Print wrong input
	if (wrong == 1){

		if (type == "Residential"){
			cout << "Ignoring bad "<<type<<" in input file : "<<type<<" "<< rental<<" "<<price <<" "<< occupied <<" "<< address << endl;
		}
		else if (type == "Commercial"){
			cout << "Ignoring bad " << type << " in input file : " << type << " " << rental << " " << price << " " << occupied <<" "<< discount<< " " << address << endl;
		}
	}
	//Save correct input
	else{
		if (type == "Residential"){
			Residential* apt = new Residential(address);
			apt->set_price(price);
			apt->set_rental(rental);
			apt->set_occupied(occupied);
			house.push_back(apt);
		}
		else if (type == "Commercial"){
			Commercial* apt = new Commercial(address);
			apt->set_price(price);
			apt->set_rental(rental);
			apt->set_discount_tf(occupied);
			apt->set_discount(discount);
			house.push_back(apt);
		}
	}
}
//---------------------------------------------------------------------------------------
//Print tax report
void tax_report(const vector<Property*> house){
	cout << "\nNOW PRINTING TAX REPORT:\n";

	for (size_t spot = 0; spot < house.size(); spot++)
	{
		cout << "** Taxes due for the property at: " << house[spot]->get_address() << endl <<
			"   Property id:                             " << house[spot]->get_id() << endl <<
			"   This property has an estimated value of: " << house[spot]->get_price() << endl <<
			"   Taxes due on this property are:          " << house[spot]->get_tax() << endl;
	}
}
//---------------------------------------------------------------------------------------
//Sort by tax
void tax_report_tax(vector<Property*> house, vector<Property*> &_house){
		
	int _spot = 0;
	while (house.size() != 0)
	{
		double min = RAND_MAX;
		for (size_t spot = 0; spot < house.size(); spot++)
		{
			if (house[spot]->get_tax() < min){
				min = house[spot]->get_tax();
				_spot = spot;
			}
		}
		_house.push_back(house[_spot]);
		house.erase(house.begin() + _spot);
	}
}
//---------------------------------------------------------------------------------------
//Convert int to string
void convert1(string &_string, int _int){
	stringstream ss;
	ss << _int;
	ss >> _string;
}
//---------------------------------------------------------------------------------------
//Convert string to int
void convert2(string _string, int &_int){
	stringstream ss;
	ss << _string;
	ss >> _int;
}
//---------------------------------------------------------------------------------------
//Sort by number 
void minimum_number(vector<int> address_numbers, vector<Property*> &_house, vector<Property*> house){

	int _spot;
	int posission = 0;
	while (address_numbers.size() != 0)
	{
		int min = RAND_MAX;
		for (size_t spot = 0; spot < address_numbers.size(); spot++)
		{
			if (address_numbers[spot] < min){
				min = address_numbers[spot];
				posission = address_numbers[spot + 1];
				_spot = spot;
			}
			spot++;
		}
		_house.push_back(house[posission]);
		address_numbers.erase(address_numbers.begin() + _spot);
		address_numbers.erase(address_numbers.begin() + _spot);
	}
}
//---------------------------------------------------------------------------------------
//Sort by name
void minimum_name(vector<string> address_names, vector<Property*> &_house, vector<Property*> house){

	int _spot;
	string posission;
	int _posission = 0;

	while (address_names.size() != 0)
	{
		string max = "Z";
		for (size_t spot = 0; spot < address_names.size(); spot++)
		{
			if (address_names[spot] <= max){
				max = address_names[spot];
				posission = address_names[spot + 1];
				_spot = spot;
			}
			spot++;
			
		}
		convert2(posission, _posission);
		_house.push_back(house[_posission]);
		address_names.erase(address_names.begin() + _spot);
		address_names.erase(address_names.begin() + _spot);
	}
}
//---------------------------------------------------------------------------------------
//Get address number, name and posission
void adress_name_number(vector<Property*> house, vector<int> &address_numbers, vector<string> &address_name, int spot, int criteria){

	int number;
	string name;
	stringstream ss;
	string _spot;
	convert1(_spot, spot);
	ss << house[spot]->get_address();
	ss >> number;
	ss >> name;
	if (criteria == 1){
		address_numbers.push_back(number);
		address_numbers.push_back(spot);
	}
	else{
				
		address_name.push_back(name);
		address_name.push_back(_spot);
	}
}
//---------------------------------------------------------------------------------------
//Zero Property vector
void zero_p(vector<Property*> &house){

	while (house.size() != 0)
	{
		house.erase(house.begin());
	}
}
//---------------------------------------------------------------------------------------
//Zero string vector
void zero_s(vector<string> &house){

	while (house.size() != 0)
	{
		house.erase(house.begin());
	}
}
//---------------------------------------------------------------------------------------
//zero int vector
void zero_i(vector<int> &house){

	while (house.size() != 0)
	{
		house.erase(house.begin());
	}
}
//---------------------------------------------------------------------------------------
//Sort by number and name
void minimum_number_name(vector<int> numbers, vector<Property*> &_house, vector<Property*> house){
	vector<Property*> name;
	vector<string> hola;
	vector<Property*> _name;
	vector<int> _number;
	int posission = 0;
	int equal_n = 0;		

		while (numbers.size() != 0){
			int n_equal = 0;
			equal_n = numbers[0];
			name.push_back(_house[numbers[1]]);
			
			numbers.erase(numbers.begin());
			numbers.erase(numbers.begin());
			n_equal++;
			for (size_t spot = 0; spot<numbers.size(); spot++){

				if (numbers[spot] != equal_n){
					
				}
				else{
					posission = numbers[spot + 1];
					name.push_back(_house[posission]);
					numbers.erase(numbers.begin() + spot);
					numbers.erase(numbers.begin() + spot);
					n_equal++;
					spot--;
					spot--;
				}
				spot++;
			}			
				for (int spot = 0; spot < n_equal; spot++)
				{
					adress_name_number(name, _number, hola, spot, 0);
				}
				minimum_name(hola, _name, name);
			
				zero_s(hola);
				zero_p(name);
		}
		zero_p(_house);
		for (size_t spot = 0; spot < _name.size(); spot++)
		{
			_house.push_back(_name[spot]);			
		}
}
//---------------------------------------------------------------------------------------
int main(int argc, char* argv[]){
//Enter file name
	vector<Property*> _house;
	cout << "Enter a file name:\n\n";

		string file_name;
		cin.sync();
		getline(cin, file_name);
		cout << endl;
//Open file
		ifstream in_file;

		in_file.open(file_name);

		if (in_file.fail())
		{
			cout << "\nCouldn't load file\n\n" << endl;
			system("pause");
			return 0;
		}
		else{

			string all_line;

			vector<Property*> house;

			while (getline(in_file, all_line))
			{
				read_file(house, all_line);
			}
				in_file.close();
				cout << endl;
//Ways to print a file
				for (size_t spot = 0; spot < house.size(); spot++)
				{
					cout << house[spot]->to_string();
				}
				cout << "\nHow do you want to print your tax report?\n\n"
					"Sorted by ID (ID from lowest to highest) <Type 1>:\n"
					"Sorted by Taxes (amount due from lowest to highest)<Type 2>:\n"
					"Sorted by Address (numeric from lowest to highest, then alphabetic)<Type 3>:\n\n";
					int choice;
				
				cin >> choice;

				cout << endl;

				switch (choice)
				{
				case 1:
					//Display the tax by id
					tax_report(house);
					break;

				case 2:
					//Display by tax
					tax_report_tax(house, _house);
					tax_report(_house);

					break;

				case 3:
					//Display by address
					vector<int> address_numbers;
					vector<string> address_name;
					
					
						for (size_t spot = 0; spot < house.size(); spot++)
						{
							adress_name_number(house, address_numbers, address_name, spot, 1);
						}
						minimum_number(address_numbers, _house, house);
						zero_i(address_numbers);
						for (size_t spot = 0; spot < house.size(); spot++)
						{
							adress_name_number(_house, address_numbers, address_name, spot, 1);
						}						
						minimum_number_name(address_numbers, _house, house);
					tax_report(_house);

					break;					
				}
		}	
	return 0;
}
//---------------------------------------------------------------------------------------
