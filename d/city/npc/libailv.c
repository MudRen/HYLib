// npc: /d/city/npc/libailv.c
// Last Modified by Winder on Jul. 15 2000

#include <ansi.h>
inherit NPC;
inherit F_DEALER;

void create()
{
	set_name( YEL "�����" NOR , ({ "li bailv","li","bailv" }) );
	set("age", 43);
	set("title", "���˿Ь���ϰ�");
	set("long", @LONG
�������һ����С�ĺ��ӣ��������ģ�����ȴ���о��񡣴��۾����
�ܿ������Ǹ������������ˡ����������Ь����ϰ塣
LONG
	);
	set("chat_chance", 40);
	set("chat_msg", ({
		"���ϰ��������������ݳ����������Ļ������簡��\n",
		"���ϰ����˵�𱾸��ĳ���ү����������һ��һ�Ĵ���ӣ���ѧ�ʣ�\n",
		"���ϰ�����ٺ٣��͹٣������˵�����찡���չ��չ�С�϶������Ⱑ��\n",
		"���ϰ�����͹٣������ƣ���˫˿Ь����ʰ����������ԣ����Ұ������ϣ���ô����\n",
	}));
	set("inquiry", ([
		"˿Ь" : "������Ҫ��˿Ь�ǰɣ�û���⣬�ۼҵ�Ь�����ݳ���ͷһ�ݣ�\n",
		"here" : "�����ݳǰ������Ǵ��ϱ�ͷһ��������ȥ����\n",
	]) );
	set("vendor_goods", ({
		__DIR__"obj/maxie",
		__DIR__"obj/pixue",
		__DIR__"obj/sifeng_huangxue",
		__DIR__"obj/sifeng_kuanxue",
		__DIR__"obj/sixie",
		__DIR__"obj/baodi_kuaixue",
		__DIR__"obj/xiuhua_xie2",
		__DIR__"obj/zihua_xie",
		__DIR__"obj/gongxie",
		__DIR__"obj/caoxie",
	        __DIR__"obj/flower_shoe",
	}) );

	set("attitude", "friendly");
	set("rank_info/respect", "�ϸ�");
	set("rank_info/rude","�����˵�");
	set("combat_exp",100);
	set_skill("unarmed", 5);
	setup();
	carry_object( "/clone/cloth/male1-cloth")->wear();
}

void init()
{
	object ob = this_player();
	::init();
	if( interactive(ob) && !is_fighting() )
	{
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
	add_action("do_list", "list");
	add_action("do_buy", "buy");
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	message_vision( "���ϰ������ӭ���������͹٣�����˫Ь����������Ҫ����������ɫô����\n",ob);
	return;
}
