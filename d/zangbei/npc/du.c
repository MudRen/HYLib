#include <ansi.h>
inherit NPC; 
void create()
{
        set_name("������",({"du qinglian","du"}));
        set("title",HIC"��������"NOR);
        set("long","
����ɫ�԰ף��ݷ�������ݣ���ȴЦ���º͡���ֹ���ţ�����Ҳ����������
������Ȼ������Ȼ�в��������������������õ��£��������������͡�������
��ʲô�¶�������Ȥ�����������Ҳ����Ȥ��
\n");
        
        set("gender","����");
        
        set("age",32);          
        set("int",52);
        set("cor",30);
        set("cps",20);
        set("str",40);
        set("per",40);
        set("difficulty",10);
        set("reward_npc",1);
        
        set("neili",1500);
        set("max_neili",1500);
        set("force_factor",120);
        set("max_atman",500);
        set("atman",500);
        set("max_mana",500);
        set("mana",500);
        set("combat_exp",7500000);  
        set("attitude", "friendly");
        
        set("resistance/kee",30);
        set("resistance/gin",30);
        set("resistance/sen",30);
        
        set("death_msg",CYN"\n$N˵�������߲��������߲��ư�����\n"NOR);          
        set("nb_chat_chance", 100);
        set("nb_chat_msg_combat", ([ 
        ]) );      
        set("chat_chance",1);
        set("chat_msg",({
                name()+"����������ѩ�������ʣ���÷�����㡣��¿���Ź��������춣����\n",
        }) );                   
        
        
        setup();
        carry_object(__DIR__"obj/qiucloth")->wear();
        carry_object(__DIR__"obj/dustick")->wield();    
    
}  
