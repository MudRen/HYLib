#include <room.h>

inherit ROOM;
void create()
{
	set("short", "�ƹ�");
	set("long", @LONG
����һ��С�ƹݣ��������������ţ��忪������棬��ģ���Ĵ�
�������������˶ൽ���������Ъ�ţ�����һ�̰�����ɱ��ţ���⣬��
�ϼ��ڴ�������̾ƣ����㷹�����֮�ʴ��ϼ����������С���Σ���
Ǯ�����ֺ�ʵ�ݣ������ر������������ǳ�������������¥��¥�ݣ���
������������
LONG );
	set("exits", ([
		"south" : __DIR__"xidajie",
	]));
	set("objects", ([
		__DIR__"npc/xiaoer2" : 1,
	]));
	set("outdoors", "xuzhou");
	setup();
	replace_program(ROOM);
}

