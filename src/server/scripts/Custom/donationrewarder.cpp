
#include "ScriptPCH.h"
#include <cstring>
#include "CharacterDatabaseCleaner.h"
#include "DatabaseEnv.h"
#include "ObjectMgr.h"


class donationrewarder : public CreatureScript
{
    public:

        donationrewarder()
            : CreatureScript("donationrewarder")
        {
        }

        void Reward(Player* pPlayer, Creature* pCreature, int item , int count, int cost, int type = 3, int32 spell = 0)
        {
            QueryResult result;
            result = LoginDatabase.PQuery("SELECT dp FROM account WHERE id = '%u'", pPlayer->GetSession()->GetAccountId());
            char str[200];
            if (!result) // check
            {
                sprintf(str,"I'm Broken! Contact a gamemaster!");
                pPlayer->PlayerTalkClass->ClearMenus();
                OnGossipHello(pPlayer, pCreature);
                pCreature->MonsterSay(str, LANG_UNIVERSAL, pPlayer->GetGUID());
                return;
            }
            Field *fields = result->Fetch();
            uint32 points = fields[0].GetUInt32();

            switch (type)
            {

                case 1:         // type 1 = rename
                {
                    if (points < cost)
                    {
                        sprintf(str,"You don't have enough points to do that!!!");
                        pPlayer->MonsterWhisper(str,pPlayer->GetGUID(),true);
                    }
                    else
                    {
                        LoginDatabase.PQuery("Update account Set dp = dp - '%u' WHERE id = '%u'", cost, pPlayer->GetSession()->GetAccountId());
                        sprintf(str,"Your points are taken, Please Relog!!!!");
                        pPlayer->MonsterWhisper(str,pPlayer->GetGUID(),true);
                        pPlayer->SetAtLoginFlag(AT_LOGIN_RENAME);
                    }

                }
                break;
                case 2:   // type 2 = get information
                {
                    sprintf(str,"You got %u donation points!", points);
                    pPlayer->MonsterWhisper(str,pPlayer->GetGUID(),true);
                }
                break;
                case 3: // type 3(default) = item
                {
                    if (points < cost)
                    {
                        sprintf(str,"You don't have enough points for this item!!");
                        pPlayer->MonsterWhisper(str,pPlayer->GetGUID(),true);
                    }
                    else
                    {
                        if (pPlayer->AddItem(item, count))
                        {
                            LoginDatabase.PQuery("Update account Set dp = dp - '%u' WHERE id = '%u'", cost, pPlayer->GetSession()->GetAccountId());
                            sprintf(str,"Your points are taken and your item is given!!!");
                            pPlayer->MonsterWhisper(str,pPlayer->GetGUID(),true);
                        }
                        else
                        {
                            sprintf(str,"Item can't be given(your bag is full or you already got the item!)!");
                            pPlayer->MonsterWhisper(str,pPlayer->GetGUID(),true);
                        }

                    }
                }
                break;
                case 4: // type 4 = race change
                    if (points < cost)
                    {
                        sprintf(str,"You don't have enough points to do that!!!");
                        pPlayer->MonsterWhisper(str,pPlayer->GetGUID(),true);
                    }
                    else
                    {
                        LoginDatabase.PQuery("Update account Set dp = dp - '%u' WHERE id = '%u'", cost, pPlayer->GetSession()->GetAccountId());
                        sprintf(str,"Your points are taken, Please Relog!!!!");
                        pPlayer->MonsterWhisper(str,pPlayer->GetGUID(),true);
                        pPlayer->SetAtLoginFlag(AT_LOGIN_CHANGE_RACE);
                        CharacterDatabase.PExecute("UPDATE characters SET at_login = at_login | '128' WHERE guid = %u", pPlayer->GetGUIDLow());

                    }
                break;
                case 5: // type 5 = faction change
                    if (points < cost)
                    {
                        sprintf(str,"You don't have enough points to do that!!!");
                        pPlayer->MonsterWhisper(str,pPlayer->GetGUID(),true);
                    }
                    else
                    {
                        LoginDatabase.PQuery("Update account Set dp = dp - '%u' WHERE id = '%u'", cost, pPlayer->GetSession()->GetAccountId());
                        sprintf(str,"Your points are taken, Please Relog!!!!");
                        pPlayer->MonsterWhisper(str,pPlayer->GetGUID(),true);
                        pPlayer->SetAtLoginFlag(AT_LOGIN_CHANGE_FACTION);
                        CharacterDatabase.PExecute("UPDATE characters SET at_login = at_login | '64' WHERE guid = %u", pPlayer->GetGUIDLow());

                    }
                break;
                case 6: // type 6 = cast spell
                    if (points < cost)
                    {
                        sprintf(str,"You don't have enough points to do that!!!");
                        pPlayer->MonsterWhisper(str,pPlayer->GetGUID(),true);
                    }
                    else
                    {
                        LoginDatabase.PQuery("Update account Set dp = dp - '%u' WHERE id = '%u'", cost, pPlayer->GetSession()->GetAccountId());
                        sprintf(str,"Your points are taken!!");
                        pPlayer->MonsterWhisper(str,pPlayer->GetGUID(),true);
                        pPlayer->CastSpell(pPlayer, spell, true);
                        
                    }                    
                break;
                case 7: // titles
                    if (points < cost)
                    {
                        sprintf(str,"You don't have enough points to do that!!!");
                        pPlayer->MonsterWhisper(str,pPlayer->GetGUID(),true);
                    }
                    else if (CharTitlesEntry const* titleEntry = sCharTitlesStore.LookupEntry(spell))
                    {
                        LoginDatabase.PQuery("Update account Set dp = dp - '%u' WHERE id = '%u'", cost, pPlayer->GetSession()->GetAccountId());
                        sprintf(str,"Your points are taken and the title is given!");
                        pPlayer->MonsterWhisper(str,pPlayer->GetGUID(),true);
                        pPlayer->SetTitle(titleEntry, false); 
                    }
                break;
            }
            pPlayer->PlayerTalkClass->ClearMenus();
            OnGossipHello(pPlayer, pCreature);
        }

