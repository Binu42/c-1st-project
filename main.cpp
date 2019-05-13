
#include"header1.h"
#include"header2.h"
#include"header3.h"

void customer_function();
void shopkeeper_function();
void show();

int main(){
  string user;
  char choice;
  ofstream fout("total_earning.txt");
  fout.close();

  while(1){
    cout<<"\nDo you want to close the Application (Y/N): ";
    cin>>choice;
    cin.ignore(222, '\n');
    if(choice == 'N' || choice == 'n'){
    cout<<"Enter you are \"customer\" or \"shopkeeper\"?: ";
    cin>>user;
    transform(user.begin(), user.end(), user.begin(), ::tolower);
    if(!user.compare("customer"))
      customer_function();

    else if(!user.compare("shopkeeper")){
      int ch = 0;
      while(1){
      if(ch == 4)
        break;
      cout<<"\n\tEnter ";
      cout<<"\n\t1. Create New Account.";
      cout<<"\n\t2. Login Account.";
      cout<<"\n\t3. Reset password.";
      cout<<"\n\t4. Exit\n";
      cout<<"\n\tYour Choice: ";
      cin>>ch;
      switch (ch) {
        case 1:{
          cout<<"\n\t\t----CREATING NEW ACCOUNT----";
          shopkeeper sh;
          int op = 0, op1 = 0;
          ofstream fout("userz.txt", ios::app|ios::out);
          if(fout.tellp() == 0){
            shopkeeper s;
            cin>>s;
            fout<<s;
            break;
          }
          else{
            cout<<"\nEnter the Already Existing user Details which you know\n";
            sh.set_user_name();
            op = sh.known_user_name();
            if(op){
              sh.set_pass();
              op1 = sh.known_user_pass();
          }
          else{
            cout<<"User Name doesn't Exist..\n";
            break;
          }
          }

          if(op1){
            cout<<"\n\t\t----NEW USER ACCOUNT----\n";
            shopkeeper s;
            s.set_user_name();
            int res;
            res = s.known_user_name();
            if(!res){
              s.set_pass();
              fout<<s;
            }

            else
              cout<<"\nEntered username Already Exist-- Try different--\n";

          }

          else

            cout<<"\nPassword Doesn't Match for User Name, Try Later...\n";

          fout.close();

        }
          break;

        case 2:{
          cout<<"\n\t\t----LOG IN----\n";
          int i = 0;
          while(1){
            i++;
            cin.get();
            shopkeeper sh;
            int outp = 0, out = 0;
            string name_entered;
            sh.set_user_name();
            out = sh.known_user_name();
            if(out)
              outp = sh.login();

            else if(i>=5){
              cout<<"\n\t\t----APPLICATION CLOSED----\n";
              cout<<"\t\t    ----Try Later---- \a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a";
              exit(1);
              }

            else{
              cout<<"User Name Entered is incorrect--\n";
              goto level;
            }

            if(outp){
              shopkeeper_function();
              break;
            }
            else if(i>=5){
              cout<<"\n\t\t----APPLICATION CLOSED----\n";
              cout<<"\t\t    ----Try Later---- \a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a";
              exit(1);
            }
            else if(!outp)
              cout<<"\nPassword Entered is Incorrect, Try Again:)\n";

            level:
            cout<<"\nDo you want to Try Login Again--(Y/N): ";
            cin>>choice;
            if(choice=='Y'||choice=='y')
              continue;
            else if(choice=='N'||choice=='n')
              break;
            else
              cout<<"Invalid Input\n";
            }
          }
          break;

          case 3:{
            cout<<"\n\t\t----RESETING PASSWORD----\n";
            string user_nm;
            cout<<"Enter User Name: ";
            cin>>user_nm;
            ifstream fin("userz.txt");
            ofstream fout("temp.txt");
            shopkeeper s;
            string cpass, npass;
            int check = 0;
            while (fin>>s) {
              if(!s.get_user_name().compare(user_nm)){
                check = 1;
                cout<<"Enter Your Current Password: ";
                cin>>cpass;
                if(!s.get_user_pass().compare(cpass)){
                  cout<<"Enter Your New password: ";
                  cin>>npass;
                  s.reset_password(cpass, npass);
                }
                else
                  cout<<"\nEntered Password For User Name is Incorrect---\n";
              }
              fout<<s;
            }
            if(check!=1)
              cout<<"\nEntered User Name Doesn't Exist--\n";
          }
            remove("userz.txt");
            rename("temp.txt", "userz.txt");
            break;

          case 4:
            break;
          default:
            cout<<"INVALID INPUT\n";
        }
      }
    }
    else
    cout<<"TRY AGAIN :)";
  }

  else if(choice == 'Y' || choice == 'y'){
    ifstream fin("total_earning.txt");
    int in, total = 0;
    while (fin>>in) {
      total += in;
    }
    fin.close();
    ofstream fout("total_earning.txt", ios::app|ios::out);
    cout<<"Total Earning: "<<total;
    fout<<"-----------------------\n";
    fout<<"Total Earning : "<<total;
    cout<<"\n\t\t----APPLICATION CLOSED----\n";
    fout.close();
    exit(1);
  }

  else
    cout<<"INVALID INPUT";
}
  return 0;
}

