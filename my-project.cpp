#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<time.h>

using namespace std;

class Stuff
{
public:
	Stuff(string Title, int Price, int id, int Stock);
	int getId()
	{
		return ID;
	}
	int getPrice()
	{
		return price;
	}
	int getStock()
	{
		return stock;
	}
	string getTitle()
	{
		return title;
	}
	void update();
	void purchase(int count)
	{
		stock -= count;
	}
private:
	int ID, price, stock;
	string title;
};
Stuff::Stuff(string Title = "", int Price = 0, int id = 1, int Stock = 1)
{
	title = Title;
	price = Price;
	ID = id;
	stock = Stock;
}

class Client
{
public:
	Client(string Name, int phone);
	string getName()
	{
		return name;
	}
	int getPhone()
	{
		return phoneNumber;
	}
	void update();
protected:
	string name;
	int phoneNumber;
};
Client::Client(string Name = "", int phone = 01)
{
	name = Name;
	phoneNumber = phone;
}

class SpecialClient : public Client
{
public:
	SpecialClient(string Name, int phone) :
			Client(Name, phone)
	{
	}
	void update();
};

// add functions

Stuff addStuff()
{
	int price, id, stock;
	string title;
	cout << "enter stuff title: ";
	cin >> title;
	cout << "enter " << title << " price: ";
	cin >> price;
	cout << "enter " << title << " id: ";
	cin >> id;
	cout << "enter number of " << title << "'s you want to add: ";
	cin >> stock;
	return Stuff(title, price, id, stock);
}

Client addClient()
{
	int phone;
	string name;
	cout << "enter client name: ";
	cin >> name;
	cout << "enter client phone number: ";
	cin >> phone;
	return Client(name, phone);
}

SpecialClient addSpecial()
{
	int phone;
	string name;
	cout << "enter client name: ";
	cin >> name;
	cout << "enter client phone number: ";
	cin >> phone;
	return SpecialClient(name, phone);
}

// update functions

void Stuff::update()
{
	int field;
	cout << "which field you want to update: \n";
	cout << "\t1:update title\n";
	cout << "\t2:update price\n";
	cout << "\t3:update stock\n";
	cout << "\t4:update id\n";
	cout << "\t5:update price and stock\n";
	cin >> field;
	switch (field)
	{
		case 1:
			cout << "enter new title: ";
			cin >> title;
			break;
		case 2:
			cout << "enter new price: ";
			cin >> price;
			break;
		case 3:
			cout << "enter new stock: ";
			cin >> stock;
			break;
		case 4:
			cout << "enter new id: ";
			cin >> ID;
			break;
		case 5:
			cout << "enter new price: ";
			cin >> price;
			cout << "enter new stock: ";
			cin >> stock;
			break;
		default:
			cout << "wrong choice!!\n";
			cout << "exit without any update\n";
	}
}

void Client::update()
{
	int field;
	cout << "which field you want to update: \n";
	cout << "\t1:update name\n";
	cout << "\t2:update phone number\n";
	cout << "\t3:update name and phone, both\n";
	cin >> field;
	switch (field)
	{
		case 1:
			cout << "enter new name: ";
			cin >> name;
			break;
		case 2:
			cout << "enter new phone number: ";
			cin >> phoneNumber;
			break;
		case 3:
			cout << "enter new name: ";
			cin >> name;
			cout << "enter new phone number: ";
			cin >> phoneNumber;
			break;
		default:
			cout << "wrong choice!!\n";
			cout << "exit without any update\n";
			break;
	}
}

void SpecialClient::update()
{
	int field;
	cout << "which field you want to update: \n";
	cout << "\t1:update name\n";
	cout << "\t2:update phone number\n";
	cout << "\t3:update name and phone, both\n";
	cin >> field;
	switch (field)
	{
		case 1:
			cout << "enter new name: ";
			cin >> name;
			break;
		case 2:
			cout << "enter new phone number: ";
			cin >> phoneNumber;
			break;
		case 3:
			cout << "enter new name: ";
			cin >> name;
			cout << "enter new phone number: ";
			cin >> phoneNumber;
			break;
		default:
			cout << "wrong choice!!\n";
			cout << "exit without any update\n";
			break;
	}
}

