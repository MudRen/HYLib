inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
������һ����������Ĵ�����ϡ���Ȼ�ֽ����´��ң��������ܻ�
�����������������ӵġ����̵ġ����Ŵ󳵵���������������ǳ���
�֡���ʱ����������������߷ɳ۶���������һ·��������·������
��������������֡�
LONG );

	set("exits", ([
               "northeast"      : __DIR__"dadao4",
               "southwest"      : __DIR__"tulu5",
		
	]));


 	set("outdoors", "guizhou");
 	set("valid_startroom", 1);
	setup();
	replace_program(ROOM);
}



