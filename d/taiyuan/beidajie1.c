// /d/taiyuan/beidajie1.c
// Room in ̫ԭ
// rich 99/04/05
inherit ROOM;
void create()	
{
	set("short", "�����");
	set("long", @LONG
��ʯ�̳ɵĴ���ж�����������Ĺ�����Ȼ�࣬���޸е�ӵ����
�����߾�Ҫ��̫ԭ�����ˣ�������̫ԭ�����Ľ�����������һ������
�ꡣ
LONG);
set("outdoors", "taiyuan");
set("exits", ([
                "north" : __DIR__"beimen", 
                "south" : __DIR__"beidajie2", 
                "east" : __DIR__"jinci", 
                "west" : __DIR__"niaolongdian",       
	]));
	set("objects",([
	__DIR__"npc/girl":1,
	]));
       setup();
	replace_program(ROOM);
}	
