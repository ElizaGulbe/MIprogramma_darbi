#include <iostream>
#include <string>
using namespace std;

void isOdd(string userInput) {
   string isOdd; 
    if (userInput.size() % 2 == 1) {
        isOdd = "nepara";
    } else {
        isOdd = "para";
    }
    cout << "'" << userInput << "' teksta garums ir  " << isOdd << "  skaitlis" << endl; 
}
void displayPossibilites() {
    cout << "1: Ievadit jaunu tekstu" << endl; 
    cout << "2: Pasaka vai ievadita teksta garums ir para vai nepara skaitlis " << endl; 
    cout << "3. Izvada summu no 1..n (kur n = teksta garums)" << endl; 
    cout << "4. Atrod faktoriali n (kur n = teksta garums" << endl; 
    cout << "5. Izvada virkni no otra gala (reversa)" << endl; 
    cout << "6. Beigt darbibu" << endl; 
}
void insertNewTxt(string& usinptVal) {
    cout << "Ievadiet jaunu tekstu" << endl;
    cin >> usinptVal; 
}
void arithmeticProgression(string userInputValTxt) {
    int arithmeticProgressionofN; 
    arithmeticProgressionofN = (1+userInputValTxt.size())*userInputValTxt.size()/2;
    cout << "Teksta garuma aritmetiskas progresijas summa ir " << arithmeticProgressionofN << endl;
}
void computeFactorial(string userInputValueTxt) { 
    int factorial; 
    factorial = 1;
    for (int i = 1; i <= userInputValueTxt.size() ;i++) {
        factorial = i * factorial; 
    }
    cout << "'" << userInputValueTxt << "' teksta garums faktorialis ir " << factorial  << endl;
}

void reverseInput(string userInputValueTxt) {
    string stringReverse = ""; 
    for (char i : userInputValueTxt) {
            stringReverse = i + stringReverse;
        }
    cout << "apgreizta vertiba tekstam" << " '" << userInputValueTxt << "' ir  '" << stringReverse << "'" << endl; 
}
int main() {
displayPossibilites();
string userInputValueTxt = "Teksts ir loti loti interesants";
int commandNumber; 
cout << "Ludzu ievadiet vertibu no 1(ieskaitot) lidz 6(ieskaitot)" << endl; 
cin >> commandNumber; 
while (1){
    switch (commandNumber) {
    case 1:
        insertNewTxt(userInputValueTxt);
        break;
    case 2:
        isOdd(userInputValueTxt);
        break;
    case 3:
        arithmeticProgression(userInputValueTxt);
        break;
    case 4:  
        computeFactorial(userInputValueTxt);
        break;
    case 5: 
        reverseInput(userInputValueTxt);
        break;
    case 6:
        cout << "Programmas darbiba izbeigta" << endl; 
        return 0; 
    default:
        cout << "Nepareiza vertiba.Ludzu ievadiet vertibu no 1(ieskaitot) lidz 6(ieskaitot)" << endl; 
        break;
    }
    displayPossibilites();
    cin >> commandNumber; 
}
    return 0;
}