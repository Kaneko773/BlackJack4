#pragma once
#include <iostream>
#include "Constant.h"
#include "CardSet.h"
using namespace std;

class Person {
public:
    Person(CardSet& shoe, const char* pname);//�R���X�g���N�^
    void Show();//��D�Ɠ��_�̕\��
    void Draw();//�h���[
    void ScoreCalculation(int outwardlyNum);//���_�v�Z
    virtual bool ContinuJudge();//�p������
    int get_score() const;

protected:
    const char* _name;
    int _hand[MAX_HANDNUM];
    int _outwardlyNum;
    int _score;
};