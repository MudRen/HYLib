inherit ROOM;

void create()
{
	set("short", "��ʯ·");
	set("long", @LONG
����һ������ɫ��ʯ�̳ɵĴ��������������������������
��Ϊ�������ר���ٸ�ʹ�ã����Ե��ϼ���û�����ˡ�
LONG );

	set("exits", ([
               "south"      : __DIR__"guanlu1",
               "northwest"      : __DIR__"xingze",
		
	]));

 	set("outdoors", "guizhou");
 	set("valid_startroom", 1);
	setup();
	replace_program(ROOM);
}



