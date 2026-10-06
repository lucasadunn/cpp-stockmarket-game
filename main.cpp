#include <iostream>
#include <string>
#include <random>
using namespace std;

int main() {

//SET VARIABLES

double Apple = 329.00;
double Nvidia = 230.00;
double Microsoft = 515.00;
double Tesla = 350.00;
double Amazon = 250.00;
double ap;
double n;
double m;
double t;
double am;
double portfolio = 0.0;
double cash = 10000.0;
char continueGame;
//prompt user for input

cout << "============================== STOCK MARKET =================================" ;
cout << "\nYou have $" << cash << " to invest in the stock market.\nYou will enter the number of shares you wish to purchase for each stock.\n";
cout << "You can enter whole shares or fractional shares (e.g 1.25 shares).\n\n";
do {
    cout << "Press G to continue: ";
    cin >> continueGame;
}
while (continueGame != 'G' && continueGame != 'g');
do {
    cout << "\n\nApple: 329.00\nNvidia: 230.00\nMicrosoft: 515.00\nTesla: 350.00\nAmazon: 250.00\n\n";
    cout << "\nEnter Shares of Apple you wish to purchase. ";
    cout << "Max Shares available: " << cash / Apple << "\n\n";
    cin >> ap;

    if ((ap * Apple) > cash) {
        cout << "You do not have enough funds to complete the transaction. Please enter a valid number of shares: ";
    }
} while ((ap * Apple) > cash);

portfolio += (ap * Apple);
cash -= (ap * Apple);

cout << "\nYour Portfolio is worth: $" << portfolio << " \nYou have $" << cash << " left\n\n";

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

do {
    cout << "\nEnter Shares of Nvidia you wish to purchase. ";
    cout << "Max Shares available: " << cash / Nvidia << "\n\n";
    cin >> n;

    if ((n* Nvidia) > cash) {
        cout << "You do not have enough funds to complete the transaction. Please enter a valid number of shares: ";
    }
} while ((n* Nvidia) > cash);

portfolio += (n* Nvidia);
cash -= (n* Nvidia);

cout << "\nYour Portfolio is worth: $" << portfolio << " \nYou have $" << cash << " left\n\n";

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

do {
    cout << "\nEnter Shares of Microsoft you wish to purchase. ";
    cout << "Max Shares available: " << cash / Microsoft << "\n\n";
    cin >> m;

    if ((m * Microsoft) > cash) {
        cout << "You do not have enough funds to complete the transaction. Please enter a valid number of shares: ";
    }
} while ((m * Microsoft) > cash);

portfolio += (m* Microsoft);
cash -= (m * Microsoft);

cout << "\nYour Portfolio is worth: $" << portfolio << " \nYou have $" << cash << " left\n\n";

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

do {
    cout << "\nEnter Shares of Tesla you wish to purchase. ";
    cout << "Max Shares available: " << cash / Tesla << "\n\n";
    cin >> t;

    if ((t * Tesla) > cash) {
        cout << "You do not have enough funds to complete the transaction. Please enter a valid number of shares: ";
    }
} while ((t * Tesla) > cash);

portfolio += (t * Tesla);
cash -= (t * Tesla);

cout << "\nYour Portfolio is worth: $" << portfolio << " \nYou have $" << cash << " left\n\n";

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

do {
    cout << "\nEnter Shares of Amazon you wish to purchase. ";
    cout << "Max Shares available: " << cash / Amazon << "\n\n";
    cin >> am;

    if ((am * Amazon) > cash) {
        cout << "You do not have enough funds to complete the transaction. Please enter a valid number of shares: ";
    }
} while ((am * Amazon) > cash);

portfolio += (am * Amazon);
cash -= (am * Amazon);

cout << "\nYour Portfolio is worth: $" << portfolio << " \nYou have $" << cash << " left\n\n";

//STOCK MARKET STARTS CHANGING
char go;
cout << "====== YOU HAVE 3 MONTHS ======";
cout << "Each month, the values of your stocks will change randomly. Buy and sell different stocks to try to maximize profit. If you have more than $10,000 at the end of 3 months, you win! If you have less than $10,000, you lose. Good luck!\n\n";
do {
cout << "\n\nType G to advance a month.\n\n";
cin >> continueGame;
} while (continueGame != 'G' && continueGame != 'g');

//SETUP RANDOM NUMBER GENERATOR
random_device rd;
mt19937 gen(rd());
std::uniform_real_distribution<double> distrib(.75, 1.25);

double applemult = distrib(gen);
double nvidiamult = distrib(gen);
double microsoftmult = distrib(gen);
double teslamult = distrib(gen);
double amazonmult = distrib(gen);

double Apple2 = Apple * applemult;
double Nvidia2 = Nvidia * nvidiamult;        
double Microsoft2 = Microsoft * microsoftmult;
double Tesla2 = Tesla * teslamult;
double Amazon2 = Amazon * amazonmult;
double portfolio2 = (ap * Apple2) + (n * Nvidia2) + (m * Microsoft2) + (t * Tesla2) + (am * Amazon2);

cout << "Your portfolio is now worth $" << portfolio2 << ".\n";
cout << "You have $" << cash << " available cash.\n";
cout << "Your total wealth is $" << portfolio2 + cash << ".\n\n";

if (portfolio2 > portfolio) {
    cout << "Your portfolio gained value!\n\n";
}
else if (portfolio2 < portfolio) {
    cout << "\n==Your portfolio has decreased in value.==\n\n";
}
else {
    cout << "Your portfolio has not changed in value.\n\n";
}

do {
    cout << "Now Press G to continue\n\n";
     cin >> continueGame;
} while (continueGame != 'G' && continueGame != 'g');

int choice;

cout << "\n1. Continue to next month\n2. Buy/Sell Stocks\n";

do {

    cout << "Enter your choice: ";

    cin >> choice;

}

while (choice != 1 && choice != 2);

if (choice == 2) {

    cout << "\n1. Buy Stocks\n2. Sell Stocks\n";

    do {

        cout << "Enter your choice: ";

        cin >> choice;

    } while (choice != 1 && choice != 2);


    //BUY STOCKS

    if (choice == 1) {

        cout << "\n1. Apple\n2. Nvidia\n3. Microsoft\n4. Tesla\n5. Amazon\n";

        cout << "You have $" << cash << " to invest.\n";

        cout << "Enter the stock you wish to buy: ";


        do {

            cin >> choice;

            if (choice < 1 || choice > 5) {

                cout << "Invalid choice. Please enter a valid choice: ";

            }

        } while (choice < 1 || choice > 5);


        double shares;


        switch (choice) {


            case 1:

                cout << "\nApple price: $" << Apple2 << "\n";

                cout << "Maximum shares available to purchase: " << cash / Apple2 << "\n";

                cout << "Enter the number of shares of Apple you wish to purchase: ";

                do {

                    cin >> shares;

                    if ((shares * Apple2) > cash || shares < 0) {

                        cout << "You have $" << cash << " available. Maximum shares available: "
                             << cash / Apple2 << "\n";

                    }

                } while ((shares * Apple2) > cash || shares < 0);

                ap += shares;

                cash -= shares * Apple2;

                cout << "You now own " << ap << " shares of Apple worth $" << ap * Apple2 << ".\n";

                cout << "You now have $" << cash << " available cash.\n";

                break;


            case 2:

                cout << "\nNvidia price: $" << Nvidia2 << "\n";

                cout << "Maximum shares available to purchase: " << cash / Nvidia2 << "\n";

                cout << "Enter the number of shares of Nvidia you wish to purchase: ";

                do {

                    cin >> shares;

                    if ((shares * Nvidia2) > cash || shares < 0) {

                        cout << "You have $" << cash << " available. Maximum shares available: "
                             << cash / Nvidia2 << "\n";

                    }

                } while ((shares * Nvidia2) > cash || shares < 0);

                n += shares;

                cash -= shares * Nvidia2;

                cout << "You now own " << n << " shares of Nvidia worth $" << n * Nvidia2 << ".\n";

                cout << "You now have $" << cash << " available cash.\n";

                break;


            case 3:

                cout << "\nMicrosoft price: $" << Microsoft2 << "\n";

                cout << "Maximum shares available to purchase: " << cash / Microsoft2 << "\n";

                cout << "Enter the number of shares of Microsoft you wish to purchase: ";

                do {

                    cin >> shares;

                    if ((shares * Microsoft2) > cash || shares < 0) {

                        cout << "You have $" << cash << " available. Maximum shares available: "
                             << cash / Microsoft2 << "\n";

                    }

                } while ((shares * Microsoft2) > cash || shares < 0);

                m += shares;

                cash -= shares * Microsoft2;

                cout << "You now own " << m << " shares of Microsoft worth $" << m * Microsoft2 << ".\n";

                cout << "You now have $" << cash << " available cash.\n";

                break;


            case 4:

                cout << "\nTesla price: $" << Tesla2 << "\n";

                cout << "Maximum shares available to purchase: " << cash / Tesla2 << "\n";

                cout << "Enter the number of shares of Tesla you wish to purchase: ";

                do {

                    cin >> shares;

                    if ((shares * Tesla2) > cash || shares < 0) {

                        cout << "You have $" << cash << " available. Maximum shares available: "
                             << cash / Tesla2 << "\n";

                    }

                } while ((shares * Tesla2) > cash || shares < 0);

                t += shares;

                cash -= shares * Tesla2;

                cout << "You now own " << t << " shares of Tesla worth $" << t * Tesla2 << ".\n";

                cout << "You now have $" << cash << " available cash.\n";

                break;


            case 5:

                cout << "\nAmazon price: $" << Amazon2 << "\n";

                cout << "Maximum shares available to purchase: " << cash / Amazon2 << "\n";

                cout << "Enter the number of shares of Amazon you wish to purchase: ";

                do {

                    cin >> shares;

                    if ((shares * Amazon2) > cash || shares < 0) {

                        cout << "You have $" << cash << " available. Maximum shares available: "
                             << cash / Amazon2 << "\n";

                    }

                } while ((shares * Amazon2) > cash || shares < 0);

                am += shares;

                cash -= shares * Amazon2;

                cout << "You now own " << am << " shares of Amazon worth $" << am * Amazon2 << ".\n";

                cout << "You now have $" << cash << " available cash.\n";

                break;

        }

    }


    //SELL STOCKS

    else {

        cout << "\n1. Apple\n2. Nvidia\n3. Microsoft\n4. Tesla\n5. Amazon\n";

        cout << "Enter the stock you wish to sell: ";


        do {

            cin >> choice;

            if (choice < 1 || choice > 5) {

                cout << "Invalid choice. Please enter a valid choice: ";

            }

        } while (choice < 1 || choice > 5);


        double shares;


        switch (choice) {


            case 1:

                cout << "\nApple price: $" << Apple2 << "\n";

                cout << "You currently own " << ap << " shares of Apple.\n";

                cout << "Shares available to sell: " << ap << "\n";

                cout << "You currently have $" << cash << " available cash.\n";

                cout << "Enter the number of shares of Apple you wish to sell: ";

                do {

                    cin >> shares;

                    if (shares > ap || shares < 0) {

                        cout << "You can sell up to " << ap << " shares. Please enter a valid number: ";

                    }

                } while (shares > ap || shares < 0);

                ap -= shares;

                cash += shares * Apple2;

                cout << "You now own " << ap << " shares of Apple worth $" << ap * Apple2 << ".\n";

                cout << "You now have $" << cash << " available cash.\n";

                break;


            case 2:

                cout << "\nNvidia price: $" << Nvidia2 << "\n";

                cout << "You currently own " << n << " shares of Nvidia.\n";

                cout << "Shares available to sell: " << n << "\n";

                cout << "You currently have $" << cash << " available cash.\n";

                cout << "Enter the number of shares of Nvidia you wish to sell: ";

                do {

                    cin >> shares;

                    if (shares > n || shares < 0) {

                        cout << "You can sell up to " << n << " shares. Please enter a valid number: ";

                    }

                } while (shares > n || shares < 0);

                n -= shares;

                cash += shares * Nvidia2;

                cout << "You now own " << n << " shares of Nvidia worth $" << n * Nvidia2 << ".\n";

                cout << "You now have $" << cash << " available cash.\n";

                break;


            case 3:

                cout << "\nMicrosoft price: $" << Microsoft2 << "\n";

                cout << "You currently own " << m << " shares of Microsoft.\n";

                cout << "Shares available to sell: " << m << "\n";

                cout << "You currently have $" << cash << " available cash.\n";

                cout << "Enter the number of shares of Microsoft you wish to sell: ";

                do {

                    cin >> shares;

                    if (shares > m || shares < 0) {

                        cout << "You can sell up to " << m << " shares. Please enter a valid number: ";

                    }

                } while (shares > m || shares < 0);

                m -= shares;

                cash += shares * Microsoft2;

                cout << "You now own " << m << " shares of Microsoft worth $" << m * Microsoft2 << ".\n";

                cout << "You now have $" << cash << " available cash.\n";

                break;


            case 4:

                cout << "\nTesla price: $" << Tesla2 << "\n";

                cout << "You currently own " << t << " shares of Tesla.\n";

                cout << "Shares available to sell: " << t << "\n";

                cout << "You currently have $" << cash << " available cash.\n";

                cout << "Enter the number of shares of Tesla you wish to sell: ";

                do {

                    cin >> shares;

                    if (shares > t || shares < 0) {

                        cout << "You can sell up to " << t << " shares. Please enter a valid number: ";

                    }

                } while (shares > t || shares < 0);

                t -= shares;

                cash += shares * Tesla2;

                cout << "You now own " << t << " shares of Tesla worth $" << t * Tesla2 << ".\n";

                cout << "You now have $" << cash << " available cash.\n";

                break;


            case 5:

                cout << "\nAmazon price: $" << Amazon2 << "\n";

                cout << "You currently own " << am << " shares of Amazon.\n";

                cout << "Shares available to sell: " << am << "\n";

                cout << "You currently have $" << cash << " available cash.\n";

                cout << "Enter the number of shares of Amazon you wish to sell: ";

                do {

                    cin >> shares;

                    if (shares > am || shares < 0) {

                        cout << "You can sell up to " << am << " shares. Please enter a valid number: ";

                    }

                } while (shares > am || shares < 0);

                am -= shares;

                cash += shares * Amazon2;

                cout << "You now own " << am << " shares of Amazon worth $" << am * Amazon2 << ".\n";

                cout << "You now have $" << cash << " available cash.\n";

                break;

        }

    }

}
//MONTH 2//////////////////////////////////////////////////////////////////////////////////


cout << "\n\n======MONTH 2======\n\n";

double applemult3 = distrib(gen);
double nvidiamult3 = distrib(gen);
double microsoftmult3 = distrib(gen);
double teslamult3 = distrib(gen);
double amazonmult3 = distrib(gen);


double Apple3 = Apple2 * applemult3;
double Nvidia3 = Nvidia2 * nvidiamult3;
double Microsoft3 = Microsoft2 * microsoftmult3;
double Tesla3 = Tesla2 * teslamult3;
double Amazon3 = Amazon2 * amazonmult3;


double portfolio3 = (ap * Apple3) + (n * Nvidia3) + (m * Microsoft3) + (t * Tesla3) + (am * Amazon3);


cout << "Your portfolio is now worth $" << portfolio3 << ".\n";
cout << "You have $" << cash << " available cash.\n";
cout << "Your total wealth is $" << portfolio3 + cash << ".\n\n";


if (portfolio3 > portfolio2) {

    cout << "Your portfolio gained value!\n\n";

}

else if (portfolio3 < portfolio2) {

    cout << "\n==Your portfolio has decreased in value.==\n\n";

}

else {

    cout << "Your portfolio has not changed in value.\n\n";

}


do {

    cout << "Now Press G to continue\n\n";

    cin >> continueGame;

} while (continueGame != 'G' && continueGame != 'g');


int choice2;


cout << "\n1. Continue to next month\n2. Buy/Sell Stocks\n";

do {

    cout << "Enter your choice: ";

    cin >> choice2;

} while (choice2 != 1 && choice2 != 2);


if (choice2 == 2) {

    cout << "\nNote: You can only buy or sell one stock per round.\n";

    cout << "1. Buy Stocks\n2. Sell Stocks\n";

    do {

        cout << "Enter your choice: ";

        cin >> choice2;

    } while (choice2 != 1 && choice2 != 2);


    //BUY STOCKS

    if (choice2 == 1) {

        cout << "\n1. Apple\n2. Nvidia\n3. Microsoft\n4. Tesla\n5. Amazon\n";

        cout << "You have $" << cash << " to invest.\n";

        cout << "Enter the stock you wish to buy: ";

        do {

            cin >> choice2;

            if (choice2 < 1 || choice2 > 5) {

                cout << "Invalid choice. Please enter a valid choice: ";

            }

        } while (choice2 < 1 || choice2 > 5);


        double shares;


        switch (choice2) {


            case 1:

                cout << "\nApple price: $" << Apple3 << "\n";

                cout << "Maximum shares available to purchase: " << cash / Apple3 << "\n";

                cout << "Enter the number of shares of Apple you wish to purchase: ";

                do {

                    cin >> shares;

                    if ((shares * Apple3) > cash || shares < 0) {

                        cout << "You have $" << cash << " available. Maximum shares available: "
                             << cash / Apple3 << "\n";

                    }

                } while ((shares * Apple3) > cash || shares < 0);

                ap += shares;

                cash -= shares * Apple3;

                cout << "You now own " << ap
                     << " shares of Apple worth $" << ap * Apple3 << ".\n";

                cout << "You now have $" << cash << " available cash.\n";

                break;


            case 2:

                cout << "\nNvidia price: $" << Nvidia3 << "\n";

                cout << "Maximum shares available to purchase: " << cash / Nvidia3 << "\n";

                cout << "Enter the number of shares of Nvidia you wish to purchase: ";

                do {

                    cin >> shares;

                    if ((shares * Nvidia3) > cash || shares < 0) {

                        cout << "You have $" << cash << " available. Maximum shares available: "
                             << cash / Nvidia3 << "\n";

                    }

                } while ((shares * Nvidia3) > cash || shares < 0);

                n += shares;

                cash -= shares * Nvidia3;

                cout << "You now own " << n
                     << " shares of Nvidia worth $" << n * Nvidia3 << ".\n";

                cout << "You now have $" << cash << " available cash.\n";

                break;


            case 3:

                cout << "\nMicrosoft price: $" << Microsoft3 << "\n";

                cout << "Maximum shares available to purchase: " << cash / Microsoft3 << "\n";

                cout << "Enter the number of shares of Microsoft you wish to purchase: ";

                do {

                    cin >> shares;

                    if ((shares * Microsoft3) > cash || shares < 0) {

                        cout << "You have $" << cash << " available. Maximum shares available: "
                             << cash / Microsoft3 << "\n";

                    }

                } while ((shares * Microsoft3) > cash || shares < 0);

                m += shares;

                cash -= shares * Microsoft3;

                cout << "You now own " << m
                     << " shares of Microsoft worth $" << m * Microsoft3 << ".\n";

                cout << "You now have $" << cash << " available cash.\n";

                break;


            case 4:

                cout << "\nTesla price: $" << Tesla3 << "\n";

                cout << "Maximum shares available to purchase: " << cash / Tesla3 << "\n";

                cout << "Enter the number of shares of Tesla you wish to purchase: ";

                do {

                    cin >> shares;

                    if ((shares * Tesla3) > cash || shares < 0) {

                        cout << "You have $" << cash << " available. Maximum shares available: "
                             << cash / Tesla3 << "\n";

                    }

                } while ((shares * Tesla3) > cash || shares < 0);

                t += shares;

                cash -= shares * Tesla3;

                cout << "You now own " << t
                     << " shares of Tesla worth $" << t * Tesla3 << ".\n";

                cout << "You now have $" << cash << " available cash.\n";

                break;


            case 5:

                cout << "\nAmazon price: $" << Amazon3 << "\n";

                cout << "Maximum shares available to purchase: " << cash / Amazon3 << "\n";

                cout << "Enter the number of shares of Amazon you wish to purchase: ";

                do {

                    cin >> shares;

                    if ((shares * Amazon3) > cash || shares < 0) {

                        cout << "You have $" << cash << " available. Maximum shares available: "
                             << cash / Amazon3 << "\n";

                    }

                } while ((shares * Amazon3) > cash || shares < 0);

                am += shares;

                cash -= shares * Amazon3;

                cout << "You now own " << am
                     << " shares of Amazon worth $" << am * Amazon3 << ".\n";

                cout << "You now have $" << cash << " available cash.\n";

                break;

        }

    }


    //SELL STOCKS

    else {

        cout << "\n1. Apple\n2. Nvidia\n3. Microsoft\n4. Tesla\n5. Amazon\n";

        cout << "Enter the stock you wish to sell: ";

        do {

            cin >> choice2;

            if (choice2 < 1 || choice2 > 5) {

                cout << "Invalid choice. Please enter a valid choice: ";

            }

        } while (choice2 < 1 || choice2 > 5);


        double shares;


        switch (choice2) {


            case 1:

                cout << "\nApple price: $" << Apple3 << "\n";

                cout << "You currently own " << ap << " shares of Apple.\n";

                cout << "Shares available to sell: " << ap << "\n";

                cout << "You currently have $" << cash << " available cash.\n";

                cout << "Enter the number of shares of Apple you wish to sell: ";

                do {

                    cin >> shares;

                    if (shares > ap || shares < 0) {

                        cout << "You can sell up to " << ap
                             << " shares. Please enter a valid number: ";

                    }

                } while (shares > ap || shares < 0);

                ap -= shares;

                cash += shares * Apple3;

                cout << "You now own " << ap
                     << " shares of Apple worth $" << ap * Apple3 << ".\n";

                cout << "You now have $" << cash << " available cash.\n";

                break;


            case 2:

                cout << "\nNvidia price: $" << Nvidia3 << "\n";

                cout << "You currently own " << n << " shares of Nvidia.\n";

                cout << "Shares available to sell: " << n << "\n";

                cout << "You currently have $" << cash << " available cash.\n";

                cout << "Enter the number of shares of Nvidia you wish to sell: ";

                do {

                    cin >> shares;

                    if (shares > n || shares < 0) {

                        cout << "You can sell up to " << n
                             << " shares. Please enter a valid number: ";

                    }

                } while (shares > n || shares < 0);

                n -= shares;

                cash += shares * Nvidia3;

                cout << "You now own " << n
                     << " shares of Nvidia worth $" << n * Nvidia3 << ".\n";

                cout << "You now have $" << cash << " available cash.\n";

                break;


            case 3:

                cout << "\nMicrosoft price: $" << Microsoft3 << "\n";

                cout << "You currently own " << m << " shares of Microsoft.\n";

                cout << "Shares available to sell: " << m << "\n";

                cout << "You currently have $" << cash << " available cash.\n";

                cout << "Enter the number of shares of Microsoft you wish to sell: ";

                do {

                    cin >> shares;

                    if (shares > m || shares < 0) {

                        cout << "You can sell up to " << m
                             << " shares. Please enter a valid number: ";

                    }

                } while (shares > m || shares < 0);

                m -= shares;

                cash += shares * Microsoft3;

                cout << "You now own " << m
                     << " shares of Microsoft worth $" << m * Microsoft3 << ".\n";

                cout << "You now have $" << cash << " available cash.\n";

                break;


            case 4:

                cout << "\nTesla price: $" << Tesla3 << "\n";

                cout << "You currently own " << t << " shares of Tesla.\n";

                cout << "Shares available to sell: " << t << "\n";

                cout << "You currently have $" << cash << " available cash.\n";

                cout << "Enter the number of shares of Tesla you wish to sell: ";

                do {

                    cin >> shares;

                    if (shares > t || shares < 0) {

                        cout << "You can sell up to " << t
                             << " shares. Please enter a valid number: ";

                    }

                } while (shares > t || shares < 0);

                t -= shares;

                cash += shares * Tesla3;

                cout << "You now own " << t
                     << " shares of Tesla worth $" << t * Tesla3 << ".\n";

                cout << "You now have $" << cash << " available cash.\n";

                break;


            case 5:

                cout << "\nAmazon price: $" << Amazon3 << "\n";

                cout << "You currently own " << am << " shares of Amazon.\n";

                cout << "Shares available to sell: " << am << "\n";

                cout << "You currently have $" << cash << " available cash.\n";

                cout << "Enter the number of shares of Amazon you wish to sell: ";

                do {

                    cin >> shares;

                    if (shares > am || shares < 0) {

                        cout << "You can sell up to " << am
                             << " shares. Please enter a valid number: ";

                    }

                } while (shares > am || shares < 0);

                am -= shares;

                cash += shares * Amazon3;

                cout << "You now own " << am
                     << " shares of Amazon worth $" << am * Amazon3 << ".\n";

                cout << "You now have $" << cash << " available cash.\n";

                break;

        }

    }

}


//MONTH 3//////////////////////////////////////////////////////////////////////////////////


cout << "\n\n======MONTH 3======\n\n";

double applemult4 = distrib(gen);
double nvidiamult4 = distrib(gen);
double microsoftmult4 = distrib(gen);
double teslamult4 = distrib(gen);
double amazonmult4 = distrib(gen);


double Apple4 = Apple3 * applemult4;
double Nvidia4 = Nvidia3 * nvidiamult4;
double Microsoft4 = Microsoft3 * microsoftmult4;
double Tesla4 = Tesla3 * teslamult4;
double Amazon4 = Amazon3 * amazonmult4;


double portfolio4 =

    (ap * Apple4) +

    (n * Nvidia4) +

    (m * Microsoft4) +

    (t * Tesla4) +

    (am * Amazon4);


cout << "Your portfolio is now worth $" << portfolio4 << ".\n";
cout << "You have $" << cash << " available cash.\n";
cout << "Your total wealth is $" << portfolio4 + cash << ".\n\n";


if (portfolio4 > portfolio3) {

    cout << "Your portfolio gained value!\n\n";

}

else if (portfolio4 < portfolio3) {

    cout << "\n==Your portfolio has decreased in value.==\n\n";

}

else {

    cout << "Your portfolio has not changed in value.\n\n";

}


do {

    cout << "Now Press G to continue\n\n";

    cin >> continueGame;

} while (continueGame != 'G' && continueGame != 'g');


int choice3;


cout << "\n1. Continue to next month\n2. Buy/Sell Stocks\n";

do {

    cout << "Enter your choice: ";

    cin >> choice3;

} while (choice3 != 1 && choice3 != 2);


if (choice3 == 2) {

    cout << "\nNote: You can only buy or sell one stock per round.\n";

    cout << "1. Buy Stocks\n2. Sell Stocks\n";

    do {

        cout << "Enter your choice: ";

        cin >> choice3;

    } while (choice3 != 1 && choice3 != 2);


    //BUY STOCKS

    if (choice3 == 1) {

        cout << "\n1. Apple\n2. Nvidia\n3. Microsoft\n4. Tesla\n5. Amazon\n";

        cout << "You have $" << cash << " to invest.\n";

        cout << "Enter the stock you wish to buy: ";

        do {

            cin >> choice3;

            if (choice3 < 1 || choice3 > 5) {

                cout << "Invalid choice. Please enter a valid choice: ";

            }

        } while (choice3 < 1 || choice3 > 5);


        double shares;


        switch (choice3) {


            case 1:

                cout << "\nApple price: $" << Apple4 << "\n";

                cout << "Maximum shares available to purchase: " << cash / Apple4 << "\n";

                cout << "Enter the number of shares of Apple you wish to purchase: ";

                do {

                    cin >> shares;

                    if ((shares * Apple4) > cash || shares < 0) {

                        cout << "You have $" << cash << " available. Maximum shares available: "
                             << cash / Apple4 << "\n";

                    }

                } while ((shares * Apple4) > cash || shares < 0);

                ap += shares;

                cash -= shares * Apple4;

                cout << "You now own " << ap
                     << " shares of Apple worth $" << ap * Apple4 << ".\n";

                cout << "You now have $" << cash << " available cash.\n";

                break;


            case 2:

                cout << "\nNvidia price: $" << Nvidia4 << "\n";

                cout << "Maximum shares available to purchase: " << cash / Nvidia4 << "\n";

                cout << "Enter the number of shares of Nvidia you wish to purchase: ";

                do {

                    cin >> shares;

                    if ((shares * Nvidia4) > cash || shares < 0) {

                        cout << "You have $" << cash << " available. Maximum shares available: "
                             << cash / Nvidia4 << "\n";

                    }

                } while ((shares * Nvidia4) > cash || shares < 0);

                n += shares;

                cash -= shares * Nvidia4;

                cout << "You now own " << n
                     << " shares of Nvidia worth $" << n * Nvidia4 << ".\n";

                cout << "You now have $" << cash << " available cash.\n";

                break;


            case 3:

                cout << "\nMicrosoft price: $" << Microsoft4 << "\n";

                cout << "Maximum shares available to purchase: " << cash / Microsoft4 << "\n";

                cout << "Enter the number of shares of Microsoft you wish to purchase: ";

                do {

                    cin >> shares;

                    if ((shares * Microsoft4) > cash || shares < 0) {

                        cout << "You have $" << cash << " available. Maximum shares available: "
                             << cash / Microsoft4 << "\n";

                    }

                } while ((shares * Microsoft4) > cash || shares < 0);

                m += shares;

                cash -= shares * Microsoft4;

                cout << "You now own " << m
                     << " shares of Microsoft worth $" << m * Microsoft4 << ".\n";

                cout << "You now have $" << cash << " available cash.\n";

                break;


            case 4:

                cout << "\nTesla price: $" << Tesla4 << "\n";

                cout << "Maximum shares available to purchase: " << cash / Tesla4 << "\n";

                cout << "Enter the number of shares of Tesla you wish to purchase: ";

                do {

                    cin >> shares;

                    if ((shares * Tesla4) > cash || shares < 0) {

                        cout << "You have $" << cash << " available. Maximum shares available: "
                             << cash / Tesla4 << "\n";

                    }

                } while ((shares * Tesla4) > cash || shares < 0);

                t += shares;

                cash -= shares * Tesla4;

                cout << "You now own " << t
                     << " shares of Tesla worth $" << t * Tesla4 << ".\n";

                cout << "You now have $" << cash << " available cash.\n";

                break;


            case 5:

                cout << "\nAmazon price: $" << Amazon4 << "\n";

                cout << "Maximum shares available to purchase: " << cash / Amazon4 << "\n";

                cout << "Enter the number of shares of Amazon you wish to purchase: ";

                do {

                    cin >> shares;

                    if ((shares * Amazon4) > cash || shares < 0) {

                        cout << "You have $" << cash << " available. Maximum shares available: "
                             << cash / Amazon4 << "\n";

                    }

                } while ((shares * Amazon4) > cash || shares < 0);

                am += shares;

                cash -= shares * Amazon4;

                cout << "You now own " << am
                     << " shares of Amazon worth $" << am * Amazon4 << ".\n";

                cout << "You now have $" << cash << " available cash.\n";

                break;

        }

    }


    //SELL STOCKS

    else {

        cout << "\n1. Apple\n2. Nvidia\n3. Microsoft\n4. Tesla\n5. Amazon\n";

        cout << "Enter the stock you wish to sell: ";

        do {

            cin >> choice3;

            if (choice3 < 1 || choice3 > 5) {

                cout << "Invalid choice. Please enter a valid choice: ";

            }

        } while (choice3 < 1 || choice3 > 5);


        double shares;


        switch (choice3) {


            case 1:

                cout << "\nApple price: $" << Apple4 << "\n";

                cout << "You currently own " << ap << " shares of Apple.\n";

                cout << "Shares available to sell: " << ap << "\n";

                cout << "You currently have $" << cash << " available cash.\n";

                cout << "Enter the number of shares of Apple you wish to sell: ";

                do {

                    cin >> shares;

                    if (shares > ap || shares < 0) {

                        cout << "You can sell up to " << ap
                             << " shares. Please enter a valid number: ";

                    }

                } while (shares > ap || shares < 0);

                ap -= shares;

                cash += shares * Apple4;

                cout << "You now own " << ap
                     << " shares of Apple worth $" << ap * Apple4 << ".\n";

                cout << "You now have $" << cash << " available cash.\n";

                break;


            case 2:

                cout << "\nNvidia price: $" << Nvidia4 << "\n";

                cout << "You currently own " << n << " shares of Nvidia.\n";

                cout << "Shares available to sell: " << n << "\n";

                cout << "You currently have $" << cash << " available cash.\n";

                cout << "Enter the number of shares of Nvidia you wish to sell: ";

                do {

                    cin >> shares;

                    if (shares > n || shares < 0) {

                        cout << "You can sell up to " << n
                             << " shares. Please enter a valid number: ";

                    }

                } while (shares > n || shares < 0);

                n -= shares;

                cash += shares * Nvidia4;

                cout << "You now own " << n
                     << " shares of Nvidia worth $" << n * Nvidia4 << ".\n";

                cout << "You now have $" << cash << " available cash.\n";

                break;


            case 3:

                cout << "\nMicrosoft price: $" << Microsoft4 << "\n";

                cout << "You currently own " << m << " shares of Microsoft.\n";

                cout << "Shares available to sell: " << m << "\n";

                cout << "You currently have $" << cash << " available cash.\n";

                cout << "Enter the number of shares of Microsoft you wish to sell: ";

                do {

                    cin >> shares;

                    if (shares > m || shares < 0) {

                        cout << "You can sell up to " << m
                             << " shares. Please enter a valid number: ";

                    }

                } while (shares > m || shares < 0);

                m -= shares;

                cash += shares * Microsoft4;

                cout << "You now own " << m
                     << " shares of Microsoft worth $" << m * Microsoft4 << ".\n";

                cout << "You now have $" << cash << " available cash.\n";

                break;


            case 4:

                cout << "\nTesla price: $" << Tesla4 << "\n";

                cout << "You currently own " << t << " shares of Tesla.\n";

                cout << "Shares available to sell: " << t << "\n";

                cout << "You currently have $" << cash << " available cash.\n";

                cout << "Enter the number of shares of Tesla you wish to sell: ";

                do {

                    cin >> shares;

                    if (shares > t || shares < 0) {

                        cout << "You can sell up to " << t
                             << " shares. Please enter a valid number: ";

                    }

                } while (shares > t || shares < 0);

                t -= shares;

                cash += shares * Tesla4;

                cout << "You now own " << t
                     << " shares of Tesla worth $" << t * Tesla4 << ".\n";

                cout << "You now have $" << cash << " available cash.\n";

                break;


            case 5:

                cout << "\nAmazon price: $" << Amazon4 << "\n";

                cout << "You currently own " << am << " shares of Amazon.\n";

                cout << "Shares available to sell: " << am << "\n";

                cout << "You currently have $" << cash << " available cash.\n";

                cout << "Enter the number of shares of Amazon you wish to sell: ";

                do {

                    cin >> shares;

                    if (shares > am || shares < 0) {

                        cout << "You can sell up to " << am
                             << " shares. Please enter a valid number: ";

                    }

                } while (shares > am || shares < 0);

                am -= shares;

                cash += shares * Amazon4;

                cout << "You now own " << am
                     << " shares of Amazon worth $" << am * Amazon4 << ".\n";

                cout << "You now have $" << cash << " available cash.\n";

                break;

        }

    }

}


//FINAL RESULTS

double finalPortfolio =
    (ap * Apple4) +
    (n * Nvidia4) +
    (m * Microsoft4) +
    (t * Tesla4) +
    (am * Amazon4);

double finalTotal = finalPortfolio + cash;

cout << "\n\n====================================\n";
cout << "          FINAL RESULTS\n";
cout << "====================================\n\n";

cout << "Stock Portfolio: $" << finalPortfolio << "\n";
cout << "Cash: $" << cash << "\n";
cout << "Total Wealth: $" << finalTotal << "\n\n";

if (finalTotal > 10000) {

    cout << "CONGRATULATIONS! YOU WIN!\n";
    cout << "You finished with more than $10,000.\n";

}

else if (finalTotal < 10000) {

    cout << "You lose.\n";
    cout << "You finished with less than $10,000.\n";

}

else {

    cout << "You broke even!\n";
    cout << "You finished with exactly $10,000.\n";

}


}
