#include <iostream>

class Test
{
private:
	int* data;
public:
	Test()
	{
		data = new int;
		*data = 0;
	}

	Test( const int data_ )
	{
		data = new int;
		data[0] = data_;
	}

	Test( const Test& obj )
	{
		std::cout << "CopyCons\n";
		data = new int;
		*data = *(obj.data);
	}

	Test& operator=( const Test& obj )	// LeftObj.operator=(obj)	// controls members of 'LeftObj' and return itself as reference
	{
		std::cout << "operator=\n";
		delete data;
		data = new int;
		*data = *(obj.data);
		return *this;
	}

	~Test()
	{
		std::cout << "Destructor Called : " << this << std::endl;
		delete data;
	}

	void Show()
	{	std::cout << "data      : " << *data << std::endl;
		std::cout << "obj  info : " << this  << std::endl;
		std::cout << "data info : " << this->data << std::endl;
	}

	void Set( int num )
	{
		*data = num;
	}
};

void ChangeValByFoo( Test& obj, const int num )
{
	obj.Set(num);
	return;
}

Test ReturnObjByFoo( Test obj )
{
	return obj;
}	

Test* CreateObjByFoo_ReturnTypePtr()
{
	Test* ret = new Test;		// ret is created by new -> need manual Destructor Call later ...
	std::cout << "In Create Foo - RetTypePtr\n";
	ret->Show();
	return ret; 
}

Test& CreateObjByFoo_ReturnTypeRef()
{
	Test ret(10);
	std::cout << "In Create Foo - RetTypeRef\n";
	ret.Show();
	return ret;
}	// This function definition is seriously wrong, return 'ret' is a temporal object & the function is trying to Referencing this temporal Rvalue

Test CreateObjByFoo_ReturnTypeRval()
{
	Test ret(10);
	std::cout << "In Create Foo - RetTypeRVal\n";
	ret.Show();
	return ret;
}

int main()
{
	Test t1;
	t1.Show();

	Test t2(t1);
	t2.Show();

	std::cout << "\n";
	std::cout << "1> ScopeTestStart\n";
	{
		Test t3;
	}
	std::cout << "*> ScopeTestEnd\n";

	std::cout << "\n";
	std::cout << "2> AssignOperatorStart\n";
	Test t3(100);
	t2 = t3;
	std::cout << "t2 info\n";
	t2.Show();
	std::cout << "t3 info\n";
	t3.Show();
	std::cout << "*> AssignOperatorEnd\n";

	std::cout << "\n";
	std::cout << "*> Set 10\n";
	t3.Set(10);
	t3.Show();
	std::cout << "*> Set 123 by Foo \n";
	ChangeValByFoo( t3, 123 );
	t3.Show();
		
	std::cout << "\n";
	std::cout << "Create Obj (by default) and Reset by obj returing foo\n";
	Test t4;
	t4.Show();
	t4 = ReturnObjByFoo(t3);	// Copy Assigned to Already Existing Lvalue 't4' .. i.e., Simply Copy Assigned.
	t4.Show();
	
// C style
	std::cout << "\n";
	std::cout << "CreateObjByFoo and ReturnPointer\n";
	Test* t5 = CreateObjByFoo_ReturnTypePtr();
	std::cout << "Info After Returned\n";
	t5->Show();
	delete t5;			// Destroctur Manually Specified (included in delete command) - Otherwise MemLeak
	std::cout << "\n\n";		// Also Recommended .. a bit OldFashioned tho

// C++ Style
	std::cout << "\n";
	std::cout << "CreateObjByFoo and ReturnReference\n";
	Test t6 = CreateObjByFoo_ReturnTypeRef();	// unexpected data ... Nothing Different with just Create 't6' Here in main();
	std::cout << "Info After Returned\n";
	t6.Show();					// Trash Data Shown .. this method will never work	// Reason Explained Above
	std::cout << "\n\n";
	// Wrong UseOf C++



	// Recommended !!
	std::cout << "*> Use of Universal Reference && : MoveSemantics ... Compare below two cases\n";
	std::cout << "\nCase 1 - Looks Correct Safe Use\n";
	std::cout << "CreatObjByFoo and ReturnRval\n";
	//Test t7 = CreateObjByFoo_ReturnTypeRval();	// This seems the solution !!	// Test& t7 -> cannot be used : reference cannot take Rvalue // This style is more efficient
	Test t7; t7 = CreateObjByFoo_ReturnTypeRval();	// Copy Assign of Temporal Obj (Rval)
	std::cout << "Info After Returned\n";
	t7.Show();
	std::cout << "\n\n";

	std::cout << "\nCase 2\n";
	std::cout << "CreatObjByFoo and ReturnRval\n";
	//Test&& t8 = std::move(CreateObjByFoo_ReturnTypeRval());	// MoveSementics? not Copy but Move	// Error .. casting Rvalue Destroys created obj by 'CreateObjByFoo_ReturnTypeRval()'
	// std::move() seems not required, since return type of Foo is already 'Rval'
	//Test t8 = CreateObjByFoo_ReturnTypeRval();	// MoveSementics - Copy
	Test&& t8 = CreateObjByFoo_ReturnTypeRval();	// MoveSementics - Move (more efficient)	
	//auto t8 = CreateObjByFoo_ReturnTypeRval();
	std::cout << "Info After Returned\n";
	t8.Show();
	//t8.~Test();
	std::cout << "\n\n";

	return 0;
}
