// /d/gaoli/yaopu
// Room in ����
// rich 99/03/28
inherit ROOM;
void create()	
{
	set("short", "ҩ��");
	set("long", @LONG
�߽�����һ��ҩ��������������㾫��Ϊ֮һ��ֻ��ҩ���ıڰ�
����ҩ�񣬼���С�������æµ���д��ſ��ˡ�ԭ�������ҩ��������
���ĺ�����νӦ�о��У��������Ĵ������Ǯ���뽭�����ˡ�
LONG
	);
set("exits", ([
               "east":__DIR__"xuanwu-2", 
	]));
       set("objects", ([
		"/d/gaoli/npc/jia" : 1,
		__DIR__"npc/lifuren":1,
	]));
       setup();
	replace_program(ROOM);
}	
