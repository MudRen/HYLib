// yangzhou 's ����

inherit NPC;

void create()
{
	set_name("����", ({ "laoshu","hao zi","mouse" }) );
	set("race", "Ұ��");
	set("age", 3);
	set("long", "һֻ������\n");
	
	set("str", 20);
	set("con", 10);

	set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }) );
	set("verbs", ({ "bite", "claw" }) );

	set("chat_chance", 30);
	set("chat_msg", ({
		(: this_object(), "random_move" :),
		"����֧����֧�����˼�����\n",
		"������������㡣\n",
                         }));		
	set_temp("apply/attack", 10);
	set_temp("apply/armor", 100);
        set("env/wimpy",80);
       set("no_clean",1);
	setup();
        add_money("coin", 10);
}




int accept_object(object who, object ob)
{
	if( ob->id("huashenmi") ) {
		set_leader(who);
                this_object()->set("title",who->query("name")+"����");
		message("vision", name() + "�������ת��һȦ��\n", environment());
		return 1;
	}

return 0;

}
