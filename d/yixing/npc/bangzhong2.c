// /d/yixing/npc/bangzhong.c
// Last Modified by winder on Jul. 12 2002
// skills and exp are set up by message_bangzhu.h file

#include <ansi.h>
inherit NPC;
//inherit F_SSERVER;


void create()
{
	set_name("����", ({ "bangzhong" }));
	set("gender", "����");
	set("party/party_name", HIC"���ְ�"NOR);
	set("party/rank", "������");
	set("age", 20 + random(10));
	set("long", "һ����ĸߴ��׳��������ɱ����һ�������ɷ��ģ����\n");
	set("attitude", "friendly");
	set("shen_type", -1);

	set("str", 24);
	set("int", 10);
	set("con", 24);
	set("dex", 24);

	set("combat_exp", 30000);


	setup();
}

