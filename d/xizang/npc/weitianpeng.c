 // weitianpeng.c
#include <ansi.h> 
inherit NPC; 
void create()
{
        set_name("������", ({ "wei tianpeng","wei" }) );
        set("gender", "����" );
        set("long",
                "�����磬�������������м��������й��������е���\n"
                );
        set("nickname", HIC"ŭ����ն��"NOR);
        set("attitude", "peaceful");
        set("age", 38);
//      set("str", 20);
        set("cor", 20);
        set("agi", 30);
        set("per", 5);
        set("combat_exp", 800000); 
        set("chat_chance", 5);
        set("chat_msg", ({
                "��������������˭�ҵ�����������ү�����Ӷ�����˵�Ͱ���һ�����ˡ�\n",
                }) ); 
        set_skill("unarmed", 100);
        set_skill("parry", 150);
        set_skill("dodge", 100);
        set_skill("blade", 100);
                
        setup();
        add_money("silver", 30);
        carry_object(__DIR__"obj/heipifeng")->wear();
        carry_object(__DIR__"obj/ghostblade")->wield();
}
