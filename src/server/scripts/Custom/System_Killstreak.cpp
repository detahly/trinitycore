#include "ScriptPCH.h"
#include "Object.h"

struct SystemInfo
{
	uint32 KillStreak;
    uint32 LastGUIDKill;
	uint32 DeathStreak;
};

static std::map<uint32, SystemInfo> KillingStreak;

class System_OnPVPKill : public PlayerScript
{
        public:
                System_OnPVPKill() : PlayerScript("System_OnPVPKill") {}

	void OnLogin(Player* pPlayer)
	{
		char str[200];
		sprintf(str,"Hello %s . Enjoy your stay on District 10!", pPlayer->GetName());
		pPlayer->MonsterWhisper(str,pPlayer->GetGUID(),true); //send welcome message ;) 
	}	

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
				KillingStreak[kGUID].DeathStreak = 0; //if kill deathstreak  = 0
				
				if (killer->GetGroup())
				{
					if (killer->InBattleground())
						KillingStreak[vGUID].DeathStreak++;  //add 1 deathstreak

				}
				else
					KillingStreak[vGUID].DeathStreak++;
                
                if (!(KillingStreak[kGUID].LastGUIDKill == vGUID)) // dont let grind
				{
					if (!killer->GetGroup() || killer->InBattleground()) // dont count killstreak if grouped and not in BG or arena
					{
						KillingStreak[kGUID].KillStreak++;      // add 1 killstreak
						KillingStreak[kGUID].LastGUIDKill = vGUID; // remember last killed
							if (killer->GetAreaId() == 3217)
								killer->AddItem(44990, 1);

                            if (killer->GetAreaId() == 15)
                                killer->AddItem(54637, 4);

						char str[200];
						sprintf(str,"Your KillStreak is %u !! Keep going!!", KillingStreak[kGUID].KillStreak);
						killer->MonsterWhisper(str,kGUID,true); //reminder
					}
				}

				if (killer->InArena() || killed->InArena())
					return;
	                
				switch(KillingStreak[kGUID].KillStreak)
				{
						case 2:
						{
							int x = urand(0,10);
							int RandomSpell[] = { 
								70788, 62398, 60342, 69861, 65712, 70571, 11010, 72523, 44800, 72100, 71994 };
								killer->CastSpell(killer,RandomSpell[x],true);
						}
						break;

					
						case 4:
						killer->CastSpell(killer,65828,true);
						break;

						case 5:
						char msg[500];
						sprintf(msg, "[District 10 PvP System]: %s killed %s and is on a 5 kill streak. ", killer->GetName(), killed->GetName());
						sWorld->SendZoneText(killer->GetZoneId(), msg);
						break;

						case 6:
						killer->CastSpell(killer,71586,true);
						break;

						case 8:
						killer->CastSpell(killer,24378,true);
						break;

						case 10:
						sprintf(msg, "[District 10 PvP System]: %s killed %s and is on a 10 kill streak. ", killer->GetName(), killed->GetName());
						sWorld->SendZoneText(killer->GetZoneId(), msg);
						killer->AddItem(45706, 2);
						break;

						case 20:
						sprintf(msg, "[District 10 PvP System]: %s killed %s and is on a 20 kill streak. ", killer->GetName(), killed->GetName());
						sWorld->SendZoneText(killer->GetZoneId(), msg);
						killer->AddItem(45706, 5);
						break;

						case 30:
						sprintf(msg, "[District 10 PvP System]: %s killed %s and is on a 30 kill streak. ", killer->GetName(), killed->GetName());
						sWorld->SendZoneText(killer->GetZoneId(), msg);
						killer->AddItem(45706, 8);
						break;

						case 40:
						sprintf(msg, "[District 10 PvP System]: %s killed %s and is on a 40 kill streak. ", killer->GetName(), killed->GetName());
						sWorld->SendZoneText(killer->GetZoneId(), msg);
						killer->AddItem(45706, 12);
						KillingStreak[kGUID].KillStreak = 0;
						break;
				}

				switch (KillingStreak[vGUID].DeathStreak)
				{
					case 5:
					killed->ResurrectPlayer(1.0f);
					killed->SetPower(POWER_MANA, killed->GetMaxPower(POWER_MANA));
					killed->SpawnCorpseBones();
					killed->SaveToDB();
					killed->CastSpell(killed,21074,true); //visual ress
					killed->CastSpell(killed,24378,true);  //cast buff
					killed->CastSpell(killed,71586,true); //cast shield
					killed->RemoveArenaSpellCooldowns();
					char msg[500];
					sprintf(msg, "%s is on 5 deathstreak and has been ressed! ",killed->GetName());
					sWorld->SendZoneText(killer->GetZoneId(), msg);
					KillingStreak[vGUID].DeathStreak++; // sometimes it dont count :(
					break;
				}
	}
};

void AddSC_System_OnPVPKill()
{
    new System_OnPVPKill;
}