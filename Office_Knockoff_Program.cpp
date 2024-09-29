#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;


class UserData{
private:


public:
    string filename,userinput;
};


//creates file with that name
void create_new_file(string titleName, UserData userdata){
fstream file(titleName, ios::app);
if(!file)
{
    ofstream file(titleName);
    file.close();
}
return;
}


//writes line onto the designated file
void write_on_file(string &titleName,string &line){
    fstream file (titleName, ios::in);
    file << line;
    file.close();
}


//keeps writing on the same line untill ENDL word is found
void write_on_file_untill_end(string titleName, string &line){
    cout << "Attempting to write on file : " << titleName << "..."<< endl;
    size_t position_for_substr = line.find("ENDL");
    string line_to_add;
    
    if(position_for_substr != std::string::npos)
    {
    position_for_substr = position_for_substr;
    fstream file(titleName, ios::app);
    file <<  line.substr(0, position_for_substr) << endl;
    file.close();
    }
    else
    {
    ofstream file(titleName, ios::app);
    file << line << " ";
    file.close();
    }
}

//couts every single line in a file 
void return_file_content(string titleName){
    fstream file(titleName);
    if(!file.is_open()){
        cout << "Unknown file, Please Try Again" << endl;
        return;
    }
    int counter;
    string line;
    cout << "File Content as Follows: " << endl;
    while(getline(file,line)){
        counter++;
        cout << "Line " << counter << " - "<< line << endl;
    }
    file.close();
    return;
}

//simple menu
void display_menu(){
    cout << "1-Create a new file" << endl;
    cout << "2-Write on a file" << endl;
    cout << "3-Display a file" << endl;
}


int main(){
    cout << "Hello! Welcome to Mini-Office Program! type whatever you need to add to a txt file and use ENDL at the end of your sentences to move to a new line" << endl;
    cout << "==================================================================================================================================================" << endl;
    UserData userdata;
    display_menu();
    int choice;
    cin >> choice;
    switch(choice){
        case 1:
            cin.ignore();
            cout << "Please provide a title for your new textfile" << endl;
            getline(cin, userdata.filename);


            userdata.filename = userdata.filename + ".txt";
            create_new_file(userdata.filename, userdata);
        break;

        case 2:
            cin.ignore();
            cout << "Please provide a title for your new/old textfile" << endl;
            getline(cin, userdata.filename);


            userdata.filename = userdata.filename + ".txt";
            create_new_file(userdata.filename, userdata);
            while (userdata.userinput != "EXIT")
            {
            cout << "please write: ";
            getline(cin,userdata.userinput);
            write_on_file_untill_end(userdata.filename, userdata.userinput);
            }
        break;

        case 3:
            cout << "Please provide a title for your new/old textfile" << endl;
            cin.ignore();
            getline(cin, userdata.filename);

            
            userdata.filename = userdata.filename + ".txt";
            return_file_content(userdata.filename);
            break;
    
     }
}