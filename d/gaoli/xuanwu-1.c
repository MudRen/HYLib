// /d/gaoli/xuanwudajie3.c
// Room in ����
// rich 99/03/28
inherit ROOM;
void create()	
{
	set("short", "�������");
	set("long", @LONG
������һ��������ʯ�����ϣ�����Ϳ쵽�����ʹ��ˣ�����ͨ��
�����ţ���ֵĶ��洫�����������Ĵ�������ԭ����һ�������̣�����
��һ��Ǯׯ���ڴ���Ͼ�����������Ǯ��������
LONG
	);
set("outdoors", "/d/gaoli");
set("exits", ([
                "north":__DIR__"xuanwu-2", 
                "south":__DIR__"yudao8", 
                "west":__DIR__"qianzhuang",
                 "east":__DIR__"tiejiangpu", 
	]));
set("objects",([
 __DIR__"npc/gaoli-yongshi":1,
 ]));
       setup();
	replace_program(ROOM);
}	
