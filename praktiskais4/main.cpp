#include <iostream>
#include <fstream>
#include <string>
#include "menuBuilder.h"
#include "ioessentials.h"
#include "funkcijas1.h"
#include "funkcijas2.h"
#include "funkcijas3.h"

using namespace std;

const string FILE_NAME = "treats.bin";

int main() {

    // nodrosina to ka fails vienmer bus izveidots
    ofstream f (FILE_NAME, ios::app);
    f.close();

    // izveido menu
    MenuBuilder mb;
    mb.addMenuItem("Datu ievade");
    mb.addMenuItem("Visu datu izvade");
    mb.addMenuItem("Nasku pardosana");
    mb.addMenuItem("Konkreta naska datu izvade");
    mb.addMenuItem("Izdrukat top3 pardotakos naskus");
    mb.addMenuItem("Izdrukat top3 vismazak pardotakos naskus");
    mb.addMenuItem("Izdrukat top3 naskus par kuriem visvairak nopelnits");
    mb.addMenuItem("Izdrukat top3 naskus par kuriem vismazak nopelnits");
    mb.addMenuItem("Izdrukat top3 dargakos naskus");
    mb.addMenuItem("Izdrukat top3 letakos naskus");
    mb.addMenuItem("Izdrukat top3 pieejamakos naskus");
    mb.addMenuItem("Izdrukat top3 mazak pieejamakos naskus");
    mb.addMenuItem("Iegadaties nasku asorti");
    //mb.addMenuItem("Iegadaties nasku asorti");
    mb.addMenuItem("Izdzest failu, kurs glaba informaciju par naskiem");
    mb.addMenuItem("Beigt programmu");

    string menu = mb.getMenuText();                 // saglaba menu stringaa
    int menuItemCount = mb.getMenuItemCount();
    enum eMenu {input = 1, outAll, sell, outOne, topSell, leastSell, topRev, leastRev, topExpens, leastExpens,mostAvailable,leastAvailable,asorti, delData, end};

    while (true) {
        // iegust skaitli starp 1 lidz menuItemCount bez fail. Katru reizi kad kaut kas nepareizi ievadits, izvada string menu
        int task = ioessent::getNumberInRangeWithoutFail(menu, 1, menuItemCount);
        cout << endl << endl;
        ioessent::clearCout();

        switch (task) {
            case input:
                dataInput(FILE_NAME);
                break;
            case outAll:
                dataOutput();
                break;
            case sell:
                sellTreat(FILE_NAME);
                break;
            case outOne:
                printOneTreatData(FILE_NAME);
                break;
            case topSell:
                topSold();
                break;
            case leastSell:
                printTop3LeastSold(FILE_NAME);
                break;
            case topRev:
                printTop3MostRevenue(FILE_NAME);
                break;
            case leastRev:
                leastRevenue();
                break;
            case topExpens:
                topExpensive();
                break;
            case leastExpens:
                printTop3Cheapest(FILE_NAME);
                break;
            case mostAvailable:
                printTop3MostAvailableSnacks(FILE_NAME);
                break;
            case leastAvailable:
                printTop3LeastAvailableSnacks(FILE_NAME);
                break;
            case asorti:
                getAsorti(FILE_NAME);
                break;
            case delData:
                ofstream(FILE_NAME).close();
                break;
            case end:
                return 0;
                break;
        }
    }
    return 0;
}
