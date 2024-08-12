
#include <vector>
//for template function body must also be defined in either .h or .inl files
template<typename T>
void printVector(const std::vector<T>& vector)
{
	for (int i = 0; i < vector.size(); ++i)
	{
		std::cout << vector[i] << " ";
	}

	for (T element : vector)
	{
		std::cout << element << "\n";
	}
}
