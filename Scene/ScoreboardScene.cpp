#include <functional>
#include <string>
#include <fstream>
#include <iostream>
#include "Engine/GameEngine.hpp"
#include "UI/Component/Image.hpp"
#include "UI/Component/ImageButton.hpp"
#include "UI/Component/Label.hpp"
#include "Engine/Point.hpp"
#include "Engine/Record.hpp"
#include "ScoreboardScene.hpp"

void ScoreboardScene::Initialize() {
	int w = Engine::GameEngine::GetInstance().GetScreenSize().x;
    int h = Engine::GameEngine::GetInstance().GetScreenSize().y;
    int halfW = w / 2;
    int halfH = h / 2;

    Engine::ImageButton *btn;

	AddNewObject(new Engine::Label("Scoreboard", "pirulen.ttf", 48, halfW, halfH / 6, 225, 255, 0, 255, 0.5, 0.5));

	btn = new Engine::ImageButton("stage-select/dirt.png", "stage-select/floor.png", halfW - 200, halfH * 5 / 3,
                                  400, 100);
    btn->SetOnClickCallback(std::bind(&ScoreboardScene::BackOnClick, this));
    AddNewControlObject(btn);
    AddNewObject(new Engine::Label("Back", "pirulen.ttf", 48, halfW, halfH * 5 / 3 + 50, 0, 0, 0, 255, 0.5, 0.5));

	btn = new Engine::ImageButton("stage-select/dirt.png", "stage-select/floor.png", halfW - 700, halfH * 5 / 3,
                                  400, 100);
    btn->SetOnClickCallback(std::bind(&ScoreboardScene::PrevPageOnClick, this));
    AddNewControlObject(btn);
    AddNewObject(new Engine::Label("Prev Page", "pirulen.ttf", 48, halfW - 500, halfH * 5 / 3 + 50, 0, 0, 0, 255, 0.5, 0.5));

	btn = new Engine::ImageButton("stage-select/dirt.png", "stage-select/floor.png", halfW + 300, halfH * 5 / 3,
                                  400, 100);
    btn->SetOnClickCallback(std::bind(&ScoreboardScene::NextPageOnClick, this));
    AddNewControlObject(btn);
    AddNewObject(new Engine::Label("Next Page", "pirulen.ttf", 48, halfW + 500, halfH * 5 / 3 + 50, 0, 0, 0, 255, 0.5, 0.5));
}
void ScoreboardScene::Terminate() {
	IScene::Terminate();
}
void ScoreboardScene::PrevPageOnClick(){
    scoreboardPage--;
    if(scoreboardPage < 0){
        scoreboardPage = 0;
    }
}
void ScoreboardScene::NextPageOnClick(){
    if(scoreRecords.size() == 0) return;
    scoreboardPage++;
    if(scoreboardPage > (scoreRecords.size() - 1) / numberPerPage){
        scoreboardPage = (scoreRecords.size() - 1) / numberPerPage;
    }
}
void ScoreboardScene::BackOnClick() {
	Engine::GameEngine::GetInstance().ChangeScene("start");
}

void ScoreboardScene::Draw() const {
    IScene::Draw();
    int w = Engine::GameEngine::GetInstance().GetScreenSize().x;
	int h = Engine::GameEngine::GetInstance().GetScreenSize().y;
    int halfW = w / 2;
	int halfH = h / 2;
    auto it = scoreRecords.begin();
    for(int i = 1; i <= scoreboardPage * numberPerPage; i++){
        it++;
    }
    for(int i = 1; i <= numberPerPage; i++){
        if(it == scoreRecords.end()) break;
        Engine::Label rank("#"+std::to_string(scoreboardPage * numberPerPage + i), "pirulen.ttf", 24, halfW - 450, halfH / 5 + i * leading, 0, 0, 0, 255, 0.5, 0.5);
        rank.Draw();
        Engine::Label name((*it).name, "pirulen.ttf", 24, halfW - 250, halfH / 5 + i * leading, 255, 255, 255, 255, 0.5, 0.5);
        name.Draw();
        Engine::Label score(std::to_string((*it).score), "pirulen.ttf", 24, halfW + 50, halfH / 5 + i * leading, 255, 255, 255, 255, 0.5, 0.5);
        score.Draw();
        Engine::Label time((*it).time, "pirulen.ttf", 20, halfW + 350, halfH / 5 + i * leading, 255, 255, 255, 255, 0.5, 0.5);
        time.Draw();
        it++;
    }
}