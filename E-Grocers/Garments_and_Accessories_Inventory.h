#pragma once
#include<iostream>
#include<fstream>
#include"Inventory.h"
using namespace std;

class Garments_and_Accessories : public Inventory
{
	string category = "Garments & Accessories";
public:
	string get_category()
	{
		return category;
	}
	static void load_Garments_and_Accessories_inventory()
	{
		Garments_and_Accessories GA;
		string name[15] = { "Trousers","T-Shirts","Pants","Shirts","Bags","Hats","Scarfs","Socks","Jackets",
			"Waisecoats","Shorts","Shoes","Sunglasses","Watches","Jewellery" };
		float price[15] = { 120,100,160,150,190,110,95,80,200,250,180,300,165,225,400 };
		int quantity[15] = { 300,400,400,250,190,100,250,280,350,290,300,200,185,275,500 };
		GA.set_inventory(GA.get_category(), name, price, quantity);
	}
};

