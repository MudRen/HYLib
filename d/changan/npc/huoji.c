// huoji. ҩ�̻��
inherit NPC;
inherit F_DEALER;
void create()
{
        set_name("ҩ�̻��", ({ "yaopu huoji", "huoji" }));
        set("str", 20);
        set("gender", "����");
        set("age", 18);
        set("long", "����ƽ��ҽ������������æ�ġ�\n");
        set("combat_exp", 250);
        set("attitude", "friendly");
        set("vendor_goods", ({
                __DIR__"obj/jinchuang",
//                __DIR__"obj/qiannengdan",
                __DIR__"obj/yangjing"
        }));
        setup();
        carry_object(__DIR__"obj/linen")->wear();
}
void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}