        bool OnGossipHello(Player* pPlayer, Creature* pCreature)
        {
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, "Howmany donation points do i have?", GOSSIP_SENDER_MAIN, 1000);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_TAXI, "Genetic Modifier", GOSSIP_SENDER_MAIN, 2000);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Rings/Trinkets", GOSSIP_SENDER_MAIN, 3000);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, "1 x Donation Coin - Cost 5 dp", GOSSIP_SENDER_MAIN, 4000);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, "4 x Donation Coin - Cost 18 dp", GOSSIP_SENDER_MAIN, 4001);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, "50 x Vote Token - Cost 5 dp", GOSSIP_SENDER_MAIN, 4002);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_TAXI, "Other Stuff", GOSSIP_SENDER_MAIN, 5000);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_TAXI, "Titles", GOSSIP_SENDER_MAIN, 6000);
            

            pPlayer->PlayerTalkClass->SendGossipMenu(DEFAULT_GOSSIP_MESSAGE, pCreature->GetGUID());

            return true;
        }

        bool OnGossipSelect(Player* pPlayer, Creature* pCreature, uint32 /*uiSender*/, uint32 uiAction)
        {
            pPlayer->PlayerTalkClass->ClearMenus();
            
            switch (uiAction)
            {
            case 1000:
                Reward(pPlayer, pCreature, 0, 0, 0, 2);
                break;
            case 2000:
                pPlayer->PlayerTalkClass->ClearMenus();
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_TAXI, "Human Male - Cost 1 dp", GOSSIP_SENDER_MAIN, 2001);
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_TAXI, "Human Female - Cost 1 dp", GOSSIP_SENDER_MAIN, 2002);
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_TAXI, "Gnome Male - Cost 1 dp", GOSSIP_SENDER_MAIN, 2003);
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_TAXI, "Gnome Female - Cost 1 dp", GOSSIP_SENDER_MAIN, 2004);
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_TAXI, "Tauren Male - Cost 1 dp", GOSSIP_SENDER_MAIN, 2005);
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_TAXI, "Tauren Female - Cost 1 dp", GOSSIP_SENDER_MAIN, 2006);
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_TAXI, "Blood Elf Male - Cost 1 dp", GOSSIP_SENDER_MAIN, 2007);
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_TAXI, "Blood Elf Female - Cost 1 dp", GOSSIP_SENDER_MAIN, 2008);
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Return", GOSSIP_SENDER_MAIN, 9999);
                pPlayer->PlayerTalkClass->SendGossipMenu(DEFAULT_GOSSIP_MESSAGE, pCreature->GetGUID());
                return true;
                break;
            case 2001:
                Reward(pPlayer, pCreature, 0,0,1,6,35466);
                break;
            case 2002:
                Reward(pPlayer, pCreature, 0,0,1,6,37805);
                break;
            case 2003:
                Reward(pPlayer, pCreature, 0,0,1,6,37808);
                break;
            case 2004:
                Reward(pPlayer, pCreature, 0,0,1,6,37809);
                break;
            case 2005:
                Reward(pPlayer, pCreature, 0,0,1,6,37810);
                break;
            case 2006:
                Reward(pPlayer, pCreature, 0,0,1,6,37811);
                break;
            case 2007:
                Reward(pPlayer, pCreature, 0,0,1,6,37807);
                break;
            case 2008:
                Reward(pPlayer, pCreature, 0,0,1,6,37806);
                break;
            case 3000:
                pPlayer->PlayerTalkClass->ClearMenus();
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_TAXI, "Sharpened Twilight Scale - Cost 5 dp", GOSSIP_SENDER_MAIN, 3001);
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_TAXI, "Charred Twilight Scale - Cost 5 dp", GOSSIP_SENDER_MAIN, 3002);
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_TAXI, "Glowing Twilight Scale - Cost 5 dp", GOSSIP_SENDER_MAIN, 3003);
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_TAXI, "Petrified Twilight Scale - Cost 5 dp", GOSSIP_SENDER_MAIN, 3004);
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_TAXI, "Deathbringer's Will - Cost 4 dp", GOSSIP_SENDER_MAIN, 3005);
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Return", GOSSIP_SENDER_MAIN, 9999);
                pPlayer->PlayerTalkClass->SendGossipMenu(DEFAULT_GOSSIP_MESSAGE, pCreature->GetGUID());
                return true;
                break;
            case 3001:
                Reward(pPlayer,  pCreature, 54590, 1, 5);
                break;
            case 3002:
                Reward(pPlayer,  pCreature, 54588, 1, 5);
                break;
            case 3003:
                Reward(pPlayer,  pCreature, 54589, 1, 5);
                break;
            case 3004:
                Reward(pPlayer,  pCreature, 54591, 1, 5);
                break;
            case 3005:
                Reward(pPlayer,  pCreature, 50363, 1, 4);
                break;
            case 4000:
                Reward(pPlayer,  pCreature, 500600, 1, 5);
                pPlayer->CLOSE_GOSSIP_MENU();       //fix?
                pPlayer->PlayerTalkClass->ClearMenus();
                OnGossipHello(pPlayer, pCreature);
                break;
            case 4001:
                Reward(pPlayer,  pCreature, 500600, 4, 18);
                pPlayer->CLOSE_GOSSIP_MENU();       //fix?
                pPlayer->PlayerTalkClass->ClearMenus();
                OnGossipHello(pPlayer, pCreature);
                break;
            case 4002:
                Reward(pPlayer,  pCreature, 37829, 50, 5);
                pPlayer->CLOSE_GOSSIP_MENU();       //fix?
                pPlayer->PlayerTalkClass->ClearMenus();
                OnGossipHello(pPlayer, pCreature);
                break;
            case 5000:
                pPlayer->PlayerTalkClass->ClearMenus();
                //pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, "[Murloc Costume] - 16 VP", GOSSIP_SENDER_MAIN, 5001);
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_TAXI, "Character Rename - Cost 4 dp", GOSSIP_SENDER_MAIN, 5002);
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_TAXI, "Race Change - Cost 8 dp", GOSSIP_SENDER_MAIN, 5003);
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_TAXI, "Faction Change - Cost 13 dp", GOSSIP_SENDER_MAIN, 5004);
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, "40x Commendation of Bravery - Cost 5 dp", GOSSIP_SENDER_MAIN, 5005);
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, "200x Champion's Seal - Cost 8 dp", GOSSIP_SENDER_MAIN, 5006);
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Return", GOSSIP_SENDER_MAIN, 9999);
                pPlayer->PlayerTalkClass->SendGossipMenu(DEFAULT_GOSSIP_MESSAGE, pCreature->GetGUID());
                return true;
                break;
            /*case 5001:
                Reward(pPlayer, pCreature, 33079,1,16); 
                break;*/
            case 5002:
                Reward(pPlayer, pCreature, 0, 0, 4, 1);
                break;
            case 5003:
                Reward(pPlayer, pCreature, 0, 0, 8, 4);
                break;
            case 5004:
                Reward(pPlayer, pCreature, 0, 0, 13, 5);
                break;
            case 5005:
                Reward(pPlayer, pCreature, 45706, 40, 5);
                break;
            case 5006:
                Reward(pPlayer, pCreature, 44990, 200, 8);
                break;
            case 6000:
                pPlayer->PlayerTalkClass->ClearMenus();
                if (pPlayer->TeamForRace(pPlayer->getRace()) == ALLIANCE)
                {
                    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_TAXI, "KNIGHT - Cost 3DP", GOSSIP_SENDER_MAIN, 6001);
                    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_TAXI, "COMMANDER - Cost 6DP", GOSSIP_SENDER_MAIN, 6002);
                    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_TAXI, "GRAND MARSHAL - COST 12DP", GOSSIP_SENDER_MAIN, 6003);
                    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Return", GOSSIP_SENDER_MAIN, 9999);
                }
                else
                {
                    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_TAXI, "LEGIONNAIRE - Cost 3DP", GOSSIP_SENDER_MAIN, 6010);
                    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_TAXI, "CHAMPION - Cost 6DP", GOSSIP_SENDER_MAIN, 6011);
                    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_TAXI, "HIGH WARLORD - COST 12DP", GOSSIP_SENDER_MAIN, 6012);
                    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Return", GOSSIP_SENDER_MAIN, 9999);
                }
                pPlayer->PlayerTalkClass->SendGossipMenu(DEFAULT_GOSSIP_MESSAGE, pCreature->GetGUID());
                return true;
                break;
            case 6001:
                Reward(pPlayer, pCreature, 0, 0, 3, 7, 6);
                break;
            case 6002:
                Reward(pPlayer, pCreature, 0, 0, 6, 7, 11);
                break;
            case 6003:
                Reward(pPlayer, pCreature, 0, 0, 12, 7, 14);
                break;
            case 6010:
                Reward(pPlayer, pCreature, 0, 0, 3, 7, 22);
                break;
            case 6011:
                Reward(pPlayer, pCreature, 0, 0, 6, 7, 24);
                break;
            case 6012:
                Reward(pPlayer, pCreature, 0, 0, 12, 7, 28);
                break;
            case 9999:
                pPlayer->PlayerTalkClass->ClearMenus();
                OnGossipHello(pPlayer, pCreature);
                break;
            }

            return true;
        }

        struct donationrewarderAI : public ScriptedAI
        {
            // *** HANDLED FUNCTION ***
            //This is the constructor, called only once when the Creature is first created
            donationrewarderAI(Creature *c) : ScriptedAI(c) {}
            uint32 SayTimer;

            void Reset()
            {
                SayTimer = 120000; //1min
            }

            void UpdateAI(const uint32 diff)
            {
                if (SayTimer <= diff)
                {
                    //insert into `custom_texts` values('-2000010','Want to earn some voting points(vp) and help the server? Go to http://pure-pvp.com and click on \'Vote Here\'. Help the server and get some cool rewards! You can vote every 12 hours!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,'0','1','0','0','pure-pvp');
                    DoScriptText(-2000011, me);
                    SayTimer = 720000;//12min
                }
                else 
                    SayTimer -= diff;
            }

        };

        CreatureAI* GetAI(Creature* pCreature) const
        {
            return new donationrewarderAI(pCreature);
        }

};

void AddSC_donationrewarder()
{
    new donationrewarder();
}