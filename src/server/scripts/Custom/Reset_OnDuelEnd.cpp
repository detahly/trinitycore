#include "ScriptPCH.h"

class Reset_OnDuelEnd : public PlayerScript
{
    public:
        Reset_OnDuelEnd() : PlayerScript("Reset_OnDuelEnd") {}

    void OnDuelEnd(Player *winner, Player *looser, DuelCompleteType type)
    {
        // reset cooldowns in durotar and dunmorogh
                if (winner->GetZoneId() == 148 || winner->GetZoneId() == 440 || winner->GetZoneId() == 4395 || winner->GetAreaId() == 1)
                {
                        winner->RemoveArenaSpellCooldowns();
                        looser->RemoveArenaSpellCooldowns();
                        winner->SetHealth(winner->GetMaxHealth());
                        winner->SetPower(POWER_MANA, winner->GetMaxPower(POWER_MANA));
                        looser->SetHealth(looser->GetMaxHealth());
                        looser->SetPower(POWER_MANA, looser->GetMaxPower(POWER_MANA));
                }
    }

};

void AddSC_Reset_OnDuelEnd()
{
    new Reset_OnDuelEnd;
}