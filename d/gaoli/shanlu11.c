// /d/gaoli/xuanwumen
// Room in ����
// rich 99/03/28
inherit ROOM;
void create()	
{
	set("short", "ɽ·");
	set("long", @LONG
������һ��ɽ·�ϡ������ϱ��߲�Զ���Ǹ������������ˡ������
���˲��Ǻܶࡣ����ƽʱ�������˵�������������ȥ����Լ���Կ���
�����ķ��̨��
LONG
	);
set("outdoors", "/d/gaoli");
set("exits", ([
		"southeast" : __DIR__"shanlu10",
        	"north":__DIR__"shanlu12",
	]));
	set("objects", ([
		"quest/skills2/wakuang/kuang/kuangmai" : 2,
	
	]));	
       setup();
	
}

