// /d/gaoli/xuanwumen
// Room in ����
inherit ROOM;

void create()

{
set("short", "ɽ·");

	set("long", @LONG
��������һ����᫲�ƽ��ɽ·�ϣ�ż������һ�����Ұ�޽�����ͷ
����һЩ��֪����С����������ȥ�����ܴ����ܲ����ʻ��̲��������֣�
����ɽ���ﴵ����������磬������������������һЩ�����Ļ��㣬��
���侳�����ӡ��ľ�֮����Ȼ������
LONG
	);
	

set("outdoors", "/d/gaoli");
set("exits", ([
		"southdown" : __DIR__"shanlu1",
		"northup" : __DIR__"xiaoxi",
                "northwest" : __DIR__"milin1",
	]));
       setup();
	replace_program(ROOM);
}
