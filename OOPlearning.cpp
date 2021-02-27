#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>

using namespace std;

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

}

bool findLogin(string login){
    return true ;
}

bool CheckPassword( string login, string password){
    return true ;
}
void Clear() {
    system("CLS") ;
}

void WelcomeMenu(){
    cout << "Choose an action : \n\n" ;
    cout << "Log in : (Press 1)\n" ;
    cout << "Log up : (Press 2)\n" ;
    cout << "Exit : (Press 3)\n" ;
}

void LogIn(){
    string login ;cout << "Enter your login : " ; cin >> login ;
    if( !findLogin(login) ){
        cout << "Ooops...Sorry, but it's wrong login. \nPlease try again.\n" ;
            LogIn() ;
    }

    string password ; cout << "Enter your password : " ; cin >> password ;
    if( !CheckPassword(login, password) ){
        cout << "Wrong one! Sorry, try again!" ;
            LogIn() ;
    }
    Clear() ;
        cout << "Everything Ok!\n" ;
            ChooseOptions() ;
}

void LogUp(){

}

void makeChoosenAction(int action, vector<DataClient>& clients ){
    if( action == 3){cout << "Thanks! See you next time!\n" ;return ;
    } else if(action == 1){LogIn(clients) ;
    } else {LogUp(clients) ;}
}

int main()
{
    vector<DataClient> clients ;
    cout << "Welcome in YourBank!\n" ;
    WelcomeMenu() ;
    int clientAction ; cin >> clientAction ;

    makeChoosenAction(clientAction, clients) ;

    return 0 ;
}
