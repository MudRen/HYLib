inherit NPC;
inherit F_VENDOR;


void create()
{
	set_name("���", ({ "cuier", "cuier", "cuier" }) );
	set("gender", "����" );
	set("age", 22);
	set("long",
		"��λ�����Ц�����æ����\n");
	set("combat_exp", 100);
	set("attitude", "friendly");
	set("no_get", "1");

	set("vendor_goods", ({
		__DIR__"obj/jiu1",
		__DIR__"obj/jiu2",
		__DIR__"obj/jiu3",
	}));
	set("long","һ������Ĺ���,��������ϸ������,�ߵõ���ͷȥ��\n");

	set("area_name","�㵴С�Ƶ�");
	set("area_file","/d/yandang/jiudian.c");

	set("inquiry", ([
		"ʳ��" : "�Բ���,��λ����,С����յ�±��������,�����Ե�����\n
������ȥ����,�����ʦ��ͨ��׼������ի!",
		"��" : "�Բ���,��λ����,С����յ�±��������,�����Ե�����\n
������ȥ����,�����ʦ��ͨ��׼������ի!",
		]) );	

        setup();
        carry_object(__DIR__"obj/chu_skirt")->wear();
	add_money("coin", 100);
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
  message_vision("$N�������,æӭ������������λ"+
	RANK_D->query_respect(ob)+"������ƺȰ�!\n",this_object());
return;
}



