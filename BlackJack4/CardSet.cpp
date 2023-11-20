#include "CardSet.h"

CardSet::CardSet() {//ƒ‰ƒ“ƒ_ƒ€‚É”š‚ğ•À‚×‚é
    _distributeNum = -1;//‚Ü‚¾1–‡‚à”z‚Á‚Ä‚È‚¢ ‚©‚Â ”z‚é‚Æ‚«‚Éæ‚É+1‚·‚é‚Ì‚Å

    srand(time(NULL));

    for (int i = 0; i < CARDNUM; ++i) {
        _card[i] = i;
    }
    for (int i = CARDNUM; i > 1; --i) {
        swap(_card[i - 1], _card[rand() % (i - 1)]);
    }
}
int CardSet::distribute() {
    ++_distributeNum;
    return _card[_distributeNum];
}