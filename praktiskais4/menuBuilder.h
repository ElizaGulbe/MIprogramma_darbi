/**
 * Klases fails, kurs vienkarso izvlenes izveidosanu
 * Lauj pievienot izvelnes objektus un parvers tos string
 */

#include <string>
#include <sstream>

using namespace std;

class MenuBuilder {
    private:
        string menuText = "Izvelne: \n";
        int menuItems = 0;

    public:
        // overwrites menu text
        MenuBuilder(string defaultText) {
            menuText = defaultText + "\n";
        }
        MenuBuilder(){}
        // adds item to menu
        void addMenuItem(string item);
        // returns menu text
        inline string getMenuText();
        // returns amount of menu items
        inline int getMenuItemCount();
};

void MenuBuilder::addMenuItem(string item) {
    menuItems++;
    stringstream ss;
    ss << '\t' << menuItems << ") " << item << '\n';
    menuText += ss.str();
}

inline string MenuBuilder::getMenuText() {
    return menuText;
}

inline int MenuBuilder::getMenuItemCount() {
    return menuItems;
}