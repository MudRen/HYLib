// /d/city/npc/dangpu_boss.c  created by Baiwt
#include <ansi.h>

inherit NPC;
void create()
{
set_name("����", ({ "xia tian","xia","boss" }) );
	set("gender", "����" );
	set("age", 39);
set("nickname", "�������ϰ�");
	set("long",
       "���ǽ������ĵ��̵��ϰ壬ʮ�־�����\n");
	set("combat_exp", 50000);
	set("attitude", "friendly");
	set("per",30);
	set("no_arrest",1);
	set_skill("unarmed",200);
	set_skill("dodge",200);
	setup();
	carry_object("/clone/misc/cloth")->wear();
}

int accept_object(object who, object ob)
{
	message_vision("$N��$n˵����л�ͣ���\n",this_object(),who);
		return 1;
}
	

