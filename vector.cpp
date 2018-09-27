/**
 * @authors Dong Jae Shin, Bernardo Cobos
 * @date 9/25/18
 * input: names to add, name to insert "Doug" into, name to delete
 * output: the vector at differing points
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void printVector(const vector<string>& inputVector);

int main() {
	// define a names vector
	vector<string> names;

	string userInput = "";

	while(userInput != "end" || cin.fail()) {

		if(cin.fail()) {
			cout << "Please enter the names correctly";
			cin.clear(); //clear fail flags
			string junk;
			getline(cin, junk); //flush buffer from potential undesireables
			cin >> userInput;
		}  //end if if
		else {

			cout << "Enter names in sequence or type 'end' to end: " ;
			cin >> userInput;
			if(userInput != "end"){
				names.push_back(userInput);
			} //end of if


		} //end of else
	} //end of ehile

	cout << "task #1: " << endl;
	// prints every elements in the vector
	printVector(names);

	// prints the first and the last name of the vector
	cout << "task #2: " << endl;
	cout << "first name: " << names [0] << " last name: " << names[names.size() - 1] << endl;

	// prints the size of the vector
	cout << "task #3: " << endl;
	cout << "the size of the vector is: " << names.size() << endl;

	cout << "task #4: " << endl;
	for(unsigned int i = 0; names.size() - 1 >= i; i++) {
		if(names[i] == "Alice") names[i] = "Alice B. Toklas";
	}
	printVector(names);

	// inserts the doug on the index of name inputed
	cout << "task #5: " << endl;

	string dougInsert = "";
	printVector(names);
	bool inserted = false;

	string junk;
	getline(cin, junk);

	cin.clear();

	cout << "Enter a name to insert 'Doug' after: ";
	getline(cin, dougInsert);

	vector<string>::iterator it; // declare iterator
	it = names.begin(); // use the iterator to point to the first element

	// loop until the name is inserted correctly
	while(!inserted){
		if(cin.fail()) {

			cout << "Please enter a correct name: " << endl;
			cin.clear(); //clear fail flags
			string junk;
			getline(cin, junk); //flush buffer from potential undesireables
			getline(cin, dougInsert);
		} //end of if

		for(unsigned int i = 0; names.size() - 1 >= i; i ++) {
			cout << dougInsert << names[i];
			// add 'doug' only if the name is in the vector
			if(dougInsert.substr(0, dougInsert.size() - 1) == names[i]){
				inserted = true;
				it++ ;
				break;
			} //end of if
			// count up the iterator when name inputted is not the same as the name in the vector
			else it++;
		} // end of for
	} //  end of while

	// insert doug on iterator assigned
	names.insert(it, "Doug");
	cout << "task #6 " << endl;

	// displays every element in the vector
	printVector(names);

	string nameToRemove = "";

	cout << "Enter a name to remove: " << endl;
	cin >> nameToRemove;

	// delcare the index to erase in the vector
	int eraseIndex = -1;

	while(cin.fail() || eraseIndex == -1){

		for(unsigned int i = 0; names.size() - 1 >= i; i ++) {

			if(nameToRemove == names[i]){ // remove the element if the input and the element is the same
				eraseIndex = i; // save the index to remove
				cout << eraseIndex << endl;
			} // end of while
		}// end of for

		// only execute if the eraseIndex is not updated
		if(eraseIndex == -1){
			cout << "Please enter a correct name to remove: " << endl;

			cin.clear(); //clear fail flags
			string junk;
			getline(cin, junk); //flush buffer from potential undesireables
			cin >> nameToRemove;
			} // end of if
		} // end of while

	// erases the element that has same name as that of user inputted.
	names.erase(names.begin() + eraseIndex);

	// display the current vector
	printVector(names);

	cout << "task #6 : " << endl;

	// copy names to names2
	vector<string> names2 = names;

	vector<string>::iterator iter; // declare iterator
	iter = names.begin(); // use the iterator to point to the first element


	names.erase(iter);

	cout << "first vector after removing the first name: " << endl;
	printVector(names);



	cout << "Copy of vector, taken before removing the first name: "<< endl;
	printVector(names2);
	return 0;
} // end of main

/////////////////////////////////////////
// prints every element in the vector  //
/////////////////////////////////////////
void printVector(const vector<string>& inputVector) {

	for (unsigned int i = 0; i <= inputVector.size() - 1; i ++) {
		cout << inputVector[i] << endl;
	} // end of for

} // end of printVector function
