//Cracked by Kafei
// bycaisang.c ���ĸ�Ů

inherit NPC;

void create()
{
	set_name("��ɣŮ", ({ "caisang nu", "nu", "girl" }) );
	set("long", "һ������İ��Ĳ�ɣ���\n");

	set("age", 18);
	set("gender", "Ů��");
	set("dalivictim",1);

	set("str", 15);
	set("cor", 15);

    set("combat_exp", 1500);
	set("max_qi", 200);
	set("qi", 200);
	set_skill("dodge", 10);
	set_skill("parry", 10);
	set_temp("apply/attack", 15);
	set_temp("apply/damage", 3);
	set_temp("apply/armor", 3);
	
	set("attitude", "peaceful");
	set("shen_type", 1);

	setup();
	carry_object("/clone/misc/cloth")->wear();
}
