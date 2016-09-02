#include "Public.h"
#include "General.h"

#define GameRunning true

int main()
{
	Initialize();
	for (int i = 0; i < AllEntities.size(); i++)
		AllEntities.at(i)->Start();
	while (GameRunning)
	{
		GlobalUpdate;
		for (int i = 0; i < AllEntities.size(); i++)
			AllEntities.at(i)->Update();
	}
	return 0;
}