// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
        set_name("��ʤ����", ({ "master yue", "master" }) );
        set("nickname", HIY"���"HIW"����"NOR);
        set("gender", "����" );
        set("age", 44);
        set("str", 50);
        set("cor", 30);
        set("cps", 30);
        set("int", 30);
	create_family("ڤ��",2,"��˾");
            set("per", 30);
	set("attitude","friendly");
        set("max_force", 15000);
        set("force", 15000);
        set("force_factor", 20);
        set("long",
"
�㿴�ſ��ţ�������λ���������ǵ���ͳ��ʮ��ֱ��������׳־δ������ɣ�
\n"
	);
        set("combat_exp", 1000000);
        set("agi",25);
        set("int",30);

        set_skill("parry", 80);
        set_skill("dodge", 80);
        set_skill("force", 80);
//   	  set_skill("leadership", 200);
        set_skill("literate", 60);
        set("skill_public",1);
	set_temp("apply/attack",200);
	set_temp("apply/defense",200);
        setup();
        carry_object(__DIR__"obj/goldarmor")->wear();
        carry_object(__DIR__"obj/silverarmor")->wear();
}


int is_ghost() { return 1; }

int recognize_apprentice(object ob)
{
        if( ob->query("marks/����") )
	{
		say("�����ȵ�������޵ľ��������ֲ���֮�ˣ�\n");
		kill_ob(ob);
		ob->kill_ob(this_object());
		return 0;
	}
        if( ob->query("marks/��") )
                return 1;
        return 0;
}
void attempt_apprentice(object ob)
{
     command("say �ðɣ��������㡣\n");
     command("recruit "+ob->query("id"));
     return;
}


