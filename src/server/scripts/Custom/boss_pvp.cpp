#include "ScriptPCH.h"


enum
{
	SPELL_DIVINESHIELD	= 40733,
	SPELL_EARTHQUAKE	= 42499,
	SPELL_BLADESTORM	= 67541, //
	SPELL_FEAR			= 71117, //
	SPELL_THROWN		= 49481, //
	SPELL_BERSERK		= 62555, //
	SPELL_DRAINMANA		= 46453, //
	SPELL_BLOODBOIL		= 22067, //
	SPELL_CURSE			= 68137, //



	GUARD_HORDE			= 3296,
	GUARD_ALLIANCE		= 68,
	GUARDS_MAX			= 30
};


const Position horde = { 1920.69f, -4127.0f, 44.0f };
const Position alliance = { -8441.42f, 333.10f, 122.6f };
const Position horde1 = { 1921.84f, -4163.29f, 41.0f };
const Position alliance1 = { -8455.50f, 350.99f, 121.0f };

class boss_pvp : public CreatureScript
{
    public:

        boss_pvp()
            : CreatureScript("boss_pvp")
        {
        }

        struct boss_pvpAI : public ScriptedAI
        {
            //*** HANDLED FUNCTION ***
            //This is the constructor, called only once when the Creature is first created
            boss_pvpAI(Creature *c) : ScriptedAI(c), Summons(me) {
				zone = (me->GetMapId());
			}

            //*** CUSTOM VARIABLES ****
            //These variables are for use only by this individual script.
            //Nothing else will ever call them but us.
			SummonList Summons;

			uint32 BladeStormTimer;
			uint32 FearTimer;
			uint32 ThrownTimer;
			uint32 BerserkTimer;
			uint32 DrainManaTimer;
			uint32 BloodBoilTimer;
			uint32 CurseTimer;
			uint32 summonetimer;
			uint32 phase;
			bool zone;
			uint32 guards;
			uint32 VolleyTimer;
			bool chasing;

            //*** HANDLED FUNCTION ***
            //This is called after spawn and whenever the core decides we need to evade
            void Reset()
            {
				phase = 1;
				BladeStormTimer = 2000;
				FearTimer = 7000;
				ThrownTimer = 1000;
				BerserkTimer = 600000;
				DrainManaTimer = 9500;
				BloodBoilTimer = urand(10000, 13000);
				CurseTimer = 7500;
				summonetimer = 0;
				guards = 0;
				VolleyTimer = 2000;
				Summons.DespawnAll();
				SetCombatMovement(true);
				chasing = true;
            }

            //*** HANDLED FUNCTION ***
            // Enter Combat called once per combat
            /*void EnterCombat(Unit* pWho)
            {
                
                
            }*/

			void JustSummoned(Creature *pSummoned)
			{
				pSummoned->SetInCombatWithZone();
				if (Unit* pTarget = SelectUnit(SELECT_TARGET_RANDOM,0))
					pSummoned->AI()->AttackStart(pTarget);
				
				Summons.Summon(pSummoned);
			}

			void SummonedCreatureDespawn(Creature *summon)
			{
				Summons.Despawn(summon);
				guards++;
			}

            //*** HANDLED FUNCTION ***
            // Attack Start is called when victim change (including at start of combat)
            // By default, attack pWho and start movement toward the victim.
            //void AttackStart(Unit* pWho)
            //{
            //    ScriptedAI::AttackStart(pWho);
            //}

            //*** HANDLED FUNCTION ***
            // Called when going out of combat. Reset is called just after.
            /*void EnterEvadeMode()
            {
                DoScriptText(SAY_EVADE, me);
            }*/

