inherit NPC;
inherit F_DEALER;

void create()
{
        set_name("����", ({ "yan song", "song" }) );
        set("gender", "Ů��" );
        set("age", 22);
        set("per", 30);
        set("class","lama");
        set("long",
                "�����Ǹ��׸�ɮ�ĵ�������ӡ�\n");
        create_family("������", 21, "����");
        set("combat_exp", 500000);
        set("attitude", "friendly");

        set_skill("lamaism", 10);
        set_skill("unarmed", 100);
        set_skill("staff", 100);
	set("vendor_goods", ({
		__DIR__"obj/fake-tooth",
	}));
        set("inquiry", ([
                "������": "��....������ӣ��������㡣\n",
                "��������": "��....����������أ����������ڴ�Į���ˡ�\n",
        ]) );

        setup();
        carry_object(__DIR__"obj/whtclothh")->wear();
        carry_object(__DIR__"obj/5staff");
        
}       
void init()
{	
	add_action("do_buy", "buy");
	add_action("do_list", "list");
}