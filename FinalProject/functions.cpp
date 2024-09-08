#include<iostream>
#include<unistd.h>
#include<conio.h>
#include<fstream>
#include<string>
#include<cctype>
#include"adminn.h"


#define sizee 100

using namespace std;

void userr::headmsg()
{
    cout<<"\n\n\n\n\n\n\n\t\t\t___________________________________________________________"<<endl;
    cout<<"\n\n\t\t\t\t\t PC AIRLINE RESERVATION SYSTEM"<<endl;
    cout<<"\t\t\t    By C.Poorvika - 22PD10 and Chaithanya.N - 22PD09"<<endl<<endl;
    cout<<"\t\t\t___________________________________________________________"<<endl;
    cout<<"\n\n\t\t\t\t\t\tloading";
    sleep(1);
    cout<<".";
    sleep(1);
    cout<<".";
    sleep(1);
    cout<<".";
    sleep(1);
    sleep(2);
}

void userr::flightDetails()
{
    cout<<"\n\n\t\t\t___________________________________________________________"<<endl;
    cout<<"\n\t\t\t\t\t     Flight Details "<<endl;
    cout<<"\t\t\t___________________________________________________________\n"<<endl;
    cout<<"\t\t\tFlight Number : AL5706"<<endl;
    cout<<"\t\t\tDeparture Airport : Cochin International Airport"<<endl;
    cout<<"\t\t\tArrival Airport : Rajiv Gandhi International Airport"<<endl;
    cout<<"\t\t\tDeparture Time : 20 Nov 2023 , 05:00"<<endl;
    cout<<"\t\t\tArrival Time : 20 Nov 2023 , 22:26"<<endl;
    cout<<"\t\t\tDuration : 17hr"<<endl;
    cout<<"\t\t\tAirline : PC Airlines"<<endl;
    cout<<"\t\t\tAircraft : Passenger Aircraft"<<endl;
    cout<<"\t\t\tSeat Availability : 100"<<endl;
    cout<<"\t\t\tFare of Ticket : Rs.3000"<<endl;
    cout<<"\t\t\tBaggage Allowance for 1 Person: 20Kg"<<endl<<endl;
}
int seat[sizee];
void passenger::pmenu()
{
    userr u;
    int choice;
    char another='y';
    system("cls");
    cout<<"\n\n\t\t\t___________________________________________________________"<<endl;
    cout<<"\n\t\t\t\t\t    Passenger Account "<<endl;
    cout<<"\t\t\t___________________________________________________________"<<endl;

    do
    {
        cout<<"\n\t\t\t\t\t\t Main Menu "<<endl;
        cout<<"\t\t\t\t       ___________________________\n"<<endl;
        cout<<"\t\t\t\t [1].Make Reservation"<<endl;
        cout<<"\t\t\t\t [2].Cancel Reservation"<<endl;
        cout<<"\t\t\t\t [3].Change Reservation"<<endl;
        cout<<"\t\t\t\t [4].Print Ticket"<<endl;             //display only their details
        cout<<"\t\t\t\t [5].Payment"<<endl;
        cout<<"\t\t\t\t [6].Feedback"<<endl;
        cout<<"\t\t\t\t [7].FAQ"<<endl;
        cout<<"\t\t\t\t [8].Flight Details"<<endl;
        cout<<"\t\t\t\t [9].Exit from Main Menu"<<endl;
        cout<<"\n\t\t\tEnter your choice: ";
        cin>>choice;
        switch(choice)
        {
         case 1:
                system("cls");
                finsert();
                break;
         case 2:
                system("cls");
                cancelTicket();

                break;
         case 3:
                system("cls");
                changeTicket();
                break;
         case 4:
                system("cls");
                printTicket();
                break;
         case 5:
                system("cls");
                payment();
                break;
         case 6:
                system("cls");
                feedback();
                break;
         case 7:
                system("cls");
                FAQ();
                break;
         case 8:
                system("cls");
                u.flightDetails();
                break;
         case 9:
                system("cls");
                mainmenu();
                break;
        }
        cout<<"\n\t\t\t\tDo you Want to Continue(y/n): ";
        cin>>another;
        system("cls");
    }while(another=='y'||another=='Y');
   mainmenu();
}

//Booking Ticket//