            //*** HANDLED FUNCTION ***
            //Update AI is called Every single map update (roughly once every 50ms if a player is within the grid)
            void UpdateAI(const uint32 diff)
            {
                //Return since we have no target
                if (!UpdateVictim())
                    return;

				if (!me->HasAura(SPELL_DIVINESHIELD))
				{
					if (ThrownTimer <= diff)
					{
						if (Unit* target = SelectUnit(SELECT_TARGET_RANDOM, 0))
							DoCast(target, SPELL_THROWN);

						ThrownTimer = urand(16000,18000);
					}
					else ThrownTimer -= diff;

					if (CurseTimer <= diff)
					{
						DoCastToAllHostilePlayers(SPELL_CURSE);

						CurseTimer = 19000;
					}
					else CurseTimer -= diff;
				
					if (BloodBoilTimer <= diff)
					{
						DoCast(me, SPELL_BLOODBOIL);
						BloodBoilTimer = 43000;
					}
					else BloodBoilTimer -= diff;

					if (BladeStormTimer <= diff)
					{
						if (Unit* target = SelectUnit(SELECT_TARGET_RANDOM, 0))
						{
							DoCast(me, SPELL_BLADESTORM);
							// random movement?
							me->GetMotionMaster()->MoveChase(target);
							BladeStormTimer = 40000;
							chasing = false;
						}
					}
					else
					{
						BladeStormTimer -= diff;
						if (!chasing && !me->HasAura(SPELL_BLADESTORM))
						{
							me->GetMotionMaster()->MoveChase(me->getVictim());
							chasing = true;
						}
					}


					if (DrainManaTimer <= diff)
					{
						DoCast(me->getVictim(), SPELL_DRAINMANA);

						DrainManaTimer = 45000;
					}
					else DrainManaTimer -= diff;

					if (FearTimer <= diff)
					{
						DoCast(me->getVictim(), SPELL_FEAR);

						FearTimer = urand(33000,36000);
					}
					else FearTimer -= diff;

					if (HealthBelowPct(70) && phase == 1)
						phase = 2;

					if (HealthBelowPct(40) && phase == 3)
						phase = 4;

					if (phase == 2 || phase == 4)
					{
						DoCast(me, SPELL_DIVINESHIELD);
						DoCast(me, SPELL_EARTHQUAKE);
						me->GetMotionMaster()->MovePoint(0, zone ? horde : alliance);
						SetCombatMovement(false);
						guards = 0;
					}
                
					if (BerserkTimer <= diff)
					{
						if (!me->HasAura(SPELL_BERSERK))
						{
							DoCast(me, SPELL_BERSERK);
						}
					}
					else BerserkTimer -= diff;

					DoMeleeAttackIfReady();
				}
				else
				{
					if (VolleyTimer <= diff) {
						DoCast(me->getVictim(), 72906); // volley
						VolleyTimer = 8000;
					}
					else VolleyTimer -= diff;

					if (CurseTimer <= diff)
					{
						DoCastToAllHostilePlayers(SPELL_CURSE);

						CurseTimer = 13000;
					}
					else CurseTimer -= diff;
					

					float x = me->GetPositionX();
					float y = me->GetPositionY();
					float z = me->GetPositionZ() + 0.2f;

					if (phase == 2)
					{
						if (summonetimer <= diff)
						{
							if (guards <= GUARDS_MAX) {
								me->SummonCreature(zone ? GUARD_HORDE : GUARD_ALLIANCE, x, y, z, me->GetOrientation(), TEMPSUMMON_CORPSE_DESPAWN, 20000);
								summonetimer = 1000;
							}
							else {
							    phase = 3;
								me->RemoveAllAuras();
								SetCombatMovement(true);
								me->GetMotionMaster()->MoveChase(me->getVictim());
							}

						}
						else summonetimer -= diff;
					}
					else
					{
						if (summonetimer <= diff)
						{
							if (guards <= GUARDS_MAX) {
								me->SummonCreature(zone ? GUARD_HORDE : GUARD_ALLIANCE, x, y, z, me->GetOrientation(), TEMPSUMMON_CORPSE_DESPAWN, 20000);
								summonetimer = 1000;
							}
							else {
							    phase = 5;
								me->RemoveAllAuras();
								SetCombatMovement(true);
								me->GetMotionMaster()->MoveChase(me->getVictim());
							}

						}
						else summonetimer -= diff;

					}	
					
				}
            }
        };

        CreatureAI* GetAI(Creature* pCreature) const
        {
            return new boss_pvpAI(pCreature);
        }

};

//This is the actual function called only once durring InitScripts()
//It must define all handled functions that are to be run in this script
void AddSC_boss_pvp()
{
    new boss_pvp();
}
