// /d/gaoli/chaguan
// Room in ����
// rich 99/03/28
inherit ROOM;
void create()	
{
	set("short", "���");
	set("long", @LONG
���ص��������ﶼ�е������������ˮҲ�Ǵӳ���ר�������ġ�
������ĺ������������ɰ����������ķ���Ҳ������ġ�ÿ��
��ĵ�һ�������������ġ������������Ĳ趼��һ�ִ����������
LONG
	);
set("exits", ([
               "north":__DIR__"baihu-2", 
	]));
     set("objects", ([
		"/d/gaoli/npc/chaer" : 1,
               //"/d/gaoli/npc/chake" : 2,
	]));
     set("resource/water",1);
       setup();
	replace_program(ROOM);
}	
