// /d/gaoli/xuanwumen
// Room in ����
// rich 99/03/28
inherit ROOM;
void create()	
{
	set("short", "ɽ·");
	set("long", @LONG
������һ��ɽ·�ϡ������ϱ��߲�Զ���Ϳ��Ե��������������ˡ�
����ĵ�·��Щ��᫣��㲻��С������������ȥ����Լ��һ���޴��
�����
LONG
	);
set("outdoors", "/d/gaoli");
set("exits", ([
		"south" : __DIR__"shanlu7",
        	"northeast":__DIR__"guangchang",
	]));
       setup();
	
}

