// chaboshi.c

inherit NPC;

void create()
{
	set_name("����", ({ "fu shang", "shang" }));
	set("shen_type", 1);
	set("str", 30);
	set("gender", "����");
	set("age", 45);
	set("long",
		"����һ�����̣�������ͷ���������·������������\n");
	set("combat_exp", 5000);
	set("attitude", "friendly");
	set("neili", 500); 
	set("max_neili", 500);
	set("jiali", 10);
	
	setup();
	carry_object("/d/city/obj/cloth")->wear();
}
