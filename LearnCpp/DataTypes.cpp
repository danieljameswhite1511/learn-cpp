#include <iostream>
#include <map>
#include <string>
#include <vector>


//Arithmetic operators

void main()
{
	int a = 10;
	int b = 20;
	int c = a + b;
	int d = a - b;
	int e = b / a;
	int f = a / b;
	int g = a % b;
	int h = 0.6;

	float a1 = 10;
	float b1 = 20;
	float c1 = a1 + b1;
	float d1 = a1 - b1;
	float e1 = b1 / a1;
	float f1 = a1 / b1;
	//float g1 = a1 % b1; not supported

	a++;
	a--;
	--a;
	++a;

	//comparison operators	

	bool ab = a == b;
	ab = a != b;
	ab = a >= b;
	ab = a <= b;


	//logical operators



	std::cout << c << "\n";
	std::cout << d << "\n";
	std::cout << e << "\n";
	std::cout << f << "\n";
	std::cout << g << "\n";
	std::cout << h << "\n";

	std::cout << c1 << "\n";
	std::cout << d1 << "\n"; 
	std::cout << e1 << "\n";
	std::cout << f1 << "\n";
	//std::cout << g1 << "\n";


}


//map
//accessing a key that does not exist wil result in the key being create e.g. if the key is a string and
//the value is and int a row with value 0 will be created
void main4()
{
	std::map<int, std::string> map{{1,"Dan"}, {2,"iel"}};
	map.insert({ 3, " " });
	map.insert({ 4, "White" });

	std::cout << map[1] << map[2] << map[3] << map[4] << "\n";

	map[2] = "";

	std::cout << map[1] << map[2] << map[3] << map[4] << "\n";

	map.erase(4);

	std::cout << "map size is : " << map.size() << "\n";
	std::cout << map[1] << map[2] << map[3] << map[4] << "\n";

	
	std::cout << "map size is : " << map.size() << " but you might expect it to be 3" <<"\n";

	map.clear();

	bool exists = map.find(1) != map.end();

	std::cout << exists;

}



//Vector	
// can change size
void main3()
{
	std::vector<std::string> stringVector = {"Ma", "Ma", "Mia"};

	std::cout << stringVector[0] << "\n";
	std::cout << stringVector[1] << "\n";
	std::cout << stringVector[2] << "\n";
	std::cout << "vector length = " << stringVector.size() << "\n";
	std::cout << "Last element is " << stringVector.back() << "\n";

	stringVector.push_back("Figaro!");

	std::cout << "vector length = " << stringVector.size() << "\n";
	std::cout << "Last element is " << stringVector.back() << "\n";




}


//Array
// will not throw error for out of bounds, can not change size
void main2() {

	std::string stringArray[]{ "Ma", "Ma", "Moa" };

	std::cout << stringArray[0] << '\n';
	std::cout << stringArray[1] << '\n';
	std::cout << stringArray[2] << '\n';
	//std::cout << stringArray[3] << '\n';

	std::cout << "Length of array = "  << sizeof(stringArray) / sizeof(std::string) << "\n";
	std::cout << "Last element is " << stringArray[sizeof(stringArray) / sizeof(std::string)-1]  << "\n";
}


//basic types
void main1() {

	std::string name = "Dan";
	int	age = 1; 
	float temperature = 34.1;
	char character = 'D';
	bool isChar = true;

	std::cout << name << " " << age << std::endl;
	std::cout << name + " " + std::to_string(age) << std::endl;
	std::cout << "The temperature is " << temperature << std::endl;

	std::cout << "The size of a string = " << sizeof(std::string) << "bytes" << std::endl;
	std::cout << "The size of an int = " << sizeof(int) << "bytes" << std::endl;
	std::cout << "The size of a char = " << sizeof(char) << "bytes" << std::endl;
	std::cout << "The size of a float = " << sizeof(float) << "bytes" << std::endl;
	std::cout << "The size of a double = " << sizeof(double) << "bytes" << std::endl;

	std::cout << "The size of a bool = " << sizeof(bool) << "bytes" << std::endl;
}