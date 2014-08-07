/*
|WiiYourself!関数一覧 2014年8月7日16時54分
|http://file.keanwortd.o-oi.net/wiiyourself_functions_reference.html
|
|参考サイト
|http://y-okamoto-psy1949.la.coocan.jp/VCpp/easyvcpp2012/
*/

#include "MainForm.h"	//フォームのファイルをインクルード
#include "wiimote.h"	//WiiYourself!のライブラリをインクルード
#include <iostream>




// WiiYourself!ライセンス文
#define WII_YOURSELF_LICENSE_WSTRING L"contains WiiYourself! wiimote code by gl.tter\nhttp://gl.tter.org\n"

using namespace Test_GUI_WiiYourself_20140807; //フォームが宣言されている名前空間
[STAThreadAttribute]	//COM関係のエラーを避けるための宣言。OpenFileDialogクラスのShowDialogメソッドなどの呼び出しを行うときにはSTAモードでなければならない
int main(){
	MainForm fm;	//フォームの変数 fm の定義
	fm.ShowDialog();	//フォームの表示。この関数はフォームが閉じられるまで実行中となる。

//以下メインプログラム自力記述

	wiimote remote;

	//wiiリモコン接続完了まで待機
	while (!remote.Connect(wiimote::FIRST_AVAILABLE)) Sleep(1);
	remote.SetReportType(wiimote::IN_BUTTONS_ACCEL_IR);

	//接続済み
	if (remote.IsConnected()){
		//printf("OK!\n");
		remote.SetLEDs(0x1);
	}

	while (true){
		//wiiリモコンのデータを更新
		remote.RefreshState();

		//AボタンのONOFFによってWiiリモコンのLED点灯パターンを変更(動作チェック目的)
		if (remote.Button.A() == true){
			remote.SetLEDs(0x1);
			std::cout << "	A = true" << std::endl;
		}else if (remote.Button.A() == false){
			remote.SetLEDs(0x8);
			std::cout << "	A = false" << std::endl;
		}
		
		//HOMEボタンでプログラム終了
		if (remote.Button.Home() == true){
			return 0;
		}
	}

	return 0;
}