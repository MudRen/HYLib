// npc: /d/city/npc/gubancheng.c
// Last Modified by Winder on Jul. 15 2000

#include <ansi.h>

inherit NPC;
inherit F_DEALER;
void create()
{
	set_name( YEL "�׽���" NOR, ({ "kong jinjin","kong","jinjin" }) );
	set("gender", "����" );
	set("title", "�׼�ͷ�����ϰ�");
	set("age", 47);
	set("long", @LONG
�׽�����ϰ忪�����ͷ�����Ѿ��кü����ˣ����ܴ�ҵĺ���������
����ҲԽ��Խ�󣬿�����ȴ�����帣����Ȼ����վ��̨���к����⡣��
����ʡ�������ֿ��Լ��ӻ���ǣ�������û��͵���Ļ��ᡣ
LONG
    );
	set("attitude", "friendly");
	set("rank_info/respect", "�ϸ�");
	set("rank_info/rude","�����˵�");
	set("combat_exp",100);
	set("inquiry", ([
		"ͷ��":"����һ�����������۹��������Ҫ����ô�����ۼҵ�ͷ���أ�\n",
		"here":"��Ӵ���͹٣�����ͷ�������ݰɣ��ú�תת�ɡ�\n",
	]) );
	set("chat_chance", 40);
	set("chat_msg", ({
		"���ϰ����Ӵ���͹٣�һ��������������ˣ������˴�����ɫͷ������ˡ�\n",
		"���ϰ�����͹٣�����˵û�У�����Ķ���ү��Ǯ��ͨ�˵����������\n",
		"���ϰ���������͹٣�ѡһ��ϲ����ͷ��ɣ��Ҹ��������������ô����\n",
		"���ϰ�����Ǻǣ��͹٣���Ҫ�ǲ������Ͷ࿴����ɫ���������æ���ء�\n",
	}));
	set("vendor_goods", ({
		__DIR__"obj/damao",             
		__DIR__"obj/mabutoujin",       
		__DIR__"obj/nuanmao",           
		__DIR__"obj/qingshajin",       
		__DIR__"obj/sanshanmao",       
		__DIR__"obj/wanzijin",         
		__DIR__"obj/yizijin",          
		__DIR__"obj/zaoshahuajin",     
		__DIR__"obj/zhanmao",           
	}) );
	set_skill("unarmed", 5);
	setup();
	carry_object( "/clone/cloth/male1-cloth")->wear();
}

void init()
{
	object ob = this_player();
	::init();
	if( interactive(ob) && !is_fighting() )
	{
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
	add_action("do_list", "list");
	add_action("do_buy", "buy");
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	message_vision( "���ϰ�����˽�������æߺ�ȣ�����һ�ƣ���һ�����ۼҵ�ͷ���治������\n",ob);
	return;
}
