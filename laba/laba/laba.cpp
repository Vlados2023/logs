#include<iostream>
#include<string>
#include<fstream>
#include <vector>
//#include<experimental/filesystem>
#include<filesystem>
using namespace std;

int main()
{
	string name;
	vector <string> str;
	string name_f;
	cout << "enter the directory:";
	cin >> name_f;
	if (cin.fail())
	{
		cout << "Error";
		return 0;
	}
	cout << "device:";
	cin >> name;
	if (cin.fail())
	{
		cout << "Error" << endl;
		return 0;
	}
	cout << "data\t\t\t"<<"name\t" << "result" << endl;
	//experimental::filesystem::create_directories("C:/Users/User/Desktop/laba/logs");
	for (auto& p : std::filesystem::directory_iterator(name_f))            //записывает пути всех файлов в массив str (динамический)
	{
		str.push_back(p.path().string());         //запись в массив str путей, в строчках, пути к логам
	}
	
  
	for (int i = 0; i < str.size(); i++)         // считывание строки
	{
		string a = str[i];    //создаем переменную типа string и присваиваем ей значение для элемента вектора
		auto file = fstream(a);
		string f;
		while (!file.eof())
		{
			auto result = f.find(':'); //первое двоеточие
			string name_a = f.substr(result + 1, f.size() - result - 1);      //после 1 двоеточия
			result = name_a.find(':');//второе двоеточие
			string name_b = name_a.substr(0, result);          //имя без двоеточий
			if (f.find("garbage")==-1 && name == name_b)
			{
				result = f.find(':');  //первое двоеточие
				string c = f.substr(0, result); //от начала и до 1 двоеточия вместе с ним
				result = name_a.find(':');//второе двоеточие
				string result_a = name_a.substr(result + 1, f.size() - result - 1);            // после девайса и двоеточия
				auto q = a.find('(');
				auto w = a.find(')');
				string data = a.substr(q + 1, w - q - 1); // дата
				cout << data << ":\t";
				cout << name_a << "\t" << result_a << endl;
			}
			getline(file, f);
		}
		file.close();

	}
	return 0;
}