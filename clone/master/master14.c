
inherit NPC;
#include <ansi.h>
void create()
{
	set_name("���촸", ({ "master lan", "lan","master" }) );
	set("gender", "����" );
        set("title",HIB "��������" NOR);
	set("age", 45);
	set("int", 30);
	set("str",700);
	set("per", 30);
        set("apprentice_available", 50);
	set("long",
		"���촸��һ�����õĳ����뻯������
ÿ�궼�͵�����������һս���½�ʤ�����֣� 
���촸��Ƣ�������һ𣬾�����Ե�޹ʵĽ����Ӵ�����˻����ǽ�ţ�\n"
		);
        set("max_neili", 3500);
        set("neili", 3500);
        set("force_factor", 30);
	set("max_qi",2999);
        set("max_jing",2999);
	set("eff_qi",2999);
	set("qi",2999);
	set("eff_jing",2999);
	set("jing",2999);
        set("skill_public",1);
        set("chat_chance", 1);
        set("chat_chance", 5);
        set("chat_msg", ({
                (: random_move :),
        }) );

set("pubmaster",1);
if (random(2)==0)
{
	set_name(HIR"������"NOR, ({ "master di", "master"}) );
        set("title", RED"������ͷ"NOR);
        set("long",
"������������֮һ����\n"
               ); 
        set("chat_chance", 3);
        set("chat_msg", ({
                (: random_move :),
        }) );

}
        set("combat_exp", 59999999);
        set("score", 90000);
        set_skill("unarmed", 100);
        set_skill("hammer", 150);
        set_skill("force", 200);
        set_skill("parry", 100);
        set_skill("literate", 100);
	set_skill("dodge", 100);

	set_skill("pangu-hammer", 250);
	set_skill("pofeng-strike", 220);
	set_skill("putiforce", 250);
	set_skill("nodust-steps", 200);

	map_skill("unarmed", "pofeng-strike");
        map_skill("hammer", "pangu-hammer");
        map_skill("force", "putiforce");
        map_skill("parry", "pangu-hammer");
        map_skill("dodge", "nodust-steps");
	set_skill("magic",100);
//	set_skill("qiankunwuxing",100);
//	map_skill("magic","qiankunwuxing");
        set("agi",25);
        set("int",30);
set("pubmaster",1);
        set("max_neili", 25000);
        set("neili", 25000);
        set("force_factor", 30);
	set("max_qi",9999);
        set("max_jing",9999);
	set("eff_qi",9999);
	set("qi",9999);
	set("eff_jing",9999);
	set("jing",9999);
      set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.luanpofeng" :),
                (: perform_action, "hammer.kaitianpidi" :),
        }) );
	set_temp("apply/attack", 200);set_temp("apply/defense", 200);set_temp("apply/armor", 500);set_temp("apply/damage", 600);setup();
        carry_object(__DIR__"obj/bluecloth")->wear();
        carry_object(__DIR__"obj/jumbohammer")->wield();
}

int accept_object(object who, object ob)
{
	int i;

	if (!(int)who->query_temp("learn_timeb"))      
		who->set_temp("learn_timeb", 0);

	if( !ob->query("money_id") )
		return 0;		


	if(who->query_skill("unarmed",1)<30)
		i=ob->value() / 50;
	else
	{
		if(who->query_skill("unarmed",1)<60)
			i=ob->value() / 100;
		else
		{
			if(who->query_skill("unarmed",1)<100)
				i=ob->value() / 100;
			else
				i=ob->value() / 100;
		}
	}
	who->add_temp("learn_timeb",i);
command("say ��Ȼ�������ѧ�ҵ��书���Ҿͳ�ȫ��ȫ��ɡ�");
	return 1;
}

int recognize_apprentice(object ob)
{
	if( ob->query_temp("learn_timeb") <= 0) return 0;
else         
ob->add_temp("learn_timeb",-1);
return 1;
}
