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
               "east"      : __DIR__"tulu5",
               "southwest"      : __DIR__"tulu7",
		
	]));

 	set("outdoors", "guizhou");
	setup();
	replace_program(ROOM);
}



