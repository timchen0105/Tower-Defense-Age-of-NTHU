#ifndef GAMEMODESELECTSCENE_HPP
#define GAMEMODESELECTSCENE_HPP
#include <allegro5/allegro_audio.h>
#include <memory>
#include "Engine/IScene.hpp"

class GameModeSelectScene final : public Engine::IScene {
private:
	std::shared_ptr<ALLEGRO_SAMPLE_INSTANCE> bgmInstance;
public:
	explicit GameModeSelectScene() = default;
	void Initialize() override;
	void Terminate() override;
	void PlayOnClick(int stage);
    void ScoreboardOnClick();
	void BackOnClick(int stage);
};

#endif // GAMEMODESELECTSCENE_HPP
