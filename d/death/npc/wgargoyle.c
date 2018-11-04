// gargoyle.c

#include <ansi.h>
#include <command.h>
#include <login.h>

inherit NPC;

string *death_msg = ({
	HIW "���޳�˵����ι�������ģ����ʲô���֣�\n\n" NOR,
	HIW "���޳���������۹ⶢ���㣬����Ҫ�������һ���Ƶġ�\n\n" NOR,
	HIW "���޳����ߡ���һ�����������ͳ�һ�����ʲ�Ķ�����������\n\n" NOR,
	HIW "���޳����ϲ��ӣ�˵�����ף�����δ������ô���ܣ�\n\n" NOR,
	HIW "���޳�ɦ��ɦͷ��̾�������˰��ˣ����߰ɡ�\n\n"
		"һ�������Ũ��ͻȻ���֣��ܿ�ذ�Χ���㡣\n\n" NOR,
});

void create()
{
	set_name("���޳�", ({ "white gargoyle", "gargoyle" }) );
	set("long",
		"���޳�������������ͷ�����㣬���׵����Ͽ������κ�ϲŭ���֡�\n");
	set("attitude", "peaceful");
	set("chat_chance", 15);
	set("chat_msg", ({
//		(: this_object(), "random_move" :),
		"���޳�����һ����������������������������ע��������ʱ�򣬵�����һ�ۡ�\n",
		"���޳��ѳ�������ͷ��������������������Լ��ְ��ֳ�����ָ��\n"
	}) );
	set("age", 217);
	set("combat_exp", 20000);
	set("max_jing", 900);
	set("max_qi", 900);
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
	call_out( "death_stage", 30, previous_object(), 0 );
}

void death_stage(object ob, int stage)
{
	int i;
	object *inv, mailbox,weapon;
	if( !ob || !present(ob) ) return;

	tell_object(ob, death_msg[stage]);
	if( ++stage < sizeof(death_msg) ) {
		call_out( "death_stage", 5, ob, stage );
		return;
	} else
		ob->reincarnate();

        inv =  all_inventory(ob);
        for (i = 0; i < sizeof(inv); i++)
if (!inv[i]->query("ownmake"))
{
                DROP_CMD->do_drop(ob, inv[i]);
}
	mailbox = new("/clone/misc/mailbox");
	mailbox->move(ob);
	ob->move(REVIVE_ROOM);
	ob->set("startroom",base_name(environment(ob)));
        ob->save();
	message("vision",
		"���Ȼ����ǰ�����һ����Ӱ����������Ӱ�ֺ����Ѿ�������\n"
		"�ܾ��ˣ�ֻ����һֱû������\n", environment(ob), ob);
		
	//qiushi
	if (ob->query("startroom")=="/d/death/qiushi")
	{
		message_vision("���������߹�������$N�����ˡ�����\n",ob);
		tell_object(ob,"�㻹������ȥ�ɡ�\n");
		ob->move(ob->query("startroom"));
	}
}


