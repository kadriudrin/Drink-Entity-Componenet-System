# DrInK-ECS
(WIP) Simplified Unity3D like C++ Entity Component System.
as of now DrInK ECS doesn't support multiple scenes, nor complex systems, only the simple and basic Unity3D like ECS !

# Tutorial

'Main.cpp' basically handles Start and Update of every Entity Created.
'Initialization.cpp' basically handles Entity Creation, Adding Components to them, and the overall scene logic.
in 'General.h' you have to manually include all created Component classes.

simple examples:

# Entity Creation:

Entity entityName() // default constructor give the name "Entity"+NameNumber, the tag "Tag"+TagNumber, and the unique ID ""+IdNumber, where all these numbers are integers that increase everytime a new entity is created!, so no 2 entities can have the same ID, even if you give them the same name and tag !

these are other ways you can create entities!

Entity entityName("name")

Entity entityName("name", "tag")

# Removing Entities:

Kill(entityName) // basically kills the given entity
Kill("name", "tag") // kill the first entity with the given name and tag
KillName("name") // kill the first entity with that name
KillTag("tag") // kill the first entity with that tag
Kill(0) // kill the entity with ID of '0'

# Component Creation:

to create a new component, you need to create a new C++ class, that inherits from the class "Component", and you must include the new component in the file 'General.h'

'DisplayText.h':

#pragma once
#include "Component.h"
class DisplayText :
	public Component
{
public:
	DisplayText() : Component("DisplayText"){};
	virtual void Start(){
		cout << "Printed On Start" << endl;
	};
	virtual void Update(){
		cout << "Printing on Update" << endl;
	};
	~DisplayText();
};

// If you would want to use Entities, or the standart library, just #include "Public.h" in 'DisplayText.cpp'

# Adding, Removing, Getting Components

Entity ent1("name");
ent1.AddComponent(new DisplayText()); // adds the argument as a component to ent1, so you can have already existing Components and just pass their reference as argument !

ent1.RemoveComponent<DisplayText>(); // Removes the given component

DisplayText *dT = ent1.GetComponent<DisplayText>(); // now when you change something in the variable dT it will apply to the component of the entity !

# Contribute

you can condribute by finding bugs, and suggesting changes, every contribution is apprecieated !