int reserve=1000;
bool taken=false;
void passenger::bookTicket()
{
    system("cls");
    cout<<"\n\n\t\t\t___________________________________________________________"<<endl;
    cout<<"\n\t\t\t\t\t Making Reservation "<<endl;
    cout<<"\n\t\t\t___________________________________________________________\n\n"<<endl;
    cout<<"\t\t\t\tEnter Your First Name: ";
    cin.ignore();
    cin.getline(fname,20);
    cout<<"\t\t\t\tEnter Your Last Name: ";
    cin.getline(lname,20);

    cout<<"\t\t\t\tGender (F/M): ";
    cin>>gender;
    while (strcmp(gender,"M")!=0 && strcmp(gender,"F")!=0)
    {
        cout << "\t\t\t\tInvalid Input\n\t\t\t\t Please Enter either M or F: ";
        cin >> gender;
    }

    cout<<"\t\t\t\tEnter Your ID: ";
    cin>>id;
    while (to_string(id).length()!=3)
    {
     cout << "\t\t\t\t  Invalid input\n\t\t\t\t  Please enter a 3 digit number: ";
     cin >> id;
    }

    cout<<"\t\t\t\tEnter Phone Number: ";
    cin>>phoneNo;
    while (to_string(phoneNo).length()!=10)
    {
        cout << "\t\t\t\t  Invalid phone number\n\t\t\t\t  Please enter 10 digits: ";
        cin >> phoneNo;
    }

    do
    {
     cout<<"\t\t\t\tEnter Seat Number which you need (<100): ";
     cin>>snum;
     while(snum>sizee)
     {
        cout<<"\t\t\t\t  Seat number is greater then availability of seats"<<endl;
        cout<<"\t\t\t\t  Try Again:  "<<endl;
        cin>>snum;
     }
     //cout<<endl;
     ifstream fin;
     fin.open("passenger.txt",ios::in|ios::binary);
     passenger ps;
     taken = false;
     while(fin.read((char*)&ps,sizeof(ps)))
     {
         if(ps.snum == this->snum)
         {
            taken = true;
            cout<<"\t\t\t\t  The seat is taken already.\n";
            cout<<"\t\t\t\t  Please choose another seat number."<<endl<<"  ";
         }
     }

    } while(taken==true);

    cout<<"\t\t\t\tEnter Your Meal Preference: "<<endl;
    cout<<"\t\t\t\t[1].Veg"<<endl;
    cout<<"\t\t\t\t[2].Non-Veg"<<endl;
    cout<<"\t\t\t\t[3].No Meal"<<endl;
    cout<<"\t\t\t\t  Enter your choice: ";
    cin>>mchoice;
    while(mchoice>3 || mchoice<1)
    {
        cout<<" \t\t\t\t Try Again  ";
        cin>>mchoice;
    }
    if(mchoice==1)
        cout<<"\t\t\t\tYou have chosen Veg meal"<<endl;
    else if(mchoice==2)
        cout<<"\t\t\t\tYou have chosen Non-Veg meal"<<endl;
    else
        cout<<"\t\t\t\tYou have not chosen any type of meal"<<endl;

   rnum=reserve++;
    cout<<"\t\t\t\tYour Reservation Number: "<<rnum<<endl;
}

int passenger::finsert()
{
    passenger p;
    fstream file;
    file.open("passenger.txt",ios::app);
    if(file.eof())
    {
        cerr<<"\t\t\t\tFile cannot be Opened"<<endl;
        return 1;
    }
    p.bookTicket();
    file.write((char*)&p,sizeof(p));
    file.seekg(0);
    file.close();
}

//End of Booking Ticket//

//Displaying Ticket of all
void passenger::display()
{
    cout<<"\t\t\t\tFirst Name   : "<<fname<<endl;
    cout<<"\t\t\t\tLast Name    : "<<lname<<endl;
    cout<<"\t\t\t\tGender       : "<<gender<<endl;
    cout<<"\t\t\t\tId           : "<<id<<endl;
    cout<<"\t\t\t\tPhone Number : "<<phoneNo<<endl;
    cout<<"\t\t\t\tSeat Number  : "<<snum<<endl;
    cout<<"\t\t\t\t[1].Veg \n\t\t\t\t[2].Non-Veg \n\t\t\t\t[3].No Meal"<<endl;
    cout<<"\t\t\t\tMeal Choice  : "<<mchoice<<endl;
    cout<<"\t\t\t\tReservation Number: "<<rnum<<endl<<endl;
}

