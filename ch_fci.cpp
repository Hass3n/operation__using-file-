#include<Windows.h>
#include<mmsystem.h>
#include <string.h>
#include<string>
#include<iomanip>
#include<iostream>
#include<fstream>
#include<cctype>
#include<conio.h>
#include<iomanip>
#include<string>
#include<Windows.h>

using namespace std;
class child
{
private:

	string id;
	string name_child;
	string name_parent;
	string  name_mother;
	string blood_type;
	string adress;
	string age;
	string  national_id;
	string phone;

public:	void en_st()
{

			cout << "enter the id " << endl;
			cin >> id;
			cout << "enter the name of child " << endl;
			cin >> name_child;
			cout << "enter the name of parent " << endl;
			cin >> name_parent;
			cout << "enter the name of mother " << endl;
			cin >> name_mother;
			cout << "enter the age of child " << endl;
			cin >> age;
			cout << "enter the type of blood " << endl;
			cin >> blood_type;
			cout << "enter the adress " << endl;
			cin >> adress;
			cout << "enter the national_id " << endl;
			cin >> national_id;
			cout << "enter the num phone " << endl;
			cin >> phone;

}
		 // write in file
		void write_data(fstream &f)
		{
			f << id << "|";
			f << name_child << "|";
			f << name_parent << "|";
			f << name_mother << "|";
			f << age << "|";
			f << blood_type << "|";
			f << adress << "|";
			f << national_id << "|";
			f << phone << "|";
			f << "\n";
		}
		// read frpm file
		void Read_data(fstream &f)
		{
			f.seekg(0, ios::beg);
			while (getline(f, id, '|'))
			{
				getline(f, name_child, '|');
				getline(f, name_parent, '|');
				getline(f, name_mother, '|');
				getline(f, age, '|');
				getline(f, blood_type, '|');
				getline(f, adress, '|');
				getline(f, national_id, '|');
				getline(f, phone, '\n');

				cout << "\n id : " << id << endl;
				cout << "\t child name : " << name_child << endl;
				cout << "\t parent name: " << name_parent << endl;
				cout << "\t mother name: " << name_mother << endl;
				cout << "\t age : " << age << endl;
				cout << "\t blood type : " << blood_type << endl;
				cout << "\t adress: " << adress << endl;
				cout << "\t person id : " << national_id << endl;;
				cout << "\t phone : " << phone << endl;
			}


		}
		// search data with id
		void searchby_id(fstream &f, int pid)
	        {
			bool flag = false;
			while (getline(f, id, '|'))
			{
				getline(f, name_child, '|');
				getline(f, name_parent, '|');
				getline(f, name_mother, '|');
				getline(f, age, '|');
				getline(f, blood_type, '|');
				getline(f, adress, '|');
				getline(f, national_id, '|');
				getline(f, phone, '\n');

				if (pid == atoi(id.c_str()))
				{
					cout << "\n id : " << id << endl;
					cout << "\t child name : " << name_child << endl;
					cout << "\t parent name: " << name_parent << endl;
					cout << "\t mother name: " << name_mother << endl;
					cout << "\t age : " << age << endl;
					cout << "\t blood type : " << blood_type << endl;
					cout << "\t adress: " << adress << endl;
					cout << "\t national_id: " << national_id << endl;;
					cout << "\t phone : " << phone << endl;
					flag = true;
					break;
				}
			}
			if (flag==false)
			{
				cout << "sorry------not Found-------" << endl;
			}
		}
		// update data with id....................................
		 
