// little_monkey.c

inherit NPC;

void create()
{
	set_name("С��",({ "little monkey", "monkey"}) );
	set("gender", "����");
	set("race", "Ұ��");
	set("age", 1);
	set("long", "����һֻ��Ƥ��С���ӣ�����������ȴϲ��ģ��������\n");
	set("combat_exp", 500);
       set("limbs", ({ "��ͷ", "����", "��צ", "����", "β��" }) );
        set("verbs", ({ "hoof","sting", "claw" }) );
set("shen_type", -1);
	set("str", 11);
	set("dex", 41);
	set("con", 11);
	set("int", 11);
        set("attitude", "peaceful");
        setup();
}
