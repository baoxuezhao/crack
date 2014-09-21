#include <iostream>
using namespace std;

class BitSet
{
private:
	char *bitset;
	int size;
	
public:
	BitSet(int size)
	{
		this.size = size;
		bitset = new char[(size >> 3) + 1]; 
	}
	
	bool get(int idx)
	{
		int byteIdx = idx / 8;
		int bitIdx  = idx % 8;
		return ((bitset[byteIdx] & (1 << bitIdx)) != 0);
	}
	
	void set(int idx)
	{
		int byteIdx = idx / 8;
		int bitIdx  = idx % 8;
		bitset[byteIdx] |= (1 << bitIdx);
	}
	
	~BitSet()
	{
		delete [] bitset;
	}
};

void checkDuplicate(int array[], int n)
{
	BitSet bits(32000);
	for(int i=0; i<n; i++)
	{
		if(bits.get(array[i]-1))
			cout << array[i] << endl;
		else
		{
			bits.set(array[i]-1);
		}
	}
}
