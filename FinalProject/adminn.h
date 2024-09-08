#include<string.h>
#include"passengerr.h"

class admin:public passenger
{
    protected:
        char user[10];
        char pswd[10];
        int wt_bag;
        char cname[20],desig[20];
        int age;
    public:
        void amenu();
        void read();
        void display();
        int separateList();

        void login();
        int searchPassenger();
        void printPassenger_list();
        void printReport();
        void BaggageDetails();

        int fcinsert();
        int fcdisplay();
        char *get_desig()
        {
            return desig;
        }
};
