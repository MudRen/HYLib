 // waiter.c
inherit NPC;
inherit F_DEALER;
void create()
{
        set_name("����", ({ "waiter" }) );
        set("gender", "����" );
    set("title", "�ϰ�" );
        set("age", 62);
        set("long",
                "һ����ͷ��Ц�����æ��������ʱ������ڲ����ϵ�Ĩ��������\n");
        set("combat_exp", 5);
        set("attitude", "friendly");
        set_skill("iron-cloth", 2000);
        set_skill("unarmed", 100);
        set_skill("bloodystrike", 50);
        map_skill("unarmed", "bloodystrike");
        set("rank_info/respect", "�϶���");

	set("vendor_goods", ({
                __DIR__"obj/junksword",
                __DIR__"obj/junkblade",
                __DIR__"obj/junkstaff",
                __DIR__"obj/jade3",
                __DIR__"obj/huboots",
                __DIR__"obj/wineskin",
                __DIR__"obj/guskin",
                __DIR__"obj/sheep_leg",
                __DIR__"obj/snake_drug",
                __DIR__"obj/movebook", 
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
        switch( random(3) ) {
                case 0:
                        say( "���ϰ�����Ц�����˵������λ" + RANK_D->query_respect(ob)
                                + "�������ȱ��裬ЪЪ�Ȱɡ�\n");
                        break;
                case 1:
                        say( "���ϰ������ò����ϵ�ë��Ĩ��Ĩ�֣�˵������λ" + RANK_D->query_respect(ob)
                                + "����������\n");
                        break;
                case 2:
                        say( "���ϰ�����˵������λ" + RANK_D->query_respect(ob)
                                + "�������ȼ���С��ľưɣ��⼸��Ŵӽ����￪���Ӵ��\n");
                        break;
        }
} 
