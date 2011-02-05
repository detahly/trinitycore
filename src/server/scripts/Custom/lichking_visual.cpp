#include "ScriptPCH.h"


enum
{
    SPELL_ARMY_DEAD = 67761,
    SPELL_DEATH_BITE      = 67875, // phase 3, phase 1, aeo
    SPELL_ICY_TOUCH = 67881, // phase 2, tank 
    SPELL_DEADEN = 41410, // phase 2, tank
    SPELL_STUN = 51750,  // phase 1, aoe
    SPELL_HARVEST_SOUL = 68980, //phase 3, random
    SPELL_BERSERK = 47008,

    PHASE_ONE = 1,
    PHASE_TWO = 2,
    PHASE_THREE = 3,

    TEXT_DIE = -2000012,
    TEXT_KILL = -2000013

};

class lichking_visual : public CreatureScript
{
    public:

        lichking_visual()
            : CreatureScript("lichking_visual")
        {
        }

        struct lichking_visualAI : public ScriptedAI
        {
            //*** HANDLED FUNCTION ***
            //This is the constructor, called only once when the Creature is first created
            lichking_visualAI(Creature *c) : ScriptedAI(c) {
			}
            std::list<uint64> SummonList;

            //*** CUSTOM VARIABLES ****
            //These variables are for use only by this individual script.
            //Nothing else will ever call them but us.
			

            uint8 phase;
            uint32 DeathArmyCheckTimer;
            uint32 BerserkTimer;
            uint32 HarverstsoulTimer;
            uint32 HarverstsoulDoneTimer;
            uint32 StunTimer;
            uint32 DeadenTimer;
            uint32 IcytouchTimer;
            uint32 DeathbiteTimer;
            uint32 DeathAndDecayTimer;
            bool DeathArmyDone;
            bool SummonArmy;
            bool harvestsoul;
            bool harvestsoulDone;

            //*** HANDLED FUNCTION ***
            //This is called after spawn and whenever the core decides we need to evade
            void Reset()
            {
                RemoveSummons();
                me->ClearUnitState(UNIT_STAT_ROOT | UNIT_STAT_STUNNED);

                phase = PHASE_ONE;

                DeathArmyCheckTimer = 7000;
                SummonArmy = false;
                DeathArmyDone = false;
                harvestsoul = false;
                harvestsoulDone = true;

                BerserkTimer = 360000;
                HarverstsoulTimer = 8000;
                HarverstsoulDoneTimer = 5000; 
                StunTimer = 8000;
                DeadenTimer = 26000;
                IcytouchTimer = 15000;
                DeathbiteTimer = 7000;
                DeathAndDecayTimer = 8000;
				
            }

            void RemoveSummons()
            {
                if (SummonList.empty())
                    return;

                for (std::list<uint64>::const_iterator itr = SummonList.begin(); itr != SummonList.end(); ++itr)
                {
                    if (Creature* pTemp = Unit::GetCreature(*me, *itr))
                        if (pTemp)
                            pTemp->DisappearAndDie();
                }
                SummonList.clear();
            }

            void JustSummoned(Creature* pSummon)
            {
                SummonList.push_back(pSummon->GetGUID());
                pSummon->AI()->AttackStart(me->getVictim());
            }

