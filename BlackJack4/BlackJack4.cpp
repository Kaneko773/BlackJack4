// BlackJack4.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include "CardSet.h"
#include "Person.h"
#include "Player.h"
#include "Dealer.h"
using namespace std;

void GeneralInformationShow(Person& player, Person& dealer);

int main()
{
    CardSet Shoe;
    Player player(Shoe, "Player");
    Dealer dealer(Shoe, "Dealer");

    int input = 0;

    do {
        player.Draw();
        GeneralInformationShow(player, dealer);
        if (!player.ContinuJudge()) break;
        do {
            cout << "1:スタンド　2:ヒット \n ＞ " << flush;
            cin >> input;
        } while (input < 1 || 2 < input);
        if (input == 1) break;
    } while (true);

    if (player.get_score() <= 21) {//プレイヤーがバーストしてたら終了
        do {
            dealer.Draw();
            GeneralInformationShow(player, dealer);
        } while (dealer.ContinuJudge());
    }

    //結果表示
    if (!player.ContinuJudge() ||
        (dealer.get_score() <= 21 && player.get_score() < dealer.get_score())) {
        cout << "ディーラーの勝利!!" << endl;
    }
    else if (dealer.get_score() > 21 || player.get_score() > dealer.get_score()) {
        cout << "プレイヤーの勝利!!" << endl;
    }
    else {
        cout << "引き分け" << endl;
    }
}

void GeneralInformationShow(Person& player, Person& dealer) {
    system("cls");
    player.Show();
    dealer.Show();
}

// プログラムの実行: Ctrl + F5 または [デバッグ] > [デバッグなしで開始] メニュー
// プログラムのデバッグ: F5 または [デバッグ] > [デバッグの開始] メニュー
// 作業を開始するためのヒント: 
//    1. ソリューション エクスプローラー ウィンドウを使用してファイルを追加/管理します 
//   2. チーム エクスプローラー ウィンドウを使用してソース管理に接続します
//   3. 出力ウィンドウを使用して、ビルド出力とその他のメッセージを表示します
//   4. エラー一覧ウィンドウを使用してエラーを表示します
//   5. [プロジェクト] > [新しい項目の追加] と移動して新しいコード ファイルを作成するか、[プロジェクト] > [既存の項目の追加] と移動して既存のコード ファイルをプロジェクトに追加します
//   6. 後ほどこのプロジェクトを再び開く場合、[ファイル] > [開く] > [プロジェクト] と移動して .sln ファイルを選択します
