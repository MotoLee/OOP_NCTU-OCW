#include <iostream>
using std::cout;
using std::endl;
#include "Package.h" // Package class definition
int main() {
	Package package1("Lou Brown", "Boston","Mary Smith" , "New York", 8.5, .5 );
	TwoDayPackage package2("Lisa Klein", "Somerville",
	                       "Bob George", "Cambridge", 10.5, .65, 2.0 );
	OvernightPackage package3("E Lewis", "Boston", "Don Kelly", "Denver",
	                          12.25, .7, .25 );

	/* display the package¡¦s information */
	cout<<"Package 1:"<<endl;
	package1.display();
	cout<<"Package 2:"<<endl;
	package2.display();
	cout<<"Package 3:"<<endl;
	package3.display();

	return 0;
}
