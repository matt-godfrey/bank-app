#include "Saving.h"

Saving::Saving(const string& t, const string& b, const string& bank, float rate):Account(t, b, bank) {
	interest = rate;
}
