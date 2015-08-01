#include <iostream>
using namespace std;

class Stack {

private:

	const static int STACK_SIZE = 100;
	int stackArray [STACK_SIZE];
	int index = -1;

public:

	bool push (int element);

	int top (void);

	bool pop (void);

	bool isEmpty() { return index < 0; }


};

bool Stack::push (int element) {
	if (index == 99) 
		return false;
	else {
		stackArray[++index] = element;
		return true;
	}
};

int Stack::top () {
	return stackArray[index];
};

bool Stack::pop () {
	if (index == -1) {
		return false;
	}
	else {
		index --;
		return true;
	}
}

int main () {
	Stack stack;
	string userInput;
	int element;

	while (true) {
		cout << "push / pop / top : ";
		getline (cin, userInput);
		if (userInput == "push") {
			cout << "Push what: ";
			cin >> element;
			cin.ignore();
			string confirmed = (stack.push(element))? "Succesful!\n" : "Stack Full\n";
			cout << confirmed;
		}
		else if (userInput == "pop") {
			string confirmed = (stack.pop())? "Succesful!\n" : "Stack Empty\n";
			cout << confirmed;
		}
		else if (userInput == "top")
			cout << stack.top() << endl;
	}
	return 0;
}