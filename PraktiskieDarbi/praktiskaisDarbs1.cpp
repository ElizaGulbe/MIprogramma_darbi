#include <iostream>
#include <string>
#include <sstream>
using namespace std;

float computeAvgValue(int arr[10]){
    float sum = 0; 
   for (int i = 0; i <= 9; i++) {
       sum += arr[i];
      
   }
   float average = sum/10;
    return average;
}

float findBiggest(float arr[10]) {
    float curBiggest = arr[0];
    for (int i = 1; i<=9; i++) {
        if (curBiggest < arr[i]) {
            curBiggest = arr[i];
        }
    }
    return curBiggest;
}
void displayArray(int arr[5][5]){
     for(int i = 0; i<5;i++) {
        for(int x = 0; x<5;x++) {
          if (x == 4) {
              cout << x << endl;
          } else {
              cout << x << " ";
          }
        }
    }
} 


void twoDimensionalArr() {
    int twoDimArr[5][5];
    for(int i = 0; i<5;i++){
        for(int x = 0; x<5;x++){
         twoDimArr[i][x] = x;
    }

    }
    displayArray(twoDimArr);
}


int countOccurance(string userInput) {
    int occuranceOfA = 0;
    for(char i: userInput) {
        if (i == 'a') {
            occuranceOfA++;
        }
    }
    
    return occuranceOfA;
}

string cutNumbers(string userInput){
    string retVal;
    for(int i = 0; i < userInput.size(); i++){

           if (isdigit(userInput[i]) == 0) {
           retVal.push_back(userInput[i]);
        } else{
           continue;
        }

    }
    return retVal;
}

int main(){
    string userInput; 
    getline(cin,userInput);
    cout << "varda " << userInput << "simbols a atkartojas " << countOccurance(userInput) << " reizes" << endl;
    string cutDigits; 
    getline(cin,cutDigits);
    cout << "iznemot no simbolu virkes  " << cutDigits << " visus ciparus sanak " << cutNumbers(cutDigits) << endl;
    int arr[10] = {1,2,3,4,5,6,8,8,9,10};
    cout << "masiva videja vertiba ir " << computeAvgValue(arr) << endl;
    float arrfloat[10] = {1.1,2.2,3.3,4.4,10.1,5.4,6.7,7.8,8.9,9.8};
    cout << "find biggest retVal" << findBiggest(arrfloat) << endl;
    twoDimensionalArr(); 
    return 0;

}