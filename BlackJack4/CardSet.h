#pragma once
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Constant.h"
using namespace std;

class CardSet {
public:
    CardSet();//コンストラクタ
    int distribute();//カードの配布

private:
    int _card[CARDNUM];
    int _distributeNum;//配った枚数
};