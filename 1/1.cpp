#include<iostream>
#include<string>
#include<memory>
#include<vector>
#include<typeinfo>
using namespace std;
// employers name, department 
class Employee; //forward declaration
class Employer
	{
public:
	string name;
	string department;
	vector<shared_ptr<Employee>> employees_list;
	shared_ptr<Employee> mm;
//	vector<Employee> employees_list;
	vector<string> emp_name;
	Employer(string n, string dept):name{n}, department{dept}
	{
//		cout<<"Employer name :"<<name<<'\n'<<"Department:"<<department<<endl;
	}
 	void get_name()
	{
		cout<<"Employer name :"<<name<<'\n'<<"Department:"<<department<<endl;
	}
	void call_share(shared_ptr<Employee> T)
	{
//		employees_list.pushback(T);
		cout<<typeid(T).name()<<endl;
		cout<<typeid(mm).name()<<endl;
	}

	~Employer()
	{
		cout<<"Employer Destroyed"<<endl;
	}
	friend class Employee;
	};

//Employee details
class Employee : public std::enable_shared_from_this<Employee>
	{
public:
	string name;
	int salary;
	weak_ptr<Employer> A;
	Employee(shared_ptr<Employer> temp,string name, int salary):salary{salary},name{name},A{temp}
	{	shared_ptr<Employer> p1;
                p1 = A.lock();
		cout<<(*p1).name<<endl;
		auto wptr = std::shared_ptr<Employee>( this, [](Employee*){} );
//		cout<<typeid(shared_from_this()).name<<endl;
//		shared_ptr<Employee> k = GetSharedPtr();
//		(*p1).call_share(p2);
        	(*p1).employees_list.push_back(shared_from_this());
//		(*temp).emp_name.push_back(name);
	}
	std::shared_ptr<Employee> GetSharedPtr(){return shared_from_this();}

	void get_info()
	{
		shared_ptr<Employer> p;
                p = A.lock();
		cout<<"Employer name :"<<(*p).name<<'\n'<<"Employee name:"<<name<<'\n'<<"Department:"<<(*p).department<<'\n'<<"Salary(in USD):"<<salary<<endl;
	}
	friend class Employer;
	~Employee()
	{
		cout<<"Employee Destroyed"<<endl;}
	};



int main()
{       
// Writing three employers and their department
	cout<<"Employers..........."<<endl;
	vector<shared_ptr<Employer>> Employer_list;
	Employer_list.push_back(move(shared_ptr<Employer>(new Employer("Apple","ECE"))));
	Employer_list.push_back(move(shared_ptr<Employer>(new Employer("Google","CS"))));
	Employer_list.push_back(move(shared_ptr<Employer>(new Employer("Sony","ME"))));
//	Employer_list[1]->get_name();
	vector<shared_ptr<Employer>>::iterator i;
	for(i = Employer_list.begin(); i != Employer_list.end(); i++)
	{
	(*i)->get_name();
	}
// Writing list of employee, their employer
	vector<shared_ptr<Employee>> Employee_list;
	Employee_list.push_back(shared_ptr<Employee>(new Employee(Employer_list[0],"Josh",1235)));
	Employee_list.push_back(shared_ptr<Employee>(new Employee(Employer_list[1],"Mike",8793)));
	Employee_list.push_back(shared_ptr<Employee>(new Employee(Employer_list[0],"Adrian",9807)));
	Employee_list.push_back(shared_ptr<Employee>(new Employee(Employer_list[2],"Andrew",3452)));
	Employee_list.push_back(shared_ptr<Employee>(new Employee(Employer_list[2],"Penny",2354)));
	Employee_list.push_back(shared_ptr<Employee>(new Employee(Employer_list[0],"Sheldon",1545)));
        cout<<"Saving Done..........."<<endl;
	cout<<'\n'<<endl;
	cout<<'\n'<<endl;
	cout<<'\n'<<endl;
	cout<<'\n'<<endl;
	cout<<"Employees..........."<<endl;

//Print employees name, employer, department and salary
	vector<shared_ptr<Employee>>::iterator l;
	for(l = Employee_list.begin();l!=Employee_list.end();l++)
	{
	(*l)->get_info();
	cout<<'\n'<<endl;
	}

	vector<shared_ptr<Employer>>::iterator j;
	for(j = Employer_list.begin(); j != Employer_list.end(); j++)
	{       cout<<'\n'<<endl;
 		cout<<"Employee:"<<(*j)->name<<endl;

//	vector<string>::iterator m;
//	for(m = (*j)->emp_name.begin(); m != (*j)->emp_name.end(); m++)
//	{
//		cout<<(*m)<<endl;
//	}


	vector<shared_ptr<Employee>>::iterator m;
	for(m = (*j)->employees_list.begin(); m != (*j)->employees_list.end(); m++)
	{
		cout<<(*m)->name<<endl;
	}
	}	
}


