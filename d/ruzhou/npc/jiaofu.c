// jiaofu.c

inherit NPC;

void create()
{
	set_name("�ŷ�", ({ "jiao fu", "fu" }) );
	set("gender", "����" );
	set("age", 20+random(15));
	set("long",
		"���Ǹ���ʵ�ͽ��������ˣ�ר�Ű��������������ð�����Բ��һ���⡣\n");
	set("combat_exp", random(10000));
   set("str", 25);
   set("dex", 22);
   set("con", 20);
   set("int", 15);
	set("attitude", "heroism");

	setup();
   carry_object("clone/misc/cloth")->wear();
}