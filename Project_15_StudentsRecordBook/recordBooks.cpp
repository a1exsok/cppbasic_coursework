#include "recordBooks.h"
#include <string>
#include <iomanip>
using namespace std;

namespace recordBooks
{
	// === Utilities 
	void copy_str(char* to, const char* from, size_t size) // Utility for copying strings
	{
		for (size_t i = 0; i < (size - 1); ++i)
		{
			to[i] = from[i];
		}
		to[size - 1] = '\0';
	}

	// ==== Student implementation
	Subject::Subject() {}
	Subject::Subject(int Id)
	{
		this->subjectName = getDefaultSubjectNameById(Id);
		this->mark = "N/A";
		this->dateOfExam = "N/A";
		this->examinatorSignature = "N/A";
	}

	// Default subjects, under the first 7 indexes.
	std::string Subject::getDefaultSubjectNameById(int subjectId) {
		switch (subjectId) {
		case 0:
			return "Math";
		case 1:
			return "Biology";
		case 2:
			return "Chemistry";
		case 3:
			return "Physics";
		case 4:
			return "Economy";
		case 5:
			return "Languages";
		case 6:
			return "The Theory of the Mechanisms and Machines";
		default:
			return "";
		}
	}

	// ==== recordBook implementation
	recordBook::recordBook()
	{
		this->ptrToSubjectToMarkMap = nullptr;
	}

	recordBook::recordBook(std::string _owner, int _numberOfSubjects)
	{
		Subject* ptr = nullptr;
		this->owner = _owner;
		this->bio = "University: KPI, Faculty: MMI, Group: MV21";
		this->numberOfSubjects = _numberOfSubjects;
		this->ptrToSubjectToMarkMap = new Subject[numberOfSubjects];
		for (int i = 0;i <= _numberOfSubjects - 1; i++) {
			ptrToSubject = new recordBooks::Subject(i);
			this->ptrToSubjectToMarkMap[i] = *ptrToSubject;
			
		}
	}

	void recordBook::printAllEntries() {

		cout << string(106, '-') << endl;
		cout << setw(2) << left << "|" << setw(6) << "Owner";
		cout << setw(2) << left << ":" << setw(32) << this->getOwner();
		cout << setw(2) << left << "|" << setw(60) << this->getBio();
		cout << setw(2) << right << "|" << endl;

		cout << string(106, '-') << endl;
		cout << setw(2) << left << "|" << setw(6) << "Index";
		cout << setw(2) << left << "|" << setw(45) << "Subject Name";
		cout << setw(2) << left << "|" << setw(13) << "Date of Exam";
		cout << setw(2) << left << "|" << setw(5) << "Mark";
		cout << setw(2) << left << "|" << setw(25) << "Examinator Signature";
		cout << setw(2) << right << "|" << endl;
		cout << string(106,'-') << endl;


		for (int i = 0; i <= this->numberOfSubjects-1;i++) {
			cout << string(106, '-') << endl;
			cout << setw(2) << left << "|" << setw(6) << i;
			cout << setw(2) << left << "|" << setw(45) << this->getPtrToSubjectToMarkMap()[i].getSubjectName();
			cout << setw(2) << left << "|" << setw(13) << this->getPtrToSubjectToMarkMap()[i].getDateOfExam();
			cout << setw(2) << left << "|" << setw(5) << this->getPtrToSubjectToMarkMap()[i].getSubjectMark();
			cout << setw(2) << left << "|" << setw(25) << this->getPtrToSubjectToMarkMap()[i].getExaminatorSignature();
			cout << setw(2) << right << "|" << endl;
		}
		cout << string(106, '-') << endl;
	}

	void recordBook::deleteSubject() {}

	recordBook::~recordBook()
	{
		delete[] ptrToSubjectToMarkMap;
		ptrToSubjectToMarkMap = nullptr;
	}

	// ==== allRecordBooks implementation
	allRecordBooks::allRecordBooks(int _numberOfStudents) {
		this->maxSupportedStudents = 1000;
		this->studentsCurrently = _numberOfStudents;
		recordBooks::recordBook* ptrToAllStudentRecordBooks = new recordBooks::recordBook[maxSupportedStudents];
		this->ptrToAllStudentRecordBooks = ptrToAllStudentRecordBooks;
		for (int i = 0;i <= studentsCurrently - 1; i++) {
			ptrToRecordBook = new recordBooks::recordBook("Not assigned", 7);
			this->ptrToAllStudentRecordBooks[i] = *ptrToRecordBook;
		}
	}

	void allRecordBooks::printAllStudentRecordBooks() {

		cout << string(80, '-') << endl;
		cout << setw(2) << left << "|" << setw(7) << "Index";
		cout << setw(2) << left << "|" << setw(20) << "Owner";
		cout << setw(2) << left << "|" << setw(45) << "Description";
		cout << setw(2) << right << "|" << endl;
		cout << string(80,'-') << endl;

		for (int i = 0;i <= this->studentsCurrently - 1; i++) {
			cout << string(80, '-') << endl;
			cout << setw(2) << left << "|" << setw(7) << i;
			cout << setw(2) << left << "|" << setw(20) << this->ptrToAllStudentRecordBooks[i].getOwner();
			cout << setw(2) << left << "|" << setw(45) << this->ptrToAllStudentRecordBooks[i].getBio();
			cout << setw(2) << right << "|" << endl;
		}
	}

	void allRecordBooks::addRecordBook(std::string _owner, int _numOfSubjects) {
		ptrToRecordBook = new recordBooks::recordBook(_owner, _numOfSubjects);
		this->ptrToAllStudentRecordBooks[this->studentsCurrently] = *ptrToRecordBook;
		this->studentsCurrently+=1;
	}
	
	void allRecordBooks::delRecordBook(int _indexOfRecordBookToRemove) {
		ptrToRecordBook = new recordBooks::recordBook("Not assigned", 7);
		this->ptrToAllStudentRecordBooks[_indexOfRecordBookToRemove] = *ptrToRecordBook;
	}
	
	allRecordBooks::~allRecordBooks() {
		delete[] this->ptrToRecordBook;
		delete[] this->ptrToAllStudentRecordBooks;
		this->ptrToRecordBook = nullptr;
		this->ptrToAllStudentRecordBooks = nullptr;
	}
}

