// /d/gaoli/xuanwudajie1.c
// Room in ����
// rich 99/03/28
inherit ROOM;
void create()	
{
	set("short", "�������");
	set("long", @LONG
������һ��������ʯ�����ϣ������Ǹ����ı����������ţ�����
���߾Ϳ쵽�����ʹ��ˣ���ֵĶ�����һ��˽�ӣ������������������
����һ��ҩ�̡�
LONG
	);
set("outdoors", "/d/gaoli");
set("exits", ([
                "north":__DIR__"xuanwumen", 
                "south":__DIR__"xuanwu-1", 
                "west":__DIR__"yaopu",
                 "east":__DIR__"sishu", 
	]));
       setup();
	replace_program(ROOM);
}	
