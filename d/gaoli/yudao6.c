// /d/gaoli/yudao1
// Room in ����
// rich 99/03/28
inherit ROOM;
void create()	
{
	set("short", "�ʳ�����");
	set("long", @LONG
����Ľֵ������ɾ�������������·�汻��ˮ��ù����羵����
���ڲ��Ǹߴ��ΰ�Ļʳǳ�ǽ��ǽ��Ʈ����һ����������
LONG
	);
set("outdoors", "/d/gaoli");
set("exits", ([
                "south":__DIR__"yudao4", 
                "east":__DIR__"yudao8",
	]));
       setup();
	replace_program(ROOM);
}	
