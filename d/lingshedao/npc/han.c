//NPC: /d/lingshedao/npc/han.c
//Creat by Yjss on Sep.1999 
#include "ansi.h"
inherit NPC;
inherit F_MASTER;
inherit F_UNIQUE;
int ask_yy();
int ask_mj();
void create()
{
        set_name("������", ({"jin hua", "han", "popo", }));
        set("long",
        "�������������׷�����,���Ǹ�ƶ���ϸ�.\n"
        "����ͣ�ؿ�����,����ȥ�ƺ���վҲ�Եü�������!\n"
        );

        set("nickname",HIW"������" NOR);
        set("gender", "Ů��");
        set("attitude", "peaceful");
        set("shen_type",1);

        set("age", 50);
        set("per", 16);
        set("str", 30);
        set("int", 30);
        set("con", 30); 
        set("dex", 30);
        set("qi", 2000);
        set("max_qi", 2000);
        set("jing", 2000);
        set("max_jing", 2000);
        set("neili", 3000);
        set("max_neili", 3000);
        set("jiali", 80);
        set("combat_exp", 2500000);
        set("score", 55000);
    
        set_skill("force", 340);
        set_skill("staff", 360);
        set_skill("dodge", 360);
        set_skill("parry", 340);
        set_skill("shenghuo-shengong", 350);
        set_skill("throwing", 360);
        set_skill("duoming-jinhua", 360);
        set_skill("xiaoyao-bu", 360);
        
        map_skill("parry", "duoming-jinhua");
        map_skill("force", "shenghuo-shengong");
        map_skill("dodge", "xiaoyao-bu");
        map_skill("throwing", "duoming-jinhua");
        
        set("chat_chance", 500);
        set("chat_msg", ({
                (: exert_function, "recover" :),
                (: exert_function, "heal" :),
        }) );
        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: perform_action, "throwing.lianhuan" :),
        }) );
	create_family("����",34, "����");

        set("inquiry", ([
             "����" : (: ask_mj :),
             "��Ҷ����" : (: ask_yy :),
             "������" : "�����õ���������ȥ�������������!\n",
        ]) );

        setup();
        carry_object("/d/lingshedao/obj/jinhua")->wield();
        carry_object("/d/city/obj/cloth")->wear();
}


void init()
{
        object ob=this_player();
        :: init();
        if(interactive(ob)&& ob->query_temp("nk") )
        {
        message_vision("�����Ŷ�$N���һ��:���ⲻ��������?\n",ob);
        kill_ob(ob);
        }
}


int ask_mj()
{
        message_vision("������������߽һ���:���ǹ�ȥ������,����������!
ͻȻ�ع�ͷ��������$N��:�㾿����˭,��������ʲô��?\n",this_player());
        return 1;
}

int ask_yy()
{
       message_vision("��������Ȼ��:��,�����ú�ԩ��!���Ǻ���ţ�⹷������,�Ҳ���Ź�����,
������Ȼ��:���̣����̣�ԭ����������Ϊ������!\n",this_player());
       return 1;
}
#include "fawang.h"