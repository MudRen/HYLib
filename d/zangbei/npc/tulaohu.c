#include <ansi.h>
//inherit NPC; 
inherit NPC;
void create()
{
        set_name("���ϻ�",({"tu laohu","tu","laohu"}));
        set("title",YEL"����կ ����"NOR);
        set("long","
���ϻ���ͷ�Ա����ͱ�һֻ�ϻ��������˶��٣������ںȾ�֮������ֱ����
��������Ҳ���ϻ���Ҫ�ס������׵���ȭͷ����˵��һȭ���Դ���ֻ���ϻ���
����Ȼû����Ŀ�����ȴû���˸һ��ɡ���Ϊ��һȭ���������Ѳ��١�\n");
        set("gender","����");
        set("age",32);
        set("group","longhuzhai");
         set("reward_npc", 1);
        set("difficulty", 1);
                
        set("int",22);
        set("cor",30);
        set("cps",100);
        set("str",40+random(50));
        
        set_skill("unarmed",300);
        set_skill("dodge",120);
        set_skill("parry",160);
        set_skill("move",150); 
        
        set("neili",1500);
        set("max_neili",1500);
        set("force_factor",10);
        set("max_atman",500);
        set("atman",500);
        set("max_mana",500);
        set("mana",500);
        set("combat_exp",4500000);  
        set("attitude", "friendly");
        
        set("resistance/kee",30);
        set("resistance/gin",30);
        set("resistance/sen",30);
        set("step_less",2);
        
        
        set("death_msg",CYN"\n$N��һ�ٶ���ص����ӣ�����÷��˳�ȥ���ɳ�ȥ�����⣬���ص�ײ
��ǽ�ϣ�������ǽ��������\n"NOR);         
        set("nb_chat_chance", 100);
        set("nb_chat_msg_combat", ([ 
        ]) );           
           set("chat_chance_combat", 100);
         set("chat_msg_combat", ({

            (: perform_action, "unarmed.paoxiao" :),
            }) ); 
        set("chat_chance",1);
        set("chat_msg",({
                "���ϻ���Ц����������������Ҹ��ط�˯�������Ҵ�ط��ˣ�����û�д���ֻ�йײġ���\n",
        }) );                   
        
//        auto_npc_setup();("wang",200,200,0,"/obj/weapon/","fighter_w","dragonstrike-jg",2);
        
        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object(__DIR__"obj/seed");    
    
}   
void die()
{
        object me, owner;
        if(objectp(me=query_temp("last_damage_from") )) {    
                if(owner=me->query("possessed")) me = owner;
                if(me->query("wanma/׼��ɱɽ��")) me->set_temp("wanma/���ϻ�",1);
        }
        ::die();
}
