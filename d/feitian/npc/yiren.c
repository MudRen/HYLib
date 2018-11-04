// yiren.c

inherit NPC;

void create()
{
	set_name("����", ({ "yi ren","ren","yi" }) );
	set("gender", "����" );
	set("age", 38);
	set("long", "һ���������ˣ������ϴ�����һ����˪����˵�ǴӶ�������\n");

	set("str", 30);
	set("cor", 30);
	set("cps", 30);
	set("int", 15);

	set("max_qi", 500);
	set("max_jing", 100);
	set("neili", 500);
	set("max_neili", 500);
	set("jiali", 50);
	set("shen_type", 0);

	set_temp("apply/attack",  20);
	set_temp("apply/defense", 20);
	set_temp("apply/damage",  20);

	set("combat_exp", 15000);

	set("max_force", 200);
	set("force_factor", 2);

	set_skill("unarmed", 100);
	set_skill("dodge", 100);
	set_skill("parry", 80);
	setup();
	set("chat_chance", 10);
	set("chat_msg", ({
                       "����˵��: С���ǴӶ������ģ�������ػ�������������\n",
		"����˵��: ��ҿ��ò��ã�С�����ү�ǿ��Ÿ���ͭ��ɡ�\n",
		"��������һ������˫�ַ��ɣ����һ·̫�泤ȭ��\n",
		"����һ·ȭ��ʹ�գ���������һ��Ҿ������ЩС������ү�Ǽ�Ц�ˡ�\n",
	}) );
	//add_money("silver", 10);
}

int accept_object(object me, object obj)
{
	if (obj->query("money_id") && obj->value() >= 10) {
        	 command("smile");
	         command("say ��л��λ" + RANK_D->query_respect(me) +"�����¸�����Ҿ�� !");
	}
        else {
        	 command("shake");
	         command("say ���Ǳ�Ǹ�����ֶ����һ��ò��ţ���л��λү�� !");
		 return 0;
        }

	return 1;
}

int accept_fight(object me)
{
	command("say " + RANK_D->query_respect(me) + "�Ź�С�İɣ�С�������������֣�\n");
	return 0;
}
