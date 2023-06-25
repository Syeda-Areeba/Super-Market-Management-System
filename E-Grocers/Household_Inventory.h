#pragma once
#include<iostream>
#include<fstream>
#include"Inventory.h"
using namespace std;

class HouseHold : public Inventory
{
	string category = "HouseHold";
public:
	string get_category()
	{
		return category;
	}

	static void load_household_inventory()
	{
		HouseHold H;
		string name[15] = { "Toothpaste","Toothbrush" ,"Shampoo","Soap","Disinfectant","Dish Cleaner","Cells",
			"Bedsheet","Towel", "Pillows","Crockery sets", "Bucket","Vaccum","Tissue Paper","Detergent" };
		float price[15] = { 75,80,100,95,125,100,60,400,175,140,280,110,360,105,135 };
		int quantity[15] = { 250,350,200,400,200,150,250,270,300,290,310,270,240,400,350 };
		H.set_inventory(H.get_category(), name, price, quantity);
	}
};
