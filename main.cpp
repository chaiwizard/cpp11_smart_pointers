// rvalue-references-move-semantics.cpp
// compile with: /EHsc
#include "MemoryBlock.h"
#include <vector>

using namespace std;

int main()
{
   // Create a vector object and add a few elements to it.
   vector<MemoryBlock> v;
   v.push_back(MemoryBlock(25));
   cout << "-----------------1" <<endl;
   v.push_back(MemoryBlock(75));
   cout << "-----------------2" <<endl;
   // Insert a new element into the second position of the vector.
   v.insert(v.begin() + 1, MemoryBlock(50));
   cout << "-----------------3" <<endl;
   
   
   vector<int> arr;
   arr.push_back(1);
   arr.push_back(2);
   arr.insert(arr.begin() + 1, 3);
   for(auto i : arr){
	   cout << i << " ";
   }
   cout << endl;
   
   return 0;
}