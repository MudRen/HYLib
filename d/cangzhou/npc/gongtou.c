// hou.c

inherit NPC;
#include <ansi.h>;

void create()
{
	set_name("������", ({ "wang dami", "dami", "wang" }));
	set("gender", "����");
	set("nickname", HIC"���й�ͷ"NOR);
	set("age", 40);
	set("str", 20);
	set("dex", 20);
	set("per", 20);
	set("long", "��λ����������еĹ�ͷ������ָ�ӹ��˽������������\n"+
		"��������׬ЩǮ�����Ը���̸̸����\n");
	set("combat_exp", 35000);
	set("shen_type", 0);
	set("attitude", "peaceful");

	set_skill("cuff", 60);
	set_skill("force", 60);
	set_skill("dodge", 60);
	set_skill("parry", 60);
	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/armor", 50);
	set_temp("apply/damage", 30);

	set("neili", 400); 
	set("max_neili", 400);
	set("jiali", 10);

	setup();
	carry_object("/clone/misc/cloth")->wear();
}
