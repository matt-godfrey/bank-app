#include "Saving.h"

Saving::Saving(const string& t, const string& b, const string& bank, Customer* c, float rate):Account(t, b, bank, c) {
	interest = rate;
}
