 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
inherit F_MASTER;
#include <ansi.h>

void create()
{
    set_name("������", ({ "master yan", "master"}) );
    set("nickname", GRN "����"NOR);
    set("gender", "Ů��" );
    set("class","quanli");
    set("reward_npc", 1);
    set("difficulty", 10);
    set("age", 60);
    set("ill_boss",5);
    set("per", 25);
    set("str", 88);
    set("int",30);
    set("attitude","friendly");
            set("max_jing",16000);
        set("max_qi",16000);
    set("max_neili", 8000);
    set("neili", 8000);
    set("atman", 5400);
    set("max_atman", 5400); 
    set("mana", 5000);
    set("max_mana", 5000);
    set("no_busy", 8);
            set("neili",16000);
        set("max_neili",16000);
        set_skill("literate", 100);
	set_skill("sword",330);
	set_skill("softsword",350);
        set_skill("cloudforce",320);
        set_skill("shadowsteps",320);
	map_skill("force", "cloudforce");
	map_skill("parry","softsword");
        map_skill("sword","softsword");
        map_skill("dodge","shadowsteps");
        map_skill("dodge","shadowsteps"); 
    set("long", "
С�����걾������������ʵ�ģ���ϧ�����Ƕ���ǰ���¡�
�����������Ѿ������ֳ��˼����ܡ�ֻ������һ������Ȼ���˸һ��ɡ�\n");
    create_family("������", 6, "����");
    set("rank_nogen",1);
    set("ranks",({"�ŷ�","���","�Ų�","������","ִ����","��ʦ","��ͷ",
                      "������ͷ","����ͷ",HIW"��ʹ"NOR,
                      RED"����"NOR,HIY"�󵱼�"NOR}));
    set("rank_levels",({ 32000,64000,128000,256000,512000,
                             1024000,1536000,2304000,3456000,
                             5187000,26244000 })); 

    set("combat_exp", 10000000);



    set_skill("parry",200);
    set_skill("dodge", 120);
    set_skill("force", 160);
    set_skill("literate", 150);
    set_skill("unarmed",160);
    set_skill("staff",200);
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 600);      
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.bajian" :),
                (: perform_action, "sword.yixiao" :),
                (: perform_action, "dodge.lianhuanjiao" :),
        }) );





   setup();
   carry_object(__DIR__"obj/junkstaff")->wield();
   carry_object("/clone/misc/cloth")->wear(); 
   add_money("gold", 1);
} 
