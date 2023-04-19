#ifndef COINS_H
#define COINS_H
#include <iosfwd>


constexpr int CENTS_PER_QUARTER = 25;
constexpr int CENTS_PER_DIME = 10;
constexpr int CENTS_PER_NICKEL = 5;


class Coins {
public:

	Coins(int q, int d, int n, int p); // D.

	void deposit_coins(Coins& coins); // D.

	bool has_exact_change_for_coins(Coins const& coins) const; // D.

	Coins extract_exact_change(Coins const& coins); // D.

	int total_value_in_cents() const; // D.

	void print(std::ostream& out) const; // D.

	bool operator==(Coins const& other) const = default;

private:
	int quarters, dimes, nickels, pennies; // E.D.
};


std::ostream& operator<<(std::ostream& out, Coins const& coins); // D.


Coins coins_required_for_cents(int amount_in_cents); // D.


void print_cents(int cents, std::ostream& out); // D.


Coins ask_for_coins(std::istream& in, std::ostream& out); // D.


void coins_menu(std::istream& in, std::ostream& out); // D.


#endif


