#include "Saving.h"

Saving::Saving(const string& t, const string& b, const string& bank, const string& n, float rate):Account(t, b, bank, n) {
	interest = rate;
}
