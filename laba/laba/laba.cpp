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
	cin >> name;
	if (cin.fail())
	{
		cout << "Error" << endl;
		return 0;
	}
	cout << "data\t\t\t"<<"name\t" << "result" << endl;
	//experimental::filesystem::create_directories("C:/Users/User/Desktop/laba/logs");
	for (auto& p : std::filesystem::directory_iterator("C:/Users/User/Desktop/logs"))
	{
		str.push_back(p.path().string());
	}
	for (int i = 0; i < str.size(); i++)
	{
		string a = str[i];
		auto file = fstream(a);
		string f;
		while (!file.eof())
		{
			auto result = f.find(':');
			string name_a = f.substr(result + 1, f.size() - result - 1);
			result = name_a.find(':');
			string name_b = name_a.substr(0, result);
			if (f.find("garbage") && name == name_b)
			{
				result = f.find(':');
				string c = f.substr(0, result);
				result = name_a.find(':');
				string result_a = name_a.substr(result + 1, f.size() - result - 1);
				auto q = a.find('(');
				auto w = a.find(')');
				string data = a.substr(q + 1, w - q - 1);
				cout << data << ":\t";
				cout << name_a << "\t" << result_a << endl;
			}
			getline(file, f);
		}
		file.close();

	}
	return 0;
}