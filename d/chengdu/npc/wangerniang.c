// wangerniang.c ������ 
// Last Modifyed by Winder on Dec. 24 2001

inherit NPC;

void create()
{
	set_name("������", ({ "wang erniang", "wang", "erniang" }) );
	set("gender", "Ů��" );
	set("age", 53);
	set("long", "��������50�����ˣ�����������ϣ������ȴ档\n");
	set("combat_exp", 7000);
	set("attitude", "friendly");
	set("rank_info/respect", "������");	
	setup();
	carry_object(__DIR__"obj/cloth/female-cloth")->wear();
	carry_object(__DIR__"obj/cloth/female-shoe")->wear();
	add_money("silver",20);
}

