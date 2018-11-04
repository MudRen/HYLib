// camel.c

#include <command.h>
#include <dbase.h>
#include <origin.h>

inherit NPC;

void create()
{
        set_name("������", ({ "camel" }));
        set("long","һƥ�����ա�\n");
        set("race", "Ұ��");
        set("age", 5);
        set("limbs", ({ "ͷ��", "����", "����", "β��" }) );
        set("verbs", ({ "bite" }) );
        set("attitude","heroism");
        set("str", 30);
        set("dex", 35);
        set("con", 40);
        set("int", 10);
        set("shen", 1);
        set("combat_exp", 2000);
        set_temp("apply/attack", 7);
        set_temp("apply/damage", 4);
	set_temp("apply/defence",6);
	set_temp("apply/armor",5);
        setup();
}
