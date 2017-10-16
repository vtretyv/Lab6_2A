	/*Name: Vladimir Tretyakov
	Student ID : 20082073
	Date : 10 / 12 / 2016
	Class : CS2A
	Assignment : Lab 6
	Project Purpose : Use 2 classes to create an online store
	*/
#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include "lab6finalheaderh.h"

using namespace std;

float OnlineSuperMarket::tax_rate_ = 0.085;

void pause() {
	long count = 0;
	while (isspace(cin.peek()) && count != 30000000) {
		count++;
	}
}

Fruit::~Fruit() {
	cout << "Fruit Deconstructed " << fruit_name_ << "   " << weight_ << "    " << unit_price_ << endl;
}
Fruit& Fruit::set_name(string name) {
	fruit_name_ = name;
	return *this;
}
string Fruit::get_name() const {
	return fruit_name_;
}
Fruit& Fruit::set_weight(float weight) {
	weight_ = weight;
	return *this;
}
float Fruit::get_weight() const {
	return weight_;
}
Fruit& Fruit::set_price(float price) {
	unit_price_ = price;
	return *this;
}
float Fruit::get_price() const {
	return unit_price_;
}
float Fruit::Order(float weight) {
	if (weight > this->get_weight()) {
		return -1;
	}
	else {
		this->set_weight(this->get_weight() - weight);
		return (weight*this->get_price());
	}
}
void Fruit::Display() {
	cout << setw(10) << this->get_name();
	cout << setw(7) << fixed << "$" << setprecision(2) << this->get_price();
	cout << setw(7) << fixed << setprecision(2) << this->get_weight() << endl;
}


OnlineSuperMarket::~OnlineSuperMarket() {
	cout << "Online super market " << get_name() << "at " << get_address() << " is closed ..." << endl;
	for (int i = 0; i < 8; i++) {
		delete fruit_list_[i];
	}
}
void OnlineSuperMarket::set_name(string name) {
	market_name_ = name;
}
string OnlineSuperMarket::get_name()const {
	return market_name_;
}
void OnlineSuperMarket::set_address(string address) {
	web_address_ = address;
}
string OnlineSuperMarket::get_address()const {
	return web_address_;
}

//price = LO + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(HI-LO)));
void OnlineSuperMarket::Init() {
	float price, rand_weight;
	//made an array holding LO and HI to ease this function
	string names[8] = { "Banana", "Strawberry", "Orange", "Grapes", "Watermelon", "Apple", "Blueberry", "Mango" };
	float low[8] = { 0.5,2.10,3.0,2.15,0.20,1.50,3.0,0.75 };
	float high[8] = { 0.85,3.5,3.5,4.5,0.45,3.2,4.5,1.25 };

	for (int i = 0; i < 8; i++) {
		price = low[i] + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (high[i] - low[i])));
		rand_weight = (rand() % 40) + 10.0;
		fruit_list_[i] = new Fruit();
		fruit_list_[i]->set_name(names[i]).set_price(price).set_weight(rand_weight);
	}
}
void OnlineSuperMarket::Sort() {
	//your code from class adjusted for fruit objects
	int  walker = 0;

	for (int curr = 0; curr < 8 - 1; ++curr) {
		for (walker = 8 - 1; walker > curr; --walker) {  // start from end of the array
			if (fruit_list_[walker]->get_name() < fruit_list_[walker - 1]->get_name()) {  // swap
				Fruit *fruit_tmp = fruit_list_[walker];
				fruit_list_[walker] = fruit_list_[walker - 1];
				fruit_list_[walker - 1] = fruit_tmp;
			}
		}
	}
}
void OnlineSuperMarket::Run() {
	cout << " List of Fruits in sorted order by Fruit names with weight and price" << endl << endl;
	cout << "Your most convenient and time savings way to order food and fruit from" << endl;
	cout << "\t\t\t" << market_name_ << endl;
	cout << "\t\t\t" << web_address_ << endl;
	cout << "\t\t\t" << "FRUIT ORDERING" << endl;
	string fruit_name;
	int temp_index = 0;
	float temp_weight = 0;
	while (true) {
		cout << "Enter a fruit name or XXX to end :";
		cin >> fruit_name;
		if (fruit_name == "XXX") {
			break;
		}
		temp_index = Find(fruit_name);
		if (temp_index == -1) {
			cout << "Invalid Fruit Entered." << endl;
			continue;
		}

		Fruit* fruit = fruit_list_[temp_index];

		cout << "Enter weight in lbs : ";
		cin >> temp_weight;
		if (fruit->Order(temp_weight) < 0) {
			cout << "Not enough fruit available." << endl;
			continue;
		}
		cout << "Total cost : " << ((fruit_list_[temp_index]->get_price()*temp_weight)+ ((fruit_list_[temp_index]->get_price()*temp_weight)* get_tax_rate())) <<  "  (tax included)" << endl;
	}
	Quit();
}
int OnlineSuperMarket::Find(string name) {
	for (int i = 0; i < 8; i++) {
		if (name == fruit_list_[i]->get_name()) {
			return i;
		}
	}
	return -1;
}
void OnlineSuperMarket::Quit() {
	cout << "Thanks for your visit and come again." << endl;
}
void OnlineSuperMarket::ShowAll() {
	for (int i = 0; i < 8; i++) {
		fruit_list_[i]->Display();
	}
}
int main() {
	OnlineSuperMarket * my_ptr = NULL;
	OnlineSuperMarket * p = new OnlineSuperMarket("MortMart", "www.MortMart.com");
	my_ptr = p;
	my_ptr->Init();
	my_ptr->Sort();
	my_ptr->ShowAll();
	my_ptr->Run();

	delete my_ptr;
	pause();

	return 0;

}
