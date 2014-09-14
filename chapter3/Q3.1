//============================================================================
// Name        : threeStack.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

struct StackData {
	int start;
	int pointer;
	int size;
	int capacity;

	StackData(int _start, int _capacity) {
		size = 0;
		start = _start;
		pointer = _start - 1;
		capacity = _capacity;
	}

	bool isWithinStack(int index, int total_size)
	{
		// Note: if stack wraps, the head (right side) wraps around to the left.
		if (start <= index && index < start + capacity) {
			// non-wrapping, or "head" (right side) of wrapping case
			return true;
		} else if (start + capacity > total_size &&
				   index < (start + capacity) % total_size) {
			// tail (left side) of wrapping case
			return true;
		}
		return false;
	}
};

class NStackOneArray {
	int number_of_stacks;
	int default_size;
	int total_size;

	vector<StackData> stacks;
	vector<int> buffer;

public:
	NStackOneArray(int NStack, int stackSize)
	{
		number_of_stacks = NStack;
		default_size = stackSize;
		total_size = default_size * number_of_stacks;

		for(int i=0; i<NStack; i++)
		{
			StackData stack(default_size*i, default_size);
			stacks.push_back(stack);
		}
		buffer.reserve(total_size);
	}

	int numberOfElements() {
		int size;
		for(int i=0; i<number_of_stacks; i++)
		{
			size += stacks[i].size;
		}
		return size;
	}

	int nextElement(int index)
	{
		if (index + 1 == total_size) {
			return 0;
		} else {
			return index + 1;
		}
	}

	int previousElement(int index) {
		if (index == 0) {
			return total_size - 1;
		} else {
			return index - 1;
		}
	}

	void shift(int stackNum)
	{
		StackData &stack = stacks[stackNum];
		if (stack.size >= stack.capacity) {
			int nextStack = (stackNum + 1) % number_of_stacks;
			shift(nextStack); // make some room
			stack.capacity++;
		}
		for (int i = (stack.start + stack.capacity - 1) % total_size; // end of array
					  stack.isWithinStack(i, total_size);
					  i = previousElement(i)) {
			buffer[i] = buffer[previousElement(i)];
		}
		buffer[stack.start] = 0;
		stack.start = nextElement(stack.start); // move start start
		stack.pointer = nextElement(stack.pointer); // move stack pointer
		stack.capacity--; // return capacity to original
	}

	/* Expand stack by shifting over other stacks */
	void expand(int stackNum)
	{
		shift((stackNum + 1) % number_of_stacks);
		stacks[stackNum].capacity++;
	}

	void push(int stackNum, int value)
	{
		StackData &stack = stacks[stackNum];
		/* Check that we have space */
		if (stack.size >= stack.capacity)
		{
			if (numberOfElements() >= total_size) { // Totally full
				cout << ("Out of space.") << endl;
				exit(-1);
			} else // just need to shift things around
			{
				expand(stackNum);
			}
		}
		/* Find the index of the top element in the array + 1,
		 * and increment the stack pointer */
		stack.size++;
		stack.pointer = nextElement(stack.pointer);
		buffer[stack.pointer] = value;

	}

	int pop(int stackNum)
	{
		StackData &stack = stacks[stackNum];
		if (stack.size == 0) {
			cout << ("Trying to pop an empty stack.") << endl;
			exit(-1);
		}
		int value = buffer[stack.pointer];
		buffer[stack.pointer] = 0;
		stack.pointer = previousElement(stack.pointer);
		stack.size--;
		return value;
	}

	int peek(int stackNum) {
		return buffer[stacks[stackNum].pointer];
	}

	bool isEmpty(int stackNum) {
		return stacks[stackNum].size == 0;
	}
};

int main() {

	NStackOneArray nstack(3, 10);

	nstack.push(0, 10);
	nstack.push(1, 20);
	nstack.push(2, 30);

	nstack.push(1, 21);
	nstack.push(0, 11);
	nstack.push(0, 12);

	int val = nstack.pop(0);
	cout << val << endl;

	nstack.push(2, 31);

	nstack.push(0, 13);
	nstack.push(1, 22);

	nstack.push(2, 31);
	nstack.push(2, 32);
	nstack.push(2, 33);
	nstack.push(2, 34);

	val = nstack.pop(1);
	cout << val << endl;

	nstack.push(2, 35);

	return 0;
}
