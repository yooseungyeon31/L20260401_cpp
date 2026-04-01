#include <iostream>
#include "SDL.h"


#pragma comment(lib, "SDL2")
#pragma comment(lib, "SDL2main")

using namespace std;

int SDL_main(int argc, char* argv[])
{
	SDL_Init(SDL_INIT_EVERYTHING); //윈도우 초기화
	

	//윈도우 가리키고 만들고
	SDL_Window* MyWindow = SDL_CreateWindow("MoveRect", 100, 100, 640, 480, SDL_WINDOW_SHOWN);

	//GPU, 붓
	SDL_Renderer* MyRender = SDL_CreateRenderer(MyWindow, -1, 0);


	//사각형 좌표
	int RectX = 0;
	int RectY = 0;



	//계속 실행
	while (true)
	{
		//
		SDL_Event MyEvent;
		while (SDL_PollEvent(&MyEvent)) //계속 물어보는거
		{
			//이벤트 타임이 나가기면 나가기
			if (MyEvent.type == SDL_QUIT)
			{
				break;
			}

			if (MyEvent.type == SDL_KEYDOWN)
			{
				switch (MyEvent.key.keysym.sym)
				{
				case SDLK_w: 
					RectY -= 20;
					break;
				case SDLK_s: 
					RectY += 20;
					break;
				case SDLK_a: 
					RectX -= 20;
					break;
				case SDLK_d: 
					RectX += 20;
					break;
				}

				if (RectX > 640)
				{
					RectX = -50;
				}
				if (RectY > 480)
				{
					RectY = -50;
				}
			}

		}

		//GPU한테 보낼 명령어 모음 
		//이거하고 이거해라 적은것
		SDL_SetRenderDrawColor(MyRender, 255, 255, 255, 255);
		SDL_RenderClear(MyRender);


		//사각형 그리기----------------------------------------------
		SDL_Rect rect = { RectX,RectY,50,50 };
		SDL_SetRenderDrawColor(MyRender, 255, 155, 255, 255);
		SDL_RenderFillRect(MyRender, &rect);
		//----------------------------------------------------------


		//이제 보내기
		SDL_RenderPresent(MyRender);

	}

	//랜더 한거 삭제
	SDL_DestroyRenderer(MyRender);
	//윈도우 삭제
	SDL_DestroyWindow(MyWindow);



	SDL_Quit();

	return 0;
}
