#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;
int main()
{
    int a, i = 0;
    string text, old, password1, password2, pass, name, password0, age, user, word, word1;
    string creds[2], cp[2];
    cout << " security system" << endl;
    cout << "_______________________________" << endl
         << endl;
    cout << "|          1.Register         |" << endl;
    cout << "|          2.Login            |" << endl;
    cout << "|          3.Change password  |" << endl;
    cout << "|__________4.End Program______|" << endl
         << endl;
    do
    {
        cout << endl
             << endl;
        cout << "Enter your choice:-";
        cin >> a;
        switch (a)
        {
        case 1:
        {
            cout << "_______________________________" << endl
                 << endl;
            cout << "|------------Register----------|" << endl;
            cout << "|______________________________|" << endl
                 << endl;
            cout << "Please enter username:-";
            cin >> name;
            cout << "Please enter the password:-";
            cin >> password0;
            cout << "Please enter your age:-";
            cin >> age;
            ofstream of1;
            of1.open("file.txt");
            if (of1.is_open())
            {
                of1 << name << "\n";
                of1 << password0;
                cout << "Registration successfull" << endl;
            }

            break;
        }
        case 2:
        {
            i = 0;
            cout << "_______________________________" << endl
                 << endl;
            cout << "|-------------Login------------|" << endl;
            cout << "|______________________________|" << endl
                 << endl;

            ifstream of2;
            of2.open("file.txt");
            cout << "Please enter the username:-";
            cin >> user;
            cout << "Please enter the password:-";
            cin >> pass;

            if (of2.is_open())
            {
                while (!of2.eof())
                {
                    while (getline(of2, text))
                    {
                        istringstream iss(text);
                        iss >> word;
                        creds[i] = word;
                        i++;
                    }
                    if (user == creds[0] && pass == creds[1])
                    {
                        cout << "---Login successfull---";
                        cout << endl
                             << endl;
                        cout << "  Details:   " << endl;
                        cout << "Username " + name << endl;
                        cout << "Password " + pass << endl;
                        cout << "Age " + age << endl;
                    }
                    else
                    {
                        cout << endl
                             << endl;
                        cout << "Incorrect Credentials" << endl;
                        cout << "|    1.Press 2 to Login             |" << endl;
                        cout << "|    2.Press 3 to Change Password   |" << endl;
                        break;
                    }
                }
            }
            break;
        }
        case 3:
        {
            int i = 0;
            cout << "-----------Change password-----------" << endl;

            ifstream of0;
            of0.open("file.txt");

            cout << "Enter the old password:-";
            cin >> old;

            if (of0.is_open())
            {
                while (getline(of0, text))
                {
                    istringstream iss(text);
                    iss >> word1;
                    cp[i] = word1;
                    i++;
                }

                of0.close();

                if (old == cp[1])
                {
                    ofstream of1;
                    of1.open("file.txt"); // Open the file for writing

                    if (of1.is_open())
                    {
                        cout << "Enter your new password:-";
                        cin >> password1;
                        cout << "Enter your password again:-";
                        cin >> password2;

                        if (password1 == password2)
                        {
                            of1 << cp[0] << "\n";
                            of1 << password1;
                            cout << "Password changed successfully" << endl;
                        }
                        else
                        {
                            of1 << cp[0] << "\n";
                            of1 << old;
                            cout << "Password do not match" << endl;
                        }

                        of1.close(); // Close the file after writing
                    }
                    else
                    {
                        cout << "Error opening file for writing." << endl;
                    }
                }
                else
                {
                    cout << "Please enter a valid password" << endl;
                }
            }
            else
            {
                cout << "Error opening file for reading." << endl;
            }

            break;
        }

        case 4:
        {
            cout << "_________Thankyou!__________";
            break;
        }
        default:
        {
            cout << "Enter a valid choice";
            break;
        }
        }
    } while (a != 4);
    return 0;
}