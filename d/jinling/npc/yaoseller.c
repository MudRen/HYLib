// herbalist.c
#include <ansi.h>
inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("������", ({"xu lingren","seller"}));
	set("title","ҩ���ƹ�");
	set_skill("unarmed", 20);
	set_skill("parry", 20);
	set_skill("dodge", 70);
	set_skill("literate", 70);
	
	set("combat_exp",10000);
     	set("age", 44);
	set("long",
		"ҩ���ƹ����λ���꺺�ӣ�������������ʮ�꣬��\n"
		"������棬����������ɼ����Լ������屣���ĺ�\n"
		"�ã�������� list ������������Щҩ��\n");
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
		"����": "�����и���ҩ������ֻ����Щ��ȥ���ˣ�����ܿ�ͺã�\n",
		"����": "�����и���ҩ������ֻ����Щ��ȥ���ˣ�����ܿ�ͺã�\n",
		"����": "�����и���ҩ������ֻ����Щ��ȥ���ˣ�����ܿ�ͺã�\n",
	]) );


	setup();
	carry_object(__DIR__"obj/silk-cloth")->wear();
}

void init()
{
	::init();
	add_action("do_buy", "buy");
	add_action("do_list", "list");
}


