// Room: /d/wizard/robot_court.c
// By Jpei  Aug 1997

#include <ansi.h>

inherit ROOM;

void hour_pass();

void create()
{
	set("short", "�����˷�ͥ");
	set("long", @LONG
��������������˺��µĻ����˷�ͥ�����˿�ǽ��һ����ľ������������
�Ļ����˷����⣬����ʲôҲû�С�
�����������Ҫ�����У�ask faguan about ����
����ʱ�ش���󣬿���Ҫ�����ߣ�ask faguan about ����
������ǹ���Ա��������testr <id>������ĳ�����
LONG);

	set("objects", ([
		"/clone/npc/robot-judge" : 1,
	]) );
	set("no_clean_up", 1);
	set("no_fight", 1);
	setup();
//	hour_pass();
}

void init()
{
	add_action("do_test", "testr");
	add_action("do_action", "");
}

int do_action(string arg)
{
	string action = query_verb();

	switch (action) {
		case "gohome":
		case "use":
		case "zhaohuan":
		case "quit":
		case "home":
		case "whistle":
		case "chen":
		case "mache":
		case "use":
		case "fastmove":
		case "dazuo":
		case "exercise":
		case "tuna":
		case "ride":	
		case "meditate":
		case "lian":
		case "practice":
			write("�ⲻ�����������ĵط���\n");
			return 1;
		case "gohome":
		case "use":
		case "zhaohuan":
		case "quit":
		case "home":
    case "whistle":
    case "fastmove":
    case "ride":	
		case "yun":
		case "exert":
		case "perform":
		case "yong":
		case "fight":
		case "hit":
		case "kill":
			write("�ⲻ�����ܴ�ܵĵط���\n");
			return 1;


	}
	return 0;
}

void test_robot()
{
	int i;
	object antirobot;
	object *ob = users();

	message("channel:chat", HIC "�����ġ��������켩�ܲ����������̽Ա��ע�⣬ɨ���ж���ʽ��ʼ��\n" NOR, users());
	for (i = 0; i < sizeof(ob); i++) {
		antirobot = new("/clone/npc/antirobot2");
		antirobot->test_robot(ob[i]);
	}
}
void do_test(string str)
{
	int i;
	object antirobot;
	object ob ,me=this_player();
if (!wizardp(me)) return notify_fail("ֻ��wiz����\n");
if (!str) return notify_fail("<Syntax>: testr <player id>\n");
	ob = LOGIN_D->find_body(str);
	if (!ob) return notify_fail("��... ���������?\n");
if (wizardp(ob)) return notify_fail("���ܶ�wiz��\n");
if (me->query("id")!="hxsd")
	message("channel:chat", HIC "�����ġ�"+me->query("name")+"���������̽Ա��ע�⣬ɨ���ж���ʽ��ʼ��\n" NOR, users());
		antirobot = new("/clone/npc/antirobot"+(2+random(2)));
CHANNEL_D->do_channel( antirobot, "rumor", ob->short(1)+"���ڽ��ܻ����˳�顣");
		antirobot->test_robot(ob);

//message("channel:chat", HIC "�����ġ�"+ob->query("name")+"���ر����������\n" NOR, users());
                ob->delete("liwuopen");

}

void hour_pass()
{
	mixed *local;

	local = localtime(time());
//	if (local[2] == 1) test_robot();
//	call_out("hour_pass", 3600);
}
