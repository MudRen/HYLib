// /d/gaoli/sishi
// Room in ����
// rich 99/03/28
inherit ROOM;
void create()	
{
	set("short", "˽��");
	set("long", @LONG
������һ��������ķ��䣬ֻ���ı���������ܣ�����ϵ��鼮
�����Ӱټҵ�ʫ�ʸ踳Ӧ�о��С����䵱����һ��̴����������ǽ����
����һ���ֻ���һλ��������������
LONG
	);
set("exits", ([
               "west":__DIR__"xuanwu-2", 
	]));
      set("objects", ([
		"/d/gaoli/npc/xuejiu" : 1,
		__DIR__"npc/gongzi2":1,
	]));
       setup();
	replace_program(ROOM);
}	
