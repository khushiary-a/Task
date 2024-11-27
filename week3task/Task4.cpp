// Implement a system to manage different themes or skins for an HMI display.
// Requirements:
// Create a Theme class:
// Attributes: backgroundColor, fontColor, fontSize, and iconStyle.
// Implement methods to apply and display the theme.
// Store multiple themes using std::map:
// Example themes: Classic, Sport, and Eco.
// Create a simple user interface to switch between themes:
// Use console input to select a theme.
// Display a preview of the selected theme on the console (e.g., "Sport Theme: Red Background, White Font").
// Deliverables:
// A C++ program that demonstrates theme switching.
// Output displaying applied themes.
#include <iostream>
#include<map>
#include<thread>
#include<chrono>
using namespace std;
enum theme  {classic , sport ,eco};
class Attributes
{
public:
    string backgroundcolor;
    string fontcolor;
    int fontsize;
    string iconstyle;    
    Attributes() : backgroundcolor(""), fontcolor(""), fontsize(0), iconstyle("") {}   
    Attributes(string bg, string fc, int fs, string ic) 
        : backgroundcolor(bg), fontcolor(fc), fontsize(fs), iconstyle(ic) {}

};
string themechange(theme t ){
switch (t)
{
 case classic: return "classic";
        case sport: return "sport";
        case eco: return "eco";
        default: return "Unknown";

}

}
void print(map<theme , Attributes> mymap){
    for(auto i : mymap){
        cout<<"--------------------------"<<endl;
        cout<<"Theme is : "<<themechange(i.first)<<endl;
        Attributes a = i.second;
        cout<<"Background-color is : "<<a.backgroundcolor<<endl;
        cout<<"Font-color is : "<<a.fontcolor<<endl;
        cout<<"Font-size is : "<<a.fontsize<<endl;
    }
}

void PrintByChoice(map<theme , Attributes> mymap , int a ){
    for(auto i : mymap){
        cout<<"--------------------------"<<endl;
        if(i.first == a){
        cout<<"Theme is : "<<themechange(i.first)<<endl;
        Attributes a = i.second;
        cout<<"Background-color is : "<<a.backgroundcolor<<endl;
        cout<<"Font-color is : "<<a.fontcolor<<endl;
        cout<<"Font-size is : "<<a.fontsize<<endl;
        break;
        }else{
            cout<<"theme is not present "<<endl;
        }
    }
}


void MyOperation(map<theme , Attributes> mymap){
     cout<<"Theme which are present "<<endl;  
     print(mymap);
     cout<<"--------------------------"<<endl;
    while(true){
    int choice;
     cout<<"1 . for classic \n2 . for sport \n3 . for eco"<<endl;
     cout<<"Enter u r choice : ";
     cin>>choice;
     switch(choice){       
      case 1 : 
      PrintByChoice(mymap , 0);
       break;
      case 2 :
      PrintByChoice(mymap , 1);
      break;
      case 3:
      PrintByChoice(mymap , 2);
      break;
      default: 
      cout<<"theme is not present"<<endl;
     }

    
    }
}
int main()
{
    map<theme , Attributes> mymap ;
    Attributes obj1("white ", "black " , 20 , "sans-serif");
    Attributes obj2("Blue ", "white " , 20 , "sans-serif");
    Attributes obj3("Green", "Pink" , 20 , "sans-serif");
    mymap[classic] = obj1;
    mymap[sport] = obj2;
    mymap[eco] = obj3;
    MyOperation(mymap);

    return 0;
}