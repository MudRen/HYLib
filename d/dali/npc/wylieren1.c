//Cracked by Kafei
// wylieren.c ��������

inherit NPC;

void create()
{
	set_name("����", ({ "lie ren", "ren", "hunter" }) );
	set("long", "һλ�������������֣�����һ�����Ƥë����������������������Ƥ���ġ�\n");

	set("age", 35);
	set("gender", "����");
	set("dalivictim",1);

	set("str", 20);
	set("cor", 20);

    set("combat_exp", 12000);
	set("max_qi", 200);
	set("qi", 200);
	set_skill("dodge", 20);
	set_skill("parry", 20);
	set_temp("apply/attack", 20);
	set_temp("apply/damage", 5);
	set_temp("apply/armor", 10);
	
	set("attitude", "peaceful");
	set("shen_type", 1);

	setup();
	carry_object("/clone/misc/cloth")->wear();
}
