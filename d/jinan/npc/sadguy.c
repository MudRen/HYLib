#include <ansi.h>
inherit NPC; 
void create()
{
        set_name("�ϳ���", ({ "duanchang ren","ren" }) );
        set("gender", "����" );
        set("long",
                "һ���Ĵ�Ư�����޼ҿɹ�������ˡ�\n"
                );
        set("title", WHT"���Ĺ���"NOR);
        set("attitude", "peaceful");
    set("age", 25);
        set("str", 10);
        set("cor", 18);
        set("agi", 20);
        set("per", 20);
        set("combat_exp", 20000);
        set("max_qi", 900);
        set("max_gin", 700);
        set("max_sen", 700);
        set("max_force", 400);
        set("force", 500);
        set("force_factor", 10);
        set_temp("apply/damage", 50); 
        set("chat_chance", 1);
        set("chat_msg", ({
                "�ϳ���������������������ѻ, С����ˮ�˼�, �ŵ���������.Ϧ�����£�\n�ϳ��������ġ�����һ���ϳ��������ġ���\n",
                }) ); 
        set_skill("unarmed", 80);
        set_skill("parry", 100);
        set_skill("dodge", 300);
    set_skill("doomforce", 10);
    set_skill("doomstrike", 10);
    set_skill("doomsteps", 20);
    map_skill("unarmed", "doomstrike");
    map_skill("dodge", "doomsteps");
        setup();
        carry_object("/clone/misc/cloth")->wear();
}    
