//Cracked by Kafei
// bywoman.c �����̷�

inherit NPC;

void create()
{
	set_name("�����̷�", ({ "shang fan", "fan", "shang" }) );
	set("long", "һ�����ĸ�Ů�����Ÿ���¨����Щ˿֯��Ʒ���ֹ���Ʒ��\n");

	set("age", 30);
	set("gender", "Ů��");
	set("dalivictim",1);

	set("str", 15);
	set("cor", 15);

    set("combat_exp", 2000);
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
