#include <ansi.h>
//inherit NPC; 
inherit NPC;
void create()
{
        set_name("ɽկ���",({"bandit"}));
        set("title",YEL"����կ"NOR); 
        set("long","һ�������£��������λθֵ���С���ˡ�\n");
        set("gender","����");
        set("age",32);
        set("group","longhuzhai");      
        set("int",22);
        set("cor",30);
        set("cps",20);
        set("str",35);
        
        set_skill("blade",180);
        set_skill("dodge",200);
        set_skill("parry",160);
        set_skill("move",150); 
        set_skill("bat-blade",100);
        set_skill("tie-steps",120); 
        
        map_skill("parry","bat-blade");
        map_skill("blade","bat-blade");
        map_skill("dodge","tie-steps");
        map_skill("move","tie-steps");
        
        set("neili",500);
        set("max_neili",500);
        set("force_factor",90+random(60));
        set("max_atman",200);
        set("atman",200);
        set("max_mana",200);
        set("mana",200);
        
        set("combat_exp",1034101);  
        set("attitude", "aggressive");
                
        set("death_msg",CYN"\n$N�е�������֪�������Ͳ��������ˡ�����\n"NOR);    
        set("nb_chat_chance", 100);
        set("nb_chat_msg_combat", ([
                10: "ɽկ��޽е����������ŵķ��򣬵����ǲ�����ѽ����\n",
                15: "ɽկ��޽е������������������������ס�ˡ���\n",
        ]) );           
        set("chat_chance_combat", 100);
/*        set("chat_msg_combat", ({
             (: auto_smart_fight(20) :),
        }) );*/
        set("chat_chance",1);
        set("chat_msg",({
                "ɽկ��޽е���������կ�Ĵ����ڴˣ������˵������ˣ���\n",
        }) );                   
           
//        CHAR_D->setup();_char(this_object());
//        auto_npc_setup();("wang",150,130,1,"/obj/weapon/","fighter_w","bat-blade",2);
        
        setup();
        carry_object("/clone/misc/cloth")->wear();    
        //carry_object("/clone/weapon/gangdao")->wield();    
}  
int accept_object(object who, object ob)
{ 
        if( ob->value() >= 10000) {
                        command( "say ������������Т˳�ķ��ϣ��͸��������ɡ�");
                        who->set_temp("wild4_pass", 1);
                        who->remove_all_killer();
                        return 1;
                } else {
                        command("say �ޣ��㵱��ү�ǽл��ӣ�\n");
                        return 0;
                }
        return 0;
}     
