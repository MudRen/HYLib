// /d/gaoli/baihuuedajie3
// Room in ����
// rich 99/03/28
inherit ROOM;
void create()	
{
	set("short", "�������");
	set("long", @LONG
������һ��������ʯ�����ϣ�����Ϳ쵽�����ʹ��ˡ������Կ�
���ʹ���Χǽ�������Ǹ����Ķ��ų����ţ�������һ��С���̣����䲻
�󣬿ɶ���ȴ���٣�������һ��С��ݣ�����������������Ȳ衣
LONG
	);
set("outdoors", "/d/gaoli");
set("exits", ([
		"west" : __DIR__"baihu-1",
		"east" : __DIR__"baihumen",
                "north":__DIR__"xiaochipu",
                "south":__DIR__"chaguan",    
	]));
set("objects",([
 __DIR__"npc/dipi":1,
 ]));
       setup();
	replace_program(ROOM);
}	
