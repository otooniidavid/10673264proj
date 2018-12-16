#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
//#include <person.h>

using namespace std;

template <class var>

void print(var textline){
    cout << textline;
}



//structs
struct course {
    int level;
    string subjects[10];
};

struct record{
    int semester;
    int credit_hr;
    string course_name;
    int mark;
    string grade;
};


class person
{
    public:
        person()
        {
            //set empty student name = ""
            status = "null";
        }
        //setter functions for student
        void setName(string val){
            name = val;
        }

        void setStatus(string val){
            status = val;
        }

        void setAge(int val){
            age = val;
        }

        void setID(int val){
            object_id = val;
        }

        void setIndex(int val){
            index = val;
        }

        void setResidence(string val){
            residence = val;
        }

        void listItems(vector <string> arrayVar){
            int len = arrayVar.size();
            for (int i=0;i<len;i++){
                print(arrayVar[i]);
                if ((i+1)%3 == 0){
                    print("\n");
                }else{
                    print("\t\t");
                }
            }
        }


        //getter functions for student
        string getName(){
            return name;
        }

        string getStatus(){
            return status;
        }

        int getAge(){
            return age;
        }

        string getResidence(){
            return residence;
        }

        string getType(){
            return "person";
        }

        int getID(){
            return object_id;
        }

        int getIndex(){
            return index;
        }

        void getInfo(){
            cout << "\nname       : " << getName() << "\nage        : " << getAge() << "\nperson ID    : " << getID() <<endl;
        }

    private:
        string name;
        int age;
        int index;
        int object_id;
        string status;
        string residence;
};


struct student{
    person details;
    float schoolfees;
    int level;
    string course;
    string department;
    vector<string> subjects;
    vector<record> academic_records;
};

struct staff{
    person details;
    string job;
    string department;
    vector<string> subjects;
};


//###  functions prototypes  ##########
void addStudent(),editStudent(),manageStudent(),GpaCalc(student obj);
void addStaff(),editStaff(),manageStaff(),GpaCalc(student obj);
string lower(string line),gradeCalc(double score);

student Stu_Container[10000];
staff Sta_Container[10000];


int stu_base_id=10440000;
int sta_base_id=11440000;
int stu_count = 0;
int sta_count = 0;
string str;int num;


//#########################################################
//when you get this just edit the print statements i used..
//its the same as cout << [content] <<endl;
//you can beautify all the print statements
//symbols and stuff like that...
//add more options if possible..
//########################################################

int main()
{
   print("##########################################################################################################################################################################################\n");
   print("###########################################################################################################################################################################################\n");
   print("###########################################################################################################################################################################################\n");
   print("############################################################################################################################################################################################\n");
   print("############################################################################################################################################################################################\n");
   print("##############################################################################################################################################################################################\n");
   print("###############################################################################################################################################################################################\n");
   print("#################################################################################################################################################################################################\n");

print("########   #########     ###        ###              ####                   ###                                                                                                      \n");
print("##         ##            ###        ###              #### ###           ### ###                                                                                                            \n");
print("##         ##            ###        ###              ####   ###        ###  ###         ############       ##########     ###########      ###########         ####################################\n");
print("########   ##            ##############              ####    ###      ###   ###                   ##       ##      ##              ##      ##       ##        ####################################\n");
print("      ##   ##            ###        ###              ####     ###    ###    ###          ###########       ##      ##       #########      ##       ##        ######################################\n");
print("      ##   ##            ###        ###              ####       ### ###     ###          ##       ##       ##      ##       ##     ##      ##       ##           ###                               \n");
print("########   #########     ###        ###              ####         ###       ###          ###########       ##      ##       #########      ###########           ###                                  \n");
print("                                                                                                                                                    ##                                                     \n");
print("                                                                                                                                                    ##          ######################################\n");
print("                                                                                                                                                    ##          #########################################\n");
print("                                                                                                                                            ###########         #########################################\n");

print("###########################################################################################################################################################################################################\n");
print("################################################################            ###############################################################################################################################\n");
print("##########################################################################################################################################################################################################\n");
print("################################################################################################################################################################################################################\n");
print("################################################################################################################################################################################################################\n");

    //change this statement to something nicer;
    print("\nHello... Welcome:)\n");
    //############################
    string option;

    //this is the engine that runs the app
    //functions are at the bottom of this file
    while (true){
       print("\n1. student \n2. staff \n0. exit\n");
       print("\nselect person : >>>");
       cin >> str;
       if (str == "1"){
            print("\nstudent route");//change this print statement
            while (true){
                print("\n\n1. add \n2. edit \n3. manage \n0. exit");
                print("\n\nselect an option : >>>");
                cin >> option;
                if (option == "1"){
                    addStudent();//to add students...
                }
                else if (option == "2"){
                    editStudent();//edit stuent object
                }
                else if (option == "3"){
                    manageStudent();//manage student object;
                }
                else if (option == "0"){
                    break;
                }
                cin.clear();
            }
        }
        else if (str == "2"){
            print("\nSTAFF INFO");
            while (true){
                print("\n\n1. add \n2. edit \n3. manage \n0. exit");
                print("\n\nselect an option : >>>");
                cin >> option;
                if (option == "1"){
                    addStaff();
                }
                else if (option == "2"){
                    editStaff();
                }
                else if (option == "3"){
                    manageStaff();
                }
                else if (option == "0"){
                    break;
                }
                cin.clear();
            }
        }
        else if (str == "0"){
            break;
        }
    }
    return 0;
}


