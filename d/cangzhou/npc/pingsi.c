
inherit NPC;
#include <ansi.h>;
void create()
{
	set_name("ƽ��", ({ "ping si", "ping", "si" }));
	set("gender", "����");
	set("age", 40);
	set("str", 20);
	set("dex", 20);
	set("long", "����һλ�������ˣ�ԭ�ǲ��ݿ�ջ��һ���ջ��С��ƣ�\n"+
		"�������˷�ͺ�һ���������˺�һ�������Ӻ�쳣����������ˡ�\n");
	set("combat_exp", 150000);
	set("shen_type", 1000);
	set("attitude", "peaceful");

	set_skill("cuff", 160);
	set_skill("force", 160);
	set_skill("dodge", 160);
	set_skill("parry", 160);
	set_temp("apply/attack", 120);
	set_temp("apply/defense", 120);
	set_temp("apply/armor", 130);
	set_temp("apply/damage", 110);

	set("neili", 1900);
	set("max_neili", 1900);
	set("jiali", 20);
	setup();
	carry_object("/clone/misc/cloth")->wear();
}
