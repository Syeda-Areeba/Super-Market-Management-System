#pragma once
#include<iostream>
#include<fstream>
#include"Inventory.h"
using namespace std;

class Beauty_and_Personal_Care_Inventory: public Inventory
{
	string category = "Beauty & Personal Care";
public:
	string get_category()
	{
		return category;
	}
	static void load_Beauty_and_Personal_Care_inventory()
	{
		Beauty_and_Personal_Care_Inventory BPC;
		string name[15] = { "Sunblock","Perfume","Toner","Exfoliator","Face Mask","Face Cream","Lipsticks",
			"Lotion", "Hair color", "Lense","Foundations","Highlighter","Mascara","Makeup Kit","Band-aids" };
		float price[15] = { 175,200,110,100,95,155,250,190,200,250,290,210,125,340,130 };
		int quantity[15] = { 250,400,200,150,200,300,350,270,210,250,340,200,200,400,350 };
		BPC.set_inventory(BPC.get_category(), name, price, quantity);
	}
};

