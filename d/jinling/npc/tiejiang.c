// smith.c
inherit NPC;
inherit F_DEALER;


void create()
{
	set_name("����", ({ "tie jiang","tie","jiang" }) );
	set("str", 29);
	set("cor", 17);
	set("cps", 15);

	set("long",
		"һ����Ĵ�׳����������æµ�ع�������\n"
		"���������һЩ������������ list ������Щ�������� buy ����������\n");
	set("vendor_goods", ({
		__DIR__"obj/longsword",
		__DIR__"obj/blade",
		__DIR__"obj/hammer",
		__DIR__"obj/shield",		
	}));


	set("chat_chance", 5);
	set("chat_msg", ({
		"������һ���պ�����顸�͡���һ������һ�Ե�ˮ���С�\n",
		"���������е������������������ô�\n",
		"����˵����վ���㣬С�ı������ˡ�\n",
		"����˵������ ... ����Ҹ�æ���ˡ�\n",
	}));
	setup();
	carry_object(__DIR__"obj/linen")->wear();
}

void init()
{
	::init();
	add_action("do_buy", "buy");
	add_action("do_list", "list");
}

int accept_fight(object me)
{
        command("say " + RANK_D->query_respect(me) + 
"���ܣ��ѵ��һ�������\n");
        return 1;
}
 
