#include <ansi.h>
//inherit NPC; 
inherit NPC;
void create()
{
        set_name("��������",({"baimian langzhong","baimian","langzhong"}));
        set("title",YEL"����կ �϶�"NOR);
        set("long","
��������������կ�Ķ����ҡ������������ܰף�Ҳ��û�������У�����������
�ú���û��һ����������ţ��ǻ���ʲô���ֺú��������������ѽ��Լ�����
�������ˡ�\n");
        
        set("gender","����");
        set("group","longhuzhai");
        
        set("age",32);          
        set("int",52);
        set("cor",30);
        set("cps",20);
        set("str",80);
        set("class", "tieflag");

        set("reward_npc", 1);
        set("difficulty", 1);
        
        set_skill("sword",180);
        set_skill("dodge",200);
        set_skill("parry",160);
        set_skill("move",150); 

        set_skill("tie-steps",220); 
        
        map_skill("parry","six-chaos-sword");
        map_skill("sword","six-chaos-sword");
        map_skill("dodge","tie-steps");
        map_skill("move","tie-steps");

        
        set("neili",2500);
        set("max_neili",2500);
        set("force_factor",20);
        set("max_atman",800);
        set("atman",800);
        set("max_mana",500);
        set("mana",500);
        set("combat_exp",2000000);  
        set("attitude", "friendly");
        
        set("resistance/kee",30);
        set("resistance/gin",30);
        set("resistance/sen",30);
        
        set("death_msg",CYN"\n$N˵�������߲��������߲��ư�����\n"NOR);          
           
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.chansi" :),
        }) ); 

        set("chat_chance",1);
        set("chat_msg",({
                "�������е���������������˱����Ͳ�ϲ����ܵġ���\n",
        }) );                   
        
//        auto_npc_setup();("wang",200,160,0,"/obj/weapon/","fighter_w","fy-sword",2);
        
        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object(__DIR__"obj/gsword")->wield();    
    
}  
