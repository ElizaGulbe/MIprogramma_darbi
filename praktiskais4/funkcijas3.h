/** 
 * Papildināt šokolādes automāta programmatūras funkcijas:
Izveidot jaunu izvēlni: Našķu asorti
Izvēloties šo izvēlni - programma lietotājam prasa ievadīt naudas summu.
Pēc ievadītās summas, algoritms iet cauri našķiem un, ja ir iespējams, vienu iegādājas. Pēc našķa pirkuma attiecīgi samazinās ievadītās naudas summas lielums
 Algoritms darbojas tik ilgi līdz kamēr ir iespējams nopirkt kādu našķi. Funkcijas darbības beigās uz ekrāna tiek izdrukāta informācija - kādi našķi, cik daudz un par kādu summu ir pirkti, kā arī cik daudz no ievadītās naudas summas beigās ir palicis.
Izdrukāt uz ekrāna Top3 visvairāk pieejamākos našķus automātā
Izdrukāt uz ekrāna Top3 vismazāk pieejamākos našķus automātā


Piezīmes. 
Funkcionalitāte ir jāveic atbilstoši projektu autora stilam un domu gājienam. Ja autors datus lasa pa taisno no binārā faila, tad arī jaunajai funkcionalitātei tā ir jādara. 
Arī Top3 funkcijas ir jāveido pēc līdzīga principa, kā autors veidoja savas funkcijas

**/  

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include <tuple>
#include "treat.h"
#include <climits> 
#include <iomanip> 
using namespace std; 
#define MAX_DOUBLE 1.7976931348623157E+308
    struct snackAsorti { 
        string snackName;
        double snackPrice;
        int numofProductsAsorti;
    };
void printTop3MostAvailableSnacks(const string& fName) {
    ifstream file (fName, ios::binary);
    tuple<int, string> nameAndAvailableCount[3];
    for (int i = 0; i<3; i++) nameAndAvailableCount[i] = make_tuple(INT_MIN, "");
    int iSmallest = 0;                            // seko lidzi indeksam tuple masiva kurs saistis ar mazako elementu
    Treat treat;
    file.read(reinterpret_cast<char*>(&treat), sizeof(Treat));
    while (file.good()) {
        if (treat.curCount> get<0>(nameAndAvailableCount[iSmallest])) {
            nameAndAvailableCount[iSmallest] = make_tuple(treat.curCount, string(treat.name));
            // atrod jaunu indeksu, kurs saistits ar mazako elementu tuple masiva
            iSmallest = get<0>(findIMinMidMax(nameAndAvailableCount));
        }
        file.read(reinterpret_cast<char*>(&treat), sizeof(Treat));
    }
    // atrod mazako, videjo un lielako skaitli tuple masiva
    tuple<int, int, int> sml = findIMinMidMax(nameAndAvailableCount);
    iSmallest = get<0>(sml);
    int iMiddle = get<1>(sml);
    int iLargest = get<2>(sml);
    cout << "Top3 visvairak pieejamakie naski:" << endl;
    if (get<1>(nameAndAvailableCount[iLargest]) != "") cout << "1. vieta: " << get<1>(nameAndAvailableCount[iLargest]) << " ar skaitu: " << get<0>(nameAndAvailableCount[iLargest]) << endl;
    if (get<1>(nameAndAvailableCount[iMiddle]) != "") cout << "2. vieta: " << get<1>(nameAndAvailableCount[iMiddle]) << " ar skaitu: " << get<0>(nameAndAvailableCount[iMiddle]) << endl;
    if (get<1>(nameAndAvailableCount[iSmallest]) != "") cout << "3. vieta: " << get<1>(nameAndAvailableCount[iSmallest]) << " ar skaitu: " << get<0>(nameAndAvailableCount[iSmallest]) << endl;
    file.close();
    return;
}

