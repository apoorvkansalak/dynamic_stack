#include<process.h>
#include<iostream.h>
#include<conio.h>
#include<stdio.h>

struct emp{				// A structure to hold my values,usually called node
	int eno;
	char name[20];
	emp *ptr;		
};

class dynamic_stack
{
 emp *top;			// Variable holds address of last element
public:
	dynamic_stack()		// Constructor to initialise variables
	{
		top=NULL;		// ALl pointers must be initalise, or it can collapse comp memory
	}
	void indata();
	void deldata();
	void show();
};

// Function body of all the class functions

void dynamic_stack::indata()
{
	//This function takes input from user and adds it to the dynamic stack

	emp *tmp;
	tmp = new(emp);	//allocates memory to the temp variable
	
	cout<<"\nEnter Eno and Name";
	cin>>tmp->eno;
	gets(tmp->name);

	tmp->ptr=top;
	top=tmp;

}

void dynamic_stack::deldata()
{
	emp *tmp;

	if (top==NULL)		//Checking if stack is empty
	{
		cout<<"\nstack is empty";
		getch();
		exit(0);
	}
	else
	{
		tmp=top;
		top=tmp->ptr;
		delete(tmp);		//This free's up the allocated memory to tmp
		cout<<"\nLast element deleted";
	}

}

void dynamic_stack::show()
{
	emp *tmp;
	if (top==NULL)		//To check if stack is empty
	{
		cout<<"\nstack is empty";
		getch();
		exit(0);
	}
	else
	{
		tmp=top;
		while(tmp!=NULL)		//To run loop untill tmp variable becomes NULL
		{
			cout<<"\nEno:"<<tmp->eno;
			cout<<"\nName:"<<tmp->name;
			cout<<endl;

			tmp=tmp->ptr;		//To change the value of tmp
		}
	}
}

void main()
{
	dynamic_stack dq;
	int n;
	char ch='y';
	do
	{
		clrscr();
		cout<<"\nEnter your choice:\n";
		cout<<"\n1.Enter data \n2.Delete data \n3.Show data \n4.Exit\n";
		cin>>n;
		switch(n)
		{
			case 1:
			dq.indata();
			break;
			
			case 2:
			dq.deldata();
			break;

			case 3:
			dq.show();
			break;

			case 4:
			exit(0);
			break;

			default:
			cout<<"\nWrong Choice!!";
		}
		cout<<"\nWant to enter again?";
		cin>>ch;

	}while(ch=='y'||ch=='Y');
	getch();			//Just to hold program
}




