// duximeng.c ��ϣ��

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("��ϣ��", ({ "du ximeng", "du", "ximeng" }) );
	set("gender", "����");
	set("title", "���ɽׯׯ��");
	set("age", 53 + random(20));
	set("long","���������ɽׯ��ׯ����ѩɽ�ɺ��ľ˾ˡ�\n");
	set("attitude", "friendly");
	set("str", 15);
	set("int", 15);
	set("con", 19);
	set("dex", 17);
	set("combat_exp", 200000);
	set_skill("dodge", 50);
	set_skill("force", 50);
	set_skill("blade", 50);
	set_skill("cuff", 50);
	set_skill("hand", 50);
	set_skill("changquan", 50);

	set_skill("wuhu-duanmendao", 50);
	map_skill("cuff", "changquan");

	map_skill("blade", "wuhu-duanmendao");
	map_skill("parry", "wuhu-duanmendao");
	prepare_skill("cuff", "changquan");


	setup();
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/gangdao")->wield();
}
