 inherit NPC;
#include <ansi.h>
void create()
{
        object armor;
        set_name(RED"�������"NOR, ({ "red lama"}) );
        set("gender", "����" );
        set("age", 40+random(10));
        set("int", 30);
        set("long",
                "��̸�ɮ���ܸ���֮����������������ʧ��֮�¡�\n"
                );
        set("class","lama");
        set("combat_exp", 2500000);
        set("score", 900);
        set("fle",50);
        set("neili",1000);
        set("max_neili",1000);
        set("force_factor",50);
        set("atman",2500);
        set("max_atman",2500);
        set("mana",4000);
        set("max_mana",4000);
        set("resistance/kee",30);
        set("class","lama");        
        set("chat_chance", 1);
        set("chat_msg", ({
                "���������Ȼ˵��������һ�ղ��鲼�����������Ǿ�һ�ղ��ܰ�˯��\n",
                (: random_move :),
                }) );
        
        set_skill("iron-cloth", 200);
        set_skill("staff",150);
        set_skill("cloudstaff", 160);
        set_skill("unarmed",150);
        set_skill("bloodystrike", 150);
        set_skill("force", 80);
        set_skill("spells",150);
        set_skill("parry",140);
        
        if (random(2)) set_skill("jin-gang",100);
        
        map_skill("iron-cloth","jin-gang");
        map_skill("parry","cloudstaff");
        map_skill("unarmed", "bloodystrike");
        map_skill("staff", "cloudstaff");
        
        add_temp("apply/iron-cloth", 100);
        
        setup();
        armor=new(__DIR__"obj/redclothh");
        armor->set_name(RED"�����ߺ���"NOR,({"cloth"}) );
        armor->move(this_object());
        armor->wear();
        carry_object(__DIR__"obj/7staff")->wield();
}  