void addStudent(){
    //add student detail....read class and struct
    cin.clear();
    print("\n**************ADDING NEW STUDENT*****************");
    student temp;
    print("\nAssigned Student ID : ");print(stu_base_id+stu_count);
    temp.details.setID(stu_base_id+stu_count);temp.details.setIndex(stu_count);stu_count++;
    string str;int num;
    print("\nEnter Students Name : >>>");
    cin.ignore();getline(cin, str);cin.clear();
    temp.details.setName(str);
    print("\nEnter Students Age : >>>");
    cin >> num;
    while (cin.fail()){
        print("\n( invalid ) Try Again : ");
        cin.clear();cin.ignore();cin >> num;
    }
    temp.details.setAge(num);
    //list department for student to choose from
    print("\nEnter Department Name : >>>");
    cin >> str;
    temp.department = str;
    //list course using department
    print("\nEnter Students Course : >>>");
    cin >> str;
    temp.course = str;
    //set controls
    print("\nEnter Students Level  : >>>");
    cin >> num;
    while (cin.fail()){
        print("\n( invalid ) Try Again : ");
        cin.clear();cin.ignore();cin >> num;
    }
    while (num != 100 && num != 200 && num != 300 && num != 400){
        print("( invalid ) Enter Level  : ");
        cin >> num;
        while (cin.fail()){
            print("\n( invalid ) Try Again : ");
            cin.clear();cin.ignore();cin >> num;
        }
    }
    temp.level = num;
    //set controls
    print("\nEnter Students School Fees : >>>");
    cin >> num;
    while (cin.fail()){
        print("\n( invalid ) Try Again  : ");
        cin.clear();cin.ignore();cin >> num;
    }
    temp.schoolfees = num;

    //pushing to array
    Stu_Container[temp.details.getIndex()] = temp;

    print("\nDo you want to add another student? (y/n) : >>>");
    cin >> str;
    if (str == "y"){
        addStudent();
    }
    else{
        //pass
    }

};

