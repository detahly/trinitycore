#include "ScriptPCH.h"

class welcome_script : public CreatureScript
{
    public:
        welcome_script() : CreatureScript("welcome_script") {}

    bool OnQuestAccept(Player* pPlayer, Creature* pCreature, Quest const* pQuest)
	{
		if (pQuest->GetQuestId() == 599998)
		{
			char str[200];
			sprintf(str,"Dear Players, We have a new champion joined our server. His name is %s ! LuminaWoW wishes %s good luck!", pPlayer->GetName(), pPlayer->GetName());
			pCreature->MonsterYell(str, LANG_UNIVERSAL, pPlayer->GetGUID());
			pCreature->HandleEmoteCommand(21);
		}
		return true;
	}

	bool OnQuestComplete(Player* pPlayer, Creature* pCreature, Quest const* pQuest)
	{
		if (pQuest->GetQuestId() == 599998)
		{
			pPlayer->SendPlaySound(11466, true);
		}
		return true;
	}
};

void AddSC_welcome_script()
{
    new welcome_script;
}