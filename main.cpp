/*
    Info:This program is created by : Mariam Ahmad Amin .
         Faculty of Computers and information- Cairo University
         Data Structers Course   4/3/2019 .
    Description:


*/
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int k=0;
class name {
    private :
        string fullName ;
        string names [6];

    public :
        name(string n)
        {
            int i=0,c=0 ;
            fstream file;


            fullName=n ;

            /// We use file in order to let it easy to separate words.
            file.open("file.txt",ios::out);
            file<<fullName;
            file.close();

            file.open("file.txt",ios::in);
            while(!file.eof())
            {
                file>> names[i];
                i++;
            }
            /// Calculating number of spaces.
            for(int i=0 ; i<fullName.size(); i++){
                if(fullName[i]==' ')   c++ ;
            }
            ///number of real words.
            k=c;
            ///There is only one word.
            if (c==0)
            {
                names[1]=names[0];
                names[2]=names[0];
                k=3;
            }
            ///There is only two words.
            if (c==1)
            {
                names[2]=names[1];
                k=3;
            }
        }

        void print ()
        {
            for(int i=0 ; i<6 ; i++)
            {
                cout<<names[i]<<endl;
            }
        }
        bool canReplace (int i,int j)
        {  int p=k+1;
            if ((i>=1 && i<=p)&&(j>=1 && j<=p)) {cout<<"True";return true;}
            else { cout<<"False " ;return false;}

        }
        void Replace (int i , int j) {
            swap (names[i-1],names[j-1]);

        }



};


int main()
{
string x;
bool y;
int i ,j,c;
cout<<"Enter the full name : "<<endl ;
getline(cin,x);
    name s(x);
    s.print();
cout<<"What do you want?\n1)Exit the program.\n2)change the arrangment of the name and check if it's vaild."<<endl;
cin>>c;
if (c==1) return 0 ;
if (c==2){
cout<<"Enter the number of the two parts you want to swap."<<endl;
cin>>i>>j;
cout<<"Can I change it? :" ;
y=s.canReplace(i,j);
if(y==1){
s.Replace(i,j);
cout<<endl<<"The new name is:"<<endl;
s.print();}}
    return 0;
}
