#pragma once
#include <iostream>
#include "Constant.h"
#include "CardSet.h"
using namespace std;

class Person {
public:
    Person(CardSet& shoe, const char* pname);//コンストラクタ
    void Show();//手札と得点の表示
    void Draw();//ドロー
    void ScoreCalculation(int outwardlyNum);//得点計算
    virtual bool ContinuJudge();//継続判定
    int get_score() const;

protected:
    const char* _name;
    int _hand[MAX_HANDNUM];
    int _outwardlyNum;
    int _score;
};