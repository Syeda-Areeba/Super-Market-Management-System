#pragma once
#include<iostream>
#include<ctime>
#include<fstream>
#include"Customer.h"
#include"Cart.h"
using namespace std;

class Order
{
private:
	double bill;

public:
	Order()
	{
		
	}
/*----------------------------------------------------------------------------------------------------------------
													SETTERS
----------------------------------------------------------------------------------------------------------------*/
	void set_bill(const double bill)
	{
		this->bill = bill;
	}
/*----------------------------------------------------------------------------------------------------------------
													GETTERS
----------------------------------------------------------------------------------------------------------------*/
	double get_bill() const
	{
		return bill;
	}
/*----------------------------------------------------------------------------------------------------------------
													OTHER FUNCTIONS
----------------------------------------------------------------------------------------------------------------*/
	void calculate_bill(string filename,Cart customer_cart)
	{
		bill = 0; // to avoid garbage value
		Product purchased_product;
		ifstream file(filename + ".dat", ios::binary);
		while (file.read((char*)&purchased_product, sizeof(purchased_product)))
		{
			bill = bill + (purchased_product.get_price() * purchased_product.get_quantity());
		}
	}
	bool confirm_order()
	{
		char ch;
		cout << "Do you want to confirm the order ?" << endl;
		cout << "Press: " << endl;
		cout << "1. y for yes" << endl;
		cout << "2. n for no" << endl;
		do
		{
			cin >> ch;
			if (ch == 'N' || ch == 'n')
			{
				return 0;
			}
			else if (ch == 'Y' || ch == 'y')
			{
				return 1;
			}
			else
			{
				cout << "Oops! Invalid option. Please try again." << endl;
			}
		} while (ch != 'N' && ch != 'n' && ch != 'Y' && ch != 'y');
	}
	void cancel_order()
	{
		//delete order file
	}
	void display_order(string filename, Cart customer_cart)
	{
		Product purchased_product;
		ifstream file(filename + ".dat", ios::binary);
		int i = 1;
		cout << endl << endl << endl << endl << endl;
		cout << "\t\t-------------------------------------------------------------------------\t\t" << endl;
		cout << "\t\t|\t\t\t\t  " << "ORDER" << "\t\t\t\t\t|" << endl;
		cout << "\t\t-------------------------------------------------------------------------\t\t" << endl;
		cout << "\t\t|\t" << setw(10) << left << "NO" << "\t" << setw(20) << left << "NAME" << setw(15)
			<< left << "PRICE" << setw(10) << left << "QUANTITY" << "\t|" << endl;
		cout << "\t\t-------------------------------------------------------------------------\t\t" << endl;
		while (file.read((char*)&purchased_product, sizeof(purchased_product)))
		{
			cout << "\t\t|\t" << setw(10) << left << i << "\t" << setw(20) << left <<
				purchased_product.get_name() << setw(15) << left << purchased_product.get_price() << setw(10)
				<< left << purchased_product.get_quantity() << "\t|" << endl;
			i++;
		}
		cout << "\t\t-------------------------------------------------------------------------\t\t" << endl;
		cout << "\t\t|\t\t\t Total Amount: " << bill << " Rs" << "\t\t\t\t|" << endl;
		cout << "\t\t-------------------------------------------------------------------------\t\t" << endl;
		cout << endl << endl; 
	}
};