void editStudent(){
//search student
int pass = 1;
print("\n( edit ) Enter students ID or 0 to leave : ");
int stu_id;
cin >> stu_id;
while (cin.fail()){
    print("\n( invalid ) Try Again : ");
    cin.clear();cin.ignore();cin >> stu_id;
}
if (stu_id != 0){

    stu_id -= stu_base_id;
    //controls
    while (stu_id < 0 || stu_id >= stu_count){
        print("\n( invalid ) Enter Students ID or 0 to leave : ");
        cin >> stu_id;
        while (cin.fail()){
            cin.clear();cin.ignore();
            print("\n( invalid ) Enter valid student ID : ");
            cin >> stu_id;
        }
        if(stu_id != 0){
            stu_id -= stu_base_id;
        }
        else{
            pass = 0;
            break;
        }
    }

    if (pass == 1){
        //found student
        print("\nStudent Found\n");
        student obj = Stu_Container[stu_id];
        //editing student
        //list option for edit...eg name ,age etc.
        while (true){
            print("\n\n1. name \n2. age \n3. level \n4. course \n5. department \n6. student subjects \n7. residence \n0. exit\n");
            print("\nWhat do you want to edit : ");
            string edit;
            cin >> edit;
            if (edit == "1"){
                print("\nStudents name : ");print(obj.details.getName());
                print("\n\nChange to : ");
                cin.ignore();getline(cin, str);cin.clear();
            }
            else if (edit == "2"){
                print("\nStudents age : ");print(obj.details.getAge());
                print("\n\nChange to : ");
                cin >> num;
                while (cin.fail()){
                    print("\n( invalid ) Try Again : ");
                    cin.clear();cin.ignore();cin >> num;
                }
                obj.details.setAge(num);
            }
            else if (edit == "3"){
                print("\nStudents level : ");print(obj.level);
                print("\n\nChange to : ");
                cin >> num;
                while (cin.fail()){
                    print("\n( invalid ) Try Again : ");
                    cin.clear();cin.ignore();cin >> num;
                }
                while (num != 100 && num != 200 && num != 300 && num != 400){
                    print("\n\nChange to 100,200,300 or 400 : ");
                    cin >> num;
                    while (cin.fail()){
                        print("\n( invalid ) Try Again : ");
                        cin.clear();cin.ignore();cin >> num;
                    }
                }
                obj.level = num;
            }
            else if (edit == "4"){
                print("\nStudents course : >>>");print(obj.course);
                cin.ignore();getline(cin, str);cin.clear();
                obj.course = str;
            }
            else if (edit == "5"){
                print("\nStudents Department : >>>");print(obj.department);
                print("\n\nChange to : ");
                cin.ignore();getline(cin, str);cin.clear();
                obj.department = str;
            }
            else if (edit == "6"){
                print("\n\n\nStudents subject : >>>\n");//list obj.subjects;
                while (true){
                    print("1. add subject \n2. remove subject \n0. exit\n");
                    print("select an option : >>>");
                    cin >> str;
                    if (str == "1"){
                        cin.ignore();
                        while (true){
                            print("\nenter subject to add or use 0 to leave : >>>");
                            getline(cin, str);
                            if (str == "0"){
                                break;
                            }
                            else{
                               obj.subjects.push_back(str);
                               record _new;
                               _new.course_name = str;
                               _new.mark = -1;
                               obj.academic_records.push_back(_new);
                            }
                        }

                    }
                    else if (str == "2"){
                        cin.ignore();
                        while (true){
                            print("\nenter subject to remove or use 0 to leave : >>>");
                            getline(cin, str);
                            if (str == "0"){
                                break;
                            }
                            else{
                                int len = obj.subjects.size();
                                for (int i=0;i<len;i++){
                                    if (lower(obj.subjects[i]) == lower(str)){
                                        obj.subjects.erase(obj.subjects.begin()+i);
                                        obj.academic_records.erase(obj.academic_records.begin()+i);
                                        print("\nSubject successfully removed ...");
                                        break;
                                    }
                                    if (i == len-1){
                                        print("\ncant find subject index ...\n");
                                    }
                                }
                            }
                        }
                    }else if (str == "0"){
                        break;
                    }
                }

            }
            else if (edit == "7"){
                print("\nStudents Residence : >>>");print(obj.details.getResidence());
                print("\n\nChange to : >>>");
                cin.ignore();getline(cin, str);cin.clear();
                cin.clear();obj.details.setResidence(str);
            }
            else if (edit == "0"){
                //commit changes and push
                Stu_Container[obj.details.getIndex()] = obj;
                break;
            }
        }
    }
}

};

