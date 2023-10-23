#include <iostream>
#include "recordBooks.h"
#include <string>
#include "windows.h" 
#include <iomanip>

using namespace std;

// Utility | Render sample menu:
void runMenu(int _typeOfWindow,  string _input="", string _customText1 = "", string _cText2 = "", int w2=0, int w3=0) {
    switch (_typeOfWindow) {
    case 0:
        cout << "=============== This is the Students' Record Books Database ====================" << endl;
		/*

		cout << string(80,'-') << endl;
		cout << setw(2) << left << "|" << setw(7) << "Action";
		cout << setw(2) << left << "|" << setw(67) << "Description";
		cout << setw(2) << right << "|" << endl;
		cout << string(80,'-') << endl;
		*/
		runMenu(5);
		cout << setw(2) << left << "|" << setw(7) << "a";
		cout << setw(2) << left << "|" << setw(67) << "List the inforation about the Record Books for all the Students.";
		cout << setw(2) << right << "|" << endl;
		cout << string(80,'-') << endl;
        cout << setw(2) << left << "|" << setw(7) << "b";
		cout << setw(2) << left << "|" << setw(67) << "Add another Record Book";
		cout << setw(2) << right << "|" << endl;
		cout << string(80,'-') << endl;
        cout << setw(2) << left << "|" << setw(7) << "c";
		cout << setw(2) << left << "|" << setw(67) << "Remove particular Record Book.";
		cout << setw(2) << right << "|" << endl;
		cout << string(80,'-') << endl;
        break;
    case 1:
        cout << string(80,'=') << endl;
		cout << setw(2) << left << "|" << setw(7) << "";
		cout << setw(2) << left << "|" << setw(67) << "To view and/or modify the particular Record Book, type it's index.";
		cout << setw(2) << right << "|" << endl;
		cout << string(80,'=') << endl;
        break;
	case 2:
        cout << string(80,'=') << endl;
		cout << setw(2) << left << "|" << setw(7) << "";
		cout << setw(2) << left << "|" << setw(67) << "Type the name of the owner for the new Record Book (First.";
		cout << setw(2) << right << "|" << endl;
		cout << string(80,'=') << endl;
        break;
	case 3:
		cout << string(80,'=') << endl;
		cout << setw(2) << left << "|" << setw(7) << "Action";
		cout << setw(2) << left << "|" << setw(67) << "Description";
		cout << setw(2) << right << "|" << endl;
		cout << string(80,'-') << endl;
		cout << setw(2) << left << "|" << setw(7) << "a";
		cout << setw(2) << left << "|" << setw(67) << "Change the Bio of Record Book (short description).";
		cout << setw(2) << right << "|" << endl;
		cout << string(80,'-') << endl;
		break;
	case 4:
		cout << string(106, '-') << endl;
		cout << setw(2) << left << "|" << setw(6) << "Owner";
		cout << setw(2) << left << ":" << setw(32) << _customText1;
		cout << setw(2) << left << "|" << setw(60) << _cText2;
		cout << setw(2) << right << "|" << endl;
		cout << string(106, '-') << endl;
		cout << string(80,'=') << endl;
		cout << _input;
		break;
	case 5:
		cout << string(80,'-') << endl;
		cout << setw(2) << left << "|" << setw(7) << "Action";
		cout << setw(2) << left << "|" << setw(67) << "Description";
		cout << setw(2) << right << "|" << endl;
		cout << string(80,'-') << endl;
		break;
    case 6:
        cout << string(80,'=') << endl;
        cout << "Type 'x' and press ENTER to exit this program\nor type the letter (a,b or c) and follow the instruction." << endl;
		cout << string(80,'=') << endl;
        break;
    case 7:
        cout << string(80,'=') << endl;
		cout << setw(2) << left << "|" << setw(7) << "Return(r)";
		cout << setw(2) << left << "|" << setw(65) << "Return to the previous menu";
		cout << setw(2) << right << "|" << endl;
		cout << string(80,'=') << endl;
        break;
    case 8:
        cout << string(80,'=') << endl;
        cout << setw(31) << "| You've entered the following value: \n\n" << setw(75) << left << _input << endl;
        cout << setw(2) << left << "\n|" << left << setw(75) << _customText1 << endl;
        cout << string(80,'=') << endl;
    default:
        return;
    }

	if (w2 != 0) runMenu(w2);
	if (w3 != 0) runMenu(w3);
}

