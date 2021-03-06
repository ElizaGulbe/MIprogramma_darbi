#include <iostream>
#include <string>
#include <sstream>
using namespace std;

template <class SomeType>
SomeType minVal(SomeType a, SomeType b){
  if(a > b) {
      return b;
  }
    return a;
}

string reverseString(string userInput){
    string retVal; 
    for(int counter = userInput.size()-1; counter >= 0 ; counter-- ) {
        retVal.push_back(userInput[counter]);
    }
    return retVal;
}

string reversewithIterator(string userInput){
    string retVal; 
    for(char i:userInput) {
        retVal = i + retVal;
    }
    return retVal;
}
int computeSum(int a){
  if (a > 1)
   return (a + computeSum(a-1));
  else
   return 1;
}

int addOperation(int a, int b){
    return a+b;
}
int subtractOperation(int a, int b){
    return a-b;
}
int multiplyOperation(int a, int b){
    return a*b;
}
float divideOperation(int a, int b){
    return (float)a/(float)b;
}

void print(int value){
    cout << value << endl;
}
void print(string value){
    cout << value << endl;
}
void print(char value){
    cout << value << endl;
}
void print(double value){
    cout << value << endl;
}

int main(){
    // 1.2. Izveidot papildus realizāciju, ka lietotājs ievad vēl vienu virkni - to saglabā char masīvā un izveidot funkciju, 
    // kura veic šo pašu uzdevumu (reverse) tikai ar char masīvu
    // 1. uzdevums
    cout << "Ievadiet simbolu virkni:" << endl;
    string userInput; 
    getline(cin,userInput);
    cout << "Simbolu virknes" << userInput << "apgriezta vertiba ir " << reverseString(userInput) << endl; 
    // 1.1 uzdevums
    cout << "Simbolu virknes" << userInput << "apgriezta vertiba (ar iterator) ir " << reversewithIterator(userInput) << endl;
    // 2. uzdevums
    cout << "Ievadiet skaitli:" << endl;
    int userInputNumber;
    cin >> userInputNumber;
    cout << "Aritmetiskas progresijas summa skaitlim " << userInputNumber << " ir " << computeSum(userInputNumber) << endl;
    // 3. uzdevums 3.1 izpildits 
    cout << "ludzu ievadiet veselu skaitli" << endl;
    int skaitlis;
    cin >> skaitlis;
    cout << "Ievaditais skaitlis ir ";
    print(skaitlis);
    cout << "ludzu ievadiet simbolu virkni" << endl;
    string simboluVirkne;
    cin >> simboluVirkne;
    cout << "Ievadita simbolu virkne ir  ";
    print(simboluVirkne);
    cout << "ludzu ievadiet 1 simbolu" << endl;
    char ievaditaisSimbols;
    cin >> ievaditaisSimbols;
    cout << "Ievaditais simbols ir  ";
    print(ievaditaisSimbols);
    cout << "ludzu ievadiet decimalskaitli(double)" << endl;
    double decimalskaitlis;
    cin >> decimalskaitlis;
    cout << "Ievaditais skaitlis ir  ";
    print(decimalskaitlis);
    // 4.uzdevums
    
    int i=5, j=6, k;
    double f=2.0, g=0.5, h;
    string str1 = "manisauceliza", str2 = "anisauceliza", str3;
    char ch1 = 'b', ch2 = 'a', ch3;
    k = minVal<int>(i,j);
    h = minVal<double>(f,g);
    str3 = minVal<string>(str1,str2);
    ch3 = minVal<char>(ch1,ch2);
    cout << k << endl;
    cout << h << endl;
    cout << str3 << endl;
    cout << ch3 << endl;
    //5.uzdevums
    cout << "Ievadiet 1. skaitli:" << endl;
    int number1;
    cin >> number1;
    cout << "Ievadiet 2. skaitli:" << endl;
    int number2;
    cin >> number2;
    cout << "Ievadiet atbilstoso operaciju (+,-,*,/)" << endl;
    char operatorIs;
    cin >> operatorIs;
     if(operatorIs == '+'){
            cout << addOperation(number1,number2) <<endl;
        } else if(operatorIs == '-'){
            cout << subtractOperation(number1,number2) <<endl;
        } else if(operatorIs == '*'){
            cout << multiplyOperation(number1,number2) <<endl;
        } else if(operatorIs == '/'){
            cout << divideOperation(number1,number2) <<endl;
        } else { 
            cout << "Incorrect operator" << endl;
        }
    return 0;
}
