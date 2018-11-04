
// waiter.c

inherit NPC;
inherit F_DEALER;

int on_service = 0;

void create()
{
	set_name("��С��", ({ "waiter", "snow_inn_waiter" }) );

	set("age", 21);
	set("long",
		"һ��Լ��ʮ��ͷ������С��ƣ���æ��æ���к����ˣ��������\n"
		"list �����Ե�ʲ��ˣ��� buy ����С����ˡ�\n");
	set("chat_chance", 1);
	set("chat_msg", ({
		"��С���������ģ�����С��������\n",
		"��С��һƨ�������ż��ϣ����������\n",
		"��С��˵�������Ľ�����ô�пգ����������������˵��������\n",
	}));
	
		set("vendor_goods", ({
		__DIR__"obj/jitui",
		__DIR__"obj/jiudai",
		__DIR__"obj/shuihu",

		__DIR__"obj/songbing",
		__DIR__"obj/cai",
						
	}));
	
	
	setup();
}

void init()
{
	::init();
	add_action("do_buy", "buy");
	add_action("do_list", "list");
}


int accept_fight(object ob)
{
//	do_chat("��С�����˸�������˵��������Ҫ��ܵĻ���С���ҿɲ��Ƕ��֡�\n");
	say("��С�����˸�������˵��������Ҫ��ܵĻ���С���ҿɲ��Ƕ��֡�\n");
	return 0;
}


