inherit ROOM;

void create()
{
	set("short", "��·");
	set("long", @LONG
����һ����������Ĵ���������Լ����������������������
�����߾����ǹ��ݵ���������������ĳ������˲��ϣ���Ϊ���̵�ԭ
������·�ϻ���һ�Ӷӹٱ�������ż��������Ĺٱ��ɳ۶���������һ
Ƭ������
LONG );

	set("exits", ([
               "northwest"      : __DIR__"tulu3",
               "southeast"      : __DIR__"heyang",
               "south"      : __DIR__"jinyong-cheng",
		
	]));

 	set("outdoors", "guizhou");
 	set("valid_startroom", 1);
	setup();
	replace_program(ROOM);
}



