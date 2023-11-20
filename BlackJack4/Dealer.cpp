#include "Dealer.h"

bool Dealer::ContinuJudge() {
    if (_score >= 17) {
        return false;
    }
    else {
        return true;
    }
}