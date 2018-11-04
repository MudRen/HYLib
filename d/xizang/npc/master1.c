 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
inherit F_MASTER;
#include <ansi.h>

void create()
{
    set_name("�����", ({ "master hongpao", "master"}) );
    set("nickname", RED "����"NOR);
    set("gender", "����" );
    set("class","quanli");
    set("reward_npc", 1);
    set("difficulty", 10);
    set("age", 88);
    set("per", 10);
    set("str", 100);
    set("ill_boss",5);
    set("int",30);
    set("attitude","friendly");
    set("max_neili", 8000);
    set("neili", 8000);
    set("atman", 5400);
    set("max_atman", 5400); 
    set("mana", 5000);
    set("max_mana", 5000);
    set("no_busy", 9);
            set("neili",16000);
        set("max_neili",16000);

    set("long", "
������ı���Ӧ�úܸߣ����������Ѿ���Ϻ��һ��ή�����ͣ���ͷ�׷�Ҳ�Ѿ�������ˣ�
���Ƶ�����ȫ�����ƣ����Ͼ�Ȼ������Ⱥ컨����Ĵ�����ӣ������Ǵ�˿�ģ����ú�
�ֹ���������Ҫ����\n");
    create_family("������", 4, "����");
    set("rank_nogen",1);
    set("ranks",({"�ŷ�","���","�Ų�","������","ִ����","��ʦ","��ͷ",
                      "������ͷ","����ͷ",HIY"��ʹ"NOR,
                      RED"����"NOR,HIW"�󵱼�"NOR}));
    set("rank_levels",({ 32000,64000,128000,256000,512000,
                             1024000,1536000,2304000,3456000,
                             5187000,26244000 })); 

    set("combat_exp", 15000000);



    set_skill("parry",150);
    set_skill("dodge", 120);
    set_skill("force", 280);
    set_skill("literate", 180);
    set_skill("unarmed",220);
    set_skill("sword",220);

        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.taixubaihuan" :),
                (: perform_action, "unarmed.yaozhan" :),
        }) );
	set_skill("kongshoudao", 300);
	set_skill("bat-blade", 330);
	set_skill("ghosty-force", 300);
	set_skill("ghosty-steps", 300);

	map_skill("unarmed", "kongshoudao");
        map_skill("blade", "bat-blade");
        map_skill("force", "ghosty-force");
        map_skill("parry", "bat-blade");
        map_skill("dodge", "ghosty-steps");
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 600);
   setup();
//   carry_object(__DIR__"obj/thin_sword")->wield();
     carry_object(__DIR__"obj/redcloth3")->wear(); 
     carry_object("/clone/misc/cloth");
     add_money("gold", 1);


} 
