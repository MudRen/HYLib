//Cracked by Kafei
// niu.c ˮţ

inherit NPC;

void create()
{
	set_name("ˮţ", ({ "shui niu", "niu", "cow" }) );
	set("race", "Ұ��");
	set("age", 10);
	set("long", "һͷ�Ϸ�ɽ��������ˮţ���Ǹ�����������Ҳ���������������ˮ��ïʢ������ʮ�ַ�׳��\n");

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
