//Cracked by Kafei
// byshanren.c ����ɽ��

inherit NPC;

void create()
{
	set_name("������", ({ "caisun ren", "ren", "man" }) );
	set("long", "һ��׳�����ס��������Ĵ�ׯ�������˸��������һ�ѿ��񵶣���ɽ��������\n");

	set("age", 25);
	set("gender", "����");
	set("dalivictim",1);

	set("str", 25);
	set("cor", 25);

    set("combat_exp", 5000);
	set("max_qi", 200);
	set("qi", 200);
	set_skill("dodge", 10);
	set_skill("parry", 10);
	set_temp("apply/attack", 10);
	set_temp("apply/damage", 5);
	set_temp("apply/armor", 5);
	
	set("attitude", "peaceful");
	set("shen_type", 1);

	setup();
	carry_object("/clone/misc/cloth")->wear();
	}
