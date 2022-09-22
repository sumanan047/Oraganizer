#include <iostream>
#include <string>
#include <random>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include <thread>

using std::cin;
using std::cout;
using std::endl;
using std::string;

string string_randomizer(string &str, int len_pass){
    srand((unsigned) time(0));
    string loose_string;            // the collected string which will be returned.
    for (int i= 0; i< len_pass; i++){
        loose_string = loose_string + str[rand()%len_pass];
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(5000));
    return loose_string;
}

void print_stuff(){
    cout << "*************"<<endl;
}


int main(){
    int len_pass;
    string passwd;
    // Initialize string array
    string pass_token[4]= { "0123456789", "abcdefghijklmnopqrstuvwxyz", "ABCDEFGHIJKLMNOPQRSTUVWXYZ", "$&_#!" };
    srand((unsigned) time(0));
    cout << "Enter the length of the desired passoword: "<< endl;
    try {
    // Block of code to try
        cin >> len_pass;
        if (len_pass>=6){
            cout << "Minimum passowrd length requirement satisfied! Working magic now!"<< endl;
                for (int j = 0; j< len_pass; j++){
                // sampling various candidate characters for a passoword component
                    for (int i = 0; i <4 ; i++){
                        int num = rand()%pass_token[i].length();
                        passwd += pass_token[i][num];
                    }
    }
    
    //std::thread first ()
    std::thread second (print_stuff);
    passwd = string_randomizer(passwd, len_pass);
    

    // synchronize threads:
    //first.join();                // pauses until first finishes
    second.join();               // pauses until second finishes

    cout << passwd << endl;
        }
        else{
            throw (len_pass); // Throw an exception when a problem arise
        }
    }
    catch (int len_pass) {
    // Block of code to handle errors
    cout << "The length of passowrd asked for was: " << len_pass << " .This won't provide a great security. Request aborted!" << endl;
    }
       
}

