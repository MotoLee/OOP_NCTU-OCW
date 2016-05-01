// Package.h
#ifndef PACKAGE_H
#define PACKAGE_H
#include <iostream>
#include <string>
using namespace std;

class Package {
	private:
		string senderName;
		string senderCity;
		string recipientName;
		string recipientCity;
		double weight; // weight of the package
		double costPerWeight; // cost per weight to ship the package
	public:
		Package();
		Package(string sn, string sc, string rn, string rc, double w, double cpw);
		/* any member functions if necessary */
		void displaySenderRecipient();
		void display();
		double calculateCost(double w, double cpw);
		double getWeight();
		double getCostPerWeight();
};
class TwoDayPackage : public Package {
	private:
		double flatFee; // flat fee for two-day-delivery service
	public:
		TwoDayPackage();
		TwoDayPackage(string sn, string sc, string rn, string rc, double w, double cpw, double ff);
		/* any member functions if necessary */
		void display();
		double calculateCost(double w, double cpw, double ff);
};
class OvernightPackage : public Package {
	private:
		double overnightFreePerWeight; // flat fee weight for overnight delivery
	public:
		OvernightPackage();
		OvernightPackage(string sn, string sc, string rn, string rc, double w, double cpw, double ofpw);
		/* any member functions if necessary */
		void display();
		double calculateCost(double w, double cpw, double ofpw);
};
#endif
