
#pragma once
#include<string>
#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;
class customer_Item{
public:
  string name;
  int num;
  float price;
public:
  customer_Item();
  customer_Item(string s, int p, int n);
  friend ofstream& operator<<(ofstream& fout, customer_Item& i);
  friend ifstream& operator>>(ifstream& fin, customer_Item& i);
  friend ostream& operator<<(ostream& out, customer_Item& i);
  friend istream& operator>>(istream& in, customer_Item& i);
};
customer_Item::customer_Item(){}
customer_Item::customer_Item(string s, int p, int n)
{
  name = s.assign(s);
  price = p;
  num = n;
}
ifstream& operator>>(ifstream& fin, customer_Item& i){
  fin>>i.name>>i.price>>i.num;
  return fin;
}

ofstream& operator<<(ofstream& fout, customer_Item& i){
  fout<<i.name<<endl;
  fout<<i.price<<endl;
  fout<<i.num<<endl;
  return fout;
}

ostream& operator<<(ostream& out, customer_Item& i){
  cout<<setw(25)<<left<<"Item name: "<<i.name<<endl;
  cout<<setw(25)<<left<<"price of Item is: "<<i.price<<endl;
  cout<<setw(25)<<left<<"Number of Item is: "<<i.num<<endl;
  return out;
}

istream& operator>>(istream& in, customer_Item& i){
  cout<<"\nItem Name: ";
  cin>>i.name;
  cout<<"Price of item you want to buy: ";
  cin>>i.price;
  return in;
}
