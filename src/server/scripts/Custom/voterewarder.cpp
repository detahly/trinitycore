
#include "ScriptPCH.h"
#include <cstring>
#include "CharacterDatabaseCleaner.h"
#include "DatabaseEnv.h"
#include "ObjectMgr.h"


class voterewarder : public CreatureScript
{
    public:

        voterewarder()
            : CreatureScript("voterewarder")
        {
        }

        void RewardItem(Player* pPlayer, Creature* pCreature, int item , int count, int cost)
        {
            QueryResult result;
            result = CharacterDatabase.PQuery("SELECT votepoints FROM auth.account WHERE id = '%u'", pPlayer->GetSession()->GetAccountId());
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

            if (item == 0)
            {
                sprintf(str,"You got %u voting points!", points);
                pPlayer->MonsterWhisper(str,pPlayer->GetGUID(),true);
            }
            else
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
                        CharacterDatabase.PQuery("Update auth.account Set votepoints = votepoints - '%u' WHERE id = '%u'", cost, pPlayer->GetSession()->GetAccountId());
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
            pPlayer->PlayerTalkClass->ClearMenus();
            OnGossipHello(pPlayer, pCreature);
        }

        bool OnGossipHello(Player* pPlayer, Creature* pCreature)
        {
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Homuch voting points do i have?", GOSSIP_SENDER_MAIN, 1000);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Weapons", GOSSIP_SENDER_MAIN, 2000);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Rings/Trinkets", GOSSIP_SENDER_MAIN, 3000);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Vote Token - Cost 5 VP", GOSSIP_SENDER_MAIN, 4000);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Other Stuff", GOSSIP_SENDER_MAIN, 5000);
            

            pPlayer->PlayerTalkClass->SendGossipMenu(907, pCreature->GetGUID());

            return true;
        }

        bool OnGossipSelect(Player* pPlayer, Creature* pCreature, uint32 /*uiSender*/, uint32 uiAction)
        {
            pPlayer->PlayerTalkClass->ClearMenus();
            
            switch (uiAction)
            {
            case 1000:
                RewardItem(pPlayer, pCreature, 0, 0, 0);
                break;
            case 2000:
                pPlayer->PlayerTalkClass->ClearMenus();
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Havoc's Call, Blade of Lordaeron Kings - 70 VP", GOSSIP_SENDER_MAIN, 2001);
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Mithrios, Bronzebeard's Legacy - 100 VP", GOSSIP_SENDER_MAIN, 2002);
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Shadowmourne - 120 VP", GOSSIP_SENDER_MAIN, 2003);
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Archus, Greatstaff of Antonidas - 120 VP", GOSSIP_SENDER_MAIN, 2004);
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Royal Scepter of Terenas II - 70 VP", GOSSIP_SENDER_MAIN, 2005);
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Glorenzelg, High-Blade of the Silver Hand - 120 VP", GOSSIP_SENDER_MAIN, 2006);
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Bloodsurge, Kel'Thuzad's Blade of Agony - 70 VP", GOSSIP_SENDER_MAIN, 2007);
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Heaven's Fall, Kryss of a Thousand Lies - 70 VP", GOSSIP_SENDER_MAIN, 2008);
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Oathbinder, Charge of the Ranger-General - 120 VP", GOSSIP_SENDER_MAIN, 2009);
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Return", GOSSIP_SENDER_MAIN, 9999);
                pPlayer->PlayerTalkClass->SendGossipMenu(907, pCreature->GetGUID());
                return true;
                break;
            case 2001:
                RewardItem(pPlayer, pCreature,50737,1,70); 
                break;
            case 2002:
                RewardItem(pPlayer, pCreature,50738,1,100);
                break;
            case 2003:
                RewardItem(pPlayer, pCreature,49623,1,120);
                break;
            case 2004:
                RewardItem(pPlayer, pCreature,50731,1,120);
                break;
            case 2005:
                RewardItem(pPlayer, pCreature,50734,1,70);
                break;
            case 2006:
                RewardItem(pPlayer, pCreature,50730,1,120);
                break;
            case 2007:
                RewardItem(pPlayer, pCreature,50732,1,70);
                break;
            case 2008:
                RewardItem(pPlayer, pCreature,50736,1,70);
                break;
            case 2009:
                RewardItem(pPlayer, pCreature,50735,1,120);
                break;
            case 3000:
                pPlayer->PlayerTalkClass->ClearMenus();                
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "[Deathbringers will](heroic) - 60 VP", GOSSIP_SENDER_MAIN, 3001);
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Return", GOSSIP_SENDER_MAIN, 9999);
                pPlayer->PlayerTalkClass->SendGossipMenu(907, pCreature->GetGUID());
                return true;
                break;
            case 3001:
                RewardItem(pPlayer, pCreature, 50363,1,60);
                break;
            case 4000:
                RewardItem(pPlayer,  pCreature, 37829, 1, 5);
                break;
            case 5000:
                pPlayer->PlayerTalkClass->ClearMenus();
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "[Murloc Costume] - 16 VP", GOSSIP_SENDER_MAIN, 5001);
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Return", GOSSIP_SENDER_MAIN, 9999);
                pPlayer->PlayerTalkClass->SendGossipMenu(907, pCreature->GetGUID());
                return true;
                break;
            case 5001:
                RewardItem(pPlayer, pCreature, 33079,1,16); 
                break;
            case 9999:
                pPlayer->PlayerTalkClass->ClearMenus();
                OnGossipHello(pPlayer, pCreature);
                break;
            }


            return true;
        }

};

void AddSC_voterewarder()
{
    new voterewarder();
}
