// huoji. �����̻��

inherit NPC;
int ask_yaochu();

void create()
{
	set_name("�����̻��", ({ "tiejianpu huoji", "huoji" }));
	set("str", 20);
	set("gender", "����");
	set("age", 18);
	set("long", "���Ǳ��ٸ���������æ�ġ�\n");
	set("combat_exp", 250);
	set("attitude", "friendly");
        set("inquiry", ([
                "����" : (: ask_yaochu :),
                "job"  : (: ask_yaochu :),
                "tiechan":(: ask_yaochu :),
        ]));

	setup();
	carry_object("/clone/misc/cloth")->wear();
}


int ask_yaochu()
{
	object ob;
	ob = this_player ( ) ;
        message_vision("���Ц��������Ҳ��ҪǮ���أ����Ҷ�ʮ�������Ҿ������㣡\n",ob);
	ob->set_temp ("����" , 1 );
	return 1;
}

int accept_object(object who, object ob)
{
	object obj ;
	if (!(int)who->query_temp("����"))
	{
        message_vision("��ƶ�$N˵������Ǯ��ʲô��\n", who);
		return 0 ;
	}
	else
        if (present("tie chan", this_player()))
        {
         message_vision("��ƶ�$N˵�����������������ˣ���Ҫ��ô̰�ġ�\n",who);
                return 0;
        }
        else        	
	if (ob->query("money_id") && ob->value() >= 2000)
	{
		message_vision("��Ƹ���$N������\n" , who);
		this_player()->delete_temp("����" );
		obj=new("/clone/box/tiechan");
		obj->move(this_player());

	}
	return 1;
}