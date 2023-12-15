#include <iostream>
using namespace std;

class person{
private:
    string name;
    string cnic;
    person *next;
public:
    virtual void setter();
    virtual void getter()const;
    void set_next(person *p);
    person* get_next();
    virtual bool outstanding() = 0;
    person(string n ="",string c="",person *p= nullptr):name(n),cnic(c),next(p){}
};
void person::setter() {

    cout<<"Enter Full Name"<<endl;
    cin.ignore();
    getline(cin,name);
    cout<<"Enter Your CNIC Number"<<endl;
    cin.ignore();
    getline(cin,cnic);
}
void person::set_next(person *p) {
    next = p;
}
person* person::get_next() {

    return next;
}
void person::getter()const {

    cout<<"Name :"<<name<<endl;
    cout<<"CNIC NO:"<<cnic<<endl;
}
class teacher: virtual public person{
private:
    string deptt;
    int noofpub;
public:
    void setter();
    void getter()const;
    bool outstanding();
    teacher(string n1 ="",string c1="",person *p1= nullptr,string d="",int p=0): person(n1,c1,p1),deptt(d),noofpub(p){}
};
void teacher::setter() {
    person::setter();
    cout<<"Enter Your Department"<<endl;
    getline(cin,deptt);
    cout<<"Enter No Of Pulication"<<endl;
    cin>>noofpub;
}
void teacher::getter() const {

    cout<<"**********(Teacher DATA)***************"<<endl;
    person::getter();
    cout<<"Dapartment :---->"<<deptt<<endl;
    cout<<"No Of Publication :----->"<<noofpub<<endl;
}
bool teacher::outstanding() {
    if(noofpub>=10)
        return true;
    }
}
class student :virtual public person{
private:
    string degreeprog;
    float cgpa;
public:
    void setter();
    void getter()const;
    bool outstanding();
    student(string n3 = "",string c3="",person *p3= nullptr,string deg="",float cg=0.0): person(n3,c3,p3),degreeprog(deg),cgpa(cg){}
};
void student::setter() {
    person::setter();
    cout<<"Enter Degree Programme"<<endl;
    getline(cin,degreeprog);
    cout<<"Enter Your CGPA out of/4"<<endl;
    cin>>cgpa;
}
void student::getter() const {
    cout<<"*************(Student DATA)*****************"<<endl;
    person::getter();
    cout<<"Degree Programme:---->"<<degreeprog<<endl;
    cout<<"CGPA :---->"<<cgpa<<endl;
}
bool student::outstanding() {
    if(cgpa>=3){
        return true;
    }
}
int main(){
    person *first=NULL,
           *cur=NULL,
           *prev=NULL;
    int nt=0;
    int ns=0;
    int os=0,ot=0;
    int ch;


    do{
        cout << "********* MENU ********" << endl
             << " 1. Create Database For Teacher" << endl
             << " 2. Create Database For Student" << endl
             << " 3. Display All Data" << endl
             << " 4. Display Statistically" << endl
             << " 5. Exit" << endl
             << " Enter your choice: ";
        cin>>ch;

        switch (ch) {

            case 1://create Teacher Database
               cur = new teacher;
               cur->setter();
               if(!first){
                   first = prev = cur;
               }
               else{
                   prev->set_next(cur);
                   prev=cur;
               }
               if(cur->outstanding()){
                             ot++;
               }
               nt++;
                break;

            case 2://create Student Database
                cur = new student;
                cur->setter();
                if(!first){
                    first = prev = cur;
                }
                else{
                    prev->set_next(cur);
                    prev=cur;
                }
                if(cur->outstanding()){
                    os++;
                }
                ns++;
                break;

            case 3://Display
            cur=first;
            while(cur){
                cur->getter();
                if(cur->outstanding()){
                    cout<<"**(outstanding)**"<<endl;
                }
                cur = cur->get_next();
            }

                break;
            case 4://Display statistically

                cout<<"No of Objects Of Teacher In DB :"<<nt<<endl;
                cout<<"No of Objects Of Student In DB :"<<ns<<endl;
                cout<<"No of Outstanding Teacher:"<<ot<<endl;
                cout<<"no of outstanding student:"<<os<<endl;
                break;

            case 5://Exit
                return 0;

        }

    } while (true);//End of do while

}