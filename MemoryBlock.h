#pragma once
#include <iostream>
#include <algorithm>
using namespace std;

class MemoryBlock{
public:
	//Simple constructor that initialize the resource
	explicit MemoryBlock(size_t length)
		:_length(length),
		_data(new int[length])
	{
		cout << "In MemoryBlock(size_t). length = "
			<< _length << "." << endl;
	}
	
	//Destructor
	~MemoryBlock()
	{
		cout << "In ~MemoryBlock(). length = "
			<< _length << "." << endl;
		
		if(_data != NULL){
			cout << "Delete resource.";
			delete [] _data;
		}
		cout << endl;
	}
	
	//copy constructor
	MemoryBlock(const MemoryBlock& other)
		:_length(other._length),
		_data(new int[other._length])
	{
		cout << "In MemoryBlock(const MemoryBlock&). length = "
			<< other._length << ".Coping resource." << endl;
		std::copy(other._data,other._data + _length, _data);
	}
	
	//copy assignment operator
	MemoryBlock& operator=(const MemoryBlock& other)
	{
		cout << "In operator=(const MemoryBlock&). length = "
			<< other._length << ".Coping resource." << endl;
		
		if(this != &other)
		{
			delete[] _data;
			
			_length = other._length;
			_data = new int[_length];
			std::copy(other._data,other._data + _length, _data);
		}
		
		return *this;
	}
	
	
	// Move constructor.
	MemoryBlock(MemoryBlock&& other)
		: _data(NULL)
		, _length(0)
	{
		std::cout << "In MemoryBlock(MemoryBlock&&). length = " 
             << other._length << ". Moving resource." << std::endl;
#if 0
		// Copy the data pointer and its length from the 
		// source object.
		_data = other._data;
		_length = other._length;

		// Release the data pointer from the source object so that
		// the destructor does not free the memory multiple times.
		other._data = NULL;
		other._length = 0;
#endif
		*this = std::move(other);
	}

	// Move assignment operator.
	MemoryBlock& operator=(MemoryBlock&& other)
	{
		std::cout << "In operator=(MemoryBlock&&). length = " 
             << other._length << "." << std::endl;

		if (this != &other)
		{
			// Free the existing resource.
			delete[] _data;

			// Copy the data pointer and its length from the 
			// source object.
			_data = other._data;
			_length = other._length;

			// Release the data pointer from the source object so that
			// the destructor does not free the memory multiple times.
			other._data = NULL;
			other._length = 0;
		}
		return *this;
	}
	
	//Retrieves the length of the data resource
	size_t length()const{
		return _length;
	}
	
	
private:
	size_t _length;//The length of the resource
	int* _data;//The resource
};