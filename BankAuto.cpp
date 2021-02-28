#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>
#include <fstream>
#include <sys/types.h>
#include <sys/stat.h>

using namespace std;
namespace fs = filesystem ;

struct DataClient{
    string Login,
           Password ;
};

class Client{
private:
    string Login;
    string Password ;
public:
    Client(string login, string password){
        Login = login, Password = password ;
    }

    void setPassword(string password ){
        Password = password ;
    }
    void setLogin(string login){
        Login = login ;
    }
    string getLogin(){return Login ;}
    string getPassword(){return Password ; }
};

void ChooseOptions(){
    /*
    27.02.2021
    Now you have only 2 options:
    1. Put money : just enter amount you "put"
    2. Get money from your account :
        2.1. Check if you have enough money
        2.2. Confirmation SMS if amount of money is too big (to a file)
        2.3. Case when you enter wrong amount or want to exit
    */
}

bool findLogin(string login, vector<DataClient> clients){
    /*
    Not linear search,
    maybe hash table or just binary tree
    */
}

bool CheckPassword( string login, string password, vector<DataClient> clients){
    /*
    If password is right - everything Ok!
    Should be hash table or binary tree
    */
    return true ;
}
void Clear() {
    system("CLS") ;
}

void WelcomeMenu(){
    /*
    Try to make everything not in console
    */
    cout << "Choose an action : \n\n" ;
    cout << "Log in : (Press 1)\n" ;
    cout << "Log up : (Press 2)\n" ;
    cout << "Exit : (Press 3)\n" ;
}

void LogIn(vector<DataClient>& clients){
    /*
    Should be a chance to exit whenever you want
    */

    string login ;cout << "Enter your login : " ; cin >> login ;
    if( !findLogin(login, clients) ){
        cout << "Ooops...Sorry, but it's wrong login. \nPlease try again.\n" ;
            LogIn(clients) ;
    }

    string password ; cout << "Enter your password : " ; cin >> password ;
    if( !CheckPassword(login, password, clients) ){
        cout << "Wrong one! Sorry, try again!" ;
            LogIn(clients) ;
    }
    Clear() ;
        cout << "Everything Ok!\n" ;
            ChooseOptions() ;
}

void LogUp(vector<DataClient>& clients){
    /*
    Create login -> check if it has already existed
    Create password -> make a system to check if it is safety or not
    Confirm password
    */
}

void makeChoosenAction(int action, vector<DataClient>& clients ){
    if( action == 3){cout << "Thanks! See you next time!\n" ;return ;
    } else if(action == 1){LogIn(clients) ;
    } else {LogUp(clients) ;}
}

vector<DataClient> addAllClients(string files_path){
    vector<DataClient> dataclient ;

    /// make directory with .csv
    vector<string> filesWithClientsData ;
    for( const auto &entry: filesystem::directory_iterator(files_path)){
        if(entry.path().extension() == ".csv"){
            fs::path path{entry} ;
            filesWithClientsData.push_back(path.string()) ;
        }
    }
    ifstream current_file ;
    for(int i = 0 ; i < filesWithClientsData.size() ; i ++ ){

        current_file.open(filesWithClientsData[i]) ;
        if(!current_file.is_open()){
            Clear(); return dataclient;
        }
        string current_client ;
        while(getline(current_file, current_client)){
            int space = current_client.find(' ') ;
            string login = current_client.substr(0, space),
                   password = current_client.substr(space + 1, current_client.size() - space) ;
            dataclient.push_back({login, password}) ;
        }
        current_file.close() ;
    }
    return dataclient ;
}

int main()
{

    vector<DataClient> clients = addAllClients("clients") ;

    for(int i = 0 ; i < clients.size() ; i ++ )
        cout << clients[i].Login << " | " << clients[i].Password << '\n' ;

    cout << "Welcome in YourBank!\n" ;
    WelcomeMenu() ;
    int clientAction ; cin >> clientAction ;

    makeChoosenAction(clientAction, clients) ;

    return 0 ;
}
