// xiaoer2.c �Ƶ�С��


inherit NPC;
inherit F_DEALER;


void create()
{
	set_name("��С��", ({ "xiao er", "xiao", "waiter" }) );
	set("gender", "����" );
	set("age", 22);
	set("long",
		"��λ��С����Ц�����æ��������ʱ������ڲ����ϵ�Ĩ��������\n");
	set("combat_exp", 100);
	set("attitude", "friendly");
	set("rank_info/respect", "С����");
	set("vendor_goods", ({
		__DIR__"obj/jitui",
		__DIR__"obj/jiudai",
		__DIR__"obj/baozi",
		__DIR__"obj/niurou",
		__DIR__"obj/huasheng"
	}));
	setup();
	carry_object("/clone/misc/cloth")->wear();
}

int init()
{	add_action("do_buy","buy");
	add_action("do_list","list");
}