// Room: /d/chengdu/npc/huoji.c
// Last Modifyed by Winder on Jan. 4 2002

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("���", ({ "huoji" }));
	set("str", 20);
	set("gender", "����");
	set("age", 18);
	set("long", "���������м�������������ͦ�ڿ�ġ�\n");
	set("combat_exp", 2500);
	set("attitude", "friendly");
	set("vendor_goods", ({
		__DIR__"obj/jewelry/necklace",
		__DIR__"obj/jewelry/goldring",
		__DIR__"obj/jewelry/biyu",
		__DIR__"obj/jewelry/crystal",
		__DIR__"obj/jewelry/feicui",
		__DIR__"obj/jewelry/manao",
		__DIR__"obj/jewelry/maoeryan",
		__DIR__"obj/jewelry/shanhu",
		__DIR__"obj/jewelry/shouzhuo",
		__DIR__"obj/jewelry/yubei",						
		__DIR__"obj/jewelry/yudai",	
		__DIR__"obj/jewelry/yufa",	
		__DIR__"obj/jewelry/yujie",	
		__DIR__"obj/jewelry/yupei",									
		__DIR__"obj/jewelry/yuruyi",									
		__DIR__"obj/jewelry/yushou",									
		__DIR__"obj/jewelry/yuzhan",													
		__DIR__"obj/jewelry/zhenzhu",													
		__DIR__"obj/jewelry/zumulv",													
	}));

	setup();
	carry_object(__DIR__"obj/cloth/male-cloth")->wear();
	carry_object(__DIR__"obj/cloth/male-shoe")->wear();
}

void init()
{
	add_action("do_list", "list");
	add_action("do_buy", "buy");
}

