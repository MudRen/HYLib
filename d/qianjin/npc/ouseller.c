// waiter.c

inherit NPC;
inherit F_DEALER;
#include <ansi.h>
void create()
{
	set_name("����Ů", ({ "cailing" }) );
	set("gender", "Ů��" );
	set("age", 15);
	set("long",
		"��λ�߾��ſ�ţ�Ц����ؿ����㣮\n");
	set("combat_exp", 5000);
	set("attitude", "friendly");
	set("per",30);
       	set("vendor_goods", ({
                __DIR__"obj/ou",
	}));
	set_skill("unarmed",50);
	set_skill("dodge",50);
	setup();
	carry_object("clone/cloth/cloth")->wear();
}

void init()
{	
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
            add_action("do_buy", "buy");
	add_action("do_list", "list");

}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(10) ) {
		case 0:
message_vision("$NЦ������Ĺ��ﶼ������ź����һ�飿\n",this_object(),ob);
			break;
	}
}
int accept_object(object me, object obj)
{
        command("smile");
        command("say ��л��λ" + RANK_D->query_respect(me) +
"����һ�����������Ŀ��ĵģ�");
        return 1;
}

