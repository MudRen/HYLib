// waiter.c

inherit NPC;

void create()
{
	set_name("Ԫ��", ({ "yuan cai", "yuan" }) );
	set("gender", "����" );
	set("title",  "����" );
	set("age", 43);
	set("long",
		"��λ��������ĵ���������ȥ�Һ���ʵ�����ӡ�\n");
	set("combat_exp", 100);
	set("attitude", "friendly");
	set("rank_info/respect", "�ϰ�");
	setup();
}

int accept_object(object who, object ob)
{
	
	if (ob->query("money_id") && ob->value() >= 5000) 
	{
		tell_object(who, "Ԫ��һ������˵������л�͹٣�¥���롣\n");

		who->set_temp("rent_paid",1);

		return 1;
	}

	return 0;
}
