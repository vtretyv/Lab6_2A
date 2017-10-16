#pragma once
	/*Name: Vladimir Tretyakov
	Student ID : 20082073
	Date : 10 / 12 / 2016
	Class : CS2A
	Assignment : Lab 6
	Project Purpose : Use 2 classes to make an online store
	*/
#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <cstdlib>
#include <cmath>

	using namespace std;


class Fruit {
private:
	string fruit_name_;
	float weight_, unit_price_;
public:
	//construct & dstruct
	Fruit() : weight_(0.0), unit_price_(0.0) {}
	Fruit(string fruit, float weight, float price) : fruit_name_(fruit), weight_(weight), unit_price_(price) { cout << "Fruit Constructed" << endl; }
	~Fruit();

	//getters and mutators
	Fruit& set_name(string name);
	string get_name() const;

	Fruit& set_weight(float weight);
	float get_weight() const;

	Fruit& set_price(float price);
	float get_price() const;

	//other functions
	float Order(float weight);

	void Display();

};

class OnlineSuperMarket {
private:
	Fruit* fruit_list_[8];
	string market_name_;
	string web_address_;
	static float tax_rate_;
public:
	//constructor & dstructor
	OnlineSuperMarket();
	OnlineSuperMarket(string market_name, string web_address) : market_name_(market_name), web_address_(web_address) {}
	~OnlineSuperMarket();

	//Accessor and mutator
	void set_name(string name);
	string get_name() const;

	void set_address(string address);
	string get_address() const;

	static float get_tax_rate() {
		return tax_rate_;
	}

	//Other
	void Init();
	void Sort();
	void Run();
	int Find(string name);
	void Quit();
	void ShowAll();
};

