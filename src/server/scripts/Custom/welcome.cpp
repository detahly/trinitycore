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
			sprintf(str,"Welcome to District10. We hope you will enjoy our server! Don't forgot to invite your friends too!");
			pCreature->MonsterSay(str, LANG_UNIVERSAL, pPlayer->GetGUID());
			pCreature->HandleEmoteCommand(21);
		}
		return true;
	}
};

void AddSC_welcome_script()
{
    new welcome_script;
}