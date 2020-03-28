// Student class is implemented based on string and do not need any change

#include <iostream>
#include <string>
#include <list>
#include <fstream>
#include <map>

using namespace std;

// ----------------------------- Base class

class Person{
	protected:
		string name;

	public:
		void setname(char const *);
		string getname();


		Person(); 				// default constructor
		Person(const char *);
		Person(const Person &); 		// copy constructor

		Person(const string &);

		virtual ~Person();

};

void Person::setname(char const *n)
{
	name = n;
}

string Person::getname()
{
	return name;
}


Person::Person()
{
	name = "";
}

Person::Person(char const *n)
{
	setname(n);
}

Person::Person(const string & n)
{
	name = n;
}

Person::~Person()
{
}

Person::Person(const Person &t):name(t.name)
{
}

// -----------------------------  Student class

class Student : public Person{
	private:
		double grade;

	public:

      	void setgrade(double);
      	double getgrade();

      	Student();    // default constructor
		Student(string, double);
		Student(const Student &);  // copy constructor

		~Student();

	friend ostream & operator<<(ostream &, const Student &);
	friend bool operator==( const Student &, const Student &);

};

void Student::setgrade(double g)
{
	grade =g;
}

double Student::getgrade()
{
	return grade;
}

ostream & operator<<(ostream & out, const Student & s)
{
		out << s.name << "," << s.grade;
		return out;

}

bool operator==( const Student &s, const Student &t)
{
	return s.name == t.name;
}

Student::Student(): grade(0)
{
}

Student::Student(string n, double g): Person(n)
{
	setgrade(g);
}

Student::Student(const Student &t):Person(t.name)
{
	grade = t.grade;
}

Student::~Student()
{
}

int main()
{

	// Write your code for Task 1
	/*list<Student> students;
	double grade;
	string name;
	cout << "Please insert the name and grade of the student (insert -1 to stop): " << endl;
	cin >> name >> grade;
	while(name != "-1"){
		students.push_back(Student(name, grade));
		cout << "Please insert the name and grade of the student (insert -1 to stop): " << endl;
		cin >> name >> grade;
	}

	students.sort();

	list<Student>::iterator i;
	for (i = students.begin(); i != students.end(); ++i)
	{
			cout << *i << endl;
	}*/

	// Task 2
	list<Student> students;
	list<Student>::iterator i;
	ifstream infile("file.txt");
	if (infile.is_open()) {
		string name;
		double grade;
		int counter;
		while (!infile.eof()) {
			infile >> name;
			infile >> grade;
			Student student = Student(name, grade);
			if (grade < 50) {
				counter = 0;
				for (i = students.begin(); i != students.end(); ++i){
						if (*i == student){
							counter++;
						}
				}
				if(counter == 0) {
					students.push_back(student);
				}
			}
		}
		infile.close();
	}
	else {
		cerr << "Unable to open file\n";
	}

	for (i = students.begin(); i != students.end(); ++i)
	{
			cout << i->getname() << endl;
	}

	//Task 3
	/*
	map<string, int> c;
	map<string, int>::iterator it;
	ifstream infile3("filename.txt");
	if (infile3.is_open()) {
		string name;
		double grade;
		int counter = 0;
		while (!infile.eof()) {
			infile >> name;
			infile >> grade;

		infile3.close();
	}
	else {
		cerr << "Unable to open file\n";
	}
	*/
	// I'm sorry, I honestly could not wrap my head around task 1 and 3

	return 0;
}
