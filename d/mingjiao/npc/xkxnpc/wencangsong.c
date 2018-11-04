//Cracked by Roath

#include <ansi.h>
#include "mingjiao_npc.c"
#include "mingjiao_job.h"

string ask_job();

void create()
{
		mapping S_skills= ([ ]);
		mapping I_inquiry=([ ]);
		mixed Skill_name;

        set_name("�Ų���", ({ "wen cangsong","wen"}) );
        set("title", "���̾�ľ������ʹ");
        create_family("����",37,"����ʹ");
        set("gender", "����");
        set("age",36);
        set("long", "
����
\n");
        set("attitude", "peaceful");
        set("shen", 1000000);
        
	I_inquiry["name"]="���¾������̾�ľ������ʹ�Ų��ɣ���֪�����к�ָ�̡�";
	I_inquiry["����"]=(: ask_job :);
	I_inquiry["job"]=(: ask_job :);
	I_inquiry["����"]=(: ask_abandon :);
	I_inquiry["abandon"]=(: ask_abandon :);

	Skill_name=({"shenghuo-xuanming","wuxing-bu","duoming-bi",
		     "riyue-shenzhang","shenghuo-quan","guangming-xinfa"});

	Set_Inquiry(I_inquiry,Skill_name);

	Set_Npcattrib(23,5,2000,300,4000,400,4000,300,3000,1000,700000,50000);

//	S_skills["force"]="shenghuo-xuanming";
//	S_skills["dodge"]="wuxing-bu";
//	S_skills["parry"]="shenghuo-quan";
//	S_skills["stroke"]="duoming-bi";
//	S_skills["strike"]="riyue-shenzhang";
//	S_skills["cuff"]="shenghuo-quan";
//	set_skill("guangming-xinfa",100+random(20));
	set_skill("literate",100+random(20));
	
//	Set_Npcskills(100,20,S_skills);
	
//	prepare_skill("cuff","shenghuo-quan");
//	prepare_skill("strike","riyue-shenzhang");

        setup();

	carry_object(OBJ_PATH"/changpao")->wear();


}

string ask_job()
{
     object player=this_player();
     mapping fam ;
     object ling,axe,shugan;

    if (!(fam = this_player()->query("family")) || fam["family_name"] != "����")
        return "��λ"+RANK_D->query_respect(player)+"�����ҽ̵��֣��Ǹ������Ǹҷ��ɸ���ʲô�����ء�\n";

	if(!objectp(ling = present("tieyan ling", player)) )
		return "��λ"+RANK_D->query_respect(player)+"û���ҽ��������������μ�¼���͹�ʧ��\n";

//	if (fam["generation"] <37)
//		 return "��λ"+RANK_D->query_respect(player)+"�ѹ�Ϊ�ҽ�"+fam["title"]+"������ͷ���ܡ�\n";

	if ( player->query("mingjiao/job")=="mu_kanshu" && shugan=present("shu gan",player) )
	{
		if (shugan->query("owner")==player->query("id"))
		{
			command("pat "+player->query("id"));
			if (axe=present("axe",player))
				destruct(axe);
			message_vision("�Ų��ɽ���һ�����ڣ���$N�����ɽ��˹�ȥ��\n",player);
			destruct(shugan);
			player->delete_temp("apply/short");
			remove_call_out("reward");
			call_out("reward",1,this_player(),"����");
			return player->query("name")+"�ɵò�����ȥ�ú���Ϣ��Ϣ��\n";
		}
		else
			return "��������㿳�İɡ���͵����\n";
	}

	if(player->query("mingjiao/job"))
		return judge_jobmsg(player,0);

	command("nod "+player->query("id"));

	player->set("mingjiao/job","mu_kanshu");
	
	axe=new(OBJ_PATH"/axe");
	axe->move(player);
	tell_object(player,"�Ų��ɸ���һ�Ѹ�ͷ��\n");
	
	return "���������ã��ֵ��������󷨣���ľ�����ˣ���ȥ�����￳Щ���ɿ�������\n";

}   


