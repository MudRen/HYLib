#include <ansi.h>
//inherit NPC; 
inherit NPC;
void create()
{
        set_name("������",({"one eye","eye"}));
        set("title",YEL"����կ �ϴ�"NOR);
        set("long","
������������կ���ϴ���ϲ����һ��ڲ�������ֻϹ�˵��۾�����Ϊ��
���������ӿ������������ϡ���ʵ�ϣ���Ҳ��ȷ�Ǹ��������ϵ��ˣ���Ϊ
����Ȼ���̣�ȴ�ܹ�ƽ��ֻ�й�ƽ���ˣ������������ֺú����ϴ�\n");
        
        set("gender","����");
        set("group","longhuzhai");
        set("age",42);
         set("reward_npc", 1);
        set("difficulty", 1);
                
        set("int",22);
        set("cor",30);
        set("cps",20);
        set("str",40);
        set("class", "bat");
        set_skill("blade",180);
        set_skill("dodge",120);
        set_skill("parry",160);
        set_skill("move",150); 
        set_skill("bat-blade",220);
        set_skill("tie-steps",200); 
        
        map_skill("parry","bat-blade");
        map_skill("blade","bat-blade");
        map_skill("dodge","tie-steps");
        map_skill("move","tie-steps");
        
        set("neili",1500);
        set("max_neili",1500);
        set("force_factor",120);
        set("max_atman",500);
        set("atman",500);
        set("max_mana",500);
        set("mana",500);
        
        set("combat_exp",5000000);  
        set("attitude", "friendly");
        
        set("resistance/kee",30);
        set("resistance/gin",30);
        set("resistance/sen",30);
        
        set("death_msg",CYN"\n$N�ں޵�˵�����������һֻ�ۻ��ڵĻ������ľ������ˡ���\n"NOR);    
        set("nb_chat_chance", 100);
        set("nb_chat_msg_combat", ([ 
        ]) );           
         set("chat_chance_combat", 100);
         set("chat_msg_combat", ({

            (: perform_action, "blade.shiwanshenmo" :),
            }) ); 

        set("chat_chance",1);
        set("chat_msg",({
                "������Ц�ŵ�������֪���Ѹ��մ������������ﶺ����ã���\n",
        }) );                   
        
//        auto_npc_setup();("wang",200,200,0,"/obj/weapon/","fighter_w","lianxin-blade",2);
        
        setup();
        carry_object("/clone/misc/cloth")->wear();    
        carry_object(__DIR__"obj/gblade")->wield();    
    
}  
void die()
{
        object me, owner;
        if(objectp(me=query_temp("last_damage_from") )) {    
                if(owner=me->query("possessed")) me = owner;
                if(me->query("wanma/׼��ɱɽ��"))
                        me->set_temp("wanma/������",1);
        }
        ::die();
}
