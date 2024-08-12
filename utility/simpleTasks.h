#pragma once
#include <vector>

std::vector<int> GetRandomNumbers();

std::vector<int> SortVector(std::vector<int>& vector);

template<typename T>
void printVector(const std::vector<T>& vector);

#include "simpleTasks.inl"

//for template function body must also be defined either here or in .inl file
//template<typename T>
//void printVector(const std::vector<T>& vector)
//{
//	for (int i = 0; i < vector.size(); ++i)
//	{
//		std::cout << vector[i] << " ";
//	}
//
//	for (T element : vector)
//	{
//		std::cout << element << "\n";
//	}
//}

