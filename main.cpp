#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main(){

    ifstream file("users.txt");
    string line, token;

    if(!file){
        cout << "Error while opening \"users.txt\"!" << endl;
        return 1;
    }

    vector<string> temp;

    while(getline(file, line)){
        stringstream ss(line);
        while (getline(ss, token, ','))
        {
            temp.push_back(token);
        }
        if(temp.size() == 3){
            cout << "Name    : " << temp[0] << endl;
            cout << "Age     : " << temp[1] << endl;
            cout << "Country : " << temp[2] << endl;
            cout << "===================================" << endl;
            temp.clear();
        }else{
            cout << "Invalid format in \"users.txt\"!" << endl;
            return 1;
        }
    }
    return 0;
}
