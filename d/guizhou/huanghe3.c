inherit ROOM;

void create()
{
	set("short", "�Ͻ�����");
	set("long", @LONG
�������Ͻ��ĵİ��ߡ���վ�ڰ��ߵĴ���ϣ���ǰ�Ͻ�����������
���ˡ��޷綼�������ˣ���ˮ������ɳ������������о���̺�����
�𶯡�
LONG );

	set("exits", ([
               "west"      : __DIR__"huanghe4",
               "east"      : __DIR__"huanghe2",
		
	]));


 	set("outdoors", "guizhou");
 	set("valid_startroom", 1);
	setup();
	replace_program(ROOM);
}



