inherit NPC;
#include <ansi.h>
void create()
{
        set_name(HIY "�������" NOR, ({ "tianji", "Tian ji", "Tian" }) );
        set("gender", "����");
        set("age", 99);
        set("long",
		"�������������ף��׷�ͯ�ա��ڱ�������������һ��
�����Ϲ٣�С��֮�ϣ�����������а�����¶��ɰ�����������������ͽ�����ޣ�������\n");
	set("title", HIC"����Ұ��"NOR);
        set("attitude", "peaceful");
        set("skill_public",1);
        set("str", 26);
        set("cor", 30);
        set("int", 24);
        set("cps", 30);
        set("chat_chance", 1);
        set("chat_msg", ({
                "������������̳��˼��ڣ�������\n",
        }) );

if (random(2)==0)
{
	set_name(RED"���"NOR, ({ "master yang", "yang"}) );
        set("title", HIY"���"NOR);
        set("long",
"������������֮һ����\n"
               ); 
        set("chat_chance", 3);
        set("chat_msg", ({
                (: random_move :),
        }) );

}
	set("neili", 40000);
	set("max_neili", 80000);
	set("force_factor", 1000);

	set("combat_exp", 10000000);
	set("score", 200000);

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

	set_skill("unarmed", 220);
	set_skill("force", 200);
	set_skill("iron-cloth", 300);
	set_skill("yiqiforce", 230);
	set_skill("dagger",300);

	map_skill("iron-cloth", "yiqiforce");
        map_skill("force", "yiqiforce");
        map_skill("unarmed", "yiqiforce");


        set("chat_chance", 5);
        set("chat_msg", ({
                (: random_move :),
        }) );

	set_temp("apply/attack", 200);
	set_temp("apply/defense", 200);
	set_temp("apply/armor", 500);
	set_temp("apply/damage", 600);
	setup();

	carry_object(__DIR__"obj/jade-ring")->wear();
	carry_object(__DIR__"obj/jade-pin")->wear();
	carry_object(__DIR__"obj/jade-boots")->wear();
	carry_object(__DIR__"obj/jade-cloth")->wear();
	carry_object(__DIR__"obj/hanyan")->wield();
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
