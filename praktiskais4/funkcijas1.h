#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include <tuple>
#include "treat.h"
#include <climits>

using namespace std;

// atrod mazaka, videja un lielaka tuple masiva elementa indeksu 
// 1: mazaka indeks, 2: videja indeks, 3: lielaka indeks
template <typename T>   // T ir skaitliska vertiba (double, int, long, char, ...)
tuple<int, int, int> findIMinMidMax(const tuple<T, string> t[3]) {
    int iMin, iMid, iMax;
    if (get<0>(t[0]) >= get<0>(t[1]) && get<0>(t[0]) >= get<0>(t[2])) {
        iMax = 0;
        if (get<0>(t[1]) >= get<0>(t[2])) {
            iMin = 2;
            iMid = 1;
        } else {
            iMin = 1;
            iMid = 2;
        }
    }
    else {
        if (get<0>(t[1]) >= get<0>(t[2])) {
            iMax = 1;
            if (get<0>(t[0]) >= get<0>(t[2])) {
                iMin = 2;
                iMid = 0;
            }
            else {
                iMin = 0;
                iMid = 2;
            }
        }
        else {
            iMax = 2;
            if (get<0>(t[0]) >= get<0>(t[1])) {
                iMin = 1;
                iMid = 0;
            }
            else {
                iMin = 0;
                iMid = 1;
            }
        }
    }

    return make_tuple(iMin, iMid, iMax);
}

// pardod naski
int sellTreat(const string& fName, string tName = "") {
    fstream file (fName, ios::out | ios::in | ios::binary);

    if (!file.is_open()) {
        cout << "Fails neeksiste!" << endl;
        return -1;
    }
    if (tName == ""){
    cout << "Ievadi produkta vardu kuru velies pardot: ";
    string tName;
    getline(cin, tName);
    }


    // pardod treat faila
    Treat treat;
    streampos curPos;
    while (file.good()) {
        // iegust poziciju no kuras notiks lasisana
        curPos = file.tellg();

        file.read(reinterpret_cast<char*>(&treat), sizeof(Treat));
        if (strcmp(treat.name, tName.c_str()) == 0) {  
            if (treat.curCount > 0) {
                treat.curCount--;
                treat.soldCount++;

                // atjaunina datus bin faila
                file.seekp(curPos);
                file.write(reinterpret_cast<char*>(&treat), sizeof(Treat));

                cout << "Naskis pardots!" << endl;
                file.close();

                return 1;
            }
            cout << "Nav pietiekamai daudz naski lai tos pardotu!" << endl;
            file.close();
            return -1;
        }
    }

    cout << "Naskis nav saraksta!" << endl;
    file.close();
    return -1; 
}

// izvada datus par 1 naski
void printOneTreatData(const string& fName) {
    ifstream file (fName, ios::binary);
    
    cout << "Ievadi produkta vardu kura datus velies iegut: ";
    string tName;
    getline(cin, tName);

    Treat treat;
    file.read(reinterpret_cast<char*>(&treat), sizeof(Treat));
    while (file.good()) {
        if (strcmp(treat.name, tName.c_str()) == 0) {
            cout << endl << "Nosaukums: " << treat.name << "\nCena: " << treat.price << "\nPieejamo nasku skaits: " << treat.curCount << "\nPardoto nasku skaits: " << treat.soldCount << endl;
            file.close();
            return;
        }
        file.read(reinterpret_cast<char*>(&treat), sizeof(Treat));
    }

    cout << "Naskis nav saraksta!" << endl;
    file.close();
    return;
}

// izvada top 3 vismazak pardotakos nasksus
void printTop3LeastSold(const string& fName) {
    ifstream file (fName, ios::binary);

    tuple<int, string> nameAndSoldCount[3];
    for (int i = 0; i<3; i++) nameAndSoldCount[i] = make_tuple(INT_MAX, "");

    int iLargest = 0;                      // seko lidzi indeksam tuple masiva kurs saistis ar lielako elementu

    Treat treat;
    file.read(reinterpret_cast<char*>(&treat), sizeof(Treat));
    while (file.good()) {

        if (treat.soldCount < get<0>(nameAndSoldCount[iLargest])) {
            nameAndSoldCount[iLargest] = make_tuple(treat.soldCount, string(treat.name));

            // atrod jaunu indeksu, kurs saistits ar lielaku elementu tuple masiva
            iLargest = get<2>(findIMinMidMax(nameAndSoldCount));
        }

        file.read(reinterpret_cast<char*>(&treat), sizeof(Treat));
    }

    // atrod mazako, videjo un lielako skaitli tuple masiva
    tuple<int, int, int> sml = findIMinMidMax(nameAndSoldCount);
    int iSmallest = get<0>(sml);
    int iMiddle = get<1>(sml);
    iLargest = get<2>(sml);

    cout << "Top3 vismazak pardotakie naski:" << endl;
    if (get<1>(nameAndSoldCount[iSmallest]) != "") cout << "1. vieta: " << get<1>(nameAndSoldCount[iSmallest]) << " ar skaitu: " << get<0>(nameAndSoldCount[iSmallest]) << endl;
    if (get<1>(nameAndSoldCount[iMiddle]) != "") cout << "2. vieta: " << get<1>(nameAndSoldCount[iMiddle]) << " ar skaitu: " << get<0>(nameAndSoldCount[iMiddle]) << endl;
    if (get<1>(nameAndSoldCount[iLargest]) != "") cout << "3. vieta: " << get<1>(nameAndSoldCount[iLargest]) << " ar skaitu: " << get<0>(nameAndSoldCount[iLargest]) << endl;

    file.close();
    return;
}

