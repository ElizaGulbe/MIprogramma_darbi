#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <cstdlib>
using namespace std;


void createAndDisplayQueue(const vector<int> &initialValue){
    queue<int> myqueue;
    for(int i = 0 ; i < initialValue.size() ; i++) {
        myqueue.push(initialValue[i]); // pievieno vectoru stack
    }
    cout << "queue dequeue seciba" << endl; 
    for (int i = 0 ; i < initialValue.size() ; i++) {
        cout << myqueue.front() << " " ;
        myqueue.pop();
    }
    cout << endl;
}
void displayOpportunities(){
    cout << "Iespejamas darbibas ir: " << endl;
    cout << "1: Ievadit skaitlus" << endl;
    cout << "2: Rinda" << endl;
    cout << "3. Steks" << endl;
    cout << "4. Divi steki (Rinda)" << endl;
    cout << "5. Izvada skaitlu virkni" << endl;
    cout << "6. Beigt darbibu" << endl;
    cout << "ludzu ievadiet skaitli" << endl;
}

void createAndDisplayStack(const vector<int> &initialValue){
stack<int> data;
    for(int i = 0 ; i < initialValue.size() ; i++) {
        data.push(initialValue[i]); // pievieno vectoru stack
    }
    cout << "Stack pop seciba" << endl; 
    for (int i = 0 ; i < initialValue.size() ; i++) {
     cout << data.top() << " ";
     data.pop();
    }
    cout << endl;
}

void createAndDisplayDoubleStack(const vector<int> &initialValue){
 stack<int> stack1;
 stack<int> stack2;
 for(int i = 0 ; i < initialValue.size() ; i++) {
     stack1.push(initialValue[i]); // pievieno vectoru pirmajam stack
 }
 cout << "Double stack pop seciba" << endl; 
for (int i = 0 ; i < initialValue.size() ; i++) {
     stack2.push(stack1.top());  // parliek stack1 - > stack 2 ; 
     stack1.pop();
 }
for (int i = 0 ; i < initialValue.size() ; i++) {
     cout << stack2.top() << " ";
     stack2.pop();   // iznem no  stack2 value un izprinte vertibu
    }
cout << endl;

}


void displayList(vector<int> &initialValue) {
    string retVal = "[";
    for(int i = 0 ; i < initialValue.size(); i++) {
        if (i == initialValue.size() - 1) {
            retVal = retVal + to_string(initialValue[i]) + "]";
        } else {
            retVal = retVal + to_string(initialValue[i]) + ",";  
        }
        
    }
    
    cout << retVal << endl;  
}

int switchcase(const int &inputData, vector<int> &initialValue) {
    switch (inputData) {
        case 1:
            cout << "ievadiet 1 skaitli" << endl; 
            int number;     // ievada pa vienam skaitlim lidz lietotajs vairs nevelas ievietot skaitli 
            cin >> number; 
            initialValue.push_back(number); 
            char response; 
            cout << "vai velaties ievadit vel vienu skaitli? y - Ja , n - ne" << endl;
            cin >> response;
            while(response == 'y') {
                cout << "ievadiet 1 skaitli" << endl; 
                cin >> number; 
                initialValue.push_back(number); 
                cout << "vai velaties ievadit vel vienu skaitli? y - Ja , n - ne" << endl;
                cin >> response;
            }
            return 1;
            break;
        case 2:
            createAndDisplayQueue(initialValue);
            return 1;
            break;
        case 3:
            createAndDisplayStack(initialValue);
            return 1;
            break;
        case 4: 
            createAndDisplayDoubleStack(initialValue);
            return 1;
            break;
        case 5:
            displayList(initialValue);
            return 1;
            break;
        case 6:
            cout << "Programmas darbiba izbeigta" << endl; 
            return 0; 
        default:
            cout << "Nepareiza vertiba.Ludzu ievadiet vertibu no 1(ieskaitot) lidz 6(ieskaitot)" << endl;
            return 0;  
            break;
        }

}
int main(){
    vector<int> initialValue;
    for (int i = 4 ; i < 9 ; i++ ) {
        initialValue.push_back(i);
    } 
     while (1) {
        displayOpportunities();
        int inputData;
        cin >> inputData;
         if(switchcase(inputData,initialValue) == 0) break; 
    }
    return 0;
}