// zhou.c ������

#include <command.h>
#include <ansi.h>

inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("������", ({ "zhou-zhiruo","zhiruo","zhou"}));
        set("long",
                "���Ƕ����ɵĵ��Ĵ����ŵ��ӡ�\n"
                "һ�����������ס�����һ�������ѡ�\n"
                "�����������Ц�д���Щ�����Ρ�\n"
                "���ܼ�į��\n");
        set("gender", "Ů��");
        set("age", 20);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("class", "fighter");
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("per", 30);

        set("max_qi", 13500);
        set("max_jing",11000);
        set("neili", 13500);
        set("max_neili", 13500);
        set("jingli", 1000);
        set("max_jingli", 1000);

        set("combat_exp", 15000000);
        set("score", 1000);
        set_skill("persuading", 80);
        set_skill("force", 100);
        set_skill("throwing", 100);
        set_skill("dodge", 100);
        set_skill("finger", 100);
        set_skill("parry", 100);
        set_skill("unarmed", 100);
        set_skill("strike", 100);
        set_skill("sword", 100);
        set_skill("claw", 100);
        set_skill("literate", 100);
        set_skill("mahayana", 100);
        set_skill("jinding-zhang", 300);
        set_skill("jiuyin-baiguzhao", 300);
        set_skill("tiangang-zhi", 300);
        set_skill("huifeng-jian", 300);
        set_skill("zhutian-bu", 300);
        set_skill("linji-zhuang", 330);
        map_skill("force","linji-zhuang");
        map_skill("claw","jiuyin-baiguzhao");
        map_skill("dodge","zhutian-bu");
        map_skill("strike","jinding-zhang");
        map_skill("sword","huifeng-jian");
        map_skill("parry","huifeng-jian");
        prepare_skill("strike","jinding-zhang");
        set_temp("apply/attack", 500);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 550);
        create_family("������", 4, "���ŵ���");

        setup();
        carry_object("/clone/weapon/changjian");
        carry_object("/d/emei/obj/ycloth.c")->wear();
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob=this_player()) && !is_fighting() )
        {
                remove_call_out("greeting");
                call_out("greeting", 2, ob);
        }
}

