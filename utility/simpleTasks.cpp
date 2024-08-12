

#include <iostream>
#include <map>
#include <sstream>
#include <vector>
#include "simpleTasks.h"	


//the language compiler creates a function at runtime with the types it is called with
// it will infer types if none are specified based on the values
//template<typename argOne, typename argTwo>
//argOne sum(argOne one, argTwo two)
//{
//	return one + two;
//}
//

//This is required by the recursive call
template<typename T>
T sum(T value)
{
	return value;
}
//variadic template function
// this creates a recursive function call to sum(one, two) 
template<typename argOne, typename... argTwo>
argOne sum(argOne one, argTwo... two)
{
	return one + sum(two...);
}

//specialization for string


std::string sum(std::string value)
{
	return value;
}
 
template<typename... argTwo>
std::string sum(std::string one, argTwo... two)
{
	return one + " " + sum(two...);
}


void mainTemplates()
{
	std::cout << sum<int, int>(1, 2) << ", ";

	std::cout << sum<int, int>(1, 2,3,3,3);

	//this doesn't work as the types ae specified in thsi instance so picks teh wrong template
	std::cout << sum<std::string, std::string>("Dan", "White");
	//works
	std::cout << sum(std::string{ "Dan" }, std::string{ "White" });



}


//bubble sort
//quick sort
//merge sort
//insertion sort
//binary heap sort

template<typename T>

std::vector<T> GetRandomNumbers()
{
	std::vector<T> randomNumbers;

	std::srand(std::time(nullptr));



	for (int i = 0; i <= 20; ++i)
	{
		int number = std::rand() % 100;

		randomNumbers.push_back(number);


	}
	return randomNumbers;
}


std::vector<int> GetRandomNumbers()
{
	std::vector<int> randomNumbers;

	std::srand(std::time(nullptr));



	for (int i = 0; i <= 20; ++i)
	{
		int number = std::rand() % 100;

		randomNumbers.push_back(number);


	}
	return randomNumbers;
}
template<typename T>
std::vector<T> SortVector(std::vector<T> &vector)
{
	for (int i = 0; i < vector.size(); ++i)
	{
		int valueToSort = vector[i];
		int sortIndex = i;

		for (int j = i + 1; j < vector.size(); ++j) {

			if (vector[i] > vector[j]) {
				int valueToSwap = vector[j];
				vector[j] = vector[i];
				vector[i] = valueToSwap;
			}

		}

	}

	return vector;
}

std::vector<int> SortVector(std::vector<int>& vector)
{
	for (int i = 0; i < vector.size(); ++i)
	{
		int valueToSort = vector[i];
		int sortIndex = i;

		for (int j = i + 1; j < vector.size(); ++j) {

			if (vector[i] > vector[j]) {
				int valueToSwap = vector[j];
				vector[j] = vector[i];
				vector[i] = valueToSwap;
			}

		}

	}

	return vector;
}

//template<typename T>
//void printVector(const std::vector<T> &vector)
//{
//	for (int i = 0; i < vector.size(); ++i)
//	{
//		std::cout << vector[i] << " "; 
//	}
//
//	for(T element : vector)
//	{
//		std::cout << element << "\n";
//	}
//}


//void printVector(const std::vector<int>& vector)
//{
//	//for (int i = 0; i < vector.size(); ++i)
//	//{
//	//	std::cout << vector[i] << " ";
//	//}
//
//	for (int element : vector)
//	{
//		std::cout << element << "\n";
//	}
//}



void mainBubbleSortAndTemplates()
{
	std::vector<float> randomNumbers = GetRandomNumbers<float>();
	
	SortVector(randomNumbers);

	printVector<float>(randomNumbers);
}


 

void mainSmallestInt()
{
	std::vector<int> randomNumbers;

	std::srand(std::time(nullptr));

	

	for (int i = 0; i <= 20; ++i)
	{
		int number = std::rand() % 100;
		
		randomNumbers.push_back(number);

	}


	//t smallest = std::numeric_limits<int>::max();
	int smallest = randomNumbers[0];

	if(!randomNumbers.empty())
	{

		for (int i = 0; i < randomNumbers.size(); ++i)
		{
			std::cout << randomNumbers[i] << " ";

			if(randomNumbers[i] < smallest)
			{
				smallest = randomNumbers[i];
			}
		}

	}

	std::cout << "The smallest number is: " << smallest;

 
}

void mainWordCount()
{
	std::string text = "c C c C a c a bb c b B B A a e e ffff f g ggg.hhh g h hhh h c c c c c c c c c c cc h e e e e ";

	std::stringstream ss;
	ss << text;
	std::string nextStr = "";
	std::map<std::string, int> map;


	while (ss >> nextStr)
	{
		std::string word = "";

		 
		if(!map.empty()){

			int charIndex = 0;
			for (char nextCharacter : nextStr)
			{
				charIndex++;

				if(std::isalpha(nextCharacter))
				{
					word.push_back(std::tolower(nextCharacter));
					
				}else
				{
					if(charIndex < nextStr.size())
					{
						std::string leftOverString = nextStr.substr(charIndex);
						ss << ' ' << leftOverString;
					}
					
					break;
				}
			}

			bool exists = map.find(word) != map.end();
			if(exists)
			{
				map[word]++;
			}else
			{
				map.insert({ word, 1 });
			}
		}else
		{
			map.insert({ word, 1 });
		}
		
	}

	for (auto value : map)
	{
		std::cout << value.first << " " << value.second << "\n";
	}
}

void mainOddOrEven()
{
	int number = 0;
	float remainder = 0;

	std::cout << "Please enter a number\n>>>";
	std::cin >> number;

	while(!std::cin.good())
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		std::cout << "Please enter a number\n>>>";
		std::cin >> number;

	}

	remainder = number % 2;

	if(remainder > 0)
	{
		std::cout << "odd\n";
	}else
	{
		std::cout << "even\n";
	}
}


//convert miles to km
void mainMtoKm()
{
	float miles = 0;
	const float multiplier = 1.609;
	std::cout << "Enter the number of miles\n";
	std::cin >> miles;

	float kilometers = multiplier * miles;

	while (!std::cin.good())
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max());
		std::cout << "Enter the number of miles\n";
		std::cin >> miles;
	}


	std::cout << miles << " miles is equal to " << kilometers << " kilometers\n";

	
}
