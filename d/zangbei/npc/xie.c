#include <ansi.h>

inherit NPC; 

void create()
{ 
        set_name("лС��",({"xie xiaoyu","xie","xiaoyu"}));
        set("title",HIG"��ɽׯ"NOR);
        set("long", "
лС����˵�ӡ���������Ů�����ڰ�ɴ��Լ�б�¶�����е�Ů�Ե�������ֻ��
������һ�����С�һ����ʥ��ׯ�ϵ����У��·���ȫ������һ��ʥ��Ĺ⣬ʹ��
���ұ��ӡ�ʹ��Ը�����һ�У���Ϊ��ǰ��������\n"); 
        set("age",20);
        set("combat_exp", 7500000);
        //set("class","swordsman");               
        set("attitude","friendly");
        set("gender", "Ů��" );
        set("max_atman", 600);
        set("atman", 600);
        set("max_mana", 600);
        set("mana", 600);
        set("max_neili",1500);
        set("neili",1500);
        set("force_factor",120); 
        set("str",40);
        set("cor", 40);
        set("cps", 40);
        set("agi",40);
        set("per",80);
        set("fle",40);
        set("ill_boss",5);

    set_skill("parry",100);
    set_skill("dodge", 100);
    set_skill("force", 100);
    set_skill("literate", 100);
    set_skill("blade", 100);
    set_skill("unarmed",100);
    set_skill("demon-steps",100);
    set_skill("demon-strike",100);
    set_skill("demon-blade",100);
    set_skill("demon-force",100);

    map_skill("parry", "demon-blade");
    map_skill("blade", "demon-blade");
    map_skill("dodge", "demon-steps");
    map_skill("force", "demon-force");
    map_skill("unarmed", "demon-strike");

        
        set("resistance/gin",30);
        set("resistance/kee",30);
        set("resistance/sen",30);
        
//      set("death_msg",CYN"\n$N˵���϶�������Ϊ�ұ���ġ������������� \n"NOR);         
        set("nb_chat_chance", 100);
        set("nb_chat_msg_combat", ([ 
        ]) );       
        set("chat_chance_combat", 100);    
          set("chat_msg_combat", ({
        (: perform_action, "unarmed.dimo" :),
            (: perform_action, "dodge.lianhuanbabu" :),
            (: perform_action, "unarmed.dimo" :),

            }) );

        //auto_npc_setup();("wang",300,200,0,"/obj/weapon/","fighter_w","shadowsteps+dabei",2);
                
        setup();
        carry_object("/clone/misc/cloth")->wear(); 
}  
