 // copyright apstone, inc 1998
inherit NPC;

inherit F_DEALER;
void create()
{
        set_name("�����Ѹɵ�", ({ "putao seller" }) );
        set("gender", "Ů��" );
        set("age", 30);
        set("long",
                "һ������ͨͨ�ı����ˣ�û��һ�����۵ĵط���\n");
        set("combat_exp", 2000);
        set("attitude", "friendly");
        set("vendor_goods", ({
                __DIR__"obj/putaogan",
        }));
        setup();
        carry_object(__DIR__"obj/skirt")->wear();
} 
void init()
{
        object ob; 
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_buy", "buy");add_action("do_list", "list");
} 
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
                        say( "�����Ѹɵĸ߽е����޺����Ѹɣ����óԲ�ҪǮ�ϣ�����\n");
} 
