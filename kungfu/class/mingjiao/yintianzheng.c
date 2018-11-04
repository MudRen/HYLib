// YinTianZheng.c
// pal 1997.05.09

#include "ansi.h"

inherit NPC;
inherit F_MASTER;
inherit F_UNIQUE;

void create()
{
	set_name("������", ({"yin tianzheng", "yin", "tianzheng", }));
	set("long",
        "����һλ��Ŀ����ͺ���ߣ���һ����ɫ���ۡ�\n"
        "����üʤѩ�������۽ǣ����ӹ���������ӥ�졣\n"
	);
                                                          
	set("title",HIG "����" HIW "��üӥ��" NOR);
	set("level",9);
	set("gender", "����");
	set("attitude", "peaceful");

	set("age", 72);
	set("shen_type", 1);
	set("per", 22);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set("qi", 13500);
	set("max_qi", 13500);
	set("jing", 11500);
	set("max_jing", 11500);
	set("neili", 23000);
	set("max_neili", 23000);
	set("jiali", 150);
	set("combat_exp", 1900000);
	set("score", 1000000);
    set_skill("cuff", 100);
    set_skill("strike", 100);
    set_skill("qingfu-shenfa", 100);
    set_skill("hanbing-mianzhang", 100);
    set_skill("sougu", 100);
	set_skill("force", 180);
	set_skill("dodge", 120);
	set_skill("unarmed", 185);
	set_skill("parry", 120);
	set_skill("claw", 185);
	set_skill("blade", 160);
	set_skill("jinwu-daofa", 160);
//	set_skill("hand", 185);
	set_skill("literate", 60);
	set_skill("jiuyang-shengong", 180);
	set_skill("xiaoyaoyou", 220);
	set_skill("sougu", 385);
	set_skill("longzhua-gong", 340);

	map_skill("force", "jiuyang-shengong");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("claw", "sougu");
	map_skill("parry", "longzhua-gong");
	map_skill("blade", "jinwu-daofa");

	prepare_skill("claw", "sougu");

	set("chat_chance_combat", 20);
	set("chat_msg_combat", ({
		(: command("perform muyeyingyang") :),
	}) );
	create_family("����",34, "����");
	set_temp("apply/attack", 200);
	set_temp("apply/defense", 200);
	set_temp("apply/damage", 660);
	set_temp("apply/armor", 660);
	setup();

	carry_object("/d/mingjiao/obj/baipao")->wear();
	carry_object("/clone/weapon/gangdao")->wield();
}

void init()
{
	object me,ob;
	me = this_object () ;
	ob = this_player () ;

	::init();

	if (interactive(this_player()) && this_player()->query_temp("fighting"))
	{
		COMBAT_D->do_attack(this_object(), this_player(), query_temp("weapon") );
		this_player()->add_temp("beat_count", 1);
	}       
	if( interactive(ob) && !is_fighting() )
	{
		remove_call_out("greeting");
		call_out("greeting", 1, me, ob);
	}
}

#include "fawang.h"
