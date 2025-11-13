#include <iostream>
#include <string>

#include "BattleField.h"

int main()
{
	std::string terranFleetComposition;
	std::string protossFleetCompositon;

	std::cin >> terranFleetComposition >> protossFleetCompositon;

	BattleField battleField;

	battleField.generateTerranFleet(terranFleetComposition);
	battleField.generateProtossFleet(protossFleetCompositon);

	battleField.startBattle();

	return 0;
}

