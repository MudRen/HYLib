// Room: /d/ruzhou/yamen.c
// llm 1999/07/04

inherit ROOM;

void create()
{
	set("short", "���ݸ�����");
	set("long", @LONG
�������������������Ŵ��ţ���ľ���������߰�ǽ���쳣��Ŀ��ͭƤ������
�߰ڶ�������ͷ������צ��ʯʨ�ӡ�ǰ����������һ����ģ���Ȼ�ǹ�С����ԩ��
�ġ�ֱ����ȥ�Ϳ��Կ���֪������Ĵ��á�
LONG
	);
	set("exits", ([
	   "south" : __DIR__"wangxi-lu",
      "north" : __DIR__"yamen-datang",
	]));
	set("objects", ([
	]));

	setup();
	replace_program(ROOM);
}

