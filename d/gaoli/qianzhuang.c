// /d/gaoli/qianzhuang
// Room in ����
// rich 99/03/28
inherit ROOM;
void create()	
{
	set("short", "����Ǯׯ");
	set("long", @LONG
���Ǹ�����ģ����һ��Ǯׯ��Ǯׯ���ſڹ���һ��ܴ�Ľ�����
�ƣ�������Ǯׯ�������Ĺ�̨������ɨ�ĸɸɾ�������̨�󼸸��˷���
����С�������æ�Ľ�ͷ�ö
LONG
	);
set("exits", ([
               "east":__DIR__"xuanwu-1", 
	]));
   set("objects", ([
		"/d/gaoli/npc/jin" : 1,
	]));
       setup();
	replace_program(ROOM);
}	
