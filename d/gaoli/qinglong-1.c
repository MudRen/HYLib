// /d/gaoli/zhuquedajie2
// Room in ����
// rich 99/03/28
inherit ROOM;
void create()	
{
	set("short", "�ɷ���");
	set("long", @LONG
������һ��������ʯ�����ϡ�������ǻʳ������ˣ��ϱ��Ǳ�Ӫ
�Ĵ��ţ����治ʱ�����ź���������������һ�������������������
�е��������ǳ����֡�
LONG
	);
set("outdoors", "/d/gaoli");
set("exits", ([
		"west" : __DIR__"qinglong-2",
		"east" : __DIR__"yudao4",
                "north":__DIR__"mafang",
                "south":__DIR__"bingyingdamen",    
	]));
      set("objects",([
         __DIR__"npc/xiake":1,
         ]));
       setup();
	replace_program(ROOM);
}	