void customer_function(){
  int total_price = 0;
  ofstream fos("customer.txt");
  fos.close();

  while(1){
    cout<<"\nEnter: ";
    cout<<"\n1. Buy Items.";
    cout<<"\n2. Menu Chart";
    cout<<"\n3. Canteen Details";
    cout<<"\n4. For Receipts";
    cout<<"\n5. Exit.";
    cout<<"\n\nYour Choice: ";
    int choice1;
    cin>>choice1;

    switch(choice1){
      case 1:{
        cout<<"\n\t\t----BUYING ITEMS----\n";
        while(1){
          int check = 0;
          ifstream fis("price.txt");
          ofstream fos("new.txt", ios::ate|ios::out);
          customer_Item itm;
          Item_details it;
          cout<<endl<<"Enter Item Name, price to Buy\n";
          cin>>itm;
          while(fis>>it){
            if(!it.name.compare(itm.name) && it.price == itm.price){
              cout<<"Enter the number you want to buy: ";
              cin>>itm.num;
              if(it.available >= itm.num){
                customer_Item ci;
                ofstream fout("temp.txt");
                ifstream fin("customer.txt");
                int check1 = 0;
                while(fin>>ci) {
                  if(!ci.name.compare(itm.name) && ci.price == itm.price){
                    ci.num += itm.num;
                    fout<<ci;
                    check1 = 1;
                  }
                  else{
                   fout<<ci;
                 }
                }
                if(check1!=1)
                  fout<<itm;
                it.available -= itm.num;
                total_price += it.price*itm.num;
                check = 1;
                fin.close();
                fout.close();
                remove("customer.txt");
                rename("temp.txt", "customer.txt");
              }
              else{
                cout<<"Item is not Available in that much Amount, Buy less :) ";
                check = 1;
              }
            }
            fos<<it;
          }

          if(check!=1)
          cout<<"Item You want is not Available, Try Something Else :)"<<endl<<endl;

          remove("price.txt");
          rename("new.txt", "price.txt");
          fis.close();
          fos.close();

          char choice2;
          cin.get();
          cout<<endl<<"Do you want to Buy Anything Else Y/N: ";
          cin>>choice2;
          if(choice2 == 'Y' || choice2 == 'y')
            continue;
          else{
            cout<<"\n-----------------------------"<<endl;
            cout<<"\tTotal Cost = "<<total_price<<endl;
            cout<<"-----------------------------"<<endl;
            cout<<"Thanks For Buying!"<<endl<<endl;
            break;
            }
          }
        }
        break;

        case 2:{
          cout<<"\n\t\t\t----MENU----\n";
          ifstream fis("price.txt");{
            Item_details itm;
            cout<<"\t\t------------------------------\n";
            cout<<"\t\t\tItems Details\n";
            cout<<"\t\t------------------------------\n";
            cout<<setw(20)<<left<<"Item Name";
            cout<<setw(20)<<left<<"Price";
            cout<<setw(20)<<left<<"Offer";
            cout<<setw(20)<<left<<"Availabilty"<<endl;
            while(fis>>itm)
              cout<<itm;
            }
          fis.close();
          }
        break;

        case 3:
            cout<<"\n\t\t*****************************";
            cout<<"\n\t\t\tCANTEEN DETAILS";
            cout<<"\n\t\t*****************************";
            cout<<"\n# TIMING:\n  11 AM TO 02 PM \n  03 PM TO 05 PM";
            cout<<"\n# CANTEEN WILL BE CLOSED ON TUESDAY";
            cout<<"\n# GOODS ONCE SOLD WILL NOT BE EXCHANGED/REPLACED";
            cout<<"\n# DO NOT BREAK ANY CANTEEN ITEMS\n\n";
        break;

        case 4:{
            customer_Item ct;
            ifstream fin("customer.txt");
            cout<<endl;
            cout<<"\t\t--------------------------------------";
            cout<<"\n\t\t\t\tRECEPITS\n";
            cout<<"\t\t--------------------------------------\n";
            while(fin>>ct)
              cout<<ct<<endl;
            fin.close();
        }
            cout<<"-----------------------------"<<endl;
            cout<<"Total Cost = "<<total_price<<endl;
            cout<<"-----------------------------"<<endl<<endl;
        break;

        case 5:{
            ofstream fout("customer.txt", ios::app|ios::out);
            ofstream fos("total_earning.txt", ios::app|ios::out);
            cout<<"-----------------------------"<<endl;
            cout<<"Total Cost = "<<total_price<<endl;
            cout<<"-----------------------------"<<endl;
            cout<<"Thanks For Buying! Visit Again!"<<endl;
            fout<<"-----------------------------"<<endl;
            fout<<"Total Cost = "<<total_price<<endl;
            fout<<"-----------------------------"<<endl;
            fout<<"Thanks For Buying! Visit Again!"<<endl;
            fos<<total_price<<endl;
            fos.close();
            fout.close();
        }
        return ;

        default:
        cout<<"Invalid Input\n";

      }
   }
}


