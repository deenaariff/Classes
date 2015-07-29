#include <iostream>
#include <string>
using namespace std;

const int MAX_SIZE = 100;

// PUSH TO QUEUE

bool push (string (&strArray) [MAX_SIZE], string element, int &lastIndex) {
    if (lastIndex >= MAX_SIZE-1) {
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

string pop (string (&strArray) [MAX_SIZE], int &index, int lastIndex) {
	if (index == MAX_SIZE - 1) {
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

	string strArray [MAX_SIZE];
	int index = 0, lastIndex = 0;
	string userInput, element;

	// Doesn't operate in constant time but is not push or pop method
	for (int i = 0; i < MAX_SIZE - 1; i++)
		strArray[i].clear();
	while ((!strArray[lastIndex].empty()) && (lastIndex != MAX_SIZE -1)) {  
		lastIndex++;
	}

	/* LOOP TESTS */

	for (int i = MAX_SIZE-1; i >= 0; i--) {         // Pushes values from 100 to 1
		string myString = to_string(i);
		push(strArray, myString, lastIndex);
	}

	cout << endl;
	cout << "Queue popped:" << endl << endl;

	for (int i = 0; i < MAX_SIZE; i++) {         // should pop values in same order as pushed
		cout << pop(strArray, index, lastIndex) << " ";
	}

	cout << endl << endl << endl;

	//USER INPUT TEST

	while (true) {
		cout << "push or pop: ";
		getline(cin, userInput);
		if (userInput == "pop") {
			string out = pop(strArray, index, lastIndex);
			cout << out << endl;
		}
		else if (userInput == "push") {
			cout << "Push what: ";
			getline(cin, element);
		    bool confirm = push(strArray, element, lastIndex);
		    if (!confirm)
		    	cout << "Cannot push value (reached queue capacity";
		}
	}
	
}

int main () {

	Queue queue;

	/* LOOP TESTS */

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


