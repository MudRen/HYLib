// Room: /u/qingyun/jyzj/dashibi.c
// Written by qingyun
// Updated by jpei

inherit ROOM;

void create()
{
	set("short", "��ʯ��");
	set("long", @LONG
�����˺ܾã�����ϥ�Ƕ��ѱ���������Ѫ���죬����ɽ���Ѳ���ζ���
�ˣ���һ������ǰ�У��ߵ��˴˴���ɽ�ڣ��˴�ɽ����һ�´����磬��ס���
ȥ·��������һ����ƽ̨��
LONG	);
	set("exits", ([
		"east" : __DIR__"dapingtai",
		"west" : __DIR__"xiepo2",
	]));
	set("outdoors", "kunlun");
	set("no_clean_up", 0);

	setup();
}