void manageStudent(){
    //search student
int pass = 1;
print("\n( manage )Enter students ID or 0 to leave : >>>");
int stu_id;
cin >> stu_id;
while (cin.fail()){
    print("\n( invalid ) Try Again : ");
    cin.clear();cin.ignore();cin >> stu_id;
}
if (stu_id != 0){

    stu_id -= stu_base_id;
    //controls
    while (stu_id < 0 || stu_id >= stu_count){
        print("\n( invalid ) Enter Students ID or 0 to leave : ");
        cin >> stu_id;
        while (cin.fail()){
            cin.clear();cin.ignore();
            print("\n( invalid ) Enter valid student ID : ");
            cin >> stu_id;
        }
        if(stu_id != 0){
            stu_id -= stu_base_id;
        }
        else{
            pass = 0;
            break;
        }
    }

    if (pass == 1){
        //found student
        print("\nStudent Found\n");
        student obj = Stu_Container[stu_id];
        //editing student
        while (true){
            print("\n\n1. enter students score \n2. show academic records \n3. remove student \n0. exit\n");
            print("\nWhat do you want to do : ");
            string manage;
            cin >> manage;
            if (manage == "1"){
                int len = obj.subjects.size();
                print("Enter the semester? (1,2) : ");
                cin >> num;
                while (num != 1 && num != 2){
                    print("Enter the semester? (1,2) : ");
                    cin >> num;
                }
                for (int i=0;i<len;i++){
                    if (obj.academic_records[i].mark == -1){
                        print("\n\nSubject :\t");print(obj.academic_records[i].course_name);
                        print("\nDo you want to record marks for this subject : ");
                        cin >> str;str = lower(str);
                        while (str != "y" && str != "n"){
                            print("\nplease choose 'y' or 'n'");
                            cin >> str;
                            str = lower(str);
                        }
                        if (str == "y"){
                            int credit_h;
                            print("\nCredit Hour(s)\t:\t");
                            cin >> credit_h;
                            while (0 > credit_h || credit_h > 3){
                                print("(invalid) Credit Hour(s)\t:\t");
                                cin >> credit_h;
                            }
                            int score;
                            print("Enter Mark\t:\t");
                            cin >> score;
                            while (0 > score || score >100){
                                print("(invalid) Enter Mark\t:\t");
                                cin >> score;
                            }
                            obj.academic_records[i].mark = score;
                            obj.academic_records[i].credit_hr = score;
                            obj.academic_records[i].semester = num;
                            obj.academic_records[i].grade = gradeCalc(score);
                        }
                    }
                }
                Stu_Container[obj.details.getIndex()] = obj;
            }
            else if (manage == "2"){
                int len = obj.subjects.size();
                print("\n\n############################################################################################");
                print("\n********************************************************************************************");
                print("\nName : ");print(obj.details.getName());print("\tDepartment : ");print(obj.department);
                print("\tCourse : ");print(obj.course);print("\tLevel : ");print(obj.level);print("\tGPA :\t");GpaCalc(obj);
                print("\n********************************************************************************************");
                print("\n============================================================================================");
                for (int i=0;i<len;i++){
                    if (obj.academic_records[i].mark != -1){
                        print("\n\nSubject :\t");print(obj.academic_records[i].course_name);
                        print("\t\tMark :\t");print(obj.academic_records[i].mark);
                        print("\t\tGrade :\t");print(obj.academic_records[i].grade);
                    }
                    else{
                        print("\n\nSubject :\t");print(obj.academic_records[i].course_name);
                        print("\t\tMark :\t");print("**N/A**");
                        print("\t\tGrade :\t");print("**N/A**");
                    }
                }
                print("\n\n============================================================================================");
                print("\n############################################################################################");
            }
            else if (manage == "3"){
                print("\nAre you sure you want to remove student? (y/n) : ");
                cin >> str;str = lower(str);
                while (str != "y" && str != "n"){
                    print("\nplease choose 'y' or 'n'");
                    cin >> str;
                    str = lower(str);
                }
                if (str == "y"){
                    obj.details.setStatus("removed");
                    Stu_Container[obj.details.getIndex()] = obj;
                }
            }
            else if (manage == "0"){
                //commit changes and push
                Stu_Container[obj.details.getIndex()] = obj;
                break;
            }
        }
    }
}
};

