// Room: huiyuan
// Date: Haa 96/03/22

inherit ROOM;

int do_say(string arg);

void create()
{
	set("short", "��԰");
	set("long", @LONG
������һ���ľ��Ļ������ڣ�ż���������������д�������������
�У�԰�������Ÿ�ʽ�����Ļ������̾գ�lvju����������lanhua)��ĵ��
��mudan����������������
LONG 
	);
	set("exits", ([
		"out" : "/d/jingzhou/zizhulin7"
	]));


	set("objects",([
		"/d/jingzhou/obj/lvju" : 3,
	]));

	setup();
}

