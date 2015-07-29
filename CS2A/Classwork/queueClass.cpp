#include <iostream>
using namespace std;

class Queue
{

public:
	int index = 0;
	int lastIndex = 0;
	int maxSize = 100;
	string strArray [100];
	Queue ();
	bool push(string element);
	string pop(void);
};

// CONSTRUCTOR

Queue::Queue () {
	// Initialize String
	for (int i = 0; i < maxSize - 1; i++) {
		strArray[i].clear();
	}
	// Set Last Index Value
	while ((!strArray[lastIndex].empty()) && (lastIndex != maxSize -1)) {  
		lastIndex++;
	}
}


// PUSH FROM QUEUE

bool Queue::push (string element) {
    if (lastIndex >= maxSize-1) {
    	strArray[lastIndex] = element;
    	lastIndex = 0;
    	return true;
    }
    else if (!strArray[lastIndex].empty()) {
    	return false;
    }
    else { 
    	strArray[lastIndex++] = element;
    	return true;
    }
}


// POP FROM QUEUE OF INDEX

string Queue::pop () {
	if (index == maxSize - 1) {
		string temp = strArray[index];
		strArray[index].clear();
		index = 0;
		return temp;
	}
	else if (strArray[index].empty())
		return "Queue is empty";
	else {
		string temp = strArray[index]; 
		strArray[index++].clear(); // make index value null and increment value
		return temp;
	}
}

int main () {

Queue queue;
string userInput, element;
const int MAX_SIZE = 100;

// LOOP TESTS 

for (int i = MAX_SIZE-1; i >= 0; i--) {         // Pushes values from 100 to 1
	string myString = to_string(i);
	queue.push(myString);
}

cout << endl;
cout << "Queue popped:" << endl << endl;

for (int i = 0; i < MAX_SIZE; i++) {         // should pop values in same order as pushed
	cout << queue.pop() << " ";
}

cout << endl << endl << endl;

//USER INPUT TEST

while (true) {
	cout << "push or pop: ";
	getline(cin, userInput);
	if (userInput == "pop") {
		string out = queue.pop();
		cout << out << endl;
	}
	else if (userInput == "push") {
		cout << "Push what: ";
		getline(cin, element);
	    bool confirm = queue.push(element);
	    if (!confirm)
	    	cout << "Cannot push value (reached queue capacity";
	}
}

return 0;
}
