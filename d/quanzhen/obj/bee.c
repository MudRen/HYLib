//Cracked by Roath
//bee.c

inherit NPC;

void create()
{
	set_name("�۷�", ({"bee"}) );
	set("race", "Ұ��");
	set("age", 5);
	set("long", "����һֻ�۷䣬��æ�Ų��ۡ�\n");
	
	set("str", 40);
	set("dex", 50);

	set("limbs", ({ "ͷ��", "����", "���", "β��" }) );
	set("verbs", ({ "bite", "claw" }) );
	set_temp("apply/attack", 33);
	set_temp("apply/armor", 5);
	
	set("chat_chance", 2);
	set("chat_msg", ({
		"�۷������˷ɹ���������ͷ��ת��һȦ���ַ����ˡ�\n",
		"�۷�ɵ�·�ߵ�һ�����޵�Ұ���ϣ�ææµµ�ز����ۡ�\n",
	 }) );

	setup();
}

void unconcious()
{
    die();
}
