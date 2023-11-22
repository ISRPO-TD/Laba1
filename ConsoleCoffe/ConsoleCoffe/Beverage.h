#pragma once
#include <string>
#include <iostream>

using namespace std;
class Beverage{
protected:
	string description;
public:
	Beverage() : description("Нет описания") {};
	virtual string getDescription() {
		return description;
	}
	virtual double getCost() = 0;
};

class HouseBlend : public Beverage {
public:
	HouseBlend() {
		description = "House Blend Coffe";
	}
	double getCost() override {
		return 10;
	}
};



class CondimentDecorator : public Beverage{
protected:
	Beverage& beverage;
public:
	CondimentDecorator(Beverage& beverage) : beverage(beverage) {};
	virtual string getDescription() = 0;
	virtual double getCost() = 0;
};

class MilkDecorator : public CondimentDecorator {
public:
	MilkDecorator(Beverage& beverage) : CondimentDecorator(beverage) {};
	string getDescription() override {
		return beverage.getDescription() + ", с молоком";
	}

	double getCost() override {
		return beverage.getCost() + 3;
	}
};