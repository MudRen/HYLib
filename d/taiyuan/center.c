// /d/taiyuan/center.c
// Room in ̫ԭ
// rich 99/04/05
inherit ROOM;
void create()	
{
	set("short", "̫ԭ�㳡");
	set("long", @LONG
������̫ԭ�ĳ����Ĺ㳡����¥��¥���ڹ㳡�����ߣ����涼��̫
ԭ����Ҫ�ֵ����̼��Ƽ���һ����ȥ����ˮ��������ɽ���˺��ò����֡�
LONG
	);
set("outdoors", "taiyuan");
set("exits", ([
                "north" : __DIR__"beidajie2", 
                "south" : __DIR__"nandajie2", 
                "east" : __DIR__"dongdajie2", 
                "west" : __DIR__"xidajie2",       
	]));
	set("objects",([
	__DIR__"npc/xiake":1,
	]));
       setup();
	replace_program(ROOM);
}	