void shopkeeper_function(){
  ifstream fis("price.txt");
  ofstream fos("price.txt", ios::app|ios::out);

  if(!fis.is_open() || fos.tellp()== 0){
    cout<<"Price and offer of Items are not setted\n";
    cout<<"Enter the Number of items Details you want to Insert: ";
    int n;
    cin>>n;
    Item_details *item = new Item_details[n];

    cout<<"\nEnter Item Name, Price, Offer and Availabilty of Items\n";
    for(int i=0; i<n; i++){
      cout<<endl<<"\t\t\t----Item---- "<<i+1<<endl;
      cin>>item[i];
      cout<<endl;
    }

    for(int i=0; i<n; i++){
      Item_details itm;
      ifstream fin("price.txt");
      int check = 0;
      while(fin>>itm){
        if(!itm.name.compare(item[i].name) && itm.price == item[i].price)
          check = 1;
    }
  if(check == 1)
    cout<<"--Item: "<<i+1<<" already exist--";
  else
    fos<<item[i];
  fin.close();
}
  delete[] item;
}
fis.close();
fos.close();
show();

  while(1){
    cout<<"Enter:\n";
    cout<<"1. Change the Item details\n";
    cout<<"2. Add New Item\n";
    cout<<"3. Delete Item\n";
    cout<<"4. Delete All Item\n";
    cout<<"5. Total earning\n";
    cout<<"6. Logout\n\n";
    cout<<"Your choice: ";
    int want;
    cin>>want;

    switch(want){
      case 1:{
        cout<<"\n\t\t----CHANGING DETAILS----\n";
        string item_name;
        Item_details it;
        int price, check = 0;
        cout<<"Enter the Item Name and Price whose Details you want to Change\n";
        cout<<"Item Name: ";
        cin>>item_name;
        ifstream fin1("price.txt");
        while(fin1>>it){
          if(!it.name.compare(item_name)){
            cout<<"Enter the Item Price: ";
            cin>>price;
            check = 1;
            break;
          }
        }
        fin1.close();
        ifstream fin("price.txt");
        ofstream fout("my.txt");
        if(check != 1){
          cout<<"\nItem Doesn't Exist\n\n";
          break;
        }
        else
          check = 0;

        while(fin>>it){
          if(!it.name.compare(item_name) && it.price == price){
            int ch;
            cout<<"Enter \n";
            cout<<"1. Change Price.\n";
            cout<<"2. Change Offer.\n";
            cout<<"3. Change Availabilty.\n";
            cout<<"Your Choice: ";
            cin>>ch;

            switch(ch){
              case 1:
                cout<<"\n\t\t----CHANGING PRICE----\n";
                int new_price;
                cout<<"Enter the New Price of Item: ";
                cin>>new_price;
                it.price = new_price;
                check = 1;
                cout<<"\n\t\t----Item price changed----\n";
                break;

              case 2:
                cout<<"\n\t\t----CHANGING OFFER----\n";
                int new_offer;
                cout<<"Enter the New Offer on item: ";
                cin>>new_offer;
                it.offer = new_offer;
                check = 1;
                cout<<"\n\t\t----Item Offer changed----\n";
                break;

              case 3:
                cout<<"\n\t\t----CHANGING AVAILABILITY----\n";
                int new_availability;
                cout<<"Enter New Availabilty of Item: ";
                cin>>new_availability;
                it.available = new_availability;
                check = 1;
                cout<<"\n\t\t----Item Availabilty changed----\n";
                break;

              default:
                cout<<"\n\t\t----Invalid Input----\n\n";
              }
            }
          fout<<it;
        }

        if(check != 1)
          cout<<"\nItem whose Details you want Change does not Exist:)\n\n";
        fin.close();
        fout.close();
        remove("price.txt");
        rename("my.txt", "price.txt");
      }
        show();
        break;

      case 2:{
          cout<<"\n\t\t----ADDING ITEM----\n";
          Item_details item;
          ofstream fos("price.txt", ios::app|ios::out);
          cout<<"\nEnter Items Details\n";
          int i = 0;
          while(1){
              cout<<endl<<"\t\t\t----Item---- "<<++i<<endl;
              cin>>item;

              Item_details itm;
              ifstream fin("price.txt");
              int check = 0;
              while(fin>>itm){
                if(!itm.name.compare(item.name) && itm.price == item.price)
                  check = 1;
            }

            if(check == 1)
              cout<<"This Item Already Exist\n\n";
            else{
              cout<<"offer after number of item: ";
              cin>>item.offer;
              cout<<"NO. of items available: ";
              cin>>item.available;
              fos<<item;

            }
            fin.close();
            cin.get();
            char ch;
            cout<<"\nDo you want to Stop Inserting Items--(Y/N): ";
            cin>>ch;
            if(ch=='Y'||ch=='y')
              break;
            }
          fos.close();
        }
        show();
        break;

      case 3:{
        cout<<"\n\t\t----DELETING ITEM----\n";
        string item_name;
        Item_details it;
        int price, check = 0;
        cout<<"Enter the Item Name: ";
        cin>>item_name;
        ifstream fin1("price.txt");
        while(fin1>>it){
          if(!it.name.compare(item_name)){
            cout<<"Enter the Item Price: ";
            cin>>price;
            check = 1;
            break;
          }
        }
        fin1.close();
        if(check != 1){
          cout<<"\nItem Doesn't Exist\n\n";
          break;
        }
        else
          check = 0;

        ifstream fin("price.txt");
        ofstream fout("my.txt");
        while(fin>>it){
          if(check==0){
          if(!it.name.compare(item_name) && it.price == price){
            cout<<"\n\t\t----Item is Deleted----\n";
            check = 1;
            continue;
          }
        }
          fout<<it;

        }

        if(check != 1)
          cout<<"\nItem whom you want to Delete does not Exist\n";
        fin.close();
        fout.close();
        remove("price.txt");
        rename("my.txt", "price.txt");
      }
        show();
        break;

      case 4:
        cout<<"\n\t\t----DELETING MENU----\n";
        remove("price.txt");
        show();
        break;

      case 5:{
        ifstream fis("total_earning.txt");
        int in, total = 0;
        while (fis>>in) {
          total += in;
        }
        cout<<"\nTotal Earning: "<<total<<endl<<endl;
      }
      break;

      case 6:
        cout<<"\n\t\t\t----LOGOUT----\n";
        show();
        return ;

      default:
          cout<<"INVALID INPUT\n";

      }
    }
}

void show(){
  Item_details itm;
  ifstream fin("price.txt");
  cout<<"\n\t\t------------------------------\n";
  cout<<"\t\t\tItems Details: \n";
  cout<<"\t\t------------------------------\n";
  cout<<setw(20)<<left<<"Item Name";
  cout<<setw(20)<<left<<"Price";
  cout<<setw(20)<<left<<"Offer";
  cout<<setw(20)<<left<<"Availabilty"<<endl;
  while(fin>>itm){
    cout<<itm;
  }
  fin.close();

  }
