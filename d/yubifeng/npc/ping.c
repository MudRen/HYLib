// ping.c ƽ����

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("ƽ����", ({ "ping asi", "asi", "ping" }) );
	set("gender", "����");
	set("age", 53);
	set("long","����ѩɽ�ɺ��ļ��͡�һ�������һ�����ӡ�\n");
	set("attitude", "friendly");
	set("str", 15);
	set("int", 15);
	set("con", 19);
	set("dex", 17);
	set("combat_exp", 170000);
	set_skill("dodge", 50);
	set_skill("force", 50);
	set_skill("cuff", 50);
	set_skill("blade", 350);
	set_skill("sword", 350);
	set_skill("liehuo-jian", 350);
	set_skill("changquan", 350);

	set_skill("blade", 50);
	set_skill("hujia-daofa", 350);
	map_skill("blade", "hujia-daofa");
	map_skill("parry", "hujia-daofa");
	map_skill("cuff", "changquan");

	prepare_skill("cuff", "changquan");
	prepare_skill("hand", "sanshou");

	setup();
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/gangdao")->wield();
}
