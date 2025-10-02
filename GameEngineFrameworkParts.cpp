// GameEngineFrameworkParts.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
//

#include <iostream>
#include "Mainframe.h"

int main()
{
	Mainframe* mainframe = new Mainframe();

	mainframe->addDamageListeners(EventTypeEnum::DAMAGE, *(new float(50.0f)), *(new DamageTypeEnum(DamageTypeEnum::PHYSICAL)));
	mainframe->addKeyboardListeners(EventTypeEnum::KEYBOARD);
	mainframe->addMouseListeners(EventTypeEnum::MOUSE);

    std::cout << "Hello World!\n";
}