//Cracked by Kafei
// tykid.c ̨��С��

inherit NPC;

void create()
{
	set_name("С��", ({ "taiyi kid", "kid" }) );
	set("long", "һ����С��̨�Ķ�ͯ��\n");

	set("age", 5);
	set("gender", "����");
	set("dalivictim",1);

	set("str", 15);
	set("cor", 15);

    set("combat_exp", 100);
	set("max_qi", 100);
	set("qi", 100);
	set_skill("dodge", 3);
	set_skill("parry", 3);
	set_temp("apply/attack", 5);
	set_temp("apply/damage", 1);
	set_temp("apply/armor", 2);
	
	set("attitude", "peaceful");
	set("shen_type", 1);

	setup();
	carry_object("/clone/misc/cloth")->wear();
}
