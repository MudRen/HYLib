inherit ROOM;

void create()
{
	set("short", "�Ͻ�����");
	set("long", @LONG
�������Ͻ��ĵİ��ߡ���վ�ڰ��ߵĴ���ϣ���ǰ�Ͻ�����������
���ˡ��޷綼�������ˣ��Ͻ�ˮ������ɳ������������о���̺�����
�𶯡�
LONG );

	set("exits", ([
               "west"      : __DIR__"huanghe3",
               "east"      : __DIR__"huanghe1",
		
	]));


 	set("outdoors", "guizhou");
 	set("valid_startroom", 1);
	setup();
	replace_program(ROOM);
}



