// jiang.c ����ȭʦ

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("����ȭʦ", ({ "jiang" }) );
	set("gender", "����");
	set("title", "�����޼��ŵ���");
	set("age", 63);
	set("attitude", "friendly");
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("combat_exp", 400000);
	set_skill("dodge", 180);
	set_skill("force", 180);
	set_skill("cuff", 180);
	set_skill("hand", 180);
	set_skill("changquan", 180);

	map_skill("cuff", "changquan");
	map_skill("hand", "sanshou");
	map_skill("parry", "sanshou");

	setup();
	carry_object("/clone/misc/cloth")->wear();
}
