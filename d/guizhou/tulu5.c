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
               "north"      : __DIR__"heyang",
               "northeast"      : __DIR__"dadao3",
               "west"      : __DIR__"tulu6",
		
	]));

 	set("outdoors", "guizhou");
	setup();
	replace_program(ROOM);
}



