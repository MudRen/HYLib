inherit NPC;
inherit F_VENDOR;

string query_save_file() { return DATA_DIR + "npc/���ϰ�"; }
void create()
{

	set_name("���ϰ�", ({ "lao ban", "chen", "laoban" }) );
	set("gender", "����" );
	set("age", 22);
	set("long",
		"��λ���ϰ���Ц�����æ����\n");
	set("combat_exp", 100);
	set("attitude", "friendly");
	set("no_get", "1");

	set("vendor_goods", ({
		__DIR__"obj/jinjiezhi",
		__DIR__"obj/zuanshijiezhi",
		__DIR__"obj/yuzhuo",
		__DIR__"obj/yuzhui",
		__DIR__"obj/xianglian",				
	}));

	setup();
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
	switch( random(2) ) {
		case 0:
			message_vision("���ϰ������$Nһ�ᣬЦ������λ"+
			RANK_D->query_respect(ob)+"������Ҫ��ʲô��\n",ob);
			break;
		case 1:
			say( "���ϰ�˵������λ" + RANK_D->query_respect(ob)
				+ "����Ҳ�����㵴��ʦ�İɡ�\n");
			break;
                           }
}



