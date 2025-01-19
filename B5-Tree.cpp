#include <iostream>
#include <string>

using namespace std;

struct node {
    string label;
    int ch_count;
    struct node* child[10];
} * root;

class GT {
public:
    GT() {
        root = NULL;
    }
    
    void create() {
        root = new node;

        cout << "Name of the book: ";
        cin >> root->label;
        cout << "Number of chapters: ";
        cin >> root->ch_count;

        for (int i = 0; i < root->ch_count; i++) {
            root->child[i] = new node;
            cout << "Name of chapter " << i + 1 << ": ";
            cin >> root->child[i]->label;
            cout << "Number of sections: ";
            cin >> root->child[i]->ch_count;

            for (int j = 0; j < root->child[i]->ch_count; j++) {
                root->child[i]->child[j] = new node;
                cout << "Name of section " << i + 1 << " - " << j + 1 << ": ";
                cin >> root->child[i]->child[j]->label;
                cout << "Number of sub-sections: ";
                cin >> root->child[i]->child[j]->ch_count;

                for (int k = 0; k < root->child[i]->child[j]->ch_count; k++) {
                    root->child[i]->child[j]->child[k] = new node;
                    cout << "Name of sub-section " << i + 1 << " - " << j + 1 << " - " << k + 1 << ": ";
                    cin >> root->child[i]->child[j]->child[k]->label;
                }
            }
        }
    }

    void display(node* r) {
        if (!r) {
            cout << "No book information available. Please add book info first.\n";
            return;
        }

        cout << "\nBOOK DETAILS\n";
        cout << "Book Name: " << r->label << endl;

        for (int i = 0; i < r->ch_count; i++) {
            node* chapter = r->child[i];
            cout << "\nChapter " << i + 1 << ": " << chapter->label << endl;

            for (int j = 0; j < chapter->ch_count; j++) {
                node* section = chapter->child[j];
                cout << "  Section " << j + 1 << ": " << section->label << endl;

                for (int k = 0; k < section->ch_count; k++) {
                    node* subsection = section->child[k];
                    cout << "    Sub-section " << k + 1 << ": " << subsection->label << endl;
                }
            }
        }
        cout << endl;
    }
};

int main() {
    GT g;

    while (true) {
        cout << "\n--- MENU ---" << endl;
        cout << "1 : Add book info" << endl;
        cout << "2 : Display info" << endl;
        cout << "3 : Exit" << endl;
        cout << "Choose an option (1-3): ";
        int ch;
        cin >> ch;

        switch (ch) {
            case 1:
                g.create();
                break;
            case 2:
                g.display(root);
                break;
            case 3:
                cout << "\nProgram exited. Goodbye!\n";
                return 0;
            default:
                cout << "Invalid option. Please choose a valid option (1-3)." << endl;
                break;
        }
    }
}