class Purchase
{
public:
	Purchase(Client client, vector<Stuff> stuff, int purchaseNo, int price);
	string getClient()
	{
		return client.getName();
	}
	vector<Stuff> getStuff()
	{
		return stuffs;
	}
	int getNo()
	{
		return purchaseNO;
	}
	int getPrice()
	{
		return price;
	}

protected:
	vector<Stuff> stuffs;
	Client client;
	int purchaseNO, price;
};
Purchase::Purchase(Client client, vector<Stuff> stuff, int purchaseNo, int price)
{
	this->stuffs = stuff;
	this->client = client;
	purchaseNO = purchaseNo;
	this->price = price;
}
class SpecialPurchase : public Purchase
{
public:
	SpecialPurchase(SpecialClient special, vector<Stuff> stuff, int purchaseNo, int price) :
			Purchase(special, stuff, purchaseNo, price)
	{
	}
};

class Shop
{
public:
	Shop(vector<Stuff> stuff, vector<Client> client, vector<SpecialClient> special,
	     vector<Purchase> purchase, vector<SpecialPurchase> specialPurchase);
	void remove(int index);
	void clientPurchase(Client client);
	void specialPurchase(SpecialClient special);
	void add();
	void update();
	void userRemove();
	void purchase();
	void report();
	vector<Stuff> getStuff()
	{
		return stuffs;
	}
	vector<Client> getClient()
	{
		return clients;
	}
	vector<SpecialClient> getSpecial()
	{
		return specials;
	}
	vector<Purchase> getPurchase()
	{
		return purchases;
	}
	vector<SpecialPurchase> getSpecialPurchase()
	{
		return specialPurchases;
	}
	fstream stuffFile, clientFile, specialFile, purchaseFile;
private:
	vector<Stuff> stuffs;
	vector<Client> clients;
	vector<SpecialClient> specials;
	vector<Purchase> purchases;
	vector<SpecialPurchase> specialPurchases;
};
Shop::Shop(vector<Stuff> stuff, vector<Client> client, vector<SpecialClient> special,
           vector<Purchase> purchase =
		           { }, vector<SpecialPurchase> specialPurchase =
		{ })
{
	stuffs = stuff;
	clients = client;
	specials = special;
	purchases = purchase;
	specialPurchases = specialPurchase;
}
void Shop::remove(int index)
{
	stuffs[index] = stuffs[stuffs.size() - 1];
	stuffs.pop_back();
}
void Shop::clientPurchase(Client client)
{
	int check = 1, choose, count;
	int total = 0;
	vector<Stuff> stuff;
	if (stuffs.size() >= 1)
	{
		while (check)
		{
			for (int i = 0; i < stuffs.size(); i++)
			{
				cout << i + 1 << ": " << "title: " << stuffs[i].getTitle() << "\tprice: "
				     << stuffs[i].getPrice() << "\tstock: " << stuffs[i].getStock() << endl;
			}
			cout << "enter your choose: \n";
			if(check%3==1)
			{
				cout << "remember that you can exit from purchasing by entering number '0'!!\n";
			}
			check++;
			cin >> choose;
			if (choose == 0)
			{
				check = 0;
				break;
			}
			if (choose <= stuffs.size() || choose > 0)
			{
				cout << "enter number of " << stuffs[choose - 1].getTitle()
				     << " you want to purchase: ";
				cin >> count;
				total += stuffs[choose - 1].getPrice() * count;

				if (count > stuffs[choose - 1].getStock())
				{
					cout << "not enough " << stuffs[choose - 1].getTitle() << "'s to purchase\n";
				}
				else
				{
					if (count < stuffs[choose - 1].getStock())
					{
						stuffs[choose - 1].purchase(count);
					}
					else
					{
						remove(choose - 1);
					}
					Stuff last = stuffs[choose - 1];
					last = Stuff(last.getTitle(), last.getPrice(), last.getId(), count);
					stuff.push_back(last);
				}
			}
		}
		cout << "you have to pay " << total << "$\n";
		srand(time(0));
		int purchaseNo = rand() % (100000) + 1;
		Purchase purchase(client, stuff, purchaseNo, total);
		purchases.push_back(purchase);

		purchaseFile << "NO: " << purchase.getNo() << " - " << "stuffs: ";
		for (int i = 0; i < purchase.getStuff().size(); i++)
		{
			Stuff writing = purchase.getStuff()[i];
			purchaseFile << writing.getTitle() << ":" << writing.getStock() << "  ";
		}
		purchaseFile << "- paid: " << purchase.getPrice() << " - " << "made by: "
		             << purchase.getClient() << endl;
	}
	else
		cout << "no stuff to purchase!!\n";
}
void Shop::specialPurchase(SpecialClient special)
{
	int check = 1, choose, count;
	int total = 0;
	vector<Stuff> stuff;
	if (stuffs.size() >= 1)
	{
		while (check)
		{
			for (int i = 0; i < stuffs.size(); i++)
			{
				cout << i + 1 << ": " << "title: " << stuffs[i].getTitle() << "\tprice: "
				     << stuffs[i].getPrice() << "\tstock: " << stuffs[i].getStock() << endl;
			}
			cout << "enter your choose: ";
			if(check%3==1)
			{
				cout << "remember that you can exit from purchasing by entering number '0'!!\n";
			}
			check++;
			cin >> choose;
			if (choose == 0)
			{
				check = 0;
				break;
			}
			if (choose <= stuffs.size() || choose > 0)
			{
				cout << "enter number of " << stuffs[choose - 1].getTitle()
				     << " you want to purchase: ";
				cin >> count;
				total += stuffs[choose - 1].getPrice() * count;

				if (count > stuffs[choose - 1].getStock())
				{
					cout << "not enough " << stuffs[choose - 1].getTitle() << "'s to purchase\n";
				}
				else
				{
					if (count < stuffs[choose - 1].getStock())
					{
						stuffs[choose - 1].purchase(count);
					}
					else
					{
						remove(choose - 1);
					}
					Stuff last = stuffs[choose - 1];
					last = Stuff(last.getTitle(), last.getPrice(), last.getId(), count);
					stuff.push_back(last);
				}
			}
		}
		cout << "total purchase is: " << total << endl;
		total = total * 0.8;
		cout << "but because you are one of our special clients ,\n";
		cout << "you have to pay " << total << "$ !!!\n";

		srand(time(0));
		int purchaseNo = rand() % (100000) + 1;
		SpecialPurchase purchase(special, stuff, purchaseNo, total);
		specialPurchases.push_back(purchase);

		purchaseFile << "NO: " << purchase.getNo() << " - " << "stuffs: ";
		for (int i = 0; i < purchase.getStuff().size(); i++)
		{
			Stuff writing = purchase.getStuff()[i];
			purchaseFile << writing.getTitle() << ":" << writing.getStock() << "  ";
		}
		purchaseFile << "- paid: " << purchase.getPrice() << " - " << "made by: "
		             << purchase.getClient() << endl;
	}
	else
		cout << "no stuff to purchase!!\n";
}