		void up_ch(int pid)
		{
			bool flag = false;
			string x1;
			cout << "enter the first path which you can red the data and update " << endl;
			cin >> x1;
			string x;
			cout << "enter the second path you can put the new data" << endl;
			cin >> x;

			fstream f(x1, ios::in);
			fstream f1(x, ios::out);
			f.seekg(0, ios::beg);
			while (getline(f, id, '|'))
			{
				getline(f, name_child, '|');
				getline(f, name_parent, '|');
				getline(f, name_mother, '|');
				getline(f, age, '|');
				getline(f, blood_type, '|');
				getline(f, adress, '|');
				getline(f, national_id, '|');
				getline(f, phone, '\n');

				if (pid == atoi(id.c_str()))
				{
				
					en_st();
					write_data(f1);
					flag = true;
					break;
					
				}
				else
				{
					f1 << id << "|";
					f1 << name_child << "|";
					f1 << name_parent << "|";
					f1 << name_mother << "|";
					f1 << age << "|";
					f1 << blood_type << "|";
					f1 << adress << "|";
					f1 << national_id << "|";
					f1 << phone << "|";
					f1 << "\n";
					

				}
				
			}
		if (flag == false)
			{
				cout << "the update is not" << endl;
			}
			f.close();
			f1.close();
		}
		// delete data with id
		void delete_ch(int pid)
		{
			bool flag = false;
			string x1;
			cout << "enter the first path which you can red the data and delete " << endl;
			cin >> x1;
			string x;
			cout << "enter the second path you can put the new data" << endl;
			cin >> x;

			fstream f(x1, ios::in);
			fstream f2(x, ios::out);
			f.seekg(0, ios::beg);
			while (getline(f, id, '|'))
			{
				getline(f, name_child, '|');
				getline(f, name_parent, '|');
				getline(f, name_mother, '|');
				getline(f, age, '|');
				getline(f, blood_type, '|');
				getline(f, adress, '|');
				getline(f, national_id, '|');
				getline(f, phone, '\n');

				if (pid != atoi(id.c_str()))
				{
					f2 << id << "|";
					f2 << name_child << "|";
					f2 << name_parent << "|";
					f2 << name_mother << "|";
					f2 << age << "|";
					f2 << blood_type << "|";
					f2 << adress << "|";
					f2 << national_id << "|";
					f2 << phone << "|";
					f2 << "\n";
					flag = true;
					break;
				}
			}
			if (flag == false)
			{
				cout << "the opeartion delete is not valid" << endl;
			}
			f.close();
			f2.close();
			


		}

};
int main(){

	//welcome screen
	for (int i = 0; i < 10; i++)
	{
		system("color 3A");
		Beep(i * 200, i * 100);
		cout << "\n";  
		cout << "              **      :::::::  !!!!!!!!           \n";
		cout << "           _____  **      ::       !!    !!         _____  \n";
		cout << "                **      ::       !!    !!                \n";
		cout << "              ******  :::::::  !!!!!!!!            \n";
		cout << "\n\n";
		cout << "\n\n";
		cout << "	      ~	__  ~ __  ~ __                  \n";
		cout << "	         |==|  |==|  |==|                 \n";
		cout << "	     __|__|__|__|__|__|_                \n";
		cout << "	  __|___________________|___            \n";
		cout << "       __|__[]__[]__[]__[]__[]__[]__|___         E L  G E N I U S\n";
		cout << "      |............................o.../ \n";
		cout << "      \\.............................../ \n";
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
		cout << " ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ \n";
		cout << "  ~  ~  ~  ~  ~  ~  ~  ~  ~  ~  ~  ~  ~  ~  ~  ~\n";
		cout << "    ~    ~     ~    ~    ~    ~    ~    ~    ~  \n";
		cout << "     ~    ~      ~    ~     ~    ~    ~      ~";
		cout << "\t\tby********* delimiter team *******\a\t  " << " \n";
		for (long j = 0; j < 80000000; j++){}
		system("cls");
	}

	Sleep(1000);
	cout << "\t\twelcome ********  in Project  File c++ ***********\a\t " << char(1) << " \n\t";
	cout << "\t\tby********* delimiter team *******\a\t  " << char(1) << " \n"; Sleep(1000);
	for (int i = 0; i < 20; i++)
	{
		cout << "  .  "; Sleep(100);
		Beep(700, 100);
	}

	cout << endl;

	system("color 3F");
	char pass[5];
	char password[5] = { '1', '2', '3', '4', '5' };

	int count = 0;
	string s = "handle";
	char p = 'A';
	cout << "enter your Usename " << endl;
	cin >> s;
	cout << "\nEnter your passwored:  " << endl;



	while (p != 'E')
	{
		if (count != 5)
		{
			count = 0;
			for (int i = 0; i < 5; i++)
			{
				p = _getch();
				if (p >= '0'&&p <= '9')
				{
					pass[i] = p;
					cout << "*";
				}
				else
					i--;
			}
			for (int i = 0; i < 5; i++)

			{
				if (pass[i] == password[i])
					count++;
			}
		}
		if (count == 5)
		{
			system("cls");
			system("color 2A");
			cout << "\nwelcome thats password is true" << endl;
			cout << "please entre  E..." << endl;
			cin >> p;

			if (p == 'E')
			{
				fstream file;
				child p; int id;
				char choose = ' ';
				cout << "Do you want to start (y,n) : "; cin >> choose;
				bool x = false;
				while (choose == 'y' || choose == 'Y')
				{
					int ch = 0;
					system("cls");
					cout << "  1 to add new child \n2 to view all child \n3 to search by id\n4to update child data by id \n5 to delete child by id \n";
					cin >> ch;
					switch (ch)
					{
					case 1:
					{
							  system("color 2B");
							  char c = 'n';
							  string x;
							  cout << "enter the path of the file to write the data" << endl;
							  cin >> x;
							  file.open(x, ios::app);
							  do
							  {
								  system("cls");
								  p.en_st();
								  p.write_data(file);
								  cout << "do you want to add another child (y,n) : ";
								  cin >> c;
							  } while (c == 'y' || c == 'Y');
							  file.close();
							  break;
					}
					case 2:
					{
							  system("color 3F");
							  system("cls");

							  string x;
							  cout << "enter the path of the file to read the data" << endl;
							  cin >> x;


							  file.open(x, ios::in);
							  p.Read_data(file);



							  file.close();

							  break;
					}

					case 3:
					{
							  system("color 4A");
							  system("cls");
							   string x;
							  cout << "enter the path of the file to search the data" << endl;
							   cin >> x;
							   file.open(x, ios::in);

							  cout << "enter child id you want to search : "; cin >> id;
							  p.searchby_id(file, id);
							  file.close();
							  break;
					}

					case 4:
				     	{                  int x;
									  system("color 3A");
							 		  system("cls");

									  cout << "enter the id of childeren" << endl;
									  cin >> x;

									  p.up_ch(x);
									  break;
									
							
					}
					case 5:
					{         int x;
					system("color 3C");
					system("cls");

					cout << "enter the id of childeren" << endl;
					cin >> x;

					p.delete_ch(x);
				

					break;
					}
					}


					cout << "do you want to start again (y,n) : ";
					cin >> choose;
					cout << endl;

				}
			}


		}
		else
		{
			system("cls");
			cout << "\n false TRY Again error username OR password " << endl;
			//	cin >> s;
		}
	}
	////////////////////////////////////////////////////////////////////////

	system("pause");
	return 0;
}