// /d/yixing/npc/cl_bei.c ����ʯ
// Last Modified by winder on Jul. 12 2002

inherit NPC;

#include <ansi.h>

void create()
{
	set_name("����ʯ", ({ "bei haishi", "bei" }));
	set("nickname", "���ֳɴ�");
	set("party/party_name", HIC"���ְ�"NOR);
	set("party/rank", "�ܹ�");
	set("long", 
		"����һ�������������ˣ�����ȥ��ɫ�԰ף�˵������������\n"
		"����ͣ�Ŀ����ţ��������ز�һ�㡣\n");
	set("gender", "����");
	set("age", 50);
	set("attitude", "friendly");
	set("shen_type", -1);
	set("str", 25);
	set("int", 30);
	set("con", 28);
	set("dex", 28);

	set("max_qi", 111900);
	set("max_jing", 111500);
	set("neili", 111700);
	set("max_neili", 111700);
	set("jiali", 140);
	set("combat_exp", 11200000);
	set("score", 1118000);

	set_skill("force", 500);
	set_skill("dodge", 500);
	set_skill("parry", 500);
	set_skill("cuff",  520);
/*
	set_skill("ding-force",  100);
	set_skill("wuxingbu",   100);
	set_skill("wuxing-quan", 120);

	map_skill("force", "ding-force");
	map_skill("dodge", "wuxingbu");
	map_skill("cuff",  "wuxing-quan");
	map_skill("parry", "wuxing-quan");

	prepare_skill("cuff", "wuxing-quan");
*/
	set("inquiry", ([
		"���ְ�" : "���ְ�ľ������������ܹܡ�",
		"���" : "��ȥ�ʰ����ɡ�",
		"�书" : "�������˼ҵ��书����ǿ���ˣ��㻹�������ѧ�ɡ�",
		"����" : "��λ�����������ɰ������˼�˵���㡣",
		"˾ͽ��" : "�Ҷ����ǰ������˼ҵľ���֮�飬�������Ͻ�ˮ���಻����",
		"����" : "�ҼҰ���˾ͽ��ү�������ϵġ������족Ҳ��",
	]));

	setup();

	carry_object("/clone/misc/cloth")->wear();
}