int passenger::fdisplay()
{
    passenger p;
    fstream file;
    file.open("passenger.txt",ios::in);
    if(file.eof())
    {
        cerr<<"\t\t\t\tFile cannot be Opened"<<endl;
        return 1;
    }
    cout<<"\t\t\t\tThe Details of Passenger: "<<endl;
    while(file.read((char*)&p,sizeof(p)))
    {
        p.display();
    }
}

int passenger::printTicket()
{
    system("cls");
    cout<<"\n\n\t\t\t___________________________________________________________"<<endl;
    cout<<"\n\t\t\t\t\t Printing Ticket "<<endl;
    cout<<"\n\t\t\t___________________________________________________________\n\n"<<endl;
    int sno,flag=0;
    passenger p;
    cout<<"\t\t\t\tEnter your Seat Number: ";
    cin>>sno;

    fstream file;
    file.open("passenger.txt",ios::in);
    if(file.eof())
    {
        cerr<<"\t\t\t\tFile cannot be Opened"<<endl;
        return 1;
    }
    file.read((char*)&p,sizeof(p));
    while(!file.eof())
    {
        if(p.snum==sno)
        {
            cout<<"\n\t\t\t\tYour Details: "<<endl;
            p.display();
            flag=1;
            break;
        }
        file.read((char*)&p,sizeof(p));
    }
    file.close();
    if(flag==0)
    {
        cout<<"\t\t\t\tDetails Not Found"<<endl;
        sleep(1);
        pmenu();
    }
}

void passenger::changeTicket()
{
    passenger p;
    char another;
    int sno;
    int pos,flag=0;

    fstream fs;
    int choice;
    system("cls");
    cout<<"\n\n\t\t\t___________________________________________________________"<<endl;
    cout<<"\n\t\t\t\t\t Modifying Information "<<endl;
    cout<<"\n\t\t\t___________________________________________________________\n\n"<<endl;
    cout<<"\t\t\t\tEnter Seat Number to be Modified: ";
    cin>>sno;
    fs.open("passenger.txt",ios::in | ios::out);
    if(fs.eof())
    {
        cerr<<"\t\t\t\tFile cannot be opened"<<endl;
        return;
    }
    while(!fs.eof())
    {
        pos=fs.tellg();
        fs.read((char*)&p, sizeof(p));
        if(true)
        {
            if(sno==p.snum)
            {
            flag=1;
            do
            {
                cout<<"\t\t\t\t[1].First Name\n\t\t\t\t[2].Last Name\n\t\t\t\t[3].Gender\n\t\t\t\t[4].ID\n\t\t\t\t[5].Phone Number\n\t\t\t\t[6].Seat Number\n\t\t\t\t[7].Meal\n"<<endl;
                cout<<"\t\t\t\tEnter Your Choice: ";
                cin>>choice;
                switch(choice)
                {
                case 1:
                    cout<<"\t\t\t\tEnter Your First Name: ";
                    cin.ignore();
                    cin.getline(p.fname,20);
                    break;
                case 2:
                    cout<<"\t\t\t\tEnter Your Last Name: ";
                    cin.ignore();
                    cin.getline(p.lname,20);
                    break;
                case 3:
                    cout<<"\t\t\t\tGender (F/M): ";
                    cin>>p.gender;
                    while (gender != "M" && gender!="F" )
                    {
                        cout << "Invalid gender, Please Enter either M or F: ";
                        cin >> gender;
                    }
                    break;
                case 4:
                    cout<<"\t\t\t\tEnter Your ID: ";
                    cin>>p.id;
                    while (to_string(p.id).length()!=3)
                    {
                        cout << "Invalid input, please enter a three-digit number: ";
                        cin >> p.id;
                    }
                    break;
                case 5:
                    cout<<"\t\t\t\tEnter Phone Number: ";
                    cin>>p.phoneNo;
                    while (to_string(p.phoneNo).length()!=10)
                    {
                        cout << "Invalid phone number, please enter 10 digits: ";
                        cin >> p.phoneNo;
                    }

                    break;
                case 6:
                    int seat[sizee];
                    do
                    {
                     cout<<"\t\t\t\tEnter Seat Number which you need (<100): ";
                     cin>>p.snum;
                     while(p.snum>sizee)
                     {
                        cout<<"Seat number is greater then availability of seats"<<endl;
                        cout<<"Try Again:  "<<endl;
                        cin>>p.snum;
                     }
                     cout<<endl;

                    } while(taken==true);
                    break;
                case 7:
                    cout<<"\t\t\t\tEnter Your Meal Preference: "<<endl;
                    cout<<"\t\t\t\t[1].Veg"<<endl;
                    cout<<"\t\t\t\t[2].Non-Veg"<<endl;
                    cout<<"\t\t\t\t[3].No Meal"<<endl;
                    cout<<"\t\t\t\tEnter your choice: ";
                    cin>>p.mchoice;
                    while(p.mchoice>3 || p.mchoice<1)
                    {
                        cout<<" \t\t\t\tTry Again  ";
                        cin>>p.mchoice;
                    }
                    if(p.mchoice==1)
                        cout<<"\t\t\t\tYou have chosen Veg meal"<<endl;
                    else if(p.mchoice==2)
                        cout<<"\t\t\t\tYou have chosen Non-Veg meal"<<endl;
                    else
                        cout<<"\t\t\t\tYou have not chosen any type of meal"<<endl;
                    break;
                }
                cout<<"\t\t\t\tDo you want to continue?\n";
                cin>>another;
            }
            while(another=='y'||another=='Y');
            fs.seekp(pos);
            fs.write((char*)&p, sizeof(p));
            break;
            }
        }
    }
    fs.close();
    if (flag == 1)
    {
        cout << "\n\t\t\t\tDetails successfully modified \n";
    }
    else
    {
        cout << "\n\t\t\t\tDetails not found \n";
    }
    pmenu();
}


