#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <stdio.h>
#include <vector>
#include <bits/stdc++.h> 
#include "treat.h"

using namespace std;

vector<Treat> binaryToVector (const string& fName){
    ifstream file;
    vector<Treat> treats;
    file.open(fName, ios::binary | ios_base::app);
    while(file.good()) {
        Treat treat;
        file.read(reinterpret_cast<char *>(&treat), sizeof(Treat));
        if(file.good()) {
            treats.push_back(treat);
        }
    }

    return treats;
}

void dataInput(const string& fName) {
    vector<Treat> treats = binaryToVector(fName);
    fstream file;
    int amount;
    file.open(fName, ios::out | ios::binary);
    Treat treat;
    int element = treats.size();
    treats.push_back(Treat());
    cout << "Ievadiet produkta nosaukumu" << endl;
    cin.getline(treats[element].name, 50);

    for (int n = 0; n < treats.size()-1; n++) {
        if(strcmp(treats[n].name, treats[element].name) == 0) {
            treats.pop_back();
            element = n;
            cout << "Ievadiet produkta daudzumu" << endl;
            cin >> amount;
            treats[element].curCount = treats[element].curCount + amount;
            for(Treat tr : treats) {
                file.write(reinterpret_cast<char *>(&tr), sizeof(Treat));
            }
            file.close();

            return;
        }
    }
    cout << "Ievadiet produkta cenu" << endl;
    cin >> treats[element].price;
    cout << "Ievadiet produkta daudzumu" << endl;
    cin >> amount;
    treats[element].curCount = treats[element].curCount + amount;
    treats[element].soldCount = 0;

    for(Treat tr : treats) {
        file.write(reinterpret_cast<char *>(&tr), sizeof(tr));
    }
    file.close();
}

void dataOutput() {
    vector<Treat> treats = binaryToVector("treats.bin");
    for (Treat i : treats) {
        cout << "Naska nosaukums: "<< i.name << endl;
        cout << "Naska cena: "<< i.price << endl;
        cout << "Pieejamais nasku daudzums: "<< i.curCount << endl;
        cout << "Pardots nasku skaits: "<< i.soldCount << endl << endl;
    }
}

void topSold() {
    vector<Treat> treats = binaryToVector("treats.bin");
    double dif[3] = {0, 0, 0};
    double top[3] = {-1, -1, -1};
    string topNames[3] = {"", "", ""};
    for (Treat i : treats) {
        for (int n = 0; n < 3; n++) {
            if (i.soldCount >= top[n]) {
                for (int p = 0; p < 3; p++) {
                    dif[p] = i.soldCount - top[p];
                }
            }
        }
        if (dif[0] >= dif[1] && dif[0] >= dif[2]) {
            top[0] = i.soldCount;
            topNames[0] = i.name;
        }
        else if(dif[1] >= dif[2] && dif[1] >= dif[0]) {
            top[1] = i.soldCount;
            topNames[1] = i.name;
        }
        else {
            top[2] = i.soldCount;
            topNames[2] = i.name;
        }
    }
    cout << "Top 3 pardotakie naski ir: " << endl;
    for (int n = 0; n < 3; n++) {
        for (int i = 0; i < 2; i++) {
            if (top[i] < top[i+1]) {
                double temp1 = top[i];
                string temp2 = topNames[i];
                top[i] = top[i+1];
                top[i+1] = temp1;
                topNames[i] = topNames[i+1];
                topNames[i+1] = temp2;
            }
        }
    }
    for (int k = 0; k < 3; k++) {
        if (topNames[k] != "") {
            cout << topNames[k] << " kuri ir pardoti " << top[k] << " reizes" << endl;
        }
    } 
}

void leastRevenue() {
    vector<Treat> treats = binaryToVector("treats.bin");
    double dif[3] = {0, 0, 0};
    double top[3] = {100000, 100000, 100000};
    string topNames[3] = {"", "", ""};
    for (Treat i : treats) {
        for (int n = 0; n < 3; n++) {
            if (i.price * i.soldCount <= top[n]) {
                for (int p = 0; p < 3; p++) {
                    dif[p] = top[p] - i.price * i.soldCount;
                }
            }
        }
        if (dif[0] >= dif[1] && dif[0] >= dif[2]) {
            top[0] = i.price * i.soldCount;
            topNames[0] = i.name;
        }
        else if(dif[1] >= dif[2] && dif[1] >= dif[0]) {
            top[1] = i.price * i.soldCount;
            topNames[1] = i.name;
        }
        else {
            top[2] = i.price * i.soldCount;
            topNames[2] = i.name;
        }
    }
    cout << "Top 3 naski ar vismazako pelnu ir: " << endl;
    for (int n = 0; n < 3; n++) {
        for (int i = 0; i < 2; i++) {
            if (top[i] > top[i+1]) {
                double temp1 = top[i];
                string temp2 = topNames[i];
                top[i] = top[i+1];
                top[i+1] = temp1;
                topNames[i] = topNames[i+1];
                topNames[i+1] = temp2;
            }
        }
    }
    for (int k = 0; k < 3; k++) {
        if (topNames[k] != "") {
            cout << topNames[k] << " kuri ir ienesusi " << top[k] << " eiro" << endl;
        }
    } 
}

void topExpensive() {
    vector<Treat> treats = binaryToVector("treats.bin");
    double dif[3] = {0, 0, 0};
    double top[3] = {-1, -1, -1};
    string topNames[3] = {"", "", ""};
    for (Treat i : treats) {
        for (int n = 0; n < 3; n++) {
            if (i.price >= top[n]) {
                for (int p = 0; p < 3; p++) {
                    dif[p] = i.price - top[p];
                }
            }
        }
        if (dif[0] >= dif[1] && dif[0] >= dif[2]) {
            top[0] = i.price;
            topNames[0] = i.name;
        }
        else if(dif[1] >= dif[2] && dif[1] >= dif[0]) {
            top[1] = i.price;
            topNames[1] = i.name;
        }
        else {
            top[2] = i.price;
            topNames[2] = i.name;
        }
    }
    cout << "Top 3 dargakie naski ir: " << endl;
    for (int n = 0; n < 3; n++) {
        for (int i = 0; i < 2; i++) {
            if (top[i] < top[i+1]) {
                double temp1 = top[i];
                string temp2 = topNames[i];
                top[i] = top[i+1];
                top[i+1] = temp1;
                topNames[i] = topNames[i+1];
                topNames[i+1] = temp2;
            }
        }
    }
    for (int k = 0; k < 3; k++) {
        if (topNames[k] != "") {
            cout << topNames[k] << " kuri maksa " << top[k] << " eiro" << endl;
        }
    } 
}