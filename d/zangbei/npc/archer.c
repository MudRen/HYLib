#include <ansi.h>
inherit NPC; 
void create()
{
        set_name("ɽկ������",({"archer"}));
        set("title",YEL"����կ"NOR); 
        set("long","һ�������£�����һ�ѳ�����С���ˡ�\n");
        set("gender","����");
        set("age",32);
        set("group","longhuzhai");      
        set("int",22);
        set("cor",30);
        set("cps",20);
        set("str",35);
        
        set("neili",500);
        set("max_neili",500);
        set("force_factor",90);
        set("max_atman",200);
        set("atman",200);
        set("max_mana",200);
        set("mana",200);
        
        set("combat_exp",1000000);  
        set("attitude", "aggressive");
                
        set("death_msg",CYN"\n$N�е�������֪�������Ͳ��������ˡ�����\n"NOR);    
        set("nb_chat_chance", 100);
        set("nb_chat_msg_combat", ([
                10: "ɽկ��޽е����������ŵķ��򣬵����ǲ�����ѽ����\n",
                15: "ɽկ��޽е������������������������ס�ˡ���\n",
        ]) );           

        set("chat_chance",1);
        set("chat_msg",({ 
        }) );                   
        
         
        setup();
        carry_object("/clone/misc/cloth")->wear();    
    
}    
