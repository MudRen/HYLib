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
               "east"      : __DIR__"ximen",
               "northwest"      : __DIR__"qingshilu1",
               "south"      : __DIR__"tulu2",
		
	]));

 	set("outdoors", "guizhou");
 	set("valid_startroom", 1);
	setup();
	replace_program(ROOM);
}



