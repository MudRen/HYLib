 inherit NPC;
#include <ansi.h>
void smart_fight(); 
void create()
{
        set_name("�·��ܻ��������κ������������", ({ "middle aged man", "man" }) );
        set("gender", "����" );
        set("age", 44);
        set("cor", 30);
        set("cps", 30);
        set("int", 30); 
        set("max_neili", 2000);
        set("neili", 2000);
        set("force_factor", 30); 
        set("long","����������һ�����������һ���������Ź��ƣ��������˿�������������¡�\n"); 
        set("combat_exp", 2000000);
         set("score", 200);
 

        
        set_skill("move", 200);
        set_skill("parry", 150);
        set_skill("dodge", 150);
        set_skill("unarmed", 150);
        set_skill("luoriquan",150);
        set_skill("fengyu-piaoxiang",200);
        
        map_skill("unarmed","luoriquan");
        map_skill("dodge","fengyu-piaoxiang");
        map_skill("move","fengyu-piaoxiang");
        
        setup();
        carry_object("/clone/misc/cloth")->wear();
} 
