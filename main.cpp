
#include "DxLib.h"	
#include "Keyboard.h"


#define GAME_TITLE	"ゲームタイトル"	
#define GAME_WIDTH	1280				
#define GAME_HEIGHT	720					
#define GAME_COLOR  32					

#define GAME_ICON_ID	333				
#define GAME_WINDOW_BAR  0

enum GAME_SCENE {
	GAME_SCENE_TITLE,
	GAME_SCENE_PLAY,
	GAME_SCENE_END,
	GAME_SCENE_CHANGE
};

GAME_SCENE GameScene;
GAME_SCENE OldGameScene;
GAME_SCENE NextGameScene;
	
BOOL IsFadeOut = FALSE;
BOOL IsFadeIn  = FALSE;

VOID Title(VOID);
VOID TitleProc(VOID);
VOID TitleDraw(VOID);

VOID Play(VOID);
VOID PlayProc(VOID);
VOID PlayDraw(VOID);

VOID End(VOID);
VOID EndProc(VOID);
VOID EndDraw(VOID);

VOID Change(VOID);
VOID ChangeProc(VOID);
VOID ChangeDraw(VOID);

int WINAPI WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow)
{
	SetOutApplicationLogValidFlag(FALSE);
	ChangeWindowMode(TRUE);								
	SetMainWindowText(GAME_TITLE);						
	SetGraphMode(GAME_WIDTH, GAME_HEIGHT, GAME_COLOR);	
	SetWindowSize(GAME_WIDTH, GAME_HEIGHT);				
	SetBackgroundColor(255, 255, 255);					
	SetWindowIconID(GAME_ICON_ID);	           
	SetWindowStyleMode(GAME_WINDOW_BAR);
	SetWaitVSyncFlag(TRUE);
	SetAlwaysRunFlag(TRUE);


	
	if (DxLib_Init() == -1){ return -1 ;}
	SetDrawScreen(DX_SCREEN_BACK);

	int x = GAME_WIDTH / 2;
	int y = GAME_HEIGHT / 2;
	int radius = 50;

	GameScene = GAME_SCENE_TITLE;

	//∞ループ
	while (1)
	{
		
		if (ProcessMessage() != 0) { break; }
		if (ClearDrawScreen() != 0) { break; }

		AllKeyUpdate();

		if (KeyClick(KEY_INPUT_ESCAPE) == TRUE) { break; }

		if (GameScene != GAME_SCENE_CHANGE)
		{
			OldGameScene = GameScene;
		}

		switch (GameScene)
		{
		case GAME_SCENE_TITLE:
			Title();
			break;
		case GAME_SCENE_PLAY:
			Play();
			break;
		case GAME_SCENE_END:
			End();
			break;
		case GAME_SCENE_CHANGE:
			Change();
			break;
		default:
			break;
		}

		if (KeyDown(KEY_INPUT_W) == TRUE)
		{
			y--;
		}
		else if (KeyDown(KEY_INPUT_S) == TRUE)
		{
			y++;
		}

		if (KeyDown(KEY_INPUT_A) == TRUE)
		{
			x--;
		}
		else if (KeyDown(KEY_INPUT_D) == TRUE)
		{
			x++;
		}

		DrawCircle(x, y ,radius, GetColor(255, 255, 0), TRUE);

		ScreenFlip(); 
	}
	
	DxLib_End();

	return 0;	
}

VOID Title(VOID)
{
	TitleProc();
	TitleDraw();
	return;
}

VOID TitleProc(VOID)
{
	return;
}

VOID TitleDraw(VOID)
{
	DrawString(0, 0, "タイトル画面", GetColor(0, 0, 0));
	return;
}

VOID Play(VOID)
{
	PlayProc();
	PlayDraw();
	return;
}


VOID PlayProc(VOID)
{
	return;
}

VOID PlayDraw(VOID)
{
	DrawString(0, 0, "プレイ画面", GetColor(0, 0, 0));
	return;
}
VOID End(VOID)
{
	EndProc();
	EndDraw();
	return;
}

VOID EndProc(VOID)
{
	return;
}

VOID EndDraw(VOID)
{
	DrawString(0, 0, "エンド画面", GetColor(0, 0, 0));
	return;
}

VOID Change(VOID)
{
	ChangeProc();
	ChangeDraw();
	return;
}

VOID ChangeProc(VOID)
{
	return;
}

VOID ChangeDraw(VOID)
{
	DrawString(0, 0, "切り替え画面", GetColor(0, 0, 0));
	return;
}