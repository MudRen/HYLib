#include <ansi.h>
inherit NPC; 
void create()
{
        set_name("С��", ({ "xiao fang","fang" }) );
        set("gender", "����" );
        set("long",
                "һ���������⡢Ư������Ĺ¶����ӡ�\n"
                );
        set("title", HIW"����"NOR);
        set("attitude", "peaceful");
        
        set("age", 28);
        set("str", 40);
        set("cor", 36);
        set("agi", 60);
        set("per", 30);
        
        set("combat_exp", 5000000);
        
        set("max_jing", 5000);
        set("max_jing", 5000);
        
        set("neili",3000);
        set("max_neili",3000);
        set("force_factor",100);
        set("no_busy",4);
        set("class","fighter");
         
        set("chat_chance", 1);
        set("chat_msg", ({
                "С��Զ�����Ŵ����ʥĸѩ�壬����ɤ�ӵ�����ӥ������һ�����ҵ�\n�㣬�ҵ�һ���úû��ŵ��㡭��\n",
                }) ); 
        set_skill("unarmed", 200);
        set_skill("parry", 200);
        set_skill("dodge", 300);
        set_skill("sword", 300);
        set_skill("doomforce", 150);

        set_skill("doomsteps", 200);
           set_skill("doomsword",150);
        
        map_skill("sword", "doomsword");
        map_skill("dodge", "doomsteps");
        map_skill("parry","doomsword"); 
        set("chat_chance_combat", 30);
        set("chat_msg_combat",({
                      (:perform_action,"sword.hunranyijian":),
        }));
        
        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object(__DIR__"obj/icesword")->wield();
} 
int accept_object(object me, object obj)
{
        if(obj->query("name") == BLU"ħ�۽�"NOR && obj->query("owner") == me->query("id"))
        {
                message_vision("$N��������ħ�۽������������˸���԰׵����Ϸ�����Ѫɫ��\n", this_object());
                message_vision("$N��$n�м��ص��˵�ͷ������绹���ţ�����֪���������š�\n",this_object(),me);
                if(!me->query("m_success/������ӥ"))
                {
                        me->set("m_success/������ӥ",1);
                        me->add("score",200);
                }
                return 1;
        }
        else
        {
                write("С�����ֵ��������Ӳ��������������²��ܽ������Ķ�������\n");
                return 0;
        }
} 
