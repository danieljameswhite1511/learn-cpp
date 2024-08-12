#include <iostream>
#include <map>
#include <string>
#include <vector>


void main11()
{
	int age = 10;

	switch(age)//works only with integer or enum
	{
	case 10://must add body to case if you want to initialize variables here
		{
		int i = age;
		std::cout << i << "\n";

		}
	case 4: case 8: case 12:
		std::cout << "go to next school\n";
		break;

	default:
		std::cout << "stay\n";
		break;

	}


	/*enum  Mood
	{
		happy = -1, angry, sad = 1000
	};*/
	enum class Mood
	{
		happy = -1, angry, sad = 1000
	};

	Mood mood = Mood::happy;
	switch (mood)
	{
	case Mood::happy:
		std::cout << "you are happy" << "\n";
		break;

	case Mood::angry:
		std::cout << "you are angry" << "\n";
		break;

	case Mood::sad:
		std::cout << "you are sad" << "\n";
		break;
	default:

		std::cout << "you are hard to read\n";
	}
}

//while loops
void main10()
{
	int i = 10;

	while (i < 5)//same as for(;condition;)
	{
		std::cout << i << "\n";
		i++;
	}

	do//will always run atleast once; runs once without checking conditions
	{


		i++;
		
	} while (i < 10);
}


//for loop with arrays and vectors
void main9()
{

	int array[]{ 1,2,3,4,5 };

	for(int i = 0; i < sizeof(array)/sizeof(int); i++)
	{
		std::cout << array[i] << "\n";
	}
	std::cout << "#####################\n";
	for(int item : array)
	{
		std::cout << item << "\n";
	}
	std::cout << "#####################\n";
	std::vector<int> vectorArray{1,2,3,4,5}; 

	for (int i = 0; i < vectorArray.size(); i++)
	{
		std::cout << array[i] << "\n";
	}
	std::cout << "#####################\n";
	for (int item : vectorArray)
	{
		std::cout << item << "\n";
	}
	std::cout << "#####################\n";
	for (std::vector<int>::iterator itr = vectorArray.begin(); itr != vectorArray.end(); itr++)
	{
		std::cout << *itr << "\n";
	}

}

//for loop
void main8()
{
	int accumulatedValue = 0;

	for (int i = 0; i <= 100; i++)
	{
		accumulatedValue += i;
	}

	std::cout << accumulatedValue;

	for (int i = 0; i <= 100; i++)
	{
		if(i >100)
		{
			//exits the for loop 
			break;
		}
		accumulatedValue += i;
	}

	std::cout << accumulatedValue;

	for (int i = 0; i <= 100; i++)
	{
		if (i > 100)
		{
			//skips this increment
			continue;
		}
		accumulatedValue += i;
	}

	std::cout << accumulatedValue;




}

//flow control construct
// if statement
void main7()
{
	int age;
	std::cout << "Please enter your age\n";
	std::cin >> age;

	if (age > 20)
	{
		std::cout << "You are old enough to play the game\n";
	}//scope/code block
	else
	{
		std::cout << "!old enough to play the game";
	}
	if(age == 10)
	{
		std::cout << "You are " << age << "\n";
	}

	if (age != 10)
	{
		std::cout << "You are not 10" << "\n";
	}

	if (!(age == 300))
	{
		std::cout << "You are not 300"  << "\n";
	}
}

void main6(){

	int age;
	std::string firstName;
	std::string surname;

	std::cout << "Please enter your age:\n";
	//cin uses the input stream buffer
	std::cin >> age;
	std::cin.clear();//clear error from the buffer 
	std::cin.ignore(1000000, '\n');
	std::cout << "you have been around the sun " << age << " times\n";
	std::cout << "Enter your full name: \n";
	//items held in the buffer are separated by spaces
	std::cin >> firstName;
	std::cin >> surname;
	std::cout << firstName << " " << surname << "\n";


	std::cin.clear();//clear error from the buffer 
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	//to get a string including the spaces use getLine
	std::cout << "type a sentence\n";
	std::string name;
	std::getline(std::cin, name);
	std::cout << "Hello " << name << "\n";




	
}

//Arithmetic operators

void main5()
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