// Room: /u/qingyun/jyzj/songshu.c
// Written by qingyun
// Updated by jpei

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һ�곤���ͱ��ϵ����������϶��������ܿ���������֮��ղŴ���
������֮ʱ���޷��ˣ��������������Բ����ļ£���ͷ�亹�乶��¡��ٿ���
�����ƣ�������Ԯ�Ǿ������ܣ�������Ҳ����ס�����������£�ʮ֮�˾�
��û�����˵ģ�Ψ������ɽ��б�£����������г�ȥ��������ѩɽ�ϵ�б�£�
�����ǰ�ɽ���¡�
LONG	);
/*	set("exits",([
	]));*/
	set("no_clean_up", 0);
	set("outdoors", "kunlun");
	setup();
}

void init()
{
	add_action("do_climb", ({"climb", "pa"}));
}

int do_climb(string arg)
{
	object me = this_player();

	if (arg == "east") {
		message("vision", me->name() + "����̫������ĵط���ȥ��\n", environment(me), ({me}));
		write("�������ѩɽб����ȥ��\n");
		me->move(__DIR__"xiepo1");
		message("vision", me->name() + "�������Ǳ����˹�����\n", environment(me), ({me}));
		return 1;
	}
	if (arg == "west") {
		message("vision", me->name() + "��������ȥ��\n", environment(me), ({me}));
		write("���������������ȥ��\n");
		me->move(__DIR__"banshanya");
		message("vision", me->name() + "�������Ǳ����˹�����\n", environment(me), ({me}));
		return 1;
	}
	return 0;
}