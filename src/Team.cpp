#include "Team.h"

bool Team::operator==(const Team other) const {
	return team_index == other.team_index;
}

sf::Color GetTeamColor(const Team t) {
	if (t == Team0)
		return sf::Color::White;
	else if (t == Team1)
		return sf::Color::Red;
	else if (t == Team2) 
		return sf::Color::Green;
	else if (t == Team3) 
		return sf::Color::Blue;
	else
		return sf::Color::Cyan;
}
