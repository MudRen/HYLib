// huoji. ҩ�̻��

inherit NPC;
inherit F_DEALER;
int ask_yaochu();

void create()
{
	set_name("ҩ�̻��", ({ "yaopu huoji", "huoji" }));
	set("str", 20);
	set("gender", "����");
	set("age", 18);
	set("long", "����ƽ��ҽ������������æ�ġ�\n");
	set("combat_exp", 250);
	set("attitude", "friendly");
	set("vendor_goods", ({
		"/clone/misc/jinchuang",
		"/clone/misc/yangjing",
		"/clone/misc/wuchangdan",
		"/clone/misc/zhujingchan",
		"/clone/misc/dust",
		"/clone/misc/yaodan",
                "/clone/misc/neilidan",
		"/d/shenlong/obj/xionghuang",
	}));
        set("inquiry", ([
                "ҩ��" : (: ask_yaochu :),
                "job"  : (: ask_yaochu :),
                "yaochu":(: ask_yaochu :),
        ]));

	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}

int ask_yaochu()
{
	object ob;
	ob = this_player ( ) ;
        message_vision("���Ц����ҩ��Ҳ��ҪǮ���أ�����һ�������Ҿ������㣡\n",ob);
	ob->set_temp ("ҩ��" , 1 );
	return 1;
}

int accept_object(object who, object ob)
{
	object obj ;
	if (!(int)who->query_temp("ҩ��"))
	{
        message_vision("��ƶ�$N˵������Ǯ��ʲô��\n", who);
		return 0 ;
	}
	else
        if (present("yao chu", this_player()))
        {
         message_vision("��ƶ�$N˵������������ҩ���ˣ���Ҫ��ô̰�ġ�\n",who);
                return 0;
        }
        else        	
	if (ob->query("money_id") && ob->value() >= 100)
	{
		message_vision("��Ƹ���$Nҩ����\n" , who);
		this_player()->delete_temp("ҩ��" );
                obj=new("/u/hxsd/cloth");
		obj->move(this_player());

	}
	return 1;
}