            void MoveInLineOfSight(Unit *pWho)
            {
                if (pWho->GetTypeId() != TYPEID_PLAYER && me->IsInRange(pWho,0,2,false))
                {
                    if (pWho->isAlive())
                    {
                        switch (pWho->GetEntry())
                        {
                        case 400000:
                        case 400001:
                             DoCast(pWho, 41080); //consume soul
                             DoScriptText(TEXT_KILL, me);
                            break;
                        default:
                            break;

                        }
                    }
                }
            }

           
            //*** HANDLED FUNCTION ***
            //Update AI is called Every single map update (roughly once every 50ms if a player is within the grid)
            void UpdateAI(const uint32 uiDiff)
            {
                //Return since we have no target
                if (!UpdateVictim())
                    return;

                if (!me->HasAura(SPELL_BERSERK))
                {
                    if (BerserkTimer <= uiDiff)
                    {
                        DoCast(me, SPELL_BERSERK); 
                    }
                    else BerserkTimer -= uiDiff;
                }
                //phase handler
                if (phase == PHASE_ONE && HealthBelowPct(65))
                {
                    phase = PHASE_TWO;
                    SummonArmy = false;
                    DeathArmyDone = false;
                }
                else if(phase == PHASE_TWO && HealthBelowPct(35))
                {
                    phase = PHASE_THREE;
                    SummonArmy = false;
                    DeathArmyDone = false;
                }


                if (!SummonArmy)
                    {
                        SummonArmy = true;
                        me->AddUnitState(UNIT_STAT_ROOT | UNIT_STAT_STUNNED);
                        DoCast(me, SPELL_ARMY_DEAD);
                    }

                if (!DeathArmyDone && SummonArmy)
                {
                    if (DeathArmyCheckTimer <= uiDiff)
                    {
                        me->ClearUnitState(UNIT_STAT_ROOT | UNIT_STAT_STUNNED);
                        DeathArmyDone = true;
                        DeathArmyCheckTimer = 7000;
                    } else DeathArmyCheckTimer -= uiDiff;

                }

                switch(phase)
                {
                case PHASE_ONE:
                {
                    if (DeathbiteTimer <= uiDiff)
                    {
                        DoCastAOE(SPELL_DEATH_BITE);
                        DeathbiteTimer = urand (12000, 13000);
                    } else DeathbiteTimer -= uiDiff;
                    
                    if (StunTimer <= uiDiff)
                    {
                        DoCastAOE(SPELL_STUN);
                        StunTimer = 34000;

                    } else StunTimer -= uiDiff;

                    break;
                }
                case PHASE_TWO:
                {                    
                    if (IcytouchTimer <= uiDiff)
                    {
                        DoCast(me->getVictim(), SPELL_ICY_TOUCH);
                        IcytouchTimer = 9800;
                    } else IcytouchTimer -= uiDiff;

                    if (DeadenTimer <= uiDiff)
                    {
                        DoCast(me->getVictim(), SPELL_DEADEN);
                        DeadenTimer = 15000;
                    } else DeadenTimer -= uiDiff;

                    if (DeathAndDecayTimer <= uiDiff)
                    {
                        if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 40, true))
                            DoCast(pTarget, 61603); //death and decay

                        DeathAndDecayTimer = 14000;
                    } else DeathAndDecayTimer -= uiDiff;

                    break;
                }
                case PHASE_THREE:
                {
                    if (DeathbiteTimer <= uiDiff)
                    {
                        DoCastAOE(SPELL_DEATH_BITE);
                        DeathbiteTimer = urand (10000, 12000);
                    } else DeathbiteTimer -= uiDiff;
                    
                    if (!harvestsoul)
                    {
                        if (HarverstsoulTimer <= uiDiff)
                        {
                            if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 40, true))
                            {
                                if (pTarget)
                                {
                                    me->AddUnitState(UNIT_STAT_ROOT | UNIT_STAT_STUNNED);
                                    DoCast(pTarget,SPELL_HARVEST_SOUL);
                                    HarverstsoulTimer = 12000;
                                    harvestsoul = true;
                                    harvestsoulDone = false;
                                }
                            }
                        }
                        else HarverstsoulTimer -= uiDiff;
                    }
                    if (!harvestsoulDone) {
                        if (HarverstsoulDoneTimer <= uiDiff)
                        {
                            me->InterruptNonMeleeSpells(true, SPELL_HARVEST_SOUL, true);
                            harvestsoul = false;
                            harvestsoulDone = true;
                            HarverstsoulDoneTimer = 5000;
                            me->ClearUnitState(UNIT_STAT_ROOT | UNIT_STAT_STUNNED);
                        
                        } else HarverstsoulDoneTimer -= uiDiff;
                    }
                    break;
                }
                }



				DoMeleeAttackIfReady();
            }

            void JustDied(Unit* /*pKiller*/)
            {
                DoScriptText(TEXT_DIE, me);
            }

        };

        CreatureAI* GetAI(Creature* pCreature) const
        {
            return new lichking_visualAI(pCreature);
        }

};

//This is the actual function called only once durring InitScripts()
//It must define all handled functions that are to be run in this script
void AddSC_lichking_visual()
{
    new lichking_visual();
}
