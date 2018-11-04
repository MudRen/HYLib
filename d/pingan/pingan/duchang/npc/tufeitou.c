// tufeitou.c

inherit NPC;

void create()
{
	set_name("����ͷ", ({ "tufei tou","bandit leader","tou" }) );
	set("gender", "����");
	set("age", 45);
	set("long",
		"��һ�����ɱ����һ�������ɷ��ģ��������������η��\n");
	set("combat_exp", 180000);

        set("shen_type", -1);
	set("attitude", "aggressive");

	set("apply/attack",  10);
	set("apply/defense", 10);

	set("chat_chance", 5);
	set("chat_msg", ({
		"����ͷ�ٺٵ���Ц��: ������ͱ����������ų�ȥ��!\n",
	}) );

	set_skill("blade", 180);
	set_skill("unarmed", 150);
	set_skill("parry", 50);
	set_skill("dodge", 50);

	setup();
       carry_object(__DIR__"obj/gangjian")->wield();
//              carry_object("d/city/npc/obj/gangjian")->wield();
        carry_object("/clone/misc/cloth")->wear();
	add_money("gold", 80);
}
