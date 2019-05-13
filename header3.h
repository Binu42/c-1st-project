#pragma once
#include<string>
#include<iostream>
#include<algorithm>
#include<fstream>
#include<iomanip>
#include<cstring>
using namespace std;

class shopkeeper{

private:
  string password;
  string user_name;

public:
  void reset_password(string current_password, string new_password);
  void set_user();
  string get_user_name(){return user_name;}
  string get_user_pass(){return password;}
  friend ifstream& operator >>(ifstream& fin, shopkeeper& s);
  friend ofstream& operator <<(ofstream& fout, shopkeeper& s);
  friend istream& operator >>(istream& out, shopkeeper& s);
  int login();
  int known_user_name();
  int known_user_pass();
  void set_user_name();
  void set_pass();
};

void shopkeeper::reset_password(string current_password, string new_password){
  if(!current_password.compare(password))
    password = new_password;
}

void shopkeeper::set_user(){
  cout<<"Enter shopkeeper name: ";
  cin>>user_name;
  cout<<"Enter password: ";
  cin>>password;
}

int shopkeeper::login(){
  string passw_entered;
  cout<<"password: ";
  cin>>passw_entered;
  ifstream fin("userz.txt");
  shopkeeper sh;
  while(fin>>sh){
    if(!passw_entered.compare(sh.password)){
      fin.close();
      return 1;
    }
  }
  fin.close();
  return 0;
}

int shopkeeper::known_user_name(){
  ifstream fin("userz.txt");
  shopkeeper s;
  while (fin>>s) {
    if(!s.user_name.compare(user_name)){
      fin.close();
      return 1;
    }
  }
  fin.close();
  return 0;
}

void shopkeeper::set_user_name(){
  cout<<"Enter the username: ";
  cin>>user_name;
}

void shopkeeper::set_pass(){
  cout<<"Enter the password: ";
  cin>>password;
}

int shopkeeper::known_user_pass(){
  ifstream fin("userz.txt");
  shopkeeper s;
  while (fin>>s) {
    if(!s.password.compare(password)){
      fin.close();
      return 1;
    }
  }
  fin.close();
  return 0;
}

ifstream& operator >>(ifstream& fin, shopkeeper& s){
  fin>>s.user_name>>s.password;
  return fin;
}

ofstream& operator <<(ofstream& fout, shopkeeper& s){
  fout<<s.user_name<<endl;
  fout<<s.password<<endl;
  return fout;
}

istream& operator >>(istream& in, shopkeeper& s){
  cout<<"\nusername: ";
  in>>s.user_name;
  cout<<"\nPassword: ";
  cin>>s.password;
  return in;
}
