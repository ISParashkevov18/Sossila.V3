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

void updateCustomer(CUSTOMER* customers, int& customerCount, CUSTOMER newCustomer, int& maxId)
{
	int index = getCustomerById(customers, customerCount, maxId);
	customers[index] = newCustomer;
}



void search(CUSTOMER* customers, int& customerCount)
{
	CUSTOMER customer;
	string familyParents;
	getline(cin, familyParents);
	if (familyParents == customer.Last_Name)
	{
		for (int i = 0; i < customerCount; i++)
		{
			cout << "id:" << customers[i].Id << endl;;
			cout << "Username: " << customers[i].Username << endl;
			cout << "Password: " << customers[i].Password << endl;
			cout << "First name: " << customers[i].First_Name << endl;
			cout << "Last Name: " << customers[i].Last_Name << endl;
			cout << "Address: " << customers[i].Address << endl;
			cout << "Student's Name: " << customers[i].Student_Name << endl;
			cout << "Customer's Year of student: " << customers[i].Year_of_student << endl;
		}
	}
	else
	{
		cout << "There aren't people with that name!";
	}
}

void CustomerMenu(CUSTOMER* customers, int& customerCount, int& maxId) {
	CUSTOMER customer;

	cout << "Username: ";
	cin >> customer.Username;

	cout << "Password: ";
	cin >> customer.Password;

	cout << "First Name: ";
	cin >> customer.First_Name;

	cout << "Last Name: ";
	cin >> customer.Last_Name;

	cout << "Address: ";
	cin >> customer.Address;

	cout << "Student's name: ";
	cin >> customer.Student_Name;

	cout << "Year of Student: ";
	while (!(cin >> customer.Year_of_student) or customer.Year_of_student < 12 or customer.Year_of_student > 16)
	{
		cin.clear();
		cin.ignore('\n');
		cout << "\nEnter correct Year: ";
	}

	createCustomer(customers, customerCount, customer, maxId);
}

void showCustomerMenu(CUSTOMER* customers, int& customerCount, int& maxId)
{

	cout << "\n List of the Customer: " << endl;

	for (int i = 0; i < customerCount; i++)
	{
		cout << "id:" << customers[i].Id << endl;;
		cout << "Username: " << customers[i].Username << endl;
		cout << "Password: " << customers[i].Password << endl;
		cout << "First name: " << customers[i].First_Name << endl;
		cout << "Last Name: " << customers[i].Last_Name << endl;
		cout << "Address: " << customers[i].Address << endl;
		cout << "Name: " << customers[i].Student_Name << endl;
		cout << "Customer's Year of student: " << customers[i].Year_of_student << endl;
	}
}

void deleteCustomerMenu(CUSTOMER* customers, int& customerCount, int& maxId) {
	int customerId;

	cout << "Enter User Id: ";
	cin >> customerId;

	deleteCustomer(customers, customerCount, customerId);
}

