// npc: /d/city/npc/libailv.c
// Last Modified by Winder on Jul. 15 2000

#include <ansi.h>

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name( YEL "����" NOR, ({ "peng baoxian","peng","baoxian" }) );
	set("gender", "����" );
	set("title", "����ʹ����ϰ�");
	set("age", 49);
	set("attitude", "friendly");
	set("rank_info/respect", "�ϸ�");
	set("rank_info/rude","�����˵�");
	set("long", @LONG
���ϰ���������ʹ��������ݳ�Ҳ�������������������Ʒ�Ĺ˿ͺ�
�࣬�������������Ǻܽ��ţ��ⲻ�����ϰ嶼���������ˡ�����һ�߸�
һ���˿����ʣ�һ�߻ش�����һ���˿͵���Ѷ������ʱ��ͷ�Ի�ƷԸ�
Щʲô��
LONG);
	set("chat_chance", 30);
	set("chat_msg", ({
		"���ϰ������ô�����͹٣������������ӳ���ô��\n",
		"���ϰ���������͹٣������ϲ���ҪǮ��\n",
		"���ϰ�������ȵȣ������æ���˾͹�����\n",
		"���ϰ壺��һ�ưգ��͹٣���֪����ү�ҵĹ�Ʒ����С�깩Ӧ�ġ�\n",
	}));
	set("inquiry", ([
		"�ʹ�" : "�����ǰ��ǰ���С������ʹ�Ӧ�о��У������ɣ�",
		"here" : "�ף����ҿ��ˣ�������ʹ��̡�������Ʋ��������ŵ�ô��",
	]) );
	set("vendor_goods", ({
		__DIR__"obj/banana",
		__DIR__"obj/banli",
		__DIR__"obj/boluo",
		__DIR__"obj/caomei",
		__DIR__"obj/foshou",
		__DIR__"obj/ganzhe",
		__DIR__"obj/guiyuan",
		__DIR__"obj/hamigua",
		__DIR__"obj/hetao",
		__DIR__"obj/hongzao",
		__DIR__"obj/juzi",
		__DIR__"obj/lemon",
		__DIR__"obj/laiyangli",
		__DIR__"obj/lizhi",
		__DIR__"obj/lizi",
		__DIR__"obj/mangguo",
		__DIR__"obj/pipa",
		__DIR__"obj/putao",
		__DIR__"obj/shiliu",
		__DIR__"obj/shizi",
		__DIR__"obj/taozi",
		__DIR__"obj/xianggua",
		__DIR__"obj/xigua",
		__DIR__"obj/xingzi",
		__DIR__"obj/yali",
		__DIR__"obj/yangmei",
		__DIR__"obj/yingtao",
	}) );
	set("combat_exp", 10000);
	set_skill("unarmed", 22);
	setup();
	carry_object("/clone/cloth/male1-cloth")->wear();
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
	message_vision("���ϰ����ߺ�ȵ�����ʱ���ʹ����������У���Ǯ������ͯ�����ۣ���\n",ob);
	return;
}
