//Cracked by Kafei
// goat.c ɽ��

inherit NPC;

void create()
{
	set_name("ɽ��", ({ "shan yang", "yang", "goat" }) );
	set("race", "Ұ��");
	set("age", 10);
	set("long", "һͷ�̽�ɽ�򣬴�����������ļ���\n");
	set("limbs", ({ "ͷ��", "����", "ǰ��", "�ᱳ", "β��" }) );
	set("str", 25);
	set("cor", 25);
	set("dalivictim",1);
    set("combat_exp", 1000);
	set("max_qi", 200);
	set("qi", 200);

	set_temp("apply/attack", 15);
	set_temp("apply/damage", 6);
	set_temp("apply/armor", 2);
	setup();
}
