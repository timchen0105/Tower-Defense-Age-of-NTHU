// [main.cpp]
// This is the entry point of your game.
// You can register your scenes here, and start the game.
#include "Engine/GameEngine.hpp"
#include "Engine/LOG.hpp"
#include "Engine/Record.hpp"
#include "Scene/PlayScene.hpp"
#include "Scene/GameModeSelectScene.hpp"
#include "Scene/StartScene.h"
#include "Scene/ScoreboardScene.hpp"
#include "Scene/SettingsScene.hpp"

int main(int argc, char **argv) {
	Engine::LOG::SetConfig(true);
	Engine::GameEngine& game = Engine::GameEngine::GetInstance();
	ReadScoreRecords();

    // TODO: [HACKATHON-1-SCENE] (3/4): Register Scenes here
	game.AddNewScene("start", new StartScene());
	game.AddNewScene("scoreboard", new ScoreboardScene());
	game.AddNewScene("settings", new SettingsScene());
	game.AddNewScene("gamemode-select", new GameModeSelectScene());
	game.AddNewScene("play", new PlayScene());

    // TODO: [HACKATHON-1-SCENE] (4/4): Change the start scene
//	game.Start("stage-select", 60, 1600, 832);
	game.Start("start", 60, 1800, 960);
	return 0;
}
