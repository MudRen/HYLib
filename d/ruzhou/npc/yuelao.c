// Npc:/d/ruzhou/npc/yuelao.c
// llm 99/02
inherit NPC;

void create()
{
	set_name("����", ({ "yue lao","yue","lao"}) );
	set("gender", "����");
	set("age", 90);
	set("long",
		"ֻ�������ú׷�ͯ�գ���ĸߴ���Ŀ���顣\n");
	set("combat_exp", 1500000);
   set("qi",1000);
   set("jing",1000);
   set("neili",1000);
   set("jiali",10);
   set("shen_type", 0);
	set("attitude", "heroism");
   set("channel_id", "����");

	set_skill("unarmed", 100);
	set_skill("parry", 100);
	set_skill("dodge", 100);

	setup();
   carry_object("/clone/misc/cloth")->wear();
}
