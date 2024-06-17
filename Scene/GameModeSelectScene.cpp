#include <allegro5/allegro_audio.h>
#include <functional>
#include <memory>
#include <string>

#include "Engine/AudioHelper.hpp"
#include "Engine/GameEngine.hpp"
#include "UI/Component/ImageButton.hpp"
#include "UI/Component/Label.hpp"
#include "PlayScene.hpp"
#include "Engine/Point.hpp"
#include "Engine/Resources.hpp"
#include "UI/Component/Slider.hpp"
#include "GameModeSelectScene.hpp"

void GameModeSelectScene::Initialize() {
    int w = Engine::GameEngine::GetInstance().GetScreenSize().x;
    int h = Engine::GameEngine::GetInstance().GetScreenSize().y;
    int halfW = w / 2;
    int halfH = h / 2;
    Engine::ImageButton* btn;
    btn = new Engine::ImageButton("stage-select/dirt.png", "stage-select/floor.png", halfW - 200, halfH * 3 / 2 - 50, 400, 100);
    btn->SetOnClickCallback(std::bind(&GameModeSelectScene::BackOnClick, this, 1));
    AddNewControlObject(btn);
    AddNewObject(new Engine::Label("Back", "pirulen.ttf", 48, halfW, halfH * 3 / 2, 0, 0, 0, 255, 0.5, 0.5));

    btn = new Engine::ImageButton("stage-select/dirt.png", "stage-select/floor.png", halfW - 200, halfH / 2 - 50, 400, 100);
    btn->SetOnClickCallback(std::bind(&GameModeSelectScene::PlayOnClick, this, 1));
    AddNewControlObject(btn);
    AddNewObject(new Engine::Label("Single Player", "pirulen.ttf", 36, halfW, halfH / 2, 0, 0, 0, 255, 0.5, 0.5));
    
    btn = new Engine::ImageButton("stage-select/dirt.png", "stage-select/floor.png", halfW - 200, halfH /2 + 100, 400, 100);
    btn->SetOnClickCallback(std::bind(&GameModeSelectScene::PlayOnClick, this, 2));
    AddNewControlObject(btn);
    AddNewObject(new Engine::Label("Multiplayer", "pirulen.ttf", 36, halfW, halfH / 2 +150, 0, 0, 0, 255, 0.5, 0.5));

    btn = new Engine::ImageButton("stage-select/dirt.png", "stage-select/floor.png", halfW - 200, halfH / 2 + 250, 400, 100);
    btn->SetOnClickCallback(std::bind(&GameModeSelectScene::ScoreboardOnClick, this));
    AddNewControlObject(btn);
    AddNewObject(new Engine::Label("Scoreboard", "pirulen.ttf", 36, halfW, halfH / 2 + 300, 0, 0, 0, 255, 0.5, 0.5));

    // Not safe if release resource while playing, however we only free while change scene, so it's fine.
	bgmInstance = AudioHelper::PlaySample("select.ogg", true, AudioHelper::BGMVolume);
}
void GameModeSelectScene::Terminate() {
	AudioHelper::StopSample(bgmInstance);
	bgmInstance = std::shared_ptr<ALLEGRO_SAMPLE_INSTANCE>();
	IScene::Terminate();
}
void GameModeSelectScene::BackOnClick(int stage) {
    Engine::GameEngine::GetInstance().ChangeScene("start");
}
void GameModeSelectScene::PlayOnClick(int gameMode) {
    PlayScene* scene = dynamic_cast<PlayScene*>(Engine::GameEngine::GetInstance().GetScene("play"));
    scene->gameMode = gameMode;
    Engine::GameEngine::GetInstance().ChangeScene("play");
}
void GameModeSelectScene::ScoreboardOnClick() {
    Engine::GameEngine::GetInstance().ChangeScene("scoreboard");
}