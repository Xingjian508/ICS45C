#include <iostream>
#include "coins.h"
using namespace std;


constexpr int CENTS_FOR_CHIPS = 149;
constexpr int CENTS_FOR_TRANSFER = 405;


int main() {
    Coins piggybank(50, 50, 50, 50);
    Coins pocket(8, 3, 6, 8);

    cout << "Initial piggy bank: ";
    piggybank.print(cout);
    cout << endl;
    cout << "Initial pocket: ";
    pocket.print(cout);
    cout << endl;
    cout << endl;

    cout << "Bought chips using pocket" << endl;
    cout << "Coins required for chips: ";
    Coins chips_required_coins = coins_required_for_cents(CENTS_FOR_CHIPS);
    chips_required_coins.print(cout);
    cout << endl;
    cout << "Pocket after paying for chips: ";
    pocket.extract_exact_change(chips_required_coins);
    pocket.print(cout);
    cout << endl;
    cout << endl;

    cout << "Transferring money to pocket" << endl;
    cout << "Coins for transfer: ";
    Coins transfer_required_coins = coins_required_for_cents(CENTS_FOR_TRANSFER);
    transfer_required_coins.print(cout);
    cout << endl;
    piggybank.extract_exact_change(transfer_required_coins);
    pocket.deposit_coins(transfer_required_coins);
    cout << "Pocket: ";
    pocket.print(cout);
    cout << endl;
    cout << "Piggy bank: ";
    piggybank.print(cout);
    cout << endl;
    cout << endl;

    cout << "Transferring sofa change to piggy bank";
    cout << endl;
    cout << "Sofa: ";
    Coins sofa_found_coins(10, 10, 10, 10);
    piggybank.deposit_coins(sofa_found_coins);
    sofa_found_coins.extract_exact_change(sofa_found_coins);
    sofa_found_coins.print(cout);
    cout << endl;
    cout << "Piggy bank: ";
    piggybank.print(cout);
    cout << endl;
    cout << endl;

    cout << "Piggy bank total: ";
    print_cents(piggybank.total_value_in_cents(), cout);
    cout << endl;
}
