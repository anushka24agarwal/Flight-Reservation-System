#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include<iomanip.h>
#include<process.h>
#include<fstream.h>
fstream f;
fstream fi;

int comp=0;
char dom[6][20]={"MUMBAI", "GOA", "DELHI", "JAIPUR", "CHENNAI", "KOLKATA"};
char inter[5][20]={"DUBAI", "PARIS", "NEW YORK CITY", "HONG KONG", "LONDON"};
char opti[11][20]={"MUMBAI", "GOA", "DELHI", "JAIPUR", "CHENNAI", "KOLKATA", "DUBAI", "PARIS", "NEW YORK CITY", "HONG KONG", "LONDON"};


class choose
{ public:
char loc[20];
char desti[20];
int op;
int choice;
int amt;
int pnr;
void location();
};
choose choo;

void choose::location()       // func to choose location
{
clrscr();
cout<<"Enter your LOCATION: \nMUMBAI \nGOA \nDELHI \nJAIPUR \nCHENNAI \nKOLKATA\n\n";
gets(loc);


cout<<"Enter\n1. For Domestic Flights\n2. For International Flights\nPlease enter your choice: ";
cin>>op;

if(op==1)
{
cout<<"Following are the DOMESTIC flights available: "<<endl;
for(int i=0; i<6;i++)
{
 cout<<i+1<<". "<<dom[i]<<"\n";

}
goto aa;
}

if(op==2)
{
cout<<"Following are the INTERNATIONAL flights available: "<<endl;
for(int i=0; i<5;i++)
 { cout<<i+1<<". "<<inter[i]<<"\n";

 }
 goto aa;
}
aa:
cout<<"Enter your DESTINATION: ";
cin>>desti;

for(int k=0;k<11;k++)
{
  if(strcmp(desti,opti[k]))
  {
   break;

   }
  else
  cout<<"Destination NOT AVAILABLE! Please enter again: \n";
  goto aa;

}
if(op==1)
{
  clrscr();
cout<<"FLIGHTS FOUND: \n\n";
cout<<"AIRLINE"<<setw(20)<<"DEPARTURE"<<setw(15)<<"PRICE"<<setw(15)<<"PNR NUMBER"<<setw(15)<<"CATEGORY\n";
cout<<"1.Air India"<<setw(15)<<"10:00 hrs"<<setw(15)<<"Rs.17,958"<<setw(15)<<"100  "<<setw(15)<<"Non-refundable\n";
cout<<"2.IndiGo"<<setw(15)<<"14:00 hrs"<<setw(15)<<"Rs.19,878"<<setw(15)<<"101 "<<setw(20)<<"Non-refundable\n";
cout<<"3.Spicejet"<<setw(15)<<"19:00 hrs"<<setw(15)<<"Rs.15,613"<<setw(15)<<"102  "<<setw(15)<<"Non-refundable\n";

cout<<"Enter your choice (1/2/3): ";
cin>>choice;
  if(choice==1)
  {amt=17958; pnr=100;}
  else if(choice==2)
  {amt=19858;  pnr=101;}
  else if(choice==3)
 { amt=15613;  pnr=102;}

 }
if(op==2)
{

  clrscr();
cout<<"FLIGHTS FOUND: \n\n";
cout<<"AIRLINE"<<setw(15)<<"DEPARTURE"<<setw(15)<<"PRICE"<<setw(15)<<"PNR NUMBER"<<setw(15)<<"CATEGORY\n";
cout<<"1.Air India"<<setw(15)<<"10:00 hrs"<<setw(15)<<"Rs.17,958"<<setw(15)<<"342  "<<setw(15)<<"Non-refundable\n";
cout<<"2.IndiGo"<<setw(15)<<"14:00 hrs"<<setw(15)<<"Rs.19,878"<<setw(20)<<"763  "<<setw(15)<<"Non-refundable\n";
cout<<"3.Spicejet"<<setw(15)<<"19:00 hrs"<<setw(15)<<"Rs.15,613"<<setw(15)<<"209  "<<setw(15)<<"Non-refundable\n";

cout<<"Enter your choice (1/2/3): ";
cin>>choice;
  if(choice==1)
  {amt=17958; pnr=342;}
  else if(choice==2)
  {amt=19858;  pnr=763;}
  else if(choice==3)
 { amt=15613;  pnr=209;}
   }

  }


void accept_details();      //prototype
void displayticket();         //prototype


void main()                       //VOID MAIN!!!
{
clrscr();
textcolor (WHITE);
textbackground(CYAN);           //BG change


// HOME PAGE

clrscr();
int choice;


//options after details entered
char opt;

main_menu: cout<<"\n\n\t\t\t WELCOME TO BOOK_MY_TICKETS.COM \n";
cout<<"\t\t<><><><><><><><><><><><><><><><><><><><><><><><> \n";
cout<<"\t\t Book your flight tickets at affordable prices! \n";
cout<<"\t\t<><><><><><><><><><><><><><><><><><><><><><><><> "<<endl;
cout<<"\t\t\t\t 1. Book Flight \n";
cout<<"\t\t\t\t 2. Check Ticket \n";
cout<<"\t\t\t\t 3. Exit \n";
cout<<" Enter your choice ";
cin>>choice;
 switch(choice)
 {
  case 1:{	    clrscr();

    accept_details();


    cout<<"\nMAIN MENU?(y/n)";
    cin>>opt;
     if((opt=='y')||(opt=='Y'))
      { clrscr();

     goto main_menu; }
    break;

  }
    case 2: {  displayticket();
      cout<<"\nMAIN MENU?(y/n)";
    cin>>opt;
     if((opt=='y')||(opt=='Y'))
     { clrscr();

     goto main_menu;
     }
    break;
    }

  case 3: exit(0);
 }
getch();
}