void printTop3LeastAvailableSnacks(const string& fName) {
    ifstream file (fName, ios::binary);
    tuple<int, string> nameAndAvailableCount[3];
    for (int i = 0; i<3; i++) nameAndAvailableCount[i] = make_tuple(INT_MAX, "");
    int iLargest = 0;                      // seko lidzi indeksam tuple masiva kurs saistis ar lielako elementu
    Treat treat;
    file.read(reinterpret_cast<char*>(&treat), sizeof(Treat));
    while (file.good()) {
        if (treat.curCount < get<0>(nameAndAvailableCount[iLargest])) {
            nameAndAvailableCount[iLargest] = make_tuple(treat.curCount, string(treat.name));
            // atrod jaunu indeksu, kurs saistits ar lielaku elementu tuple masiva
            iLargest = get<2>(findIMinMidMax(nameAndAvailableCount));
        }
        file.read(reinterpret_cast<char*>(&treat), sizeof(Treat));
    }
    // atrod mazako, videjo un lielako skaitli tuple masiva
    tuple<int, int, int> sml = findIMinMidMax(nameAndAvailableCount);
    int iSmallest = get<0>(sml);
    int iMiddle = get<1>(sml);
    iLargest = get<2>(sml);
    cout << "Top3 vismazak pieejamakie naski:" << endl;
    if (get<1>(nameAndAvailableCount[iSmallest]) != "") cout << "1. vieta: " << get<1>(nameAndAvailableCount[iSmallest]) << " ar skaitu: " << get<0>(nameAndAvailableCount[iSmallest]) << endl;
    if (get<1>(nameAndAvailableCount[iMiddle]) != "") cout << "2. vieta: " << get<1>(nameAndAvailableCount[iMiddle]) << " ar skaitu: " << get<0>(nameAndAvailableCount[iMiddle]) << endl;
    if (get<1>(nameAndAvailableCount[iLargest]) != "") cout << "3. vieta: " << get<1>(nameAndAvailableCount[iLargest]) << " ar skaitu: " << get<0>(nameAndAvailableCount[iLargest]) << endl;
    file.close();
    return;
}

int findNamePosition(vector<snackAsorti> asortiItems, string treatName){ 
    for (int i = 0 ; i < asortiItems.size() ; i++){ 
        if(asortiItems[i].snackName == treatName) return i; 
    }
    return -1;
}

void getAsorti(const string& fName){ 
    double money = ioessent::getDobuleInRangeWithoutFail("Ievadiet pieejamos lidzeklus:\n", 0, MAX_DOUBLE);
    vector<snackAsorti> asortiItems;
    int curPosition = 0; 
    while(true){
    double getCheapestItem = MAX_DOUBLE;
    vector<Treat> allTreats = binaryToVector(fName);
          for (Treat trt : allTreats){ 
        getCheapestItem = (trt.price < getCheapestItem) ? trt.price : getCheapestItem; 
    }
        if(getCheapestItem > money || allTreats.size() == 0) break;
        Treat getSnack; 
        string snackName; 
        int numberOfIterations = 0; // ja kods iet cauri vairak par allTreats masiva izmeru neko nenoperkot, tad lielais while cikls(104 rindina) apstajas
        int breakLoop = 0; // ja vertiba tiek nomainita uz 1, tad tiek "salauzts" lielais cikls
        while(true){ 
        if(numberOfIterations == allTreats.size()){
            breakLoop = 1;
            break;
        }
        curPosition = (curPosition == allTreats.size()) ? 0 : curPosition; // ja index out of range, tad nomainas veriba uz 0 
        getSnack = allTreats[curPosition++]; 
        snackName = getSnack.name; 
        if(money < getSnack.price){
            numberOfIterations++;
            continue;
        } 
        if(sellTreat(fName,snackName) == 1) break; 
        numberOfIterations++;
        } 
        if(breakLoop) break;
        int position = findNamePosition(asortiItems,snackName); 
            if(position == -1){
             snackAsorti newSnack = {snackName,getSnack.price,1};
             asortiItems.push_back(newSnack);        
            }else { 
            asortiItems[position].numofProductsAsorti++;
            }
        money = money - getSnack.price; 
    }
    if(asortiItems.empty()){
        cout << "Nepietiekams naudas daudzums nasku iegadei vai automata nav pieejami naski" << endl;
    }else { 
        cout << "Asorti iegade veiksmigi pabeigta" << endl;
        for(snackAsorti asortiTreat : asortiItems){ 
        cout << " Produkts " << asortiTreat.snackName << " iegadats " << asortiTreat.numofProductsAsorti << ( (asortiTreat.numofProductsAsorti == 1) ? " reizi par cenu " : " reizes par cenu " )<< fixed << setprecision(2) << asortiTreat.snackPrice   <<" Eiro" <<endl;
    }
    }
    cout << endl << "atlikusi naudas summa ir "<< fixed << setprecision(2) << money << " Eiro" << endl;
}







