// /d/gaoli/yamen
// Room in ����
// rich 99/03/28
inherit ROOM;
void create()	
{
	set("short", "�Ƿ�����");
	set("long", @LONG
�����Ǹ����ĳǷ��õĹ���������������ɼ������м����ų�����
һλ����������칫��������Ҫ��������ǵķ���ȫ���Լ���������
��׽���ӷ������ 
LONG
	);
set("exits", ([
                "west":__DIR__"yudao4",
//                "east": "/d/clone/room/cityroom/gaoli"    
	]));
     set("objects",([
       __DIR__"npc/guanbingc":3,
       ]));
       setup();
	replace_program(ROOM);
}	
