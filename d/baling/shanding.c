// baling/edao1
// Room in ����
inherit ROOM;

void create()
{
	set("short", "��ɽɽ��");
	set("long", @LONG
������һ����᫲�ƽ��ɽ·�ϣ�ż������һ�����Ұ�޺�������ͷ
����һЩ��֪����С����������ȥ�����ܴ����ܲ����ʻ��̲��������֣�
����ɽ���ﴵ����������磬������������������һЩ�����Ļ��㣬��
���侳�����ӡ��ľ�֮����Ȼ������
LONG);

	set("exits", ([
               "westdown" : __DIR__"shanlu",
               "northdown" : __DIR__"shanlu1",
               "southdown" : __DIR__"xiaoxi",
	]));

 	set("outdoors", "baling");
	setup();
	replace_program(ROOM);
}


