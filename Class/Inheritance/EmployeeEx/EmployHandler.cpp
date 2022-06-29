#include <iostream>
#include <cstring>

class Employee
{
private:
	char name[100];
	char* misc;
public:
	Employee( char* name_ )
	{
		strcpy(name,name_);
		misc = new char[100];
	}
	void ShowName() const
	{
		std::cout << "Name : " << name << std::endl;
	}

	virtual ~Employee()
	{
		delete[] misc;
	}

	virtual int GetPay() const = 0;
	virtual void ShowSalaryInfo() const = 0;// Abstract Foos
};

class PermanentWorker : public Employee
{
private:
	int salary;

public:
	PermanentWorker( char* name, int salary_ ) : Employee(name), salary(salary_) {}	// using 'Employee' class initialiser 

	int GetPay() const override
	{
		return salary;
	}

	void ShowSalaryInfo() const override	// Name has to be fully in match ! : Do Not Forget to Add 'const' at The End	// dynamic binding 
	{
		ShowName();
		std::cout << "salary : " << GetPay() << std::endl;
	}
};

class SalesWorker : public PermanentWorker
{
private:
	int salesResult;
	double bonusRatio;
	char* memo;

public:
	SalesWorker( char* name, int salary_, double ratio_ ) : PermanentWorker(name,salary_), salesResult(0), bonusRatio(ratio_)	// using 'PermanentWorker' initialiser
	{
		memo = new char[1024];
	}

	~SalesWorker()
	{
		delete[] memo;
	}

	void AddSalesResult(int value)
	{
		salesResult += value;
	}

	int GetPay() const override
	{
		return PermanentWorker::GetPay() + static_cast<int>(salesResult*bonusRatio);	// specification of using 'PermanentWorker::GetPay()'
		// To Access 'salary (private)' in PermanentWorker class ...
	}
	
	void ShowSalaryInfo() const override
	{
		ShowName();
		std::cout << "salary : " << GetPay() << std::endl;
	}
};

class EmployeeHandler
{
private:
	Employee* empList[50];
	int empNum;

public:
	EmployeeHandler() : empNum(0) {}

	void AddEmployee( Employee* emp )
	{
		empList[empNum++] = emp;
	}

	void ShowAllSalaryInfo() const
	{
		for(int i=0;i<empNum;i++)
		{
			empList[i]->ShowSalaryInfo();
		}
	}

	void ShowTotalSalary() const
	{
		int sum = 0;

		for(int i=0;i<empNum;i++)
		{	
			sum += empList[i]->GetPay();
		}
		std::cout << "TotalSalary : " << sum << std::endl;
	}

	~EmployeeHandler()
	{
		for(int i=0;i<empNum;i++)
		{	delete empList[i];
		}
	}
};

int main()
{
	EmployeeHandler handler;
	handler.AddEmployee(new PermanentWorker("Apple",2500));
	handler.AddEmployee(new PermanentWorker("Bannana",1500));

	//Employee* seller = new SalesWorker("WaterMelon",2000,0.13);	// cause no 'AddSalesResult' in Employee class
	SalesWorker* seller = new SalesWorker("WaterMelon",2000,0.125);
	seller->AddSalesResult(15000);
	handler.AddEmployee(seller);

	//
	std::cout << " *** List *** \n";
	handler.ShowAllSalaryInfo();
	handler.ShowTotalSalary();

	return 0;
}
