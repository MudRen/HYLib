// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <ansi.h>
inherit NPC;
void create()
{
        set_name(RED"������"NOR, ({ "master yin", "master","yin" }) );
        set("long",
                "���Ƴ�����ߵĹ٣����������ϵ�Ȩ��\n");
        set("title", RED"һƷ�ղ�"NOR);
        set("attitude", "heroism");
        set("student_title","��Ա");
        set("vendetta_mark", "authority");
        set("str", 27);
        set("cor", 26);
        set("cps", 25);
        set("agi",25);
        set("int",30);
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.yuhuan" :),
        }) );
        set("combat_exp", 90000000);
        set_temp("apply/damage",500);
        set_skill("unarmed", 200);
        set_skill("sword",100);
        set_skill("force",80);
        set_skill("parry", 120);
        set_skill("dodge", 110);
        set_skill("changquan",200);
        set_skill("feixian-steps",160);
        set_skill("feixian-sword",180);
        set_skill("blood-sword",250);
        set_skill("jingyiforce",250);
        set_skill("dodge", 120);
        set_skill("literate",90);
        map_skill("unarmed","changquan");
        map_skill("dodge","feixian-steps");
        map_skill("force","jingyiforce");
        map_skill("sword","feixian-sword");
set("pubmaster",1);
if (random(2)==0)
{
	set_name(HIY"����·"NOR, ({ "master guo", "master"}) );
        set("title", HIY"����Ӣ��"NOR);
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
        set("chat_chance", 5);
        set("chat_msg", ({
                (: random_move :),
        }) );

        set_temp("apply/attack", 200);set_temp("apply/defense", 200);set_temp("apply/armor", 500);set_temp("apply/damage", 600);setup();

        carry_object(__DIR__"obj/guanfu")->wear();
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
