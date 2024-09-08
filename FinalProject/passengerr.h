#include<string.h>
#include"user.h"

class passenger:public userr
{
    protected:
        int mchoice,snum,rnum;
        long long int phoneNo;
        char fname[20],lname[20];
        char gender[5];
        int id;

    public:
        void pmenu();

        void bookTicket();          //read
        int finsert();

        int printTicket();          //display single person
        void display();
        int fdisplay();

        void changeTicket();

        void cancelTicket();
        void payment();
        void feedback();
        void FAQ();
        void mainmenu();

        int get_snum()
        {
            return snum;
        }
};
