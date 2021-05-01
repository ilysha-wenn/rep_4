#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <windows.h>

using namespace std;

void setcur(int, int);

class OpenFile{
public:
        void openFile(string path){
            ifstream file;
            file.open(path);
            while(!file.eof()){
                string str = "";
                getline(file, str);
                cout << str << endl;
            }file.close();
        }

        void writeFile(string path){
            system("cls");

            ofstream file;
            file.open(path, ofstream::app);
            string a;

            cout << "Num: "; cin >> a;
            file<< "\n	" <<a;
            cout << "Cost: ";   cin >> a;
            file << "	" << a;
            cout << "Gun: ";   cin >> a;
            file << "	" << a;
            cout << "Caliber: ";  cin >> a;
            file << "	" << a;

            file.close();
            system("cls");
        }

        void writePeoplesinFile(string path){
            system("cls");

            ofstream file;
            file.open(path, ofstream::app);
            string a;

            cout << "Num: ";    cin >> a;
            file<< "	" <<a;
            cout << "Name: ";   cin >> a;
            file << "	" << a;
            cout << "Gun: ";    cin >> a;
            file << "	" << a;
            cout << "Cost: ";   cin >> a;
            file << "	" << a;
            cout << "Caliber: ";    cin >> a;
            file << "	" << a;

            file.close();
            system("cls");
        }

        void deleteInFile(string path){
            ifstream file_in;
            file_in.open(path);

            cout <<"Num?:: "<< std::endl;
            int i_number_line_delete = 0;
            cin >> i_number_line_delete;

            int i_number_line_now = 0;
            string line;
            string line_file_text;

            while(getline(file_in,line))
            {
                i_number_line_now++;

                if(!(i_number_line_now == i_number_line_delete))
                {
                    line_file_text.insert(line_file_text.size(),line);
                    line_file_text.insert(line_file_text.size(),"\r\n");
                }
            }file_in.close();

            ofstream file_out;
            file_out.open (path,ios::trunc | ios::binary);

            file_out.write(line_file_text.c_str(), line_file_text.size());
            file_out.clear();
            file_out.close();
        }

        void addUser(string path){
            system("cls");

            ofstream file;
            file.open(path, ofstream::app);
            string a;

            cout << "Your num in check list: "; cin >> a;
            file<< "	" <<a;
            cout << "Your name: ";  cin >> a;
            file<< "	" <<a;
            cout << "What the gun you are want: ";  cin >> a;
            file<< "	" <<a;
            cout << "Price? ";  cin >> a;
            file<< "	" <<a;
            cout << "Caliber of gun? "; cin >> a;
            file<< "	" <<a;
            file.close();
            system("cls");
        }
}openfiles;

class Information{
public:
    void Info(){
        printf("%s%s%s%s",
               "Imitated executable file of shop guns.\n",
                "Course work in college.\n",
                "Used function C/C++ lang.\n",
                "Goodbye\n");
    };
}information;




int main() {
    int a = 0;
    string path = "info.txt";
    string path_peoples = "peoples.txt";
    do{
        setcur(0, 0);
        printf("%s%s%s%s%s%s%s%s",
               "Type 1: Open List Guns\n",
               "Type 2: Open Buyer List\n",
               "Type 3: Add guns to List\n",
               "Type 4: Add peoples to buyers\n",
               "Type 5: Delete 1 line in List Gun\n",
               "Type 6: Delete 1 line in Buyer List\n",
               "Type 7: Buy Gun Role\n",
               "Type 8: Information\n");
        scanf("%d", &a);

        if(a == 1)  openfiles.openFile(path);
        if(a == 2)  openfiles.openFile(path_peoples);
        if(a == 3)  openfiles.writeFile(path);
        if(a == 4)  openfiles.writePeoplesinFile(path_peoples);
        if(a == 5)  openfiles.deleteInFile(path);
        if(a == 6)  openfiles.deleteInFile(path_peoples);
        if(a == 7)  openfiles.addUser(path_peoples);
        if(a == 8)  information.Info();

        Sleep(2000);
        system("cls");
    }while(a != -1);
}


void setcur(int x, int y){
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}