void passenger::cancelTicket()
{
    int sno,flag=0;
    passenger p;
    fstream file("passenger.txt",ios::binary|ios::in);
    fstream temp("tempPassenger.txt",ios::binary|ios::out);
    file.seekg(0);
    if(!file||!temp)
    {
        cout<<"File cannot be Opened"<<endl;
    }
    else
    {
        system("cls");
        cout<<"\n\n\t\t\t___________________________________________________________"<<endl;
        cout<<"\n\t\t\t\t\t Canceling Reservation "<<endl;
        cout<<"\n\t\t\t___________________________________________________________\n\n"<<endl;
        cout<<"\t\t\t\tEnter Your Seat Number: ";
        cin>>sno;
        while(file.read((char*)&p,sizeof(p)))
        {
            if(p.snum!=sno)
            {
                temp.write((char*)&p,sizeof(p));
            }
            else
            {
                flag=1;
            }
        }
        file.close();
        temp.close();
        remove("passenger.txt");
        cout<<"\n\t\t\t\tReservation Canceled Successfully"<<endl;
        sleep(1.5);
        rename("tempPassenger.txt","passenger.txt");
    }
    if(flag=0)
    {
        cout<<"\n\t\t\t\tDetails doesn't exist"<<endl;
        sleep(1.5);
    }
    pmenu();
}

