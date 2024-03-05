#include<iostream>
#include<conio.h>
#include<fstream>
#include<cstring>
void menu();
using namespace std;
class Base{
	 public:
	 virtual void get()=0;
	 virtual void show()=0;	 
};
class info:public Base{
    public:
	char name[50],time[50];
	int num,age;
	void get(){
	   	cin.sync();
		cout<<"\nEnter The Patient Name =";
		cin.getline(name,50);
		cout<<"\nEnter The Appoinment Time =";
		cin.getline(time,50);
		cout<<"\nEnter Age =";
		cin>>age;
		cout<<"\nEnter Appoinment No =";
		cin>>num;
		}
		void show(){
			cout<<"\nName = "<<name;
			cout<<"\nAge ="<<age;
			cout<<"\nNo ="<<num;
			cout<<"\nTime ="<<time;
		}
};
class shammas:public info{
	public:
	info a1;
	void get(){
		ofstream out("shammas.txt",ios::app);
		a1.get();
		out.write((char*)&a1,sizeof(info));
		out.close();
		cout<<"Your Entry Has been saved ";
		getch();
		menu();
	}
	void show(){
		ifstream in("shammas.txt");
		if(in==NULL){
			throw "No data in File";
			cout<<"\n\n\t\tPress Any key To Continue : ";
			getch();
			menu();
		}
		else{	
		while(!in.eof()){
         in.read((char*)&a1,sizeof(a1));
       	a1.show();
		}
		in.close();
		getch();
		menu();
	}
	}
};
class wasiq:public info{
	public:
	info a1;
	void get()
	{
		ofstream out("wasiq.txt",ios::app);
		a1.get();
		out.write((char*)&a1,sizeof(info));
		out.close();
		cout<<"Your Entry Has been saved ";
		getch();
		menu();
	}
	void show(){
		ifstream in("wasiq.txt");
		if(in==NULL){
				throw "No data in File";
			cout<<"\nPress Any key To Continue : ";
			getch();
			menu();
			}
		else{
		while(!in.eof()){
        in.read((char*)&a1,sizeof(a1));
	    a1.show();
		}
		in.close();
		cout<<"Press Enter To Continue =";
		getch();
		menu();
	}
	}
};
class zartashia:public info{
	public:
	info a1;
	void get(){
		ofstream out("zartashia.txt",ios::app);
		a1.get();
		out.write((char*)&a1,sizeof(info));
		out.close();
		cout<<"Your Entry Has been saved ";
		getch();
		menu();
	}
		void show(){
		ifstream in("zartashia.txt");
		if(in==NULL){
			
	throw "No data in File";
		
			cout<<"\nPress Any key To Continue : ";
			getch();
			menu();
		}
		else
		{
		
		while(!in.eof()){
         in.read((char*)&a1,sizeof(info));
		a1.show();
		}
		in.close();
	}
	}
};
class staff:public Base{
	public:
	char all[999];
	char name[50],age[20],sal[30],pos[20];;
	void get()
	{
		ofstream out("staff.txt",ios::app);
		{ 
			cin.sync();
			cout<<"\nEnter Name = ";
			cin.getline(name,50);
			cout<<"\nEnter Age  = ";
			cin.getline(age,20);
			cout<<"\nEnter Sallary = ";
			cin.getline(sal,30);
			cout<<"\nEnter Working Position =";
			cin.getline(pos,20);
		}
		out<<"\nName = "<<name<<"\nAge "<<age<<"\nSallary"<<sal<<"\nWorking Position\n"<<pos;
		out.close();
		cout<<"\n\nYour Information has been saved :\n\t\t\tPress any key to continue  ";
		getch();
		menu();
	}
	void show()
	{
		
	  ifstream in("staff.txt");
	  if(!in){
	  	
	throw "File Opening ERROR!!";
	}
	  
	  while(!(in.eof()))
	  {
	  	in.getline(all,999);
	  	cout<<all<<endl; 	
	  }	
	  in.close();
	  cout<<"\n\n\t\t\tPress Any Key To Continue : ";
	  getch();
	  menu();
	}	
};
class information{
	public:
	void drinfo() 
	{
	cout<<"\n===================================\n";
	cout<<"\n\n\t\t(Three Doctor Available) \n\n \t\t\[Infotmation And Timing Are Given Below]\n";
	cout<<"----------------------------------------\n";
	cout<<"\t\tDr Available:\n";
	cout<<"\n\t\tDr. Shammas (skin specialist)\n\n";
	cout<<"\t\t\t [[Timing]]:\n\n";
	cout<<"\tMonday To Friday\t\t9AM TO 5PM\n";
	cout<<"\tSatuday         \t\t9AM TO 1PM\n";
	cout<<"\tSunday          \t\t Off\n";
	cout<<"\n---------------------------------------\n";
	cout<<"\t\tDr. Wasiq (child specialist)\n\n";
	cout<<"\t\t\t [[Timing]]:\n\n";
	cout<<"\tMonday To Friday\t\t2PM TO 10PM\n";
	cout<<"\tSatuday         \t\t8AM TO 1PM\n";
	cout<<"\tSunday          \t\t12PM TO 9PM\n";
	cout<<"\n---------------------------------------\n";
	cout<<"\t\tDr. Zartashia (Surgein)\n\n";
	cout<<"\t\t\t [[Timing]]:\n\n";
	cout<<"\tMonday To Friday\t\t8AM TO 5PM\n";
	cout<<"\tSatuday         \t\t10AM TO 1PM\n";
	cout<<"\tSunday          \t\t Off\n";
	cout<<"\n---------------------------------------\n";
	cout<<"\nPrees Any Key For Continue: ";
	getch();
	menu();
	}
};
void call_dr(){
	int choice;
	cout<<"\n\n\n\t\tPress 1 for Dr shammas \n\n\t\t Press 2 for Dr Wasiq \n\n\t\t Press 3 for Dr Zartashia ";
	cin>>choice;
	Base *ptr;
	shammas s3;
	wasiq s4;
	zartashia s5;
	if(choice==1){
	ptr=&s3;
	ptr->get();
   } 
   if(choice==2){
   	ptr=&s4;
   	ptr->get();
	} 
	if(choice==3){
	ptr=&s5;
	ptr->get();
	}
else{	
	throw "Error in Call doctor funtion";
	}
}
void pinfoshow()
{
	int choice;
	cout<<"\n\n\t 1 -Press 1 for Dr shammas \n\n\t 2-  Press 2 for Dr Wasiq \n\n\t 3-  Press 3 for Dr Zartashia ";
	cout<<"\nPlease Enter Your Choice :";
	cin>>choice;
	Base *ptr;
	shammas s3;
	wasiq s4;
	zartashia s5;
	if(choice==1){
		ptr=&s3;
		ptr->show();
	}
	else if(choice==2){
		ptr=&s4;
		ptr->show();
	}
	else if(choice==3){
		ptr=&s5;
		ptr->show();
	}
	else{
	throw "Error in print information function";
	}
}
	void menu()
{
	    cout<<"\n Hospital Management system";
        cout<<"\n<<---------------------->>\n";        
        cout<<"\n\n\n";
        cout<<"\t\t                   MAIN MENU     \n";
        cout<<"\t\t         Hospital Management system       \n";
        cout<<"\t\t      ************************************     \n";        
        cout<<"\t\n          <<=========================================>>\n";
     	cout<<"\n\n\t1-\t\tPress 1 For Availabel Doctor Information\n\n";
		cout<<"\t2-\t\tPress 2 for Doctor Appointment\n\n";
		cout<<"\t3-\t\tPress 3 for Saving Staff information\n\n";
		cout<<"\t4-\t\tPress 4 for Checking Patient Appointment Menu:\n\n ";
		cout<<"\t5-\t\tPress 5 for Checking Staff Information Menu:\n\n";
	
		cout<<"\n\t          <<==============================================>>\n";
		cout<<"\n\n\t\tPlease Enter Your Choice : ";
		information a1;
		Base *ptr;
		staff a2;
		int a;
		cin>>a;
		if(a==1){
			a1.drinfo();
		}
		else if(a==2){
	    	call_dr();	
		}
		else if(a==3){
			ptr=&a2;
			ptr->get();		
		}
		else if(a==4){
			pinfoshow();
		}
		else if(a==5){
			ptr=&a2;
			ptr->show();
		}
		else{
			throw "Error in menu funtion......";
		}
	}

int main(){
	try 
	{
	
	menu();
}
catch (const char *msg) //Exeption will come and store in msg using functions because its not a class 
//so thats why we are using character array in catch!
{
	cout<<msg<<endl;
	menu();
}
		return 0;
}
