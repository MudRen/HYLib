#include <ansi.h>
inherit NPC;
int *names = ({YEL,RED,GRN,CYN,BLU,WHT,HIG,});

void create()
{      
        set_name(names[random(sizeof(names))]+"������"+NOR, ({ "hudie", "huahudie" }) );
        set("race", "Ұ��");
	set("gender", "����");
        set("age", 2);
	set("long", "һֻ��������ĺ�����\n");
        set("attitude", "friendly");
	set("str", 5);
	set("con", 20);
        set("limbs", ({ "ͷ��", "����", "���" }) );
        set("verbs", ({ "bite"}) );

	set_skill("dodge", 20);
        set_temp("apply/armor", 1);

        setup();
}