void passenger::payment()
{
    int i,cash,changer,nppl,total;
    int price=3000;
    redo:

    system("cls");
    cout<<"\n\n\t\t\t___________________________________________________________"<<endl;
    cout<<"\n\t\t\t\t\t Payment "<<endl;
    cout<<"\n\t\t\t___________________________________________________________\n\n"<<endl;

    cout<<"\n\n\n\t\t\tEnter the no. of people : ";
    cin>>nppl;

    total = price * nppl;

    cout<<"\t\t\tYour Total Bill is: "<<total;
    work:
            cout<<"\n\t\t\tPay your bill: ";
            cin>>cash;
    changer = cash-total;
    if(changer == 0)
    {
        cout<<"\n\t\t\tThanks for your payment. Have a great day!\n";
    }
    else if (changer<0)
    {
        system("cls");
        cout<<"\n\t\t\tAmount is not sufficient. :(\n\t\tPlease pay the fair price of your bill\n";
        goto work;
    }
    else
    {
        cout<<"\n\t\t\tHere is your change : Rs. "<<(cash-total)<<endl;
            cout<<"\t\t  ";
            for(i=0;i<25;i++)
            {
                cout<<"_";
            }
            if(changer>=1000 )
            {
                cout<<"\n\t\t\t1000 Rs. notes = "<<changer/1000<<endl;
                changer=changer%1000;
            }
            if(changer>=500 && changer<1000)
            {
                cout<<"\n\t\t\t 500 Rs. note(s) = "<<changer/500<<endl;
                changer=changer%500;
            }
            if(changer>=100 && changer<500)
            {
                cout<<"\n\t\t\t 100 Rs. note(s) = "<<changer/100<<endl;
                changer= changer%100;
            }
            if(changer>=50 && changer<100)
            {
                cout<<"\n\t\t\t  50 Rs. note(s) = "<<changer/50<<endl;
                changer=changer%50;
            }
             if(changer>=10 && changer<50)
            {
                cout<<"\n\t\t\t  10 Rs. note(s) = "<<changer/10<<endl;
                changer=changer%10;
            }
            if(changer>=5 && changer<10)
            {
                cout<<"\n\t\t\t   5 Rs. note(s) = "<<changer/5<<endl;
                changer=changer%5;
            }
            if(changer>=2 && changer<5)
            {
                cout<<"\n\t\t   2 Rs. note(s) = "<<changer/2<<endl;
                changer=changer%2;
            }
            if(changer>=1 && changer<2)
            {
                cout<<"\n\t\t\t   1 Rs. note(s) = "<<changer/1<<endl;
                changer=changer%1;
            }

            cout<<"\t\t\t  ";
            for(i=0;i<25;i++)
            {
                cout<<"_";
            }

        cout<<"\n\n\n\n\n\t\t\tThanks for your payment.\n\t\t\t    Have a great day!\n"<<changer;
    }
}

void passenger::FAQ()
{
    system("cls");
    cout<<"\n\n\t\t\t___________________________________________________________"<<endl;
    cout<<"\n\t\t\t\t\t\t FAQ "<<endl;
    cout<<"\n\t\t\t___________________________________________________________\n\n"<<endl;
    cout<<"Most FAQ in Airline Reservation system"<<endl;
    cout<<"#1.What is an airline reservation system?"<<endl;
    cout<<"-> An airline reservation system is a computerized system used to manage and book flights for customers."<<endl<<endl;
    cout<<"#2. How does an airline reservation system work?"<<endl;
    cout<<"-> An airline reservation system allows customers to search for available flights, select their desired flights, and book them either Online or through a travel agent."<<endl<<endl;
    cout<<"#3. What information do I need to book a flight using an airline reservation system?"<<endl;
    cout<<"-> To book a flight through an airline reservation system, you will need the origin and destination of your trip, dates of travel, and passenger information."<<endl<<endl;
    cout<<"#4. Can I cancel my flight using an airline reservation system?"<<endl;
    cout<<"-> Yes, you can cancel your flight through an airline reservation system, subject to the airline's cancellation policy."<<endl<<endl;
    cout<<"#5. Can I select my seat using an airline reservation system?"<<endl;
    cout<<"-> Yes, you can select your seat using an airline reservation system, subject to availability."<<endl<<endl;
    cout<<"#6. How can I make changes to my booking using an airline reservation system?"<<endl<<endl;
    cout<<"-> You can make changes to your booking using an airline reservation system by accessing your reservation and following the prompts to modify your itinerary."<<endl<<endl;
    cout<<"#7. Is it safe to book a flight through an airline reservation system?"<<endl;
    cout<<"-> Yes, it is generally safe to book a flight through an airline reservation system, as long as you use a reputable and secure system. However,";
    cout<<" it is important to be aware of potential scams or fraudulent websites and to exercise caution when providing personal and financial information."<<endl<<endl;
}

void passenger::feedback()
{
    fstream file;
    file.open("COMPLAINT.txt",ios::app);
    char complaint[1000];

    fflush(stdin);
    system("cls");
    cout<<"\n\n\t\t\t\tEnter your complaints / Suggestions: \n\n  ";
    gets(complaint);

    cout<<"\n\n________________________________________\n\n"<<complaint<<endl;
    file.close();
}