void Shop::add()
{
	int choose;
	cout << "choose an option below: \n";
	cout << "\t1:add a stuff \n";
	cout << "\t2:add a client \n";
	cout << "\t3:add an special client \n";
	cout << "\t4:cancel operation\n";
	cin >> choose;
	system("cls");
	switch (choose)
	{
		case 1:
		{
			stuffs.push_back(addStuff());
			Stuff last = stuffs[stuffs.size() - 1];
			stuffFile << "title: " << last.getTitle() << "\tprice: " << last.getPrice() << "\tid: "
			          << last.getId() << "\tstock: " << last.getStock() << "\tadded" << endl;
		}
			break;
		case 2:
		{
			clients.push_back(addClient());
			Client last = clients[clients.size() - 1];
			clientFile << "name: " << last.getName() << "\tphone: " << last.getPhone()
			           << "\tadded\n";
		}
			break;
		case 3:
		{
			specials.push_back(addSpecial());
			SpecialClient last = specials[specials.size() - 1];
			specialFile << "name: " << last.getName() << "\tphone: " << last.getPhone()
			            << "\tadded\n";
		}
			break;
		case 4:
			break;
		default:
			cout << "wrong choice!!\n";
			cout << "try again: \n";
			add();
			break;
	}
}
void Shop::update()
{
	int option, choose;
	cout << "choose an option below: \n";
	cout << "\t1:update a stuff\n";
	cout << "\t2:update a client\n";
	cout << "\t3:update an special client\n";
	cout << "\t4:cancel operation\n";
	cin >> option;
	system("cls");
	switch (option)
	{
		case 1:
			if (stuffs.size() >= 1)
			{
				for (int i = 0; i < stuffs.size(); i++)
				{
					cout << i + 1 << ": " << "title: " << stuffs[i].getTitle() << "\tprice: "
					     << stuffs[i].getPrice() << "\tstock: " << stuffs[i].getStock() << endl;
				}
				cout << "\nenter your choose: ";
				cin >> choose;
				if (choose <= stuffs.size())
				{
					Stuff update = stuffs[choose - 1];

					stuffFile << "title: " << update.getTitle() << "\tprice: " << update.getPrice()
					          << "\tid: " << update.getId() << "\tStock: " << update.getStock()
					          << "\tUpdated to :\n";

					stuffs[choose - 1].update();

					update = stuffs[choose - 1];
					stuffFile << '\t' << update.getTitle() << '\t' << update.getPrice() << '\t'
					          << update.getId() << '\t' << update.getStock() << endl;
				}
			}
			else
			{
				cout << "no stuff to update!!\n";
			}
			break;
		case 2:
			if (clients.size() >= 1)
			{
				for (int i = 0; i < clients.size(); i++)
				{
					cout << i + 1 << ": " << "name: " << clients[i].getName() << "\tphone: "
					     << clients[i].getPhone() << endl;
				}
				cout << "\nenter your choose: ";
				cin >> choose;
				if (choose <= clients.size())
				{
					Client update = clients[choose - 1];
					clientFile << "name: " << update.getName() << "\tphone: " << update.getPhone()
					           << "\tUpdated to:\n";
					clients[choose - 1].update();
					update = clients[choose - 1];
					clientFile << '\t' << update.getName() << '\t' << update.getPhone() << endl;
				}
			}
			else
			{
				cout << "no client to update!!\n";
			}
			break;
		case 3:
			if (specials.size() >= 1)
			{
				for (int i = 0; i < specials.size(); i++)
				{
					cout << i + 1 << ": " << "name: " << specials[i].getName() << "\tphone: "
					     << specials[i].getPhone() << endl;
				}
				cout << "\nenter your choose: ";
				cin >> choose;
				if (choose <= specials.size())
				{
					specials[choose - 1].update();
				}
			}
			else
			{
				cout << "no special client to update!!\n";
			}
			break;
		case 4:
			break;
		default:
			cout << "wrong choice!!\n";
			cout << "try again\n";
			update();
			break;
	}
}
void Shop::userRemove()
{
	int option, choose;
	cout << "choose an option below: \n";
	cout << "\t1:remove a stuff\n";
	cout << "\t2:remove a client\n";
	cout << "\t3:remove an special client\n";
	cin >> option;
	system("cls");
	switch (option)
	{
		case 1:
			if (stuffs.size() >= 1)
			{
				for (int i = 0; i < stuffs.size(); i++)
				{
					cout << i + 1 << ": " << "title: " << stuffs[i].getTitle() << "\tprice: "
					     << stuffs[i].getPrice() << "\tstock: " << stuffs[i].getStock() << endl;
				}
				cout << "\nenter your choose: ";
				cin >> choose;
				if (choose <= stuffs.size())
				{
					if (choose > 0)
					{
						Stuff del = stuffs[choose - 1];
						stuffs[choose - 1] = stuffs[stuffs.size() - 1];
						stuffs.pop_back();
						stuffFile << "title: " << del.getTitle() << "\tprice: " << del.getPrice()
						          << "\tid: " << del.getId() << '\t' << del.getStock()
						          << "\tremoved" << endl;
					}

				}
			}
			else
			{
				cout << "no stuff to remove!!\n";
			}
			break;
		case 2:
			if (clients.size() >= 1)
			{
				for (int i = 0; i < clients.size(); i++)
				{
					cout << i + 1 << ": " << "name: " << clients[i].getName() << "\tphone: "
					     << clients[i].getPhone() << endl;
				}
				cout << "\nenter your choose: ";
				cin >> choose;
				if (choose <= clients.size())
				{
					Client del = clients[choose - 1];
					clients[choose - 1] = clients[clients.size() - 1];
					clients.pop_back();
					clientFile << "name: " << del.getName() << "\tphone: " << del.getPhone()
					           << "\tremoved" << endl;
				}
			}
			else
			{
				cout << "no client to remove!!\n";
			}
			break;
		case 3:
			if (specials.size() >= 1)
			{
				for (int i = 0; i < specials.size(); i++)
				{
					cout << i + 1 << ": " << "name: " << specials[i].getName() << "\tphone: "
					     << specials[i].getPhone() << endl;
				}
				cout << "\nenter your choose: ";
				cin >> choose;
				if (choose <= specials.size())
				{
					SpecialClient del = specials[choose - 1];
					specials[choose - 1] = specials[specials.size() - 1];
					specials.pop_back();
					specialFile << "name: " << del.getName() << "\tphone: " << del.getPhone()
					            << "\tremoved" << endl;
				}
			}
			else
			{
				cout << "no special client to remove!!\n";
			}
			break;
		case 4:
			break;
		default:
			cout << "wrong choice!!\n";
			cout << "try again\n";
			userRemove();
			break;
	}
}
void Shop::purchase()
{
	int option, choose;
	cout << "choose an option below: \n";
	cout << "\t1:purchase by a client\n";
	cout << "\t2:purchase by an special client\n";
	cout << "\t3:cancel operation\n";
	cin >> option;
	system("cls");
	switch (option)
	{
		case 1:
			if (clients.size() >= 1)
			{
				for (int i = 0; i < clients.size(); i++)
				{
					cout << i + 1 << ": " << "name: " << clients[i].getName() << "\tphone: "
					     << clients[i].getPhone() << endl;
				}
				cout << "enter your choose: ";
				cin >> choose;
				if (choose >= clients.size())
				{
					clientPurchase(clients[choose - 1]);
				}
			}
			else
			{
				cout << "your shop has no clients!!\n";
			}
			break;
		case 2:
			if (specials.size() >= 1)
			{
				for (int i = 0; i < specials.size(); i++)
				{
					cout << i + 1 << ": " << "name: " << specials[i].getName() << "\tphone: "
					     << specials[i].getPhone() << endl;
				}
				cout << "enter your choose: ";
				cin >> choose;
				if (choose >= specials.size())
				{
					specialPurchase(specials[choose - 1]);
				}
			}
			else
			{
				cout << "your shop has no special clients!!\n";
			}
			break;
		case 3:
			break;
		default:
			cout << "wrong choice!!\n";
			cout << "try again\n";
			purchase();
			break;
	}
}
void Shop::report()
{
	int choose;
	cout << "choose an option below: \n";
	cout << "\t1:view all stuffs\n";
	cout << "\t2:view all clients\n";
	cout << "\t3:view shopping list\n";
	cout << "\t4:view sales list\n";
	cout << "\t5:cancel operation\n";
	cin >> choose;
	system("cls");
	switch (choose)
	{
		case 1:
			for (int i = 0; i < stuffs.size(); i++)
			{
				cout << i + 1 << ": " << "id: " << stuffs[i].getId() << "\ttitle: "
				     << stuffs[i].getTitle() << "\tprice: " << stuffs[i].getPrice()
				     << "\tstock: " << stuffs[i].getStock() << endl;
			}
			break;
		case 2:
			if (clients.size() >= 1)
			{
				cout << "all clients: \n";
				for (int i = 0; i < clients.size(); i++)
				{
					cout << i + 1 << ": " << "name: " << clients[i].getName() << "\tphone: "
					     << clients[i].getPhone() << endl;
				}
			}
			else
				cout << "no clients to show!!\n";
			if (specials.size() >= 1)
			{
				cout << "all special clients: \n";
				for (int i = 0; i < specials.size(); i++)
				{
					cout << i + 1 << ": " << "name: " << specials[i].getName() << "\tphone: "
					     << specials[i].getPhone() << endl;
				}
			}
			else
				cout << "no special client to show!!\n";

			break;
		case 3:
			if (purchases.size() >= 1)
			{
				cout << "all purchases by clients: \n";
				for (int i = 0; i < purchases.size(); i++)
				{
					cout <<'\t'<< i + 1 << ": " << "purchase no: " << purchases[i].getNo() << "\tclient: "
					     << purchases[i].getClient() << "\tprice: " << purchases[i].getPrice()
					     << endl;
				}
			}
			else
				cout << "no purchase made by clients!!\n";
			if (specialPurchases.size() >= 1)
			{
				cout << "\nall purchases by special clients: \n";
				for (int i = 0; i < specialPurchases.size(); i++)
				{
					cout << '\t'<<i + 1 << ": " << "purchase no: " << specialPurchases[i].getNo()
					     << "\tclient: " << specialPurchases[i].getClient() << "\tprice: "
					     << specialPurchases[i].getPrice() << endl;
				}
			}
			else
				cout << "no purchase made by special clients!!\n";
			break;
		case 4:
		{
			int k = 1;
			if (purchases.size() >= 1 || specialPurchases.size() >= 1)
			{
				for (int i = 0; i < purchases.size(); i++)
				{
					vector<Stuff> stuff = purchases[i].getStuff();
					for (int j = 0; j < stuff.size(); j++)
					{
						cout << k << ": " << "title: " << stuff[j].getTitle() << "\tid: "
						     << stuff[j].getId() << "\tcount: " << stuff[j].getStock() << endl;
						k++;
					}
				}
				for (int i = 0; i < specialPurchases.size(); i++)
				{
					vector<Stuff> stuff = specialPurchases[i].getStuff();
					for (int j = 0; j < stuff.size(); j++)
					{
						cout << k << ": " << "title: " << stuff[j].getTitle() << "\tid: "
						     << stuff[j].getId() << "\tcount: " << stuff[j].getStock() << endl;
						k++;
					}
				}
			}
		}
			break;
		case 5:
			break;
		default:
			cout << "wrong choice!!\n";
			cout << "try again\n";
			report();
			break;
	}
}

