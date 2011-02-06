#include "ScriptPCH.h"
#include "Object.h"

struct SystemInfo
{
	uint32 KillStreak;
    uint32 LastGUIDKill;
};

static std::map<uint32, SystemInfo> KillingStreak;

class System_OnPVPKill : public PlayerScript
{
        public:
                System_OnPVPKill() : PlayerScript("System_OnPVPKill") {}	

	void OnPVPKill(Player *killer, Player *killed)
	{
                uint32 kGUID; 
                uint32 vGUID;
                kGUID = killer->GetGUID();
                vGUID = killed->GetGUID();

				if (kGUID == vGUID)		// suicide @.@
                    return;

				KillingStreak[vGUID].KillStreak = 0;  // if die always reset
				KillingStreak[vGUID].LastGUIDKill = 0; // if die always reset
                
                if (!(KillingStreak[kGUID].LastGUIDKill == vGUID)) // dont let grind
				{
					if (!killer->GetGroup() || killer->InBattleground()) // dont count killstreak if grouped and not in BG or arena
					{
						KillingStreak[kGUID].KillStreak++;      // add 1 killstreak
						KillingStreak[kGUID].LastGUIDKill = vGUID; // remember last killed
                        if (killer->GetAreaId() == 513)
                            killer->ModifyMoney(2500);

						char str[200];
						sprintf(str,"Your KillStreak is %u !! Keep going!!", KillingStreak[kGUID].KillStreak);
						killer->MonsterWhisper(str,kGUID,true); //reminder
					}
				}

				if (killer->InArena() || killed->InArena())
					return;
	                
				switch(KillingStreak[kGUID].KillStreak)
				{
			        char msg[200];
                    case 25:
						sprintf(msg, "[Hardcore PvP System]: %s killed %s and is on a 25 killstreak. ", killer->GetName(), killed->GetName());
						sWorld->SendZoneText(killer->GetZoneId(), msg);
						killer->CastSpell(killer,42074,true);
						break;
                    case 50:
						sprintf(msg, "[Hardcore PvP System]: %s killed %s and is on a 50 killstreak. ", killer->GetName(), killed->GetName());
						sWorld->SendZoneText(killer->GetZoneId(), msg);
                        killer->CastSpell(killer,72100,true);
						break;
                    case 75:
						sprintf(msg, "[Hardcore PvP System]: %s killed %s and is on a 75 killstreak. ", killer->GetName(), killed->GetName());
						sWorld->SendZoneText(killer->GetZoneId(), msg);
						killer->CastSpell(killer,54142,true);
						break;
				}
	}
};

void AddSC_System_OnPVPKill()
{
    new System_OnPVPKill;
}