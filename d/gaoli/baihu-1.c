// /d/gaoli/baihu-1
// Room in ����
// rich 99/03/28
inherit ROOM;
void create()	
{
	set("short", "�������");
	set("long", @LONG
������һ��������ʯ�����ϣ�����Ϳ쵽�����ʹ��ˡ������Կ�
���ʹ���Χǽ�������Ǹ����Ķ��ų�����,������һ����լ,��ǽ��Ժ��
����һ��������������һ�����С���������Ļ��
LONG
	);
set("outdoors", "/d/gaoli");
set("exits", ([
		"west" : __DIR__"yudao5",
		"east" : __DIR__"baihu-2",
                "north":__DIR__"dafujia1",
                "south":__DIR__"shanghang",    
	]));
	set("objects",([
	  __DIR__"npc/shusheng":1,
	  ]));
       setup();
	replace_program(ROOM);
}	
