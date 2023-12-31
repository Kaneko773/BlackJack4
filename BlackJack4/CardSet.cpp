#include "CardSet.h"

CardSet::CardSet() {//ランダムに数字を並べる
    _distributeNum = -1;//まだ1枚も配ってない かつ 配るときに先に+1するので

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