/*
|WiiYourself!�֐��ꗗ 2014�N8��7��16��54��
|http://file.keanwortd.o-oi.net/wiiyourself_functions_reference.html
|
|�Q�l�T�C�g
|http://y-okamoto-psy1949.la.coocan.jp/VCpp/easyvcpp2012/
*/

#include "MainForm.h"	//�t�H�[���̃t�@�C�����C���N���[�h
#include "wiimote.h"	//WiiYourself!�̃��C�u�������C���N���[�h
#include <iostream>




// WiiYourself!���C�Z���X��
#define WII_YOURSELF_LICENSE_WSTRING L"contains WiiYourself! wiimote code by gl.tter\nhttp://gl.tter.org\n"

using namespace Test_GUI_WiiYourself_20140807; //�t�H�[�����錾����Ă��閼�O���
[STAThreadAttribute]	//COM�֌W�̃G���[������邽�߂̐錾�BOpenFileDialog�N���X��ShowDialog���\�b�h�Ȃǂ̌Ăяo�����s���Ƃ��ɂ�STA���[�h�łȂ���΂Ȃ�Ȃ�
int main(){
	MainForm fm;	//�t�H�[���̕ϐ� fm �̒�`
	fm.ShowDialog();	//�t�H�[���̕\���B���̊֐��̓t�H�[����������܂Ŏ��s���ƂȂ�B

//�ȉ����C���v���O�������͋L�q

	wiimote remote;

	//wii�����R���ڑ������܂őҋ@
	while (!remote.Connect(wiimote::FIRST_AVAILABLE)) Sleep(1);
	remote.SetReportType(wiimote::IN_BUTTONS_ACCEL_IR);

	//�ڑ��ς�
	if (remote.IsConnected()){
		//printf("OK!\n");
		remote.SetLEDs(0x1);
	}

	while (true){
		//wii�����R���̃f�[�^���X�V
		remote.RefreshState();

		//A�{�^����ONOFF�ɂ����Wii�����R����LED�_���p�^�[����ύX(����`�F�b�N�ړI)
		if (remote.Button.A() == true){
			remote.SetLEDs(0x1);
			std::cout << "	A = true" << std::endl;
		}else if (remote.Button.A() == false){
			remote.SetLEDs(0x8);
			std::cout << "	A = false" << std::endl;
		}
		
		//HOME�{�^���Ńv���O�����I��
		if (remote.Button.Home() == true){
			return 0;
		}
	}

	return 0;
}