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
                "south":__DIR__"yudao5", 
                "west":__DIR__"yudao8",
	]));
set("objects",([
 __DIR__"npc/gongzi":1,
 ]));
       setup();
	replace_program(ROOM);
}	