//Crew Details

void admin::read()
{
    cout<<"\n\n\t\t\t___________________________________________________________"<<endl;
    cout<<"\n\t\t\t\t\t Crew Details "<<endl;
    cout<<"\n\t\t\t___________________________________________________________\n\n"<<endl;

    cout<<"\n\t\t\t\tEnter your name : ";
    cin.ignore();
    cin>>cname;
    cout<<"\t\t\t\tAge : ";
    cin>>age;
    cout<<"\t\t\t\tGender (F/M): ";
    cin>>gender;
    while (strcmp(gender,"M")!=0 && strcmp(gender,"F")!=0)
    {
        cout << "\t\t\t\tInvalid Input\n\t\t\t\t Please Enter either M or F: ";
        cin >> gender;
    }
    cout<<"\t\t\t\tDesignation('pilot'/'airhostess') : ";
    cin>>desig;
}

void admin::display()
{
    system("cls");
    cout<<"\n\n\t\t\t___________________________________________________________"<<endl;
    cout<<"\n\t\t\t\t Displaying Crew Details "<<endl;
    cout<<"\n\t\t\t___________________________________________________________\n\n"<<endl;

    cout<<"\n\t\t\t\tName : "<<cname<<endl;
    cout<<"\t\t\t\tAge : "<<age<<endl;
    cout<<"\t\t\t\tGender:"<<gender<<endl;
    cout<<"\t\t\t\tDesignation :"<<desig<<endl<<endl;
}

int admin::fcinsert()
{
    admin ad;
    fstream file;
    file.open("admin.txt",ios::app);
    if(file.eof())
    {
        cerr<<"File cannot be Opened"<<endl;
        return 1;
    }
    ad.read();
    file.write((char*)&ad,sizeof(ad));
    file.seekg(0);
    file.close();
}

int admin::fcdisplay()
{
    admin ad;
    fstream file;
    file.open("admin.txt",ios::in);
    if(file.eof())
    {
        cerr<<"File cannot be Opened"<<endl;
        return 1;
    }
    cout<<"\n\t\t\t\tThe Details of Crew: "<<endl;
    file.read((char*)&ad,sizeof(ad));
    while(!file.eof())
    {
        ad.display();
        file.read((char*)&ad,sizeof(ad));
    }
}

int admin::separateList()
{
    int sno,flag=0;
    char desi[20];
    admin ad;
    system("cls");
    cout<<"\n\n\t\t\t___________________________________________________________"<<endl;
    cout<<"\n\t\t\t\t\t Separating crew Details "<<endl;
    cout<<"\n\t\t\t___________________________________________________________\n\n"<<endl;
    cout<<"\t\t\tEnter designation (pilot/airhostess): ";
    cin>>desi;

    fstream file;
    file.open("admin.txt",ios::in);
    if(file.eof())
    {
        cerr<<"File cannot be Opened"<<endl;
        return 1;
    }
    file.read((char*)&ad,sizeof(ad));
    while(!file.eof())
    {
        if(strcmp(ad.desig,desi)==0)
        {
            ad.display();
            flag=1;
            break;
        }
        file.read((char*)&ad,sizeof(ad));
    }
    file.close();
    if(flag==0)
    {
        cout<<"\n\t\t\t\tDetails Not Found"<<endl;
        sleep(1);
        amenu();
    }
    return 1;
}

//Admin Functions

