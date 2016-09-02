#pragma once
#include <iostream>
#include <vector>
#include <string>
#ifndef Component_h
#include "Component.h"
#endif

using namespace std;
extern int counter;
extern int NamCounter;
extern int TagCounter;
extern vector <string> AllNames;
extern vector <string> AllTags;

#ifndef Entity_h
#include "Entity.h"
extern vector <Entity*> AllEntities;
extern Entity* lastEntity;
void AddToAllENT(Entity*);
Entity* GetEntityName(string);
Entity* GetEntityTag(string);
Entity* GetEntity(string, string);
Entity* GetEntity(int);
void Kill(Entity*);
void KillName(string);
void KillTag(string);
void Kill(string, string);
void Kill(int);
void PrintNumberOfEntities();
int NumberOfEntities();
#endif

int GetCounter();
int GetNamCounter();
int GetTagCounter();
string UniqueName(string uN = "lol");
string UniqueTag(string uT = "lol");

//void* Create(Entity* prefab){
//	Entity* cop = new Entity(true);
//	cop->SetAll(prefab->GetName(), prefab->GetTag());
//	return &cop;
//}