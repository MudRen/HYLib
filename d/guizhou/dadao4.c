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
//               "north" :"/d/pengliang/nanmen",
               "northwest"      : __DIR__"dadao5",
               "southwest"      : __DIR__"dadao3",
//               "east"      : "/d/pengliang/dadao2",
//	       "west"      : "/d/yangzhoubei/shulin5",
	]));


 	set("outdoors", "guizhou");
 	set("valid_startroom", 1);
	setup();
	replace_program(ROOM);
}



