/***********************
 * Автор: Бобкова Е.А. *
 * Вариант: 16         *
 ***********************/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct person {
	string surname;
	string name;
	string group;
	int informatics;
	int math;
	int physics;
	double averageScore;
};

void output(person tempPerson, ofstream &fout) {

  cout << tempPerson.surname << " "
    << tempPerson.name << " "
    << tempPerson.group << " "
    << tempPerson.informatics << " "
    << tempPerson.math << " "
    << tempPerson.physics << " Average Score: " << tempPerson.averageScore << endl;

	fout << tempPerson.surname << " "
		<< tempPerson.name << " "
		<< tempPerson.group << " "
		<< tempPerson.informatics << " "
		<< tempPerson.math << " "
		<< tempPerson.physics << " Average Score: " << tempPerson.averageScore << endl;
}

int main() {
	double minScore = 6;
	int personCount;
	person tempPersonData;
	person theWorstStudent;

	cout << "Person Count: " << endl;
	cin >> personCount;

	ifstream in("D:/studentsList.txt");
	ofstream results("D:/studentsListResults.txt");

	if (results.is_open() == 0) {
		cout << "Error of Creating File" << endl;
		return -1;
	}

	if (in.is_open() == 0) {
		cout << "Error of Open" << endl;
		return -1;
	} else {

		for (int personIndex = 0; personIndex < personCount; ++personIndex) {
			in >> tempPersonData.surname
				>> tempPersonData.name
				>> tempPersonData.group
				>> tempPersonData.informatics
				>> tempPersonData.math
				>> tempPersonData.physics;

			tempPersonData.averageScore = (tempPersonData.informatics + tempPersonData.math + tempPersonData.physics) / 3.0;
			output(tempPersonData, results);

			if (minScore > tempPersonData.averageScore) {
				minScore = tempPersonData.averageScore;
				theWorstStudent = tempPersonData;
			}

		}
		in.close();
	}

	cout << "The worst student: " << endl;
	results << "The worst student: " << endl;

	output(theWorstStudent, results);

	results.close();

	return 0;
}