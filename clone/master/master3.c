// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
#include <ansi.h>
void create()
{
        set_name("л����", ({ "master xie", "master", "xiexiaofeng" }) );
        set("title", HIG"����"NOR);
        set("gender", "����" );
        set("age", 34);
        set("str", 30);
        set("cor", 30);
        set("cps", 30);
        set("int", 30);
	set("per", 30);
	set("attitude","aggresive");
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

        set("force_factor", 3);
        set("long",
"
л��������ѧ��,ʮ���꽣��,ʮ����ܻ�����,һ�����ϸ�����ὣ��������˫
��������������,��������Ľ����ݶ����,����һ����ծ����
\n"
	);

if (random(2)==0)
{
	set_name(GRN"½С��"NOR, ({ "master lu", "master"}) );
        set("title", HIY"��Ϭһָ"NOR);
        set("long",
"������������֮һ����\n"
               ); 
        set("chat_chance", 3);
        set("chat_msg", ({
                (: random_move :),
        }) );

}
        set("combat_exp", 80000000);
        set("score", 200000);
        set_skill("parry", 100);
        set_skill("dodge", 120);
        set_skill("force", 100);
        set_skill("literate", 100);
	set_skill("sword",130);
	set_skill("softsword",250);
        set_skill("cloudforce",220);
        set_skill("shadowsteps",220);
	map_skill("force", "cloudforce");
	map_skill("parry","softsword");
        map_skill("sword","softsword");
        map_skill("dodge","shadowsteps");
        map_skill("dodge","shadowsteps"); 
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 600);      
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.bajian" :),
                (: perform_action, "sword.yixiao" :),
                (: perform_action, "dodge.lianhuanjiao" :),
        }) );
         set("chat_chance", 5);
        set("chat_msg", ({
                (: random_move :),
        }) );
       set_temp("apply/attack", 200);set_temp("apply/defense", 200);set_temp("apply/armor", 500);set_temp("apply/damage", 600);setup();
         carry_object(__DIR__"obj/qingcloth")->wear();
        carry_object(__DIR__"obj/xiesword")->wield();
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
