

#include <iostream>
#include <string>

//constructors and destructors
class Student
{


public:
	Student() = default;
	Student(std::string firstName, std::string lastName, int age,bool active)
		: FirstName{firstName}, LastName{lastName}, Age{age}, Active{active}//initializer more performant
	{
		
	}
	Student(const char* name, const char* lastName, int age) 
		: FirstName{ name }, LastName{ lastName }, Age{age}//initializer more performant
	{

	}
	Student(const char* name, const char* lastName)
		: Student(std::string{name}, std::string{lastName}, 42, true)//initializer more performant
	{

	}

	Student(std::string firstName, std::string lastName, int age)
	{
		FirstName = firstName;
		LastName = lastName;
		Age = age;
	}
	std::string FirstName ;
	std::string LastName;
	int Age;

	~Student()//destructor 
	{
		std::cout << "Bye Bye" << "\n";
	}
private:
	bool Active;


	
};

void main()
{
	Student studentOne;
	studentOne.FirstName = "Dan";

	Student studentTwo{ "Dan", "White", 42 };
	std::cout << studentOne.FirstName << "\n";
	 

}