#include <ansi.h>
//inherit NPC;
inherit NPC;
int estate();
void create()
{
        set_name("������",({"ma yueyun","ma"}));
        set("title","�����ͻ�");
        set("long","
���е�̫̫���ͻۡ����յúܺã���������һ���һ�췢����������
������Ǹ�����С�����ӡ���̫̫����˵ʲô�����ж�ǧ���ٹˡ�
���������̫̫��Сϱ���ǣ�������Ľ��̫̫��һ�����ϱ��ӻ��˵£���
�Բż޵�����һλ���ɷ�\n");
        
        set("gender","Ů��");
        set("group","ma");
        
        set("age",32);          
        set("int",52);
        set("cor",30);
        set("cps",20);
        set("str",40);
        set("marry","����");
        set("marry_name","ma fangzhong");
        
        set("neili",1500);
        set("max_neili",1500);
        set("force_factor",120);
        set("max_atman",500);
        set("atman",500);
        set("max_mana",500);
        set("mana",500);
        set("combat_exp",500000);  
        set("attitude", "friendly");
        
        set_skill("unarmed",200);
        set_skill("dodge",150);
        set_skill("parry",160);
        set_skill("force",180);
        set_skill("move",200); 
        
        set("resistance/kee",30);
        set("resistance/gin",30);
        set("resistance/sen",30);
        
        set("inquiry", ([
                "*":    "�Һ��ٳ��ţ����ʵ���Щ�Ҷ���֪��ѽ��\n",
           ]));
        
        set("nb_chat_chance", 100);
        set("nb_chat_msg_combat", ([ 
        ]) );           
        set("chat_chance_combat", 100);
/*        set("chat_msg_combat", ({
             (: auto_smart_fight(30) :),
        }) );*/
        set("chat_chance",1);
        set("chat_msg",({
                "�����ƿ��˿���ߵ�һ˫��Ů�����������Ц�š�\n",
        }) );                   
        
                
        setup();
        carry_object("/clone/misc/cloth")->wear();
 
}      
