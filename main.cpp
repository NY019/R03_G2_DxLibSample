//�w�b�_�[�t�@�C���̓ǂݍ���
#include "DxLib.h"	//DxLib���g���Ƃ��͕K�v

//�}�N����`
#define GAME_TITLE	"�Q�[���^�C�g��"	//�Q�[���^�C�g��
#define GAME_WIDTH	1280				//�Q�[����ʂ̕�(�E�B�h�X)
#define GAME_HEIGHT	720					//�Q�[����ʂ̍���(�n�C�g)
#define GAME_COLOR  32					//�Q�[���̐F��

#define GAME_ICON_ID	333				//�Q�[����ICON��ID
#define GAME_WINDOW_BAR  0
// �v���O������ WinMain ����n�܂�܂�
//Windows�̃v���O���~���O���@ = (WinAPI)�œ����Ă���I
//DxLib�́ADirectX�Ƃ����A�Q�[���v���O���~���O�����񂽂�Ɏg����d�g��
int WINAPI WinMain(
	HINSTANCE hInstance, 
	HINSTANCE hPrevInstance, 
	LPSTR lpCmdLine, 
	int nCmdShow)
{
	SetOutApplicationLogValidFlag(FALSE);
	ChangeWindowMode(TRUE);								//�E�B���h�E���[�h�ɐݒ�
	SetMainWindowText(GAME_TITLE);						//�E�B���h�E�̃^�C�g���̕���
	SetGraphMode(GAME_WIDTH, GAME_HEIGHT, GAME_COLOR);	//�E�B���h�E�̉𑜓x��ݒ�
	SetWindowSize(GAME_WIDTH, GAME_HEIGHT);				//�E�B���h�E�̑傫����ݒ�
	SetBackgroundColor(255, 255, 255);					//�f�t�H���g�̔w�i�̐F
	SetWindowIconID(GAME_ICON_ID);	           //�A�C�R���t�@�C����Ǎ�
	SetWindowStyleMode(GAME_WINDOW_BAR);
	SetWaitVSyncFlag(TRUE);
	SetAlwaysRunFlag(TRUE);


	//�c�w���C�u��������������
	if (DxLib_Init() == -1)	
	{
		// �G���[���N�����璼���ɏI��
		return -1;
	}

	int x = GAME_WIDTH / 2;
	int y = GAME_HEIGHT / 2;

	int width = 32;
	int height = 32;

	int radius = 100;

	int Speed = 1;
	int XSpeed = Speed;
	int YSpeed = Speed;

	SetDrawScreen(DX_SCREEN_BACK);

	//�������[�v
	while (1)
	{
		//��������L�[�������ꂽ�Ƃ�
		if (CheckHitKeyAll() != 0)	//0�̂Ƃ��ɁA�����L�[�������ꂽ
		{
			break;	//�������[�v�𔲂���
		}

		//���b�Z�[�W���󂯎�葱����
		if (ProcessMessage() != 0)	//-1�̂Ƃ��A�G���[��E�B���h�E������ꂽ
		{
			break;	//�������[�v�𔲂���
		}

		if (ClearDrawScreen() != 0) { break; }

		//DrawBox(x, y, x + width, y + height, GetColor(255, 0, 0), TRUE);
		DrawCircle(x, y, radius, GetColor(0, 255, 0), FALSE, 5);
		x += XSpeed;
		y += YSpeed;

		if (x - radius < 0 || x + radius > GAME_WIDTH) {
			XSpeed = -XSpeed;

			if (XSpeed > 0) { XSpeed += 1; }
			else if (XSpeed < 0) { XSpeed -= 1; }
		}

		if (y - radius < 0 || y + radius > GAME_HEIGHT) {
			YSpeed = -YSpeed;
		}

		if (YSpeed > 0) { YSpeed += 1; }
		else if (YSpeed < 0) { YSpeed -= 1; }

		ScreenFlip();
	}


	//�c�w���C�u�����g�p�̏I������
	DxLib_End();

	return 0;	// �\�t�g�̏I�� 
}