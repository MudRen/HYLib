inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
������һ��Сɽ·��������һ��Сɽ��������ȥ�Ϳ��Ե���ܭ���ˡ�
���ߴ����������о���������������һ������
LONG );

	set("exits", ([
                          "eastup"      : __DIR__"shanbao1",
                         "northwest"      : __DIR__"shanlu2",
		
	]));
	set("outdoors", "guizhou");
	setup();
	replace_program(ROOM);
}



