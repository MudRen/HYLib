#include <ansi.h>
inherit NPC;
int estate();
void create()
{
        set_name("�ػ���",({"qin huhua","qin"}));
        set("title","³��");
        set("long","
�ػ�����³��������ҵ���һ�����ˣ�����Ѵ���㹻����������Ů����
�����������廹�Ǳ����úܺã��������Ǻܳ��棬����ÿ�����죬����Ҫ
����������һ�����ӡ��ػ��������ֵĵ�λ�����ͣ��ѿ��뵱���κ�����
�������˷�ͥ����\n");
        
        set("gender","����");
        set("group","khlr");
        
        set("age",32);          
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
                "�ػ���Ц�������Ϸ��ķ��������Ѿƣ��ұ��������Կ���֡���\n",
        }) );                   
        
        
        setup();
        carry_object("/clone/misc/cloth")->wear();
 
}  
