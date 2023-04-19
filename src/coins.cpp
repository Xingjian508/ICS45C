#include "coins.h"
#include <iostream>
#include <iomanip>


using namespace std;


Coins::Coins(int q, int d, int n, int p)
	:quarters(q), dimes(d), nickels(n), pennies(p) {
}


void Coins::print(std::ostream& out) const {
    out << quarters << " quarters, "
    << dimes << " dimes, "
    << nickels << " nickels, "
    << pennies << " pennies";
}


Coins coins_required_for_cents(int amount_in_cents) {
    int coins_list[4] = {0};
    int coins_type[] = {25, 10, 5, 1};
    int calculator = amount_in_cents;
    for (int i=0; i<4; ++i) {
        coins_list[i] = calculator / coins_type[i];
        calculator %= coins_type[i];
    }
    return Coins(coins_list[0], coins_list[1], coins_list[2], coins_list[3]);
}


Coins Coins::extract_exact_change(Coins const& coins) {
    if (quarters >= coins.quarters && dimes >= coins.dimes && nickels >= coins.nickels && pennies >= coins.pennies) {
        quarters -= coins.quarters;
        dimes -= coins.dimes;
        nickels -= coins.nickels;
        pennies -= coins.pennies;
    }
    else {
        return Coins(0, 0, 0, 0);
    }
    return Coins(coins.quarters, coins.dimes, coins.nickels, coins.pennies);
}


std::ostream& operator<<(std::ostream& out, Coins const& coins) {
	coins.print(out);
	return out;
}


void Coins::deposit_coins(Coins& coins) {
    quarters += coins.quarters;
    dimes += coins.dimes;
    nickels += coins.nickels;
    pennies += coins.pennies;
}


int Coins::total_value_in_cents() const {
    int total_value = 0;
    total_value += 25 * quarters;
    total_value += 10 * dimes;
    total_value += 5 * nickels;
    total_value += 1 * pennies;
    return total_value;
}


void print_cents(int cents, std::ostream& out) {
    out << "$";
    double divider = 100;
    double monetary_value = cents/divider;
    out << fixed << setprecision(2);
    out << monetary_value;
}


Coins ask_for_coins(std::istream& in, std::ostream& out) {
    int ans[4] = {0};
    out << "Quarters? ";
    in >> ans[0];
    out << "Dimes? ";
    in >> ans[1];
    out << "Nickels? ";
    in >> ans[2];
    out << "Pennies? ";
    in >> ans[3];

    Coins money(ans[0], ans[1], ans[2], ans[3]);
    return money;
}


void coins_menu(std::istream& in, std::ostream& out) {
    Coins bank(0, 0, 0, 0);
    bool error = false;

    out << "Coins Menu" << endl;
    out << endl;
    while (true) {
        error = false;
        out << "1. Deposit Change" << endl;
        out << "2. Extract Change" << endl;
        out << "3. Print Balance" << endl;
        out << "4. Exit" << endl;
        out << endl;

        out << "User input: ";
        int s;
        in >> s; // Loads the input into s.
        out << endl;

        if (s == 1) {
            // Deposit change.
            Coins deposited_money = ask_for_coins(in, out);
            bank.deposit_coins(deposited_money);
        }
        else if (s == 2) {
            // Extract change.
            Coins extracted_money = ask_for_coins(in, out);
            Coins result = bank.extract_exact_change(extracted_money);
            if (result.total_value_in_cents() == 0 && extracted_money.total_value_in_cents() != 0) {
                error = true;
            }
        }
        else if (s == 3) {
            // Print balance.
            print_cents(bank.total_value_in_cents(), out);
            cout << endl;
        }
        else {
            break;
        }

        out << endl;
        out << "Thank you!" << endl;
        out << endl;

        if (error) {
            cout << "ERROR: Insufficient Funds" << endl;
            cout << endl;
        }
    }
}
