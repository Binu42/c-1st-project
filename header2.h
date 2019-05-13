
#pragma once
#include<string>
#include<iostream>
#include<fstream>
#include<iomanip>
#include<cstring>
using namespace std;
class Item_details{
public:
  string name;
  int offer, available;
  float  price;
public:
  Item_details(){}
  Item_details(string s, int p, int off, float f);
  friend ifstream& operator>>(ifstream& fin, Item_details& i);
  friend ofstream& operator<<(ofstream& fout, Item_details& i);
  friend ostream& operator<<(ostream& out, Item_details& i);
  friend istream& operator>>(istream& in, Item_details& i);
};

Item_details::Item_details(string s, int p, int off, float f){
  name = s.assign(s);
  price = p;
  offer = off;
  available = f;
}

ifstream& operator>>(ifstream& fin, Item_details& i){
  fin>>i.name>>i.price>>i.offer>>i.available;
  return fin;
}

ofstream& operator<<(ofstream& fout, Item_details& i){
  fout<<endl<<i.name<<endl;
  fout<<i.price<<endl;
  fout<<i.offer<<endl;
  fout<<i.available<<endl;
  return fout;
}

ostream& operator<<(ostream& out, Item_details& i){
  cout<<setw(20)<<left<<i.name;
  cout<<setw(20)<<left<<i.price;
  cout<<setw(20)<<left<<i.offer;
  cout<<setw(20)<<left<<i.available<<endl;
  return out;
}

istream& operator>>(istream& in, Item_details& i){

  cout<<"Item Name: ";
  cin>>i.name;
  cout<<"price: ";
  cin>>i.price;
  return in;
}
