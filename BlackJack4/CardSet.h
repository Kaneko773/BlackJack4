#pragma once
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Constant.h"
using namespace std;

class CardSet {
public:
    CardSet();//�R���X�g���N�^
    int distribute();//�J�[�h�̔z�z

private:
    int _card[CARDNUM];
    int _distributeNum;//�z��������
};