 // garrison.c
#include <ansi.h> 
inherit NPC; 
void create()
{
        set_name("������", ({ "yayi", "ya" }) );
        set("long",
                "�������õ����ۣ�ǧ��Ҫ������\n"); 
        set("attitude", "heroism");
        set("vendetta_mark", "authority");
        set("reward_npc", 1);
        set("difficulty", 5); 
        set("cor", 40);
        set("cps", 25); 
        set("combat_exp", 4000000); 
        set_skill("unarmed", 200);
        set_skill("staff", 200);
        set_skill("parry", 200);
        set_skill("dodge", 200);

        

        
        set("chat_chance", 1);
        set("chat_msg", ({
"���۵��������������������䡫������\n"
        }) ); 
        setup(); 
        carry_object(__DIR__"obj/yafu")->wear();
        carry_object(__DIR__"obj/sawei")->wield();
}   
