// Room: /d/taishan/zhanlutai.c
// Last Modified by Winder on Aug. 25 2001

inherit ROOM;

void create()
{
	set("short", "հ³̨");
	set("long", @LONG
���������о�ʯͻأ����Լ����ʯ�Դ��顰հ³̨�����׳�ᦸ�
ʯ�����������Ǵ�հ³��������
LONG );
	set("exits", ([
		"down" : __DIR__"aishen",
	]));
	set("objects", ([
		__DIR__"npc/houjian" : random(2)+1,
		__DIR__"npc/daopao" : random(2)+1,
	]));
	set("outdoors", "taishan");
	set("coor/x", 370);
	set("coor/y", 760);
	set("coor/z", 220);
	setup();
	replace_program(ROOM);
}
