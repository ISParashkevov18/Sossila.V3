#include <iostream>
#include <string>
using namespace std;
bool option1Check = false;

struct CUSTOMER
{
	int Id;
	string Username;
	string Password;
	string First_Name;
	string Last_Name;
	string Address;
	string Student_Name;
	int Year_of_student;
};

void createCustomer(CUSTOMER* customers, int& customerCount, CUSTOMER newOrder, int& maxId) {
	newOrder.Id = maxId;
	customers[customerCount] = newOrder;
	customerCount++;
	maxId++;
}
int getCustomerById(CUSTOMER* customers, int& customerCount, int Id)
{
	for (int i = 0; i < customerCount; i++)
	{
		if (customers[i].Id == Id)
		{
			return i;
		}
	}

	return -1;
}

CUSTOMER getOrder(CUSTOMER* customer, int& customerCount, int Id)
{
	int index = getCustomerById(customer, customerCount, Id);
	if (index != Id)
	{
		cout << "Enter valid ID";
		cin >> index;
	}
	return customer[index];
}

bool isAdmin(string UsernName, string pass)
{
	string admin = "admin";
	string adminPass = "adminpass";
	if (UsernName == admin and adminPass == pass)
	{
		cout << "Correct Password and Username!\nAccess Granted!" << endl;
		return true;
	}
	else
	{
		cout << "Wrong Password or Username! " << endl;
		return false;
	}
}


void deleteCustomer(CUSTOMER* customer, int& customerCount, int Id) {

	int index = getCustomerById(customer, customerCount, Id);
	for (int i = index; i < customerCount - 1; i++)
	{
		customer[i] = customer[i + 1];
	}
	customerCount--;

}

