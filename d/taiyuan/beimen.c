// /d/taiyuan/beimen.c
// Room in ̫ԭ
// rich 99/04/05
inherit ROOM;
void create()	
{
	set("short", "̫ԭ����");
	set("long", @LONG
̫ԭ�����������������Ǳ��ұ���֮�أ��峯�������ռ��
���У�̫ԭ������ĸ����صأ�����̫ԭ�ķ���ʮ���ϸ����ŵĹ�
����ϸ���̲������Ŀ��̣�һ˿���Ҵ��⡣
LONG
	);
set("outdoors", "taiyuan");
set("exits", ([
                "north" : __DIR__"nroad1", 
                "south" : __DIR__"beidajie1",    
	]));
       set("objects", ([
		__DIR__"npc/bing": 2,
		__DIR__"npc/wujiang":1,
	]));
       setup();
	replace_program(ROOM);
}	
