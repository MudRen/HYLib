#include <ansi.h>
inherit NPC;
int *names = ({YEL,RED,GRN,CYN,HIB,WHT,HIG,});

void create()
{      
        set_name(names[random(sizeof(names))]+"����"+NOR, ({ "hudie", "huahudie" }) );
        set("race", "Ұ��");
	set("gender", "����");
        set("age", 5);
	set("long", "һֻ��������ĺ�����\n");
        set("attitude", "friendly");
	set("chat_chance", 30);
	set("chat_msg", ({
		(: this_object(), "random_move" :),
		"�����ڻ������������衣\n",
                         }));		

	set("str", 5);
	set("con", 20);
        set("limbs", ({ "ͷ��", "����", "���" }) );
        set("verbs", ({ "bite"}) );

	set_skill("dodge", 20);
        set_temp("apply/armor", 1);

        setup();
}

