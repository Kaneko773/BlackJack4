#include "CardSet.h"
#include "Person.h"

Person::Person(CardSet& shoe, const char* pname) {//コンストラクタ
    _name = pname;
    for (int i = 0; i < MAX_HANDNUM; ++i) {
        _hand[i] = shoe.distribute();
    }
    _outwardlyNum = 1;//最初は１枚配られる
    ScoreCalculation(_outwardlyNum);
}
void Person::Show() {//手札と得点の表示
    cout << "----------------------------------------------" << endl;
    cout << _name << "の手札" << endl;
    for (int i = 0; i < _outwardlyNum; ++i) {
        switch (_hand[i] % 4 + 1)
        {
        case 1: printf("スペード　 : %d\n", _hand[i] % 13 + 1); break;
        case 2: printf("ハート　　 : %d\n", _hand[i] % 13 + 1); break;
        case 3: printf("ダイヤ　　 : %d\n", _hand[i] % 13 + 1); break;
        case 4: printf("クローバー : %d\n", _hand[i] % 13 + 1); break;
        }
    }
    printf("点数 : %d\n", _score);
    cout << "----------------------------------------------" << endl;
}
void Person::Draw() {//ドロー
    if (_outwardlyNum < MAX_HANDNUM) {// 11枚までしか引けない
        ++_outwardlyNum;
        ScoreCalculation(_outwardlyNum);
    }
    else {
        cout << "これ以上ドロー出来ません" << endl;
    }
}
void Person::ScoreCalculation(int outwardlyNum) {//得点計算
    _score = 0;//得点をリセット
    int ANum = 0;
    for (int i = 0; i < outwardlyNum; ++i) {

        int Num = _hand[i] % 13 + 1;//札の数字だけとってくる

        if (1 <= Num && Num <= 10) {
            _score += Num;
        }
        else if (11 <= Num && Num <= 13) {
            _score += 10;
        }

        if (Num == 1) ++ANum;
    }

    for (int i = 0; i < ANum; ++i) {
        if (_score + 10 <= 21) {
            _score += 10;
        }
        else {
            break;
        }
    }
}
bool Person::ContinuJudge() {
    if (_score >= 21) {
        return false;
    }
    else {
        return true;
    }
}
int Person::get_score() const {
    return _score;
}