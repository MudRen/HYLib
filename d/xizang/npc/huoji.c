 // banker.c
#include <ansi.h> 
inherit NPC;
void create()
{
        set_name("С���", ({ "huoji" }) );
        set("title", "��ʱ��æ��");
        set("gender", "����" );
        set("age", 16);
        set("richness",1000000);
        set("long",
"����ӥ������̫�ã���ӥ����ר�Ű�͹ٴ����ӵġ�\n"
                ); 
        set("combat_exp", 2000);
        set("attitude", "friendly");
        set("env/wimpy", 70);
        setup();
        carry_object("/clone/misc/cloth")->wear(); 
        add_money("coin", 1);
}

