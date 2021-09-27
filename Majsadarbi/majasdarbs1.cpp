#include <iostream>
#include <string>
using namespace std;

string isOdd(string usrInpt){
    if(usrInpt.size()%2 == 1){
        return "nepara";
    } else{
        return "para";
    }
}

int main(){
cout << "1: Ievadit jaunu tekstu" << endl; 
cout << "2: Pasaka vai ievadita teksta garums ir para vai nepara skaitlis " << endl; 
cout << "3. Izvada summu no 1..n (kur n = teksta garums)" << endl; 
cout << "4. Atrod faktoriali n (kur n = teksta garums" << endl; 
cout << "5. Izvada virkni no otra gala (reversa)" << endl; 
cout << "6. Beigt darbibu" << endl; 

string userInputValueTxt; 
userInputValueTxt = "Teksts ir loti loti interesants";
int commandNumber; 

cout << "Ludzu ievadiet vertibu no 1(ieskaitot) lidz 6(ieskaitot)" << endl; 
cin >> commandNumber; 

string stringReverse; 
stringReverse = "";

while(1){
    switch (commandNumber){
    case 1:
        cout << "Ievadiet jaunu tekstu" << endl;
        cin >> userInputValueTxt; 
        break;
    case 2:
        cout << "'" << userInputValueTxt << "' teksta garums ir  " << isOdd(userInputValueTxt) << "  skaitlis" << endl; 
        break;
    case 3:
        int arithmeticProgressionofN; 
        arithmeticProgressionofN = (1+userInputValueTxt.size())*userInputValueTxt.size()/2;
        cout << "Teksta garuma aritmetiskas progresijas summa ir " << arithmeticProgressionofN << endl;
        break;
    case 4: 
        int factorial; 
        factorial = 1;
        for(int i = 1; i <= userInputValueTxt.size() ;i++){
            factorial = i * factorial; 
        }
        cout << "'" << userInputValueTxt << "' teksta garums faktorialis ir " << factorial  << endl; 
        break;
    case 5: 
        
        for(char i : userInputValueTxt){
            stringReverse = i + stringReverse;
        }
        cout << "apgreizta vertiba tekstam" << " '" << userInputValueTxt << "' ir  '" << stringReverse << "'" << endl;
        stringReverse = "";
        break;
    case 6:
        cout << "Programmas darbiba izbeigta" << endl; 
        return 0; 

    default:
        cout << "Nepareiza vertiba. Ludzu ievadiet vertibu no 1(ieskaitot) lidz 6(ieskaitot)" << endl; 
        break;
    }

    cin >> commandNumber; 
    

}

return 0;
}