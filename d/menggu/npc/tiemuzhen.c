inherit NPC;
#include <ansi.h>
void create()
{
   set_name("��ľ��",({"tiemuzhen"}));
   set("gender","����");
      set("long","��ľ�����ɹŲ�ԭ��Ӣ��!\n");
   set("shen",25000);
   set("combat_exp",500000);
     set("age",45);
set("pubmaster",1);
    set("food",250);
    set("water",250);
   set("neili",2500);
   set("max_neili",2500);
   set("force_factor",60);

   set_skill("dodge",260);
   set_skill("force",260);
   set_skill("parry",260);
   set_skill("qinnashou",300);
   set_skill("unarmed",260);
   set_skill("blade", 200);
	map_skill("parry", "qinnashou");
	map_skill("hand", "qinnashou");
	prepare_skill("hand", "qinnashou");


	setup();
//   carry_object("clone/weapon/gangdao")->wield();
   carry_object("clone/cloth/cloth")->wear();
	add_money("gold",1);
}


int accept_object(object who, object ob)
{
	int i;

	if (!(int)who->query_temp("learn_timea"))      
		who->set_temp("learn_timea", 0);

	if( !ob->query("money_id") )
		return 0;		


	if(who->query_skill("qinnashou",1)<30)
		i=ob->value() / 50;
	else
	{
		if(who->query_skill("qinnashou",1)<60)
			i=ob->value() / 100;
		else
		{
			if(who->query_skill("qinnashou",1)<100)
				i=ob->value() / 150;
			else
				i=ob->value() / 300;
		}
	}
	who->add_temp("learn_timea",i);

      message_vision("��ľ���$N˵������Ȼ�������ѧ�ҵ��书���Ҿͳ�ȫ��ȫ��ɡ�\n",who);
      tell_object(who,"�������������ľ��ѧϰ�ˡ�\n");

	return 1;
}

int recognize_apprentice(object ob)
{
	if( ob->query_temp("learn_timea") <= 0) return 0;
else         
ob->add_temp("learn_timea",-1);
return 1;
}


