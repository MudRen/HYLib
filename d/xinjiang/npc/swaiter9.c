 // copyright apstone, inc 1998
inherit NPC;

inherit F_DEALER;
void create()
{
        set_name("���ε�", ({ "nang seller" }) );
        set("gender", "����" );
        set("age", 30);
        set("long",
                "һ������ͨͨ�ı����ˣ�û��һ�����۵ĵط���\n");
        set("combat_exp", 2000);
        set("attitude", "friendly");
        set("vendor_goods", ({
                __DIR__"obj/nang",
        }));
        setup();
        carry_object(__DIR__"obj/kacloth")->wear();
} 
void init()
{
        object ob; 
        ::init();

        add_action("do_buy", "buy");add_action("do_list", "list");
} 
