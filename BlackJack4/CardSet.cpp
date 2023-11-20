#include "CardSet.h"

CardSet::CardSet() {//�����_���ɐ�������ׂ�
    _distributeNum = -1;//�܂�1�����z���ĂȂ� ���� �z��Ƃ��ɐ��+1����̂�

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