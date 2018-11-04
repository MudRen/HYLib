// TIE@FY3
#include <ansi.h>
#include <login.h>
#define MAX_EXP 5000
inherit NPC;
string *death_msg = ({
	HIW "�й���������Ŀ����ѵ�һ����������ɨ��ɨȥ��\n\n" NOR,
	HIW "�йٷ��˷����겾��̾������һ��ز�۵Ķ�����\n\n" NOR,
	HIW "�йٺ��ϲ���˵��������δ�������˰��ˣ����߰ɡ�\n\n" NOR,
	HIW "һ�������Ũ��ͻȻ���֣��ܿ�ذ�Χ���㡣\n\n" NOR,
});
string *revive_loc= ({
        "/d/city/wumiao",
        "/d/city/wumiao",
});

void create()
{
	set_name("����й�", ({ "panguan", "ghost judge" }) );
	set("long",
		"������ߵ�����й٣�ר���������˵�������\n");
	set("attitude", "peaceful");
	set("chat_chance", 5);
	set("chat_msg", ({
		(: random_move :),
		"�йٺȵ���ţͷ��������ڣ�\n"
	}) );
	set("age", 217);
	set("combat_exp", 20000);
	set("str",100);
	set("max_qi", 900);
	set("max_jing", 900);
	set("neili", 3000);
	set("max_neili", 3000);
	set("combat_exp", 1999999);
	set("score", 90000);
           set_skill("dodge", 40);
	set_skill("unarmed", 40);
	setup();
}

void init()
{
	::init();
	if( !previous_object()
	||	!userp(previous_object())
	||	wizardp(previous_object()) ) return;
	call_out( "death_stage", 3, previous_object(), 0 );
}

void death_stage(object ob, int stage)
{
	if( !ob || !present(ob) || (int)ob->query("combat_exp") > MAX_EXP) return;

	tell_object(ob, death_msg[stage]);
	if( ++stage < sizeof(death_msg) ) {
		call_out( "death_stage", 3, ob, stage );
		return;
	} else
		if(ob->is_ghost())
		ob->reincarnate();

	ob->move(revive_loc[random(sizeof(revive_loc))]);
	ob->set("startroom", base_name(environment(ob)));
	message("vision",
		"���Ȼ����ǰ�����һ����Ӱ����������Ӱ�ֺ����Ѿ�������\n"
		"�ܾ��ˣ�ֻ����һֱû������\n", environment(ob), ob);
}


