#include <ansi.h>
//inherit NPC;
inherit NPC;

int estate();
void create()
{
        set_name("����",({"ma fangzhong","ma"}));
        set("title","��������");
        set("long","
��������˾�����������һ�����������������ؾأ��ӳ��������ڣ�
����û�������κ�һ�����˾��þ���������¡����˾���Ӧ�ó��׵�ʱ��
���ͳ����ף����˾���Ӧ��������Ů��ʱ�����Ͳ��಻��������������
�����������Ⱥá�\n");
        
        set("gender","����");
        set("group","ma");
        
        set("age",32);          
        set("int",52);
        set("cor",30);
        set("cps",20);
        set("str",40);
        set("marry","������");
        set("marry_name","ma yueyun");
        
        set("neili",1500);
        set("max_neili",1500);
        set("force_factor",120);
        set("max_atman",500);
        set("atman",500);
        set("max_mana",500);
        set("mana",500);
        set("combat_exp",8500000);  
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
           "�ϲ�": "�ϲ����ҵ��ֵܣ��ҵ����ѣ�Ҳ���ҵĸ�ĸ����û����������ʮ����
��ʱ���Ѿ�����ɱ���ˡ�",
                "����":       "�ϲ����ҵ��ֵܣ��ҵ����ѣ�Ҳ���ҵĸ�ĸ����û����������ʮ����
��ʱ���Ѿ�����ɱ���ˡ�",
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
                "\n�����ˬ���紵�����ϣ�����Ҳ���ȡ����л���Ժ���������ţ��᲻�û�
��˯����\n",
        }) );                   
        
//        auto_npc_setup();("wang",300,200,0,"/obj/weapon/","fighter_u","nine-moon-claw",1);
        
        setup();
        carry_object("/clone/misc/cloth")->wear();
 
}  