// Utility | This function is used to help verify the input entered by the user for the different types of typos, mistakes.
string checkAndGetValidInput(string input, string allowedChars = "", bool isOnlyNumber = false, bool onlyOneChar = true) {

	bool isValid = false;
	while (isValid == false)
	{
		try {
			
			/*
			if ((input.size() > 1) && (onlyOneChar == true)) {
				runMenu(8, input, "More than 1 character is not allowed here. Please try again.");
				cin >> input;
			} 
			*/

			if (isOnlyNumber == true) {
				if (0 <= stoi(input) <= 100) return input;
				runMenu(8, input, "The current number is too big or negative. Please try again.");
			} else {
				for (int j = 0;j <= allowedChars.size() - 1;j++) {
					isValid = (input.compare(string(1, allowedChars[j])) == 0) ? true : false;
					if (isValid) return input;
				}
				runMenu(8, input, "The current input is invalid. Please try again.");
				cin >> input;
			}
		}
		catch (invalid_argument) {
			runMenu(8, input, "The current input is invalid. Please try again.");
			cin >> input;
		}
		
	}
	return input;
}


int main() {
	// AllRecordBooks | Initialize default 20 Record Books.
    recordBooks::allRecordBooks* allRecBooks = new recordBooks::allRecordBooks(20) ; 
	// AllRecordBooks | Get a shorter pointer to the long name.
	recordBooks::recordBook* tmpPtr = allRecBooks->getPtrToAllStudentsRecordBooks(); 
	tmpPtr[0].setOwner("Michael");

	string input = "", tmp1 = "", tmp2 = "", tmp3 = "";
    bool goBackInMenu = true, inModifyRecordBookMenu = false;
	int recordBookId = 0;
	
    while (input != "x") {

        if (goBackInMenu) {
            runMenu(0,"","","",6);
            cin >> input;
			input = checkAndGetValidInput(input, "abcxr", false);
            goBackInMenu = false;
        } 

		if (inModifyRecordBookMenu) {
            runMenu(3,"","","",7,6);
			cin >> input;
			input = checkAndGetValidInput(input, "axr", false);

			if (input == "a") {
				runMenu(4, "Enter the new name (First Name SPACE Last Name): ", tmpPtr[recordBookId].getOwner(), tmpPtr[recordBookId].getBio());
				cin >> input >> tmp1;
				tmpPtr[recordBookId].setOwner(input + " " + tmp1);
				tmpPtr[recordBookId].printAllEntries();
				cin >> input;
				if ((input == "b") || (input == "x")) goBackInMenu = true;
			}
		}

		if (input == "a") {
			runMenu(1);
			allRecBooks->printAllStudentRecordBooks();
			runMenu(1,"", "","");
			cin >> input;
			input = checkAndGetValidInput(input, "", true);
			recordBookId = stoi(input);
			tmpPtr[recordBookId].printAllEntries();
			inModifyRecordBookMenu = true;
		}

		if (input == "b") {
			runMenu(4, "Enter (First Name SPACE Last Name) for Record Book owner: ", "", "");
			cin >> input >> tmp1;

			allRecBooks->addRecordBook(input + " " + tmp1, 7);
			cout << "The entry has been updated successfully";
			runMenu(7);
			cin >> input;
			input = checkAndGetValidInput(input, "axr", false);
		}

		if (input == "c") {
			runMenu(4, "Enter the index for the corresponding Record Book to remove: ", "", "");
			cin >> input;
			input = checkAndGetValidInput(input, "", true);
			recordBookId = stoi(input);
			allRecBooks->delRecordBook(stoi(input));
			cout << "The entry has been removed successfully";
			runMenu(7);
			cin >> input;
			input = checkAndGetValidInput(input, "axr", false);
		}

		if (input == "r") {
			goBackInMenu = true;
			if (inModifyRecordBookMenu) inModifyRecordBookMenu = false;
		} else if (input == "x") {
			break;
		}
		
    }
    delete[] allRecBooks;
	allRecBooks = nullptr;

	return 0;
}
