 // garrison.c
#include <ansi.h> 
inherit NPC; 
void create()
{
        set_name("����", ({ "yayi", "ya" }) );
        set("long",
                "�������õ����ۣ�ǧ��Ҫ������\n"); 
        set("attitude", "heroism");
        set("vendetta_mark", "authority"); 
        set("cor", 40);
        set("cps", 25); 
        set("combat_exp", 2000000); 
        set_skill("unarmed", 200);
        set_skill("staff", 350);
        set_skill("parry", 350);
        set_skill("dodge", 350);


        

        
        set_temp("apply/attack", 270);
        set_temp("apply/dodge", 270);
        set_temp("apply/parry", 270);
        set_temp("apply/armor", 370);
        set_temp("apply/damage", 300);
        
        set("chat_chance", 1);
        set("chat_msg", ({
"���۵��������������������䡫������\n"
        }) ); 
        setup(); 
        carry_object(__DIR__"obj/yafu")->wear();
        carry_object(__DIR__"obj/sawei")->wield();
}      