void addStaff(){
    //add student detail....read class and struct
    cin.clear();
    print("\n**************adding new staff*****************");
    staff temp;
    print("\n\nAssigned Staff ID : ");print(sta_base_id+sta_count);
    temp.details.setID(sta_base_id+sta_count);temp.details.setIndex(sta_count);sta_count++;
    string str;int num;
    print("\nEnter Staff Name : ");
    cin.ignore();getline(cin, str);cin.clear();
    temp.details.setName(str);
    print("\nEnter Staff Age : ");
    cin >> num;
    while (cin.fail()){
        print("\n( invalid ) Try Again : ");
        cin.clear();cin.ignore();cin >> num;
    }
    temp.details.setAge(num);
    //list department for student to choose from
    print("\nEnter Department Name : ");
    cin >> str;
    temp.department = str;
    //list course using department

    print("\nEnter Staffs Job : ");
    cin >> str;
    temp.job = str;
    //list course using department

    //pushing to array
    Sta_Container[temp.details.getIndex()] = temp;

    print("\nDo you want to add another staff? (y/n) : ");
    cin >> str;
    if (str == "y"){
        addStaff();
    }
    else{
        //pass
    }

};

void editStaff(){
//search student
int pass = 1;
print("\n( edit ) Enter Staffs ID or 0 to leave : ");
int sta_id;
cin >> sta_id;
while (cin.fail()){
    print("\n( invalid ) Try Again : ");
    cin.clear();cin.ignore();cin >> sta_id;
}
if (sta_id != 0){
    sta_id -= sta_base_id;
    //controls
    while (sta_id < 0 || sta_id >= stu_count){
        print("\n( invalid ) Enter Staffs ID or 0 to leave : ");
        cin >> sta_id;
        while (cin.fail()){
            cin.clear();cin.ignore();
            print("\n( invalid ) Enter valid Staff ID : ");
            cin >> sta_id;
        }
        if(sta_id != 0){
            sta_id -= sta_base_id;
        }
        else{
            pass = 0;
            break;
        }
    }

    if (pass == 1){
        //found student
        print("\nStaff Found\n");
        staff obj = Sta_Container[sta_id];
        //editing student
        //list option for edit...eg name ,age etc.
        while (true){
            print("\n\n1. name \n2. age \n3. department \n4. staff subjects \n5. residence \n0. exit\n");
            print("\nWhat do you want to edit : ");
            string edit;
            cin >> edit;
            if (edit == "1"){
                print("\nStaffs name : ");print(obj.details.getName());
                print("\n\nChange to : ");
                cin.ignore();getline(cin, str);cin.clear();
            }
            else if (edit == "2"){
                print("\n\nChange to : ");
                cin >> num;
                while (cin.fail()){
                    print("\n( invalid ) Try Again : ");
                    cin.clear();cin.ignore();cin >> num;
                }
                obj.details.setAge(num);
            }
            else if (edit == "3"){
                print("\nStaffs Department : ");print(obj.department);
                print("\n\nChange to : ");
                cin.ignore();getline(cin, str);cin.clear();
                obj.department = str;
            }
            else if (edit == "4"){
                print("\n\n\nStaffs subject : \n");//list obj.subjects;
                while (true){
                    print("1. add subject \n2. remove subject \n0. exit\n");
                    print("select an option : ");
                    cin >> str;
                    if (str == "1"){
                        cin.ignore();
                        while (true){
                            print("\nenter subject to add or use 0 to leave : ");
                            getline(cin, str);
                            if (str == "0"){
                                break;
                            }
                            else{
                               obj.subjects.push_back(str);
                            }
                        }

                    }
                    else if (str == "2"){
                        cin.ignore();
                        while (true){
                            print("\nenter subject to remove or use 0 to leave : ");
                            getline(cin, str);
                            if (str == "0"){
                                break;
                            }
                            else{
                                int len = obj.subjects.size();
                                for (int i=0;i<len;i++){
                                    if (lower(obj.subjects[i]) == lower(str)){
                                        obj.subjects.erase(obj.subjects.begin()+i);
                                        print("\nSubject successfully removed ...");
                                        break;
                                    }
                                    if (i == len-1){
                                        print("\ncant find subject index ...\n");
                                    }
                                }
                            }
                        }
                    }else if (str == "0"){
                        break;
                    }
                }
            }
            else if (edit == "5"){
                print("\nStaffs Residence : ");print(obj.details.getResidence());
                print("\n\nChange to : ");
                cin.ignore();getline(cin, str);cin.clear();
                cin.clear();obj.details.setResidence(str);
            }
            else if (edit == "0"){
                //commit changes and push
                Sta_Container[obj.details.getIndex()] = obj;
                break;
            }
        }
    }
}

};

