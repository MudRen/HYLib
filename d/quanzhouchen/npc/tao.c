// tao.c
// Last Modified by winder on May. 29 2001

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("������", ({ "tao laoran", "tao", "laoren" }));
	set("gender", "����");
	set("title", "��Ȼ����ϰ�");
	set("age", 53);
	set("long","�������ǳ������Ϻ��ˣ������Ĳ������ֺã���Ǯ������
���Գ�����˶�ϲ����������衣\n");
	set("combat_exp", 200);
	set("attitude", "friendly");
	
	set("vendor_goods", ({
		__DIR__"tea/chabei",
		__DIR__"tea/guanyinchabei",
		__DIR__"tea/longjingchabei",
		__DIR__"tea/molihuachabei",
		__DIR__"tea/xiangpianchabei",
	}));

	setup();
	carry_object("/clone/cloth/cloth")->wear();
}

void init()
{
	add_action("do_list", "list");
	add_action("do_buy", "buy");
}

