// /d/gaoli/xuanwumen
#include <ansi.h>


inherit ROOM;


void create()
{
	set("short", "Ѽ�̽�����");
	set("long", @LONG
��ǰ��һ�����η����Ĵ�(river)�� �������������۾���������
�ɴ���������������һ�����������̯����Ҿͽ������ڰ��ߣ�������
������֧һ��ľ�壬���ϰ����˻�����������㡣���ٹ����Ͷ�������
�ȴ��ɴ��ڶɡ�
LONG
	);

	set("exits", ([
		"east" : __DIR__"dadao2",
		"west" : __DIR__"jiangkou",

	]));



	set("outdoors", "/d/gaoli/edao2");
	setup();
}

