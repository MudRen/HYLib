//Cracked by Kafei
// youke1.c �ο�

inherit NPC;

void create()
{
	set_name("�ο�", ({ "you ke", "ke" }) );
	set("long", "һ��Զ�����ĺ����οͣ��糾���ͣ�����ȻΪ��ǰ�����������˸߲��ҡ�\n");

	set("age", 30);
	set("gender", "����");
	set("dalivictim",1);

	set("str", 20);
	set("cor", 20);

    set("combat_exp", 8000);
	set_skill("dodge", 10);
	set_skill("parry", 10);
	set_temp("apply/attack", 10);
	set_temp("apply/damage", 5);
	set_temp("apply/armor", 5);
	
	set("attitude", "peaceful");
	set("shen_type", 1);

	setup();
	carry_object("/clone/misc/cloth.c")->wear();
}