void admin::amenu()
{
    userr u;
    passenger p;
    int choice;
    char another='y';
    system("cls");
    cout<<"\n\n\t\t\t___________________________________________________________"<<endl;
    cout<<"\n\t\t\t\t\t    Admin Account "<<endl;
    cout<<"\t\t\t___________________________________________________________"<<endl;
    do
    {
        cout<<"\n\t\t\t\t\t\t Main Menu "<<endl;
        cout<<"\t\t\t\t       ___________________________\n"<<endl;
        cout<<"\t\t\t\t [1].Add Crew Details"<<endl;
        cout<<"\t\t\t\t [2].Display Crew Details"<<endl;
        cout<<"\t\t\t\t [3].Separate List of Crew"<<endl;
        cout<<"\t\t\t\t [4].Search Passenger"<<endl;
        cout<<"\t\t\t\t [5].Print Passenger List"<<endl;
        cout<<"\t\t\t\t [6].Baggage Details"<<endl;
        cout<<"\t\t\t\t [7].Flight Details"<<endl;             //display only their details
        cout<<"\t\t\t\t [8].Exit from Main Menu"<<endl;
        cout<<"\n\t\t\t\tEnter your choice: ";
        cin>>choice;
        switch(choice)
        {
         case 1:
                system("cls");
                fcinsert();
                break;
         case 2:
                system("cls");
                fcdisplay();
                break;
         case 3:
                system("cls");
                separateList();
                break;
         case 4:
                system("cls");
                searchPassenger();
                break;
         case 5:
                system("cls");
                printPassenger_list();  //p.fdisplay();
                break;
         case 6:
                system("cls");
                BaggageDetails();
                break;
         case 7:
                system("cls");
                u.flightDetails();
                break;
         case 8:
                system("cls");
                p.mainmenu();
         default:
                cout<<"Invalid Choice"<<endl;
        }
        cout<<"\n\t\t\t\tDo You Want to Continue(y/n): ";
        cin>>another;
        system("cls");
    }while(another=='y'||another=='Y');
    p.mainmenu();
}

void admin::login()
{
    char user[20];
    char pswd[20];
    char username[20]="chaithu";  //user nameor
    char pass[20]="poorvi";       //password
    int i=0;

        system("cls");
        cout<<"\n\t\t\t___________________________________________________________"<<endl;
        cout<<"\n\t\t\t\t\t Admin Account "<<endl;
        cout<<"\n\t\t\t___________________________________________________________"<<endl<<endl;
        cout<<"\t\t\tUSERNAME: ";
        cin>>user;
        cout<<"\t\t\tPASSWORD: ";
        while(true)
            {
                char ch = getch();
                if(ch == 13 || i >= 20)
                    break;
                     cout<<"*";
                pswd[i] = ch;
                i++;
            }
            pswd[i] = '\0';
            if(strcmp(pass,pswd) == 0 && strcmp(user,username)==0)
            {
                cout<<"\nLogin successful\n";
            }
             if((strcmp(user,username)==0)&&(strcmp(pswd,pass)!=0))
             {
          do
          {
            cout<<"\n\n\t\tInvalid Login Credentials\n\t\t\t";
            system("pause");
            system("cls");
            cout<<"\n\t\t\t___________________________________________________________"<<endl;
            cout<<"\n\t\t\t\t\t\tLOGIN\n\n";
            cout<<"\n\t\t\t___________________________________________________________"<<endl<<endl;
            cout<<"\t\t\tUSERNAME : ";
            cin>>user;
            i = 0;
            cout<<"\t\t\tPASSWORD : ";
            while(true)
            {
                char ch = getch();
                if(ch == 13 || i >= 20)
                    break;
                cout<<"*";
                pswd[i] = ch;
                i++;
            }
            pswd[i] = '\0';
            if(strcmp(pass,pswd) == 0&& strcmp(user,username)==0)
            {
                cout<<"\nLogin successful\n";
            }
           }while(strcmp(user,username)!=0 || strcmp(pswd,pass)!=0);
        }
        if(strcmp(user,username)!=0&&strcmp(pswd,pass)==0)
        {
          do
          {
            cout<<"\n\n\t\tInvalid Login Credentials\n\t\t\t";
            system("pause");
            system("cls");
            cout<<"\n\t\t\t___________________________________________________________"<<endl;
            cout<<"\n\t\t\t\t\t\tLOGIN\n\n";
            cout<<"\n\t\t\t___________________________________________________________"<<endl<<endl;
            cout<<"\t\t\tUSERNAME : ";
            cin>>user;
            i = 0;
            cout<<"\t\t\tPASSWORD : ";
            while(true){
                char ch = getch();
                if(ch == 13 || i >= 20)
                    break;
                cout<<"*";
                pswd[i] = ch;
                i++;
                }
                pswd[i] = '\0';
            if(strcmp(pass,pswd) == 0&& strcmp(user,username)==0)
            {
                cout<<"\nLogin successful\n";
            }
           }while(strcmp(user,username)!=0 || strcmp(pswd,pass)!=0);
        }
    if((strcmp(user,username)!=0)&&(strcmp(pswd,pass)!=0))
        {
          do
          {
            cout<<"\n\n\t\tInvalid Login Credentials\n\t\t\t";
            system("pause");
            system("cls");
            cout<<"\n\t\t\t___________________________________________________________"<<endl;
            cout<<"\n\t\t\t\t\t\tLOGIN\n\n";
            cout<<"\n\t\t\t___________________________________________________________"<<endl<<endl;
            cout<<"\t\t\tUser : ";
            cin>>user;
            cout<<"\t\t\tPassword : ";
            i = 0;
            while(true)
            {
                char ch = getch();
                if(ch == 13 || i >= 20)
                    break;
                cout<<"*";
                pswd[i] = ch;
                i++;
            }
            pswd[i] = '\0';
            if(strcmp(pass,pswd) == 0 && strcmp(user,username)==0)
            {
                cout<<"\nLogin successful\n";
            }
           }while(strcmp(user,username)!=0 || strcmp(pswd,pass)!=0);
        }
}

