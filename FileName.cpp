#include <iostream>
#include <cstring> 
using namespace std;

struct Contact {
    char name[100];
    char homephone[20];
    char workphone[20];
    char mobilephone[20];
    char info[200];
};

class phonebook {
private:
    Contact* contacts;
    int size;

public:
    phonebook() : contacts(0), size(0) {}

    ~phonebook() {
        delete[] contacts;
    }

    void add() {
        Contact* newcontacts = new Contact[size + 1];

        for (int i = 0; i < size; ++i) {
            newcontacts[i] = contacts[i];
        }

        cout << "name: ";
        cin.ignore(); 
        cin.getline(newcontacts[size].name, 100);

        cout << "home phone: ";
        cin.getline(newcontacts[size].homephone, 20);

        cout << "work phone: ";
        cin.getline(newcontacts[size].workphone, 20);

        cout << "mobile phone: ";
        cin.getline(newcontacts[size].mobilephone, 20);

        cout << "info: ";
        cin.getline(newcontacts[size].info, 200);

        delete[] contacts;
        contacts = newcontacts;
        size++;
        cout << "contact added" << endl;
    }

    void deletec() {
        char name[100];
        cout << "name of the contact to delete: ";
        cin.ignore(); // обращался к чату гпт, потому что засчитывало новую строку как конец команды и 
        //использую здесь ignore чтобы оно игнорировало enter после того как человек выберет кого удалить из списка контактов
        // без него программа думала что enter это название контакта (крч вроде разобрался)
        cin.getline(name, 100);

        for (int i = 0; i < size; ++i) {
            if (strcmp(contacts[i].name, name) == 0) {
                Contact* newContacts = new Contact[size - 1];

                for (int j = 0, k = 0; j < size; ++j) {
                    if (j != i) {
                        newContacts[k++] = contacts[j];
                    }
                }

                delete[] contacts;
                contacts = newContacts;
                size--;

                cout << "contact deleted" << endl;
                return;
            }
        }
        cout << "contact not found" << endl;
    }

    void search() const {
        char name[100];
        cout << "name of the contact to search: ";
        cin.ignore(); 
        cin.getline(name, 100);

        for (int i = 0; i < size; ++i) {
            if (strcmp(contacts[i].name, name) == 0) {
                displayone(contacts[i]);
                return;
            }
        }
        cout << "contact not found" << endl;
    }

    void displayall() const {
        if (size == 0) {
            cout << "phone book is empty" << endl;
        }

        for (int i = 0; i < size; ++i) {
            cout << "contact " << i + 1 << ":" << endl;
            displayone(contacts[i]);
            cout << endl << endl;
        }
    }

private:
    void displayone(const Contact& contact) const {
        cout << "name: " << contact.name << endl;
        cout << "home Phone: " << contact.homephone << endl;
        cout << "work Phone: " << contact.workphone << endl;
        cout << "mobile Phone: " << contact.mobilephone << endl;
        cout << "info: " << contact.info << endl;
    }
};

int main() {
    phonebook phoneBook;

    while (true) {
        cout << endl << "menu: " << endl;
        cout << "1. add contact" << endl;
        cout << "2. delete contact" << endl;
        cout << "3. search contact" << endl;
        cout << "4. display all contacts" << endl;
        cout << "enter your choice: ";
        int choice;
        cin >> choice;


        if (choice == 1) {
            phoneBook.add();
        }
        else if (choice == 2) {
            phoneBook.deletec();
        }
        else if (choice == 3) {
            phoneBook.search();
        }
        else if (choice == 4) {
            phoneBook.displayall();
        }
        else {
            cout << "invaalid choice, try again" << endl;
        }
    }
}