int main()
{
	int choose, check = 1;
	vector<Stuff> stuffs;
	vector<Client> clients;
	vector<SpecialClient> specials;
	Shop shop(stuffs, clients, specials);
	shop.stuffFile.open("stuff.txt", ios::out);
	shop.clientFile.open("client.txt", ios::out);
	shop.specialFile.open("special.txt", ios::out);
	shop.purchaseFile.open("purchaseFile.txt", ios::out);
	int stuffSize = 0, clientSize = 0, specialSize = 0, purchaseSize = 0, specialPurchaseSize = 0;
	while (check)
	{
		cout << "choose an option below: \n";
		cout << "\t1:add an item\n";
		cout << "\t2:update an item\n";
		cout << "\t3:remove an item\n";
		cout << "\t4:make a purchase\n";
		cout << "\t5:shop reports\n";
		cout << "\t6:exit\n";
		cin >> choose;
		system("cls");
		switch (choose)
		{
			case 1:
				shop.add();
				break;
			case 2:
				shop.update();
				break;
			case 3:
				shop.userRemove();
				break;
			case 4:
				shop.purchase();

				break;
			case 5:
				shop.report();
				break;
			case 6:
				check = 0;
				break;
			default:
				cout << "ERR!!\n";
				cout << "\tplease choose a correct option\n";
				break;
		}
		system("cls");
	}
	return 0;
}
