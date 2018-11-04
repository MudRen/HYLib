//room : /u/jpei/thd/cave.c
#include <ansi.h>

inherit ROOM;

int do_pull(string arg);

void create()
{
	set("short", "�Ҷ�");
	set("long", @LONG
����һ��ɽ���ϵ�С�Ҷ�����Ȼ����������Ҳ���㹻�Ļ�ռ䡣����
͸��������ķ�϶���˽�����ӳ�ö��а����밵������Ķ�������ϡд��һ��
С��(zi)��
LONG
	);
	set("exits",([
		"out" : __DIR__"dongkou.c",
	]) );
	set("no_clean_up",0);
	set("item_desc",([
		"zi": "ֻ���������ü���֮������ֵ��������ϳ������ޣ��밡�밡....����������ֱ�һƬ��Ҷ(ye)����������\n",
		"ye": "һƬ��ͨ����Ҷ�����������ȫ����ס�ˡ�\n",
	]) );
	set("objects",([
		__DIR__"npc/zhou.c" : 1,
	]) ); 

	setup();
}

void init()
{
	add_action("do_pull","pull");
	add_action("do_pull","che");
	add_action("do_pull","move");
	add_action("do_pull","yi");
	add_action("do_quit","quit");
}

int do_pull(string arg)
{
	object me = this_player();

	if (me->is_busy() || me->is_fighting())	return notify_fail("����æ���أ�\n");
	if (arg == "ye") {
		message_vision("$N���ֽ�����Ҷ��������ͷ�����������죬��ʱ����æ��һ��Ծ������֪ƹƹ����һ���������Ӷ����ϵ��¼�ֻ�߹ޣ�����$Nһͷ����\n", me);
		return 1;
	}
	return 0;
}

int do_quit()
{
	write("���ﲻ׼�˳���\n");
	return 1;
}