void manageStaff(){
    //search student
int pass = 1;
print("\n( manage )Enter Staffs ID or 0 to leave : ");
int sta_id;
cin >> sta_id;
while (cin.fail()){
    print("\n( invalid ) Try Again : ");
    cin.clear();cin.ignore();cin >> sta_id;
}
if (sta_id != 0){
    sta_id -= sta_base_id;
    //controls
    while (sta_id < 0 || sta_id >= sta_count){
        print("\n( invalid ) Enter Staff ID or 0 to leave : ");
        cin >> sta_id;
        while (cin.fail()){
            cin.clear();cin.ignore();
            print("\n( invalid ) Enter valid staff ID : ");
            cin >> sta_id;
        }
        if(sta_id != 0){
            sta_id -= sta_base_id;
        }
        else{
            pass = 0;
            break;
        }
    }

    if (pass == 1){
        //found student
        print("\nStaff Found\n");
        staff obj = Sta_Container[sta_id];
        //editing student
        while (true){
            print("\n\n1. remove staff \n0. exit\n");
            print("\nWhat do you want to do : ");
            string manage;
            cin >> manage;
            if (manage == "1"){
                print("\nAre you sure you want to remove staff? (y/n) : ");
                cin >> str;str = lower(str);
                while (str != "y" && str != "n"){
                    print("\nplease choose 'y' or 'n'");
                    cin >> str;
                    str = lower(str);
                }
                if (str == "y"){
                    obj.details.setStatus("removed");
                    Sta_Container[obj.details.getIndex()] = obj;
                }
            }
            else if (manage == "0"){
                //commit changes and push
                Sta_Container[obj.details.getIndex()] = obj;
                break;
            }
        }
    }
}
};


string lower(string line){
    string LOWER = "abcdefghijklmnopqrstuvwxyz";
    string UPPER = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string ret_lower = "";
    int len = line.length();
    for (int i=0;i<len;i++){//boy
        for (int j=0;j<26;j++){
            if (line[i] == UPPER[j]){
                ret_lower += LOWER[j];
                break;
            }
            else if (j == 25){
                ret_lower += line[i];
            }
        }

    }
    return ret_lower;
}


string gradeCalc(double score){
    if (79 < score && score <= 100){
        return "A";
    }
    else if(74 < score && score <= 79){
        return "B+";
    }
    else if(69 < score && score <= 74){
        return "B";
    }
    else if(64 < score && score <= 69){
        return "C+";
    }
    else if(59 < score && score <= 64){
        return "C";
    }
    else if(54 < score && score <= 59){
        return "D+";
    }
    else if(49 < score && score <= 54){
        return "D";
    }
    else if(44 < score && score <= 49){
        return "E";
    }
    else if(-1 < score && score <= 44){
        return "F";
    }
    else{
        return "invalid mark";
    }
}


float getGpaScore(string grade){
    if (grade == "A"){
        return 4.0;
    }
    else if (grade == "B+"){
        return 3.5;
    }
    else if (grade == "B"){
        return 3.0;
    }
    else if (grade == "C+"){
        return 2.5;
    }
    else if (grade == "C"){
        return 2.0;
    }
    else if (grade == "D+"){
        return 1.5;
    }
    else if (grade == "D"){
        return 1.0;
    }
    else if (grade == "E"){
        return 0.5;
    }
    else if (grade == "F"){
        return 0.0;
    }
    return -1;
}

void GpaCalc(student obj){
    float gpa = 0.0;int tch=0;bool empty_score = false;
    int len = obj.academic_records.size();
    vector<record> temp_record = obj.academic_records;
    for (int i=0;i<len;i++){
        if (temp_record[i].mark == -1){
            empty_score = true;
            cout << "**N/A**";
            break;
        }
        else{
            tch += temp_record[i].credit_hr;
            gpa += getGpaScore(temp_record[i].grade)*temp_record[i].credit_hr;
        }
    }
    if (empty_score == false){
        if (len != 0){
            cout << gpa/tch;
        }
        else{
            cout << "**N/A**";
        }
    }
}
