#include<iostream>
#include<vector>
using namespace std;
// Build a Menu Navigation System
// Objective: Implement a basic menu navigation system similar to what is found in automotive HMI clusters (e.g., settings menu, media options).
// Requirements:
// Create a hierarchical menu structure using classes and data structures.
// Example:
// Main Menu
// Settings
// Display Settings
// Audio Settings
// Media
// Radio
// Bluetooth Audio
// Use a tree structure (std::vector or custom tree data structure) to represent the hierarchy.
// Implement the following functionalities:
// Navigate through menu levels (up/down/enter/back).
// Display the current menu options on the console.
// Add keyboard-based interaction (e.g., 1 to navigate down, 2 to navigate up, 3 to enter).

 struct menuNode{
    string data ;
    vector<menuNode*> child;
  
    menuNode(string data){
        this->data = data;
    }
    void addchild(menuNode *data){
        child.push_back(data);
    }  
};


void displayMenu(menuNode *menu){
     cout<<" == "<<menu->data<<" == "<<endl;
     if(menu->data.empty()){
        cout<<"No sub menu available...."<<endl;
     }else{
        for(auto  i = 0 ; i < menu->child.size(); i++){
            cout<<i+1 <<". "<<menu->child[i]->data<<endl;
        }
     }   
}
void navigate(menuNode *menu){
   int choice ;
     while(true){
           displayMenu(menu);
           cout<<"Choose an option(enter 0 to go back): "<<endl; 
           cin>>choice;

           if(choice == 0){
            cout<<"Going back... "<<endl;
            break;
           }
            
        if(choice <1 || choice > menu->child.size()){
            cout<<"Invalid choice..."<<endl;
        }else{
            cout << "Navigating to " << menu->child[choice-1]->data << "...\n";
            navigate(menu->child[choice]); 
        }                
     }
}
int main(){ 
    menuNode *root = new menuNode("Main menu");
    menuNode *submenu1 = new menuNode("settings");
    menuNode *submenu2 = new menuNode("media");

    root->addchild(submenu1);
    root->addchild(submenu2);
      
    menuNode *submenu1_1 = new menuNode("Display settings");
    menuNode *submenu1_2 = new menuNode("Audio settings");

    submenu1->addchild(submenu1_1);
    submenu1->addchild(submenu1_2);
 
    menuNode *submenu2_1 = new menuNode("Radio");
    menuNode *submenu2_2 = new menuNode("Bluethooh");

    //displayMenu(root);
    cout<<"Welcome to our playlist...."<<endl;

    navigate(root);
  
   return 0;
}