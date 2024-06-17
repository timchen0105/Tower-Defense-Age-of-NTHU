#ifndef PLAYSCENE_HPP
#define PLAYSCENE_HPP
#include <allegro5/allegro_audio.h>
#include <list>
#include <memory>
#include <utility>
#include <vector>

#include "Engine/IScene.hpp"
#include "Engine/Point.hpp"

namespace Engine {
	class Group;
	class Image;
	class Label;
	class Sprite;
}  // namespace Engine

class PlayScene final : public Engine::IScene {
private:
	enum TileType {
		TILE_UNOCCUPIED,
		TILE_P1_OCCUPIED,
		TILE_P1_TERRITORY,
		TILE_P2_OCCUPIED,
		TILE_P2_TERRITORY,
		TILE_BOTH_TERRITORY
	};
	
protected:
	
public:
	static const std::vector<Engine::Point> directions;
	static const int MapWidth, MapHeight;
	static const int BlockSize;
	static const Engine::Point P1MainTowerGridPoint;
	static const Engine::Point P2MainTowerGridPoint;
	int gameMode;
	
	Group* TileMapGroup;
	Group* StructureGroup;
	Group* SoldierGroup;
	Group* UIGroup;

	std::vector<std::vector<TileType>> mapState;

	explicit PlayScene() = default;
	void Initialize() override;
	void Terminate() override;
	void Update(float deltaTime) override;
	void Draw() const override;
	void OnMouseDown(int button, int mx, int my) override;
	void OnMouseMove(int mx, int my) override;
	void OnMouseUp(int button, int mx, int my) override;
	void OnKeyDown(int keyCode) override;

	void UpdateTerritory(int x, int y, int player);
	void ConstructMap();
	void ConstructUI();
};
#endif // PLAYSCENE_HPP
