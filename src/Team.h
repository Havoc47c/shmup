#pragma once

#include <assert.h>
#include "SFML/Graphics.hpp"

class Team {
public:
	constexpr Team(unsigned int teamNumber) : team_index(teamNumber){
		assert(teamNumber >= 0 && teamNumber < MaxTeamCount);
	}

	bool operator==(const Team t) const;
private:
	constexpr static unsigned int MaxTeamCount = 4;
	unsigned int team_index;
};

sf::Color GetTeamColor(const Team t);

constexpr Team Team0{0u};
constexpr Team Team1{1u};
constexpr Team Team2{2u};
constexpr Team Team3{3u};
