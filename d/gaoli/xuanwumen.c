// /d/gaoli/xuanwumen
// Room in ����
// rich 99/03/28
inherit ROOM;
void create()	
{
	set("short", "������");
	set("long", @LONG
�����Ǹ����������š�����͵��˳��У�Զ����ɽ�˺�����������
��������������һ����·ͨ��η�����������һЩִ�ڵı�ʿ��������
��Ķ���������ʿ��
LONG
	);
set("outdoors", "/d/gaoli");
set("exits", ([
		"south" : __DIR__"xuanwu-2",
        	"north" : __DIR__"shanlu1",
        	"northeast":__DIR__"shanlu6",
        	"northwest":__DIR__"shanlu9",
	]));
set("objects",([
  "/clone/npc/man":2,
  __DIR__"npc/guanbing":4,
  __DIR__"npc/wujiang":1,
  ]));
       setup();
	
}

