#include <ansi.h>
inherit NPC;
int estate();
void create()
{
        set_name("½����",({"lu mantian","lu"}));
        set("long","
���˵���ĸߴ󣬺ܿ�ΰ���ż�����ɫ�ĳ��ۣ����׵�ͷ�����˷��٣���
�ﶣ�����죬����������ö������\n");
        
        set("gender","����");
        
        set("age",72);          
        set("int",52);
        set("cor",30);
        set("cps",20);
        set("str",40);
        
        set("neili",1500);
        set("max_neili",1500);
        set("force_factor",120);
        set("max_atman",500);
        set("atman",500);
        set("max_mana",500);
        set("mana",500);
        set("combat_exp",8500000);  
        set("attitude", "friendly");
        
        set("resistance/kee",30);
        set("resistance/gin",30);
        set("resistance/sen",30);
        
        set("inquiry", ([
 
        ]));
        
        set("nb_chat_chance", 100);
        set("nb_chat_msg_combat", ([ 
        ]) );           
        set("chat_chance",1);
        set("chat_msg",({
                
        }) );                   
        
        
        setup();
        carry_object(__DIR__"obj/cyancloth")->wear();
 
}       
