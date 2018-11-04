//Cracked by Roath

#include <ansi.h>
#include "mingjiao_npc.c"
#include "mingjiao_job.h"

string ask_job();
int get_jingtie_num();
string ask_jingtie();
string ask_jingtie_num();
void dest_ob(object);

void create()
{
		mapping S_skills= ([ ]);
		mapping I_inquiry=([ ]);
		mixed Skill_name;

        set_name("�⾢��", ({ "wu jincao","wu"}) );
        set("title", "������������츱ʹ");
        create_family("����",37,"����ʹ");
        set("gender", "����");
        set("age",35);
        set("long", "
����
\n");
        set("attitude", "peaceful");
        set("shen", 1000000);
        
	I_inquiry["name"]="���¾���������������츱ʹ�⾢�ݣ���֪�����к�ָ�̡�";
	Skill_name=({"shenghuo-xuanming","wuxing-bu","duoming-bi",
		     "riyue-shenzhang","shenghuo-quan","guangming-xinfa"});

		I_inquiry["����"]=(: ask_job :);
		I_inquiry["datie"]=(: ask_job :);
		I_inquiry["��������"]=(: ask_jingtie_num :);
		I_inquiry["reserve"]=(: ask_jingtie_num :);
		I_inquiry["����"]=(: ask_jingtie :);
		I_inquiry["jingtie"]=(: ask_jingtie :);

	Set_Inquiry(I_inquiry,Skill_name);

	Set_Npcattrib(23,5,2000,300,4000,400,4000,300,3000,1000,700000,50000);

//	S_skills["force"]="shenghuo-xuanming";
//	S_skills["dodge"]="wuxing-bu";
//	S_skills["parry"]="duoming-bi";
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
	carry_object(OBJ_PATH"/panguan-bi")->wield();

}

string ask_job()
{
     object player=this_player();
     mapping fam ;
     object ling,chui,qiao;

    if (!(fam = this_player()->query("family")) || fam["family_name"] != "����")
        return "��λ"+RANK_D->query_respect(player)+"�����ҽ̵��֣��Ǹ������Ǹҷ��ɸ���ʲô�����ء�\n";

	if(!objectp(ling = present("tieyan ling", player)) )
		return "��λ"+RANK_D->query_respect(player)+"û���ҽ��������������μ�¼���͹�ʧ��\n";

//	if (fam["generation"] <37)
//		 return "��λ"+RANK_D->query_respect(player)+"�ѹ�Ϊ�ҽ�"+fam["title"]+"������ͷ���ܡ�\n";

	if(player->query("mingjiao/job") != "jin_caikuang")
		return judge_jobmsg(player,0);

	if( !present("wujin kuangshi",player ) )
		return "�㲢δ������ʯ����δ�����\n";

// remove tie qiao from this player.
	qiao=present("tie qiao",player );
	if (qiao) destruct(qiao);
	tell_object(player,"������½����⾢�ݡ�\n\n");	

	command("nod "+player->query("id"));

	chui=new(OBJ_PATH"/tiechui");
	chui->move(player);
	tell_object(player,"�⾢�ݸ���һ��������\n");
	
	return "�ã���ȥ�Ѳ����Ŀ�ʯ���ɾ����ɡ�\n";
		 
}   

int accept_object(object me, object ob)
{
	string name;
	string job_flg;
	object room,tool;


	name = ob->query("id");	
	if ( name != "jing tie")
		return 0;

	job_flg = judge_jobmsg(me,1);

	if ( job_flg !=  "�ɼ�����" ) 
	{
		command("hmm "+me->query("id"));
		command("say û����������Ͳ�Ҫ���ҿ��ɣ�");
		return 0;
	}
	else
	{
		command("thumb "+this_player()->query("id"));
		command("say ��λ�ֵ�������!��ȥ�ú���Ϣ��Ϣ��");
	        tool=present("tie chui",me );
		if (tool) destruct(tool);
		remove_call_out("dest_ob");
		call_out("dest_ob",1,ob);
	        if (!(room = find_object("/d/kunlun/mj_center.c")))
			room = load_object("/d/kunlun/mj_center.c");
		room->add("jingtie",1);
		remove_call_out("reward");
		call_out("reward",1,this_player(),job_flg);
		return 1;
	}
	
	return 0;

}


int get_jingtie_num()
{
        int num;
        object room;
        
        if (!(room = find_object("/d/kunlun/mj_center.c")))
		room = load_object("/d/kunlun/mj_center.c");
        num = room->query("jingtie");

	return num;

}

string ask_jingtie_num()
{
	return "���ڻ���"+chinese_number(get_jingtie_num())+"�龫����\n";
}

string ask_jingtie()
{
	int num;
	object me=this_player();
	object jingtie,room;
	string job_flg;

	job_flg = judge_jobmsg(me,1);
	if (job_flg != "�����ǹ")
		return "��λ"+RANK_D->query_respect(me)+"����û�����ǹ������ɡ�\n";
	
	if (present("jing tie",me) )
	{
		command("hmm "+me->query("id"));
		return "�㲻���Ѿ���һ�����𣿻���Ҫ������̰�����ᡣ\n";
	}

	if ( get_jingtie_num() <= 0 )
		return "�Բ����������Ѿ�û�о����ˡ�\n";

	command("nod "+me->query("id"));
	message_vision("�⾢������һ�龫����$N\n",me);
        if (!(room = find_object("/d/kunlun/mj_center.c")))
		room = load_object("/d/kunlun/mj_center.c");
	room->add("jingtie",-1);

	jingtie=new(OBJ_PATH"/jingtie");
	jingtie->move(me);

	return "�����ֵ�����������������ľ�������Ҫ�����úô��������\n";
}

void dest_ob(object ob) { destruct(ob);}