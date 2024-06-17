#ifndef SCOREBOARDSCENE_HPP
#define SCOREBOARDSCENE_HPP
#include <allegro5/allegro_audio.h>
#include <list>
#include <memory>
#include <utility>
#include <set>

#include "Engine/IScene.hpp"
#include "Engine/Point.hpp"

class ScoreboardScene final : public Engine::IScene {
private:
	float ticks;
	ALLEGRO_SAMPLE_ID bgmId;
public:
	int scoreboardPage = 0;
	int numberPerPage = 10;
	int leading = 50;
	explicit ScoreboardScene() = default;
	void Initialize() override;
	void Terminate() override;
	void PrevPageOnClick();
	void NextPageOnClick();
	void BackOnClick();
	void Draw() const override;
};

#endif // SCOREBOARDSCENE_HPP
