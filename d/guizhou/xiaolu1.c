inherit ROOM;

void create()
{
	set("short", "С·");
	set("long", @LONG
�˼���ͨ������Ժ��ɽ��һ��С·��פ����
�����ƺ����������洫�����о���������
LONG );

	set("exits", ([
                        "northeast"      : __DIR__"tulu9",
                        "southwest"      : __DIR__"xiaolu2",

	]));
	set("outdoors", "guizhou");
	setup();
	replace_program(ROOM);
}



