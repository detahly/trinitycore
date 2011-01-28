//made by rusfighter(please dont delete this if you like it!)
#include "ScriptPCH.h"
#include "Object.h"
#include "DatabaseEnv.h"

class ipcheck : public PlayerScript
{
        public:
                ipcheck() : PlayerScript("ipcheck") {}

	void OnLogin(Player* pPlayer)
    {
        uint32 accId = pPlayer->GetSession()->GetAccountId();      // get account id
        /*QueryResult result = LoginDatabase.PQuery("Select last_ip From account where id = '%u'", accId);
        if (!result)        //check
            return;
        Field* fields = result->Fetch();
        std::string last_ip = fields[0].GetString();
        //*/
        QueryResult result = LoginDatabase.PQuery("SELECT count(*) FROM account WHERE last_ip IN (Select last_ip From account WHERE id = %u) and online = 1 ", accId);
        if (!result)
            return;
        Field* fields = result->Fetch();
        uint32 online = fields[0].GetUInt32();

        if (online > 1)
        {
            pPlayer->GetSession()->KickPlayer();
        }
        	
	}	

};

void AddSC_ipcheck()
{
    new ipcheck;
}