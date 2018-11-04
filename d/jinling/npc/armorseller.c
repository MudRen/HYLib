// golder.c

#include <ansi.h>
inherit NPC;
inherit F_DEALER;
int do_make(string arg);

void create()
{
	set_name("����ؤ", ({"beggar","seller"}));
	set("title","Ʀ�Ӱ�����");
       set("nickname", HIW "��ؤ��" NOR );
	set_skill("unarmed", 100);
	set_skill("parry", 100);
	set_skill("dodge", 150);
       set_skill("blade", 100);
	set("gender","����");

	set("force",2000);
	set("max_force",2000);
	set("str",70);
	set("food",200);
	set("water",200);
	set("combat_exp",40000);

	set("age", 37);
	set("long", @LONG
�����ǽ������İ��Ʀ�Ӱ������������������ʮ���꣬
�����⣬̫��Ѩ�߸߹���һ����ֻ�书������
LONG
);


	set("vendor_goods", ({
		__DIR__"obj/armor",
	}));
	setup();
       set("chat_chance", 40);
       set("chat_msg", ({
                "����ؤ˵�����������и�����......��Ҫ��Ҫѽ��\n",
                (: random_move :)
        }) );


	carry_object(__DIR__"obj/linen")->wear();
        carry_object(__DIR__"obj/betbook");

	carry_object(__DIR__"obj/blade")->wield();
}

void init()
{
	::init();
	add_action("do_vendor_list", "list");
	add_action("do_buy", "buy");
}

