// Package.cpp
#include "Package.h" // Package class definition

Package::Package() {
	weight = 0;
	costPerWeight = 0;
}
Package::Package(string sn, string sc, string rn, string rc, double w, double cpw) {
	senderName = sn;
	senderCity = sc;
	recipientName = rn;
	recipientCity = rc;
	weight = ( w > 0 ) ? w : 0;
	costPerWeight = ( cpw > 0 ) ? cpw : 0;
}
void Package::displaySenderRecipient() {
	cout<<"Sender:"<<endl;
	cout<<senderName<<" / "<<senderCity<<endl;
	cout<<"Recipient:"<<endl;
	cout<<recipientName<<" / "<<recipientCity<<endl;
}
void Package::display() {
	displaySenderRecipient();
	cout<<"Cost: &"<<calculateCost(weight, costPerWeight)<<endl;
}
double Package::calculateCost(double w, double cpw) {
	return (w * cpw);
}
double Package::getWeight(){
	return weight;
}
double Package::getCostPerWeight(){
	return costPerWeight;
}


TwoDayPackage::TwoDayPackage() : Package() {
	flatFee = 0;
}
TwoDayPackage::TwoDayPackage(string sn, string sc, string rn, string rc, double w, double cpw, double ff) : Package(sn, sc, rn, rc, w, cpw) {
	flatFee = ff;
}
void TwoDayPackage::display() {
	displaySenderRecipient();
	cout<<"Cost: &"<<calculateCost(getWeight(), getCostPerWeight(), flatFee)<<endl;
}
double TwoDayPackage::calculateCost(double w, double cpw, double ff) {
	return (w * cpw + ff);
}

OvernightPackage::OvernightPackage() : Package() {
	overnightFreePerWeight = 0;
}
OvernightPackage::OvernightPackage(string sn, string sc, string rn, string rc, double w, double cpw, double ofpw) : Package(sn, sc, rn, rc, w, cpw) {
	overnightFreePerWeight = ofpw;
}
void OvernightPackage::display() {
	displaySenderRecipient();
	cout<<"Cost: &"<<calculateCost(getWeight(), getCostPerWeight(), overnightFreePerWeight);
}
double OvernightPackage::calculateCost(double w, double cpw, double ofpw) {
	return (w * (cpw + ofpw));
}
