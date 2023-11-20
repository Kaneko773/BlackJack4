#include "CardSet.h"
#include "Person.h"

Person::Person(CardSet& shoe, const char* pname) {//�R���X�g���N�^
    _name = pname;
    for (int i = 0; i < MAX_HANDNUM; ++i) {
        _hand[i] = shoe.distribute();
    }
    _outwardlyNum = 1;//�ŏ��͂P���z����
    ScoreCalculation(_outwardlyNum);
}
void Person::Show() {//��D�Ɠ��_�̕\��
    cout << "----------------------------------------------" << endl;
    cout << _name << "�̎�D" << endl;
    for (int i = 0; i < _outwardlyNum; ++i) {
        switch (_hand[i] % 4 + 1)
        {
        case 1: printf("�X�y�[�h�@ : %d\n", _hand[i] % 13 + 1); break;
        case 2: printf("�n�[�g�@�@ : %d\n", _hand[i] % 13 + 1); break;
        case 3: printf("�_�C���@�@ : %d\n", _hand[i] % 13 + 1); break;
        case 4: printf("�N���[�o�[ : %d\n", _hand[i] % 13 + 1); break;
        }
    }
    printf("�_�� : %d\n", _score);
    cout << "----------------------------------------------" << endl;
}
void Person::Draw() {//�h���[
    if (_outwardlyNum < MAX_HANDNUM) {// 11���܂ł��������Ȃ�
        ++_outwardlyNum;
        ScoreCalculation(_outwardlyNum);
    }
    else {
        cout << "����ȏ�h���[�o���܂���" << endl;
    }
}
void Person::ScoreCalculation(int outwardlyNum) {//���_�v�Z
    _score = 0;//���_�����Z�b�g
    int ANum = 0;
    for (int i = 0; i < outwardlyNum; ++i) {

        int Num = _hand[i] % 13 + 1;//�D�̐��������Ƃ��Ă���

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