int admin::searchPassenger()
{
    int sno,flag=0;
    passenger p;
    system("cls");
    cout<<"\n\n\t\t\t___________________________________________________________"<<endl;
    cout<<"\n\t\t\t\t\t Searching for Passenger Details "<<endl;
    cout<<"\n\t\t\t___________________________________________________________\n\n"<<endl;
    cout<<"\t\t\tEnter your Seat Number: ";
    cin>>sno;

    fstream file;
    file.open("passenger.txt",ios::in);
    if(file.eof())
    {
        cerr<<"File cannot be Opened"<<endl;
        return 1;
    }
    file.read((char*)&p,sizeof(p));
    while(!file.eof())
    {
        if(sno==p.get_snum())
        {
            cout<<"\n\t\t\t\tYour Details: "<<endl;
            p.display();
            flag=1;
            break;
        }
        file.read((char*)&p,sizeof(p));
    }
    file.close();
    if(flag==0)
    {
        cout<<"\n\t\t\t\tDetails Not Found"<<endl;
    }
    return 1;
}

void admin::printPassenger_list()
{
    passenger p;
    system("cls");
    cout<<"\n\n\t\t\t___________________________________________________________"<<endl;
    cout<<"\n\t\t\t\t\t  Passenger List "<<endl;
    cout<<"\n\t\t\t___________________________________________________________\n\n"<<endl;
    p.fdisplay();
}

void admin::BaggageDetails()
{
    int bala;
    int lim=20;

    system("cls");
    cout<<"\n\n\t\t\t___________________________________________________________"<<endl;
    cout<<"\n\t\t\t\t\t Baggage Details"<<endl;
    cout<<"\n\t\t\t___________________________________________________________\n\n"<<endl;
    cout<<"\t\t\t\tEnter weight of your luggage in kg = ";
    cin>>wt_bag;
    bala=lim-wt_bag;
    if(bala<=20 && bala>0)
    {
        cout<<"\n\t\t\t\tYour Luggage is Safe with us"<<endl;
    }
    else
    {
        cout<<"\n\t\t\t\tOops!.. Too Heavy,Reduce Your Bag Weight Please"<<endl;
    }
}

void passenger::mainmenu()
{
    admin a;
    int choice;
    system("cls");
    cout<<"\n\t\t\t___________________________________________________________"<<endl;
    cout<<"\n\t\t\t\t\t\t Login Info "<<endl;
    cout<<"\n\t\t\t___________________________________________________________"<<endl;
    cout<<"\n\t\t\t[1].Admin"<<endl<<"\t\t\t[2].Passenger"<<endl<<"\t\t\t[3].Exit"<<endl;
    cout<<"\n\t\t\t\tEnter your choice: ";
    cin>>choice;
    switch(choice)
    {
    case 1:
        a.login();
        a.amenu();
        break;
    case 2:
        pmenu();
        break;
    case 3:
        system("cls");
        cout<<"\n\t\t\t___________________________________________________________"<<endl;
        cout<<"\n\t\t\t\t\t\t Thank You\n\t\t\t\t\t\tVisit Again :) ";
        cout<<"\n\t\t\t___________________________________________________________"<<endl;
        break;
    }
}

