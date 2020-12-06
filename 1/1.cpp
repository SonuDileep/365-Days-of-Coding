
// A Simple program which implements inheritance on 3 classes

#include<iostream>
#include<string>

using namespace std;

//Stores name, age and weight 
class Gender
{
public:
	 string name;
	 int age;
	 int weight;
	Gender(string name_, int age_, int weight_):name{name_},age{age_}, weight{weight_}
	{
	 }
	void get_name()
	{
	cout<<this->name<<endl;	
	}
	void get_age()
	{
	cout<<this->age<<endl;
	}
	void get_weight()
	{
	cout<<this->weight<<endl;
	}
	virtual void get_gender() //Called from child classes
	{}

};

// Class which stores name, age and weight of males
class Male:public Gender
{
private:
	bool temp;
public:
	Male(string name_,int age_, int weight_):Gender(name_, age_, weight_)
	{temp = true;}
	void get_gender(){
	cout<<name<<" is a Male"<<endl;
	}
};

// Class which stores name, age and weight of females
class Female:public Gender
{
private:
	bool temp;
public:
	Female(string name_,int age_, int weight_):Gender(name_, age_, weight_)
	{temp = false;}
	void get_gender(){
	cout<<name<<" is a FeMale"<<endl;
	}
};

	int main(){
	Gender *G1,*G2;
	Male m("Mike",23,160);
	Female f("Joan",27,139); 
	G1 = &m;
	G2 = &f;
	G1->get_gender();
	G2->get_gender();
	return 0;
}