// izvada top3 naskus par kuriem visvairak nopelnits
void printTop3MostRevenue(const string& fName) {
    ifstream file (fName, ios::binary);

    tuple<double, string> nameAndRevenue[3];
    for (int i = 0; i<3; i++) nameAndRevenue[i] = make_tuple(INT_MIN, "");

    int iSmallest = 0;                            // seko lidzi indeksam tuple masiva kurs saistis ar mazako elementu

    Treat treat;
    file.read(reinterpret_cast<char*>(&treat), sizeof(Treat));
    while (file.good()) {

        if (treat.soldCount*treat.price > get<0>(nameAndRevenue[iSmallest])) {
            nameAndRevenue[iSmallest] = make_tuple(treat.soldCount*treat.price, string(treat.name));

            // atrod jaunu indeksu, kurs saistits ar mazako elementu tuple masiva
            iSmallest = get<0>(findIMinMidMax(nameAndRevenue));
        }

        file.read(reinterpret_cast<char*>(&treat), sizeof(Treat));
    }

    // atrod mazako, videjo un lielako skaitli tuple masiva
    tuple<int, int, int> sml = findIMinMidMax(nameAndRevenue);
    iSmallest = get<0>(sml);
    int iMiddle = get<1>(sml);
    int iLargest = get<2>(sml);

    cout << "Top3 naski par kuriem visvairak nopelnits:" << endl;
    if (get<1>(nameAndRevenue[iLargest]) != "") cout << "1. vieta: " << get<1>(nameAndRevenue[iLargest]) << " ar pelnu: " << get<0>(nameAndRevenue[iLargest]) << endl;
    if (get<1>(nameAndRevenue[iMiddle]) != "") cout << "2. vieta: " << get<1>(nameAndRevenue[iMiddle]) << " ar pelnu: " << get<0>(nameAndRevenue[iMiddle]) << endl;
    if (get<1>(nameAndRevenue[iSmallest]) != "") cout << "3. vieta: " << get<1>(nameAndRevenue[iSmallest]) << " ar pelnu: " << get<0>(nameAndRevenue[iSmallest]) << endl;

    file.close();
    return;
}

// izvada top 3 letakos nasksus
void printTop3Cheapest(const string& fName) {
    ifstream file (fName, ios::binary);

    tuple<double, string> nameAndPrice[3];
    for (int i = 0; i<3; i++) nameAndPrice[i] = make_tuple(INT_MAX, "");

    int iLargest = 0;                      // seko lidzi indeksam tuple masiva kurs saistis ar lielako elementu

    Treat treat;
    file.read(reinterpret_cast<char*>(&treat), sizeof(Treat));
    while (file.good()) {

        if (treat.price < get<0>(nameAndPrice[iLargest])) {
            nameAndPrice[iLargest] = make_tuple(treat.price, string(treat.name));

            // atrod jaunu indeksu, kurs saistits ar lielaku elementu tuple masiva
            iLargest = get<2>(findIMinMidMax(nameAndPrice));
        }

        file.read(reinterpret_cast<char*>(&treat), sizeof(Treat));
    }

    // atrod mazako, videjo un lielako skaitli tuple masiva
    tuple<int, int, int> sml = findIMinMidMax(nameAndPrice);
    int iSmallest = get<0>(sml);
    int iMiddle = get<1>(sml);
    iLargest = get<2>(sml);

    cout << "Top3 visletakie naski:" << endl;
    if (get<1>(nameAndPrice[iSmallest]) != "") cout << "1. vieta: " << get<1>(nameAndPrice[iSmallest]) << " ar cenu: " << get<0>(nameAndPrice[iSmallest]) << endl;
    if (get<1>(nameAndPrice[iMiddle]) != "") cout << "2. vieta: " << get<1>(nameAndPrice[iMiddle]) << " ar cenu: " << get<0>(nameAndPrice[iMiddle]) << endl;
    if (get<1>(nameAndPrice[iLargest]) != "") cout << "3. vieta: " << get<1>(nameAndPrice[iLargest]) << " ar cenu: " << get<0>(nameAndPrice[iLargest]) << endl;

    file.close();
    return;
}