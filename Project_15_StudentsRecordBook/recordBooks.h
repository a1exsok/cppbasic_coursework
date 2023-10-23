#pragma once
#include <iostream>
namespace recordBooks
{
	class Subject
	{
	public:
		Subject();
		Subject(int Id);
		std::string getSubjectName() {
			return this->subjectName;
		}
		std::string getSubjectMark() {
			return this->mark;
		}
		std::string getDateOfExam() {
			return this->dateOfExam;
		}
		std::string getExaminatorSignature() {
			return this->examinatorSignature;
		}

		std::string getDefaultSubjectNameById(int subjectId);

	private:
		std::string subjectName;
		std::string mark;
		std::string dateOfExam;
		std::string examinatorSignature;
	};

	class recordBook : public Subject
	{
	public:
		recordBook();
		recordBook(std::string _owner, int numberOfSubjects);
		void setOwner(std::string _owner) {
			this->owner = _owner;
		}
		void setBio(std::string _bio) {
			this->bio= _bio;
		}
		std::string getOwner() {
			return this->owner;
		}
		std::string getBio() {
			return this->bio;
		}
		int getNumberOfSubjects() {
			return this->numberOfSubjects;
		}
		Subject* getPtrToSubjectToMarkMap() {
			return this->ptrToSubjectToMarkMap;
		}
		
		void printAllEntries();
		void deleteSubject();
		~recordBook();

	private:
		Subject* ptrToSubject;
		Subject* ptrToSubjectToMarkMap;
		std::string owner;
		std::string bio;
		int numberOfSubjects;
	};

	class allRecordBooks : public recordBook
	{
	public:
		allRecordBooks(int _numberOfStudents);
		void printAllStudentRecordBooks();
		void addRecordBook(std::string _owner, int _numOfSubjects);
		void delRecordBook(int _indexOfRecordBookToRemove);
		int getHowManyStudentsCurrently() {
			return this->studentsCurrently;
		}
		recordBook* getPtrToAllStudentsRecordBooks() {
			return this->ptrToAllStudentRecordBooks;
		}

		~allRecordBooks();

	private:
		int maxSupportedStudents;
		int studentsCurrently;
		recordBooks::recordBook* ptrToRecordBook;
		recordBooks::recordBook* ptrToAllStudentRecordBooks;
	};
}