class accept         {                    // CLASS FOR PASSENGER DETAILS
		      public:
		      int age;
		      char gen;
		      char name[20];
		      char email[20];
		      char mob[10];
		      char cl;
		      void getdata();
};
  void accept :: getdata()
		      {
      cout<<"\n Enter Name of passenger "<<" : ";
     gets(name);
     cout<<"\n Enter age : ";
     cin>>age;
     cout<<"\n Enter gender(M/F/O): ";
     cin>>gen;
}


int sno,cno;
   int PNR;
accept a[10];
void accept_details()   // func to accept details
{


  f.open("Flight.txt",ios::out|ios::app);
  f.seekg(0);

  clrscr();
  choo.location();

   clrscr();
cout<<"\n ENTER DETAILS FOR BOOKING YOUR TICKET(S)\n \n[All details in BLOCK LETTERS only]\n";
cout<<"\n How many seats do you want to book?: \n";
cin>>sno;
int i=0;
for(;i<sno;i++)
{

 if(sno!=1)
 {   a[i].getdata();
    cout<<"\n Enter details of passenger :\n";
    cout<<"\n Email address : ";
    cin>>a[i].email;
    cout<<"\n Contact number : ";
    cin>>a[i].mob;
    cout<<"\n Do you wish to travel in BUSINESS CLASS or ECONOMY CLASS (B/E): \n";
    cout<<"\n[Passengers kindly note: Business class will enjoy special in-flight and airport priviledges]\n";
    cin>>a[i].cl;
      cout<<"\nRe-enter PNR no.: \n";
   cin>>PNR;
 }
else
{   a[i].getdata();
    cout<<"\n Email address : ";
    cin>>a[i].email;
    cout<<"\n Contact number : ";
    cin>>a[i].mob;
    cout<<"\n Do you wish to travel in BUSINESS CLASS or ECONOMY CLASS (B/E): \n";
    cout<<"\n[Passengers kindly note: Business class will enjoy special in-flight and airport priviledges]\n";
    cin>>a[i].cl;

}
f.write((char*)& a[i],sizeof(a[i]));
}

p:  clrscr();

cout<<"\n Kindly note that payment will take place only through ONLINE BANKING \n";
cout<<"\nPAYMENT :- \n";
cout<<"\n The total amount for your travel is "<<choo.amt<<" Rs.";
cout<<"\nEnter Credit Card number :\n";
cin>>cno;



f.close();

cout<<"\n Execute transaction of Rs."<<choo.amt<<"?\t(Y/N)\n";
char e;
cin>>e;
 if((e=='Y')||(e=='y'))
 {
  cout<<"\nPAYMENT SUCCESSFUL!";

 }
 else{
 goto p;
 }

}

//DISPLAY TICKET
void displayticket()
{
      textcolor (WHITE);
   textbackground(BROWN);

       fi.open("Flight.txt",ios::in);
       fi.seekg(0);
       for(int k=0;k<sno;k++)
       {
       fi.read((char*) &a[k],sizeof(a[k]));
       }
 //ASKing FOR FLIGHT PNR NO. FIRST
  clrscr();
  PNR=choo.pnr;
  int ccpnr;
  cout<<"\nENTER YOUR PNR NO.:\n";
  cin>>ccpnr;
  if(PNR==ccpnr)
  {clrscr();
  cout<<"\tYour e-ticket information :"<<endl;
  cout<<setw(20)<<" AIRLINE TICKET "<<endl;
  cout<<"_____________________________________________________________________"<<endl;
  cout<<"\t Passenger information -\n";

  for(int j=0;j<sno;j++)
   {
    cout<<"\n\t Name: "<<a[j].name;
    cout<<"\n\t Age: "<<a[j].age;
    cout<<"\n\t Gender: "<<a[j].gen;
    }
   
}

  cout<<"\n\t FLIGHT INFORMATION\n"<<endl;
  cout<<"\t Location -  "<<choo.loc<<endl;
  cout<<"\t Destination - "<<choo.desti<<endl;
  cout<<"\t Flight PNR No. - "<<PNR<<endl;
  cout<<"\t Non Refundable payment of Rs."<<choo.amt<<endl;
  cout<<" \t Class of travel -  "<<a[0].cl<<endl;
  cout<<"\t\n Passangers kindly note: \n\tMAX. CABIN BAGGAGE ALLOWED IS \" 25 KILOGRAMS \" "<<endl;
  cout<<"\t\t THANK YOU ";

  fi.close();
  getch();
}
