inherit NPC;
inherit F_VENDOR;

string query_save_file() { return DATA_DIR+"npc/��ľ��ӹ";}
void create()
{
	set_name("��ľ��ӹ", ({ "duanmu" }) );
	set("gender", "����" );
	set("age", 22);
	set("long",
		"��λ��ľ��ӹ��Ц�����æ��������ʱ������ڲ����ϵ�Ĩ��������\n");
	set("combat_exp", 100);
	set("attitude", "friendly");
	set("no_get", "1");

	set("vendor_goods", ({
		__DIR__"obj/guijia",

	}));


	set("area_name","����������");
	set("area_file","/d/jindezheng/gudong-shop.c");

        setup();
carry_object("/clone/misc/cloth")->wear();        
}
void init()
{
::init();
	add_action("do_buy", "buy");
	add_action("do_list", "list");

}
