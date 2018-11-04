//TIE@FY3
inherit NPC;
#include <ansi.h>
void create()
{
	set_name("����", ({ "master li", "master","li" }) );
	set("gender", "����" );
        set("title", HIC"��ɽ������"NOR);
	set("age", 25);
	set("int", 30);
	set("per", 30);
        set("apprentice_available", 50);
	set("long",
		"���������µ�һ���������֮�ӣ�����ӵ��ɽׯ����������Ϊ������Ϊ��ɽ������\n"
		);
        set("force_factor", 20);
        set("max_gin", 3000);
        set("max_kee", 3000);
        set("max_sen", 3000);
        set("eff_gin", 3000);
        set("eff_kee", 3000);
        set("eff_sen", 3000);
        set("gin", 3000);
        set("kee", 3000);
        set("sen", 3000);
        set("max_neili", 3000);
        set("neili", 3000);

        set("combat_exp", 59999999);
        set("score", 90000);
        set_skill("unarmed", 100);
        set_skill("blade", 150);
        set_skill("force", 100);
        set_skill("literate", 100);
	set_skill("dodge", 100);

	set_skill("yunwu-strike", 200);
	set_skill("qiusheng-blade", 230);
	set_skill("xianjing", 250);
	set_skill("liuquan-steps", 200);

	map_skill("unarmed", "yunwu-strike");
        map_skill("blade", "qiusheng-blade");
        map_skill("force", "xianjing");
        map_skill("dodge", "liuquan-steps");
        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.liushuichanchan" :),
                (: perform_action, "unarmed.miwu" :),
                (: perform_action, "blade.jingsheng" :),
        }) );
        set("chat_chance", 5);
        set("chat_msg", ({
                (: random_move :),
        }) );
set("pubmaster",1);
if (random(2)==0)
{
	set_name(HIR"��ӥ"NOR, ({ "master ying", "master"}) );
        set("title", WHT"�����еĵ���"NOR);
        set("long",
"������������֮һ����\n"
               ); 
        set("chat_chance", 3);
        set("chat_msg", ({
                (: random_move :),
        }) );

}
        set("max_neili", 25000);
        set("neili", 25000);
        set("force_factor", 30);
	set("max_qi",9999);
        set("max_jing",9999);
	set("eff_qi",9999);
	set("qi",9999);
	set("eff_jing",9999);
	set("jing",9999);
	set_temp("apply/attack", 200);set_temp("apply/defense", 200);set_temp("apply/armor", 500);set_temp("apply/damage", 600);setup();
	carry_object(__DIR__"obj/greencloth")->wear();
        carry_object(__DIR__"obj/yuhuan")->wield();
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
