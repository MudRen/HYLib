inherit NPC;
inherit F_VENDOR;
string query_save_file() { return DATA_DIR+"npc/��С��";}

void create()
{

	set_name("��С��", ({ "xiao mei", "xiaomei", "xiaomei" }) );
	set("gender", "Ů��" );
	set("age", 22);
	set("long",
		"��λ��С����Ц�����æ����\n");
	set("combat_exp", 100);
	set("attitude", "friendly");
	set("no_get", "1");
	set("rank_info/respect", "С����");
	set("vendor_goods", ({
		__DIR__"obj/tea"

	}));


	set("area_name","�������ͩ԰���");
	set("area_file","/d/jindezheng/tea-room.c");

	setup();
	add_money("silver",5);
	carry_object("/clone/misc/cloth")->wear();
}
void init()
{
object ob;
::init();
if (interactive(ob=this_player())&&!is_fighting()) {
remove_call_out("greeting");
call_out("greeting",1,ob);
}
	add_action("do_buy", "buy");
	add_action("do_list", "list");
}
void greeting(object ob)
{
 if (!living(ob)||environment(ob)!=environment()) return;
command("say ��λ�͹ٿ�Ҫ��һ��������,��һ������?\n");
return;
}


