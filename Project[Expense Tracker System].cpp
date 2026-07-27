#include <iostream>
#include <string>
using namespace std;

class ExpenseTracker
{
private:

    int id[100];
    string title[100];
    string category[100];
    float amount[100];
    string date[100];

    int totalExpenses;
    float budget;

public:

    ExpenseTracker()
    {
        totalExpenses = 0;
        budget = 0;
    }

    void addExpense()
    {
        cout << "\nEnter Expense ID: ";
        cin >> id[totalExpenses];
        cout << "Enter Expense Title: ";
        cin >> title[totalExpenses];
        cout << "Enter Category: ";
        cin >> category[totalExpenses];
        cout << "Enter Amount: ";
        cin >> amount[totalExpenses];
        cout << "Enter Date (DD/MM/YYYY): ";
        cin >> date[totalExpenses];

        totalExpenses++;

        cout << "\nExpense Added Successfully.\n";

    }

    void viewExpenses()
    {
        if(totalExpenses == 0)
        {
            cout << "\nNo Expense Found.\n";
        }
        else
        {
            for(int i = 0;i < totalExpenses; i++)
            {
                cout << "\n-------------------------";
                cout << "\nExpense "  << i + 1;

                cout << "\nID: " << id[i];
                cout << "\nTitle: " << title[i];
                cout << "\nCategory: " << category[i];
                cout << "\nAmount: " << amount[i];
                cout << "\nDate: " << date[i];
            }

            cout << "\n-------------------------";
        }
    }

    void searchExpense()
    {
        int searchID;
        bool found = false;

        cout << "\nEnter Expense ID to Search: ";
        cin >> searchID;

        for(int i = 0; i < totalExpenses; i++)
        {
            if(id[i] == searchID)
            {
                cout << "\nExpense Found";

                cout << " \nID: " << id[i];
                cout << " \nTitle: " << title[i];
                cout << " \nCategory: " << category[i];
                cout << " \nAmount: " << amount[i];
                cout << " \nDate: " << date[i];

                found = true;
                break;
            }
        }

        if(found == false)
        {
            cout << "\nExpense Not Found.\n";
        }
    }

    void updateExpense()
    {
        int updateID;
        bool found = false;

        cout << "\nEnter Expense ID to Update: ";
        cin >> updateID;

        for(int i = 0; i < totalExpenses; i++)
        {
            if(id[i]  == updateID)
            {
                cout <<"\nEnter New Title: ";
                cin >> title[i];

                cout << "Enter New Category: ";
                cin >> category[i];

                cout << "\nEnter New Amount: ";
                cin >> amount[i];

                cout << "\nEnter New Date: ";
                cin >> date[i];

                cout << "\nExpense Updated Successfully.\n";

                found = true;
                break;
            }
        }

        if(found == false)
        {
            cout << "\nExpense Not Found.\n";
        }
    }

    void deleteExpense()
    {
        int deleteID;
        bool found = false;

        cout << "\nEnter Expense ID to Delete: ";
        cin >> deleteID;

        for(int i = 0; i < totalExpenses; i++)
        {
            if(id[i] == deleteID)
            {
                for(int j = i; j < totalExpenses - 1; j++)
                {
                    id[j] = id[j + 1];
                    title[j] = title[j + 1];
                    category[j] = category[j + 1];
                    amount[j] = amount[j + 1];
                    date[j] = date[j + 1];
                }

                totalExpenses--;

                cout << "\nExpense Deleted Successfully.\n";

                found = true;
                break;
            }
        }
        if(found == false)
        {
            cout << "\nExpense Not Found.\n";
        }
    }

    void setBudget()
    {
        cout << "\nEnter Your Budget: ";
        cin >> budget;

        cout << "\nBudget Set Successfully.\n";
    }

    void budgetReport()
    {
        float totalAmount = 0;

        for(int i = 0; i < totalExpenses; i++)
        {
            totalAmount = totalAmount + amount[i];
        }

        cout << "\n========== BUDGET REPORT ==========";
        cout << "\nBudget: " << budget;
        cout << "\nTotal Expenses: " << totalAmount;
        cout << "\nRemaining Budget: " << budget - totalAmount;

        if(totalAmount > budget)
        {
            cout << "\nWarning: Budget Exceeded!";
        }
        else
        {
            cout << "\nYou are within your budget.";
        }

        cout << "\n===================================\n";
    }

    void menu()
    {
        int choice;

        do
        {
            cout << "\n====================================";
            cout << "\n      EXPENSE TRACKER SYSTEM";
            cout << "\n====================================";

            cout << "\n1. Add Expense";
            cout << "\n2. View Expense";
            cout << "\n3. Search Expense";
            cout << "\n4. Update Expense";
            cout << "\n5. Delete Expense";
            cout << "\n6. Set Budget";
            cout << "\n7. Budget Report";
            cout << "\n8. Exit";

            cout << "\nEnter Your Choice: ";
            cin >> choice;

            switch(choice)
            {
            case 1:
                addExpense();
                break;

            case 2:
                viewExpenses();
                break;

            case 3:
                searchExpense();
                break;

            case 4:
                updateExpense();
                break;

            case 5:
                deleteExpense();
                break;

            case 6:
                setBudget();
                break;

            case 7:
                budgetReport();
                break;

            case 8:
                cout << "\nThank You for Using Expense Tracker System.\n ";
                break;

            default:
                cout << "\nInvalid choice! Please Try Again.\n";
            }
        } while(choice != 8);
    }

};

int main()
{
    ExpenseTracker obj;

    obj.menu();

    return 0;
}

