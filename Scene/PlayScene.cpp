#include <allegro5/allegro.h>
 #include <allegro5/allegro_primitives.h>
#include <iostream>
#include <string>
#include "PlayScene.hpp"
#include "UI/Component/Image.hpp"

const std::vector<Engine::Point> PlayScene::directions = { 
	Engine::Point(-1, -1), Engine::Point(-1, 0), Engine::Point(-1, 1), 
	Engine::Point(0, -1), Engine::Point(0, 1), 
	Engine::Point(1, -1), Engine::Point(1, 0), Engine::Point(1, 1) };
const int PlayScene::MapWidth = 30, PlayScene::MapHeight = 30;
const int PlayScene::BlockSize = 32;
const Engine::Point PlayScene::P1MainTowerGridPoint = Engine::Point(0, 0);
const Engine::Point PlayScene::P2MainTowerGridPoint = Engine::Point(MapWidth - 1, MapHeight - 1);

void PlayScene::Initialize(){
	mapState.clear();
	AddNewObject(TileMapGroup = new Group());
	AddNewObject(UIGroup = new Group());
	ConstructMap();
	ConstructUI();
}

void PlayScene::Terminate(){
	IScene::Terminate();
}

void PlayScene::Update(float deltaTime){

}

void PlayScene::Draw() const {
	for (int i = 0; i < MapHeight; i++) {
		for (int j = 0; j < MapWidth; j++) {
			std::string path;
			switch (mapState[i][j])
			{
			case TILE_UNOCCUPIED:
				path = "play/unoccupied.png";
				break;
			case TILE_P1_OCCUPIED: case TILE_P1_TERRITORY:
				path = "play/p1_territory.png";
				break;
			case TILE_P2_OCCUPIED: case TILE_P2_TERRITORY:
				path = "play/p2_territory.png";
				break;
			default:
				path = "play/unoccupied.png";
				break;
			}
			TileMapGroup->AddNewObject(new Engine::Image(path, 420 + j * BlockSize, i * BlockSize, BlockSize, BlockSize));
		}
	}
	IScene::Draw();
}

void PlayScene::OnMouseDown(int button, int mx, int my) {

}
void PlayScene::OnMouseMove(int mx, int my) {

}
void PlayScene::OnMouseUp(int button, int mx, int my) {

}
void PlayScene::OnKeyDown(int keyCode) {
	
}

void PlayScene::UpdateTerritory(int x, int y, int player){
	for(Engine::Point diff : directions){
		int nowX = x + diff.x;
		int nowY = y + diff.y;
		if(nowX >= 0 && nowX < MapWidth && nowY >= 0 && nowY < MapHeight){
			if(mapState[nowY][nowX] == TILE_UNOCCUPIED){
				mapState[nowY][nowX] = (player == 1 ? TILE_P1_TERRITORY : TILE_P2_TERRITORY);
			} else if ((mapState[nowY][nowX] == TILE_P1_TERRITORY && player == 2) || 
						(mapState[nowY][nowX] == TILE_P2_TERRITORY && player == 1)) {
				mapState[nowY][nowX] = TILE_BOTH_TERRITORY;
			}
		}
	}
}

void PlayScene::ConstructMap(){
	mapState = std::vector<std::vector<TileType>>(MapHeight, std::vector<TileType>(MapWidth));
	for (int i = 0; i < MapHeight; i++) {
		for (int j = 0; j < MapWidth; j++) {
			mapState[i][j] = TILE_UNOCCUPIED;
		}
	}
	mapState[P1MainTowerGridPoint.x][P1MainTowerGridPoint.y] = TILE_P1_OCCUPIED;
	UpdateTerritory(P1MainTowerGridPoint.x, P1MainTowerGridPoint.y, 1);
	
	mapState[P2MainTowerGridPoint.x][P2MainTowerGridPoint.y] = TILE_P2_OCCUPIED;
	UpdateTerritory(P2MainTowerGridPoint.x, P2MainTowerGridPoint.y, 2);
}

void PlayScene::ConstructUI(){
	UIGroup->AddNewObject(new Engine::Image("play/sand.png", 0, 0, 420, 960));
	UIGroup->AddNewObject(new Engine::Image("play/sand.png", 1380, 0, 420, 960));
	//al_draw_rectangle(100, 100, 320, 320, )
}