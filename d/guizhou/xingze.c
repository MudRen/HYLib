inherit ROOM;

void create()
{
	set("short", "ƽ����");
	set("long", @LONG
ƽ�����Ƕ��������ص�ʮ�ֽ�ͨҪկ������������ʷ��ɣ��
������������������Ƕ���ʯ����ǽ��ʯ�����
LONG );

	set("exits", ([
               "southwest"      : __DIR__"qingshilu2",
               "east"      : __DIR__"qingshilu3",
               "southeast"      : __DIR__"guanlu2",
               "northwest"      : __DIR__"matou",
		
	]));

 	set("outdoors", "guizhou");
	setup();
	replace_program(ROOM);
}



