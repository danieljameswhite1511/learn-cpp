
#include <iostream>
#include <vector>

 #include "simpleTasks.h"

//smart pointers

//weak pointer is used in conjunction with the shared pointer
void mainWeakPointer()
{
	std::shared_ptr<int> shared_ptr = std::make_shared<int>(5);
	std::weak_ptr<int> weak_ptr = shared_ptr;//this does not increment ref_count of teh shared pointer
	//can also be empty
	std::weak_ptr<int> emptyWeakPtr;
	//weak pointers are expired when all shared pointers go out of scope

	//copy is fine too
	std::weak_ptr<int> copyWeakPointer = weak_ptr;

	//lock to output value
	std::cout << shared_ptr << "\n"; 
	std::cout << weak_ptr.lock() << "\n";

	//lock generates another shared pointer
	std::shared_ptr<int> sharedFromLock = weak_ptr.lock();//this does increment the ref_count
	std::cout << shared_ptr << "\n";
}

//shared pointer
void mainSharedPointer()
{

	std::shared_ptr<int> shared_ptr = std::make_shared<int>(5);

	std::shared_ptr<int> another_shared_ptr = shared_ptr;

	std::cout << shared_ptr << "\n";
	std::cout << another_shared_ptr << "\n";
	std::cout << *shared_ptr << "\n";
	std::cout << *another_shared_ptr << "\n";

	*another_shared_ptr = 100; 

	std::cout << shared_ptr << "\n";
	std::cout << another_shared_ptr << "\n";
	std::cout << *shared_ptr << "\n";
	std::cout << *another_shared_ptr << "\n";

	//if you want to manually free the memory
	another_shared_ptr.reset(); 

}

//unique pointer
void mainUniquePointer()
{
	//usage is very similar to raw pointer, the difference is that when the variable goes out
	// of scope it will be deleted/memory will be freed automatically
	std::unique_ptr<int> unique_ptr = std::make_unique<int>(5);

	std::cout << unique_ptr << "\n";
	std::cout << &unique_ptr << "\n";
	std::cout << *unique_ptr << "\n";

	//not allowed to copy unique pointer
	//std::unique_ptr<int> anotherUniqueptr = unique_ptr;
	//but it can be moved,	this transfers the ownership and sets uniquePtr to nullPointer
	std::unique_ptr<int> anotherUniquePtr  = std::move(unique_ptr);
}


void mainHeapVariables()
{
	auto c = new int{ 5 };


	std::cout << c << "\n";
	std::cout << &c << "\n";
	std::cout << *c << "\n";
}

void mainPointersAndArrayType()
{
	int intArray[] = { 1,2,3,4,5 };

	std::cout << intArray << "\n"; 
	std::cout << *intArray << "\n";//the array variable only stores the address of the first variable, so array is a pointer?




	for (int i = 0; i < sizeof(intArray)/sizeof(int); ++i)
	{
		std::cout << &intArray[i] << "\n";
		
	}

	for (int i = 0; i < sizeof(intArray) / sizeof(int); ++i)
	{
		std::cout << *(intArray+i) << "\n";

	}
}

void mainPointers()
{
	int x = 5;
	int& anotherX = x; //& defines a reference and means address of
	int* intPointer = &x; //represents a pointer, a pointer is a reference to a memory address
	//a pointer only holds the memory address, and not information about the type it points to
	std::cout << &x << "\n";
	std::cout << anotherX << "\n";
	std::cout << intPointer << "\n";

	*intPointer = 600; //you can deep reference the pointer to change the stored value.
	//pointers are a simple mechanic that does nothing but store the memory address  of a variable

	std::cout << x << "\n";
	std::cout << *intPointer << "\n";
	void* voidPointer = &x;

	//casting(treat value as.)
	std::cout << *(int*)voidPointer;
	std::cout << *static_cast<int*>(voidPointer);

	int** pointerToPointer = &intPointer; //pointer to pointer

}
							

//to reference an external library add header files props\vc++\include dir
// and the .lib files from the build output e.g projnme\x64\debug into props\linker\additional libraries
//also update solution dependencies solution\props\dependencies this will tell the compler to build uitilty also
void mainCallFunctionsFromLibrary()
{
	std::vector<int> numbers = GetRandomNumbers();

	SortVector(numbers);

	printVector(numbers);


}

