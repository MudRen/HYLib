inherit ROOM;

void create()
{
	set("short", "���ݵ�");
	set("long", @LONG
�����������ݺ����ݵ�Ҫ�����������ϡ����������ݳ�
�ı��ţ�����ͨ�򳤽��ߵĶɿڡ���·������һ���ޱߵ���
ɫ��Ұ����һƬ���Ϸ�⡣
LONG);
	set("no_clean_up", 0);
	set("exits", ([
  		"north" : __DIR__"to_zhongzhou2",
  		"south":__DIR__"beimen",
	]));
	set("outdoors", "zhongzhou");

	set("coor/x", -230);
	set("coor/y", 50);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
