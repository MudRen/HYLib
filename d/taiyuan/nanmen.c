// /d/taiyuan/nanmen.c
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
set("valid_startroom", 1);
set("exits", ([
                "north" : __DIR__"nandajie1", 
	        "southeast" : __DIR__"sroad1",
	]));
      set("objects", ([
		__DIR__"npc/bing": 2,
		__DIR__"npc/wujiang":1,
	]));
       setup();
	replace_program(ROOM);
}	
