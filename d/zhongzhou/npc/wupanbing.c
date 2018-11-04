#include <ansi.h>

inherit NPC;
inherit F_DEALER;

void create()
{
  	set_name("���ʱ�", ({ "wu panbing", "wu", "panbing"}));
  	set("gender","����");
	set("age", 56);
	set("title", "ҩ���ϰ�");
	set("combat_exp", 6000);
	set_skill("unarmed", 40);
	set_skill("parry", 40);
	set_skill("dodge", 40);
	set_skill("literate", 20);
	set("chat_chance", 5);
	set("chat_msg", ({
		CYN "���ʱ��ñʸ��������Դ���һ����Ȼ�����ģ����\n" NOR,
		CYN "���ʱ�ʹ�����������ߺ���ʱ���\n" NOR,
		CYN "���ʱ�������ҽ֮�У�Ҫ�����ݸ�ĿΪһ���ˡ�\n" NOR,
	}));
	setup();
	carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/book/mbook1");
        carry_object("/clone/book/mbook2");
}

void init()
{
        add_action("do_buy", "buy");
        add_action("do_list", "list");
}
