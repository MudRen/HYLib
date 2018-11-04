 // copyright apstone, inc 1998
inherit NPC;
inherit F_DEALER;
void create()
{
        set_name("������", ({ "waiter" }) );
        set("gender", "����" );
        set("age", 70);
        set("long",
                "һ��������ʵ��ɢ���Ź�ͭɫ��â������\n");
        set("combat_exp", 5);
        set("attitude", "friendly");
        set("rank_info/respect", "���˼�");
        set("vendor_goods", ({
                __DIR__"obj/milk2",
                __DIR__"obj/milk",
                __DIR__"obj/soda",
                __DIR__"obj/soda2",
        	}));
        setup();
        carry_object(__DIR__"obj/hat")->wear();
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
        switch( random(3) ) {
                case 0:
                        say( "������Ц�����˵������λ" + RANK_D->query_respect(ob)
                                + "���ǿ���ķ��˹��\n");
                        break;
                case 1:
                        say( "������̧������ͭɫ������˵������λ" + RANK_D->query_respect(ob)
                                + "�����������\n");
                        break;
                case 2:
                        say( "������˵������λ" + RANK_D->query_respect(ob)
                                + "��������ɽ��Ҫ��Щ��ˮ�ſ�����·Ӵ��\n");
                        break;
        }
} 
