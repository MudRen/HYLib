inherit ROOM;

void create()
{
	set("short", "������·");
	set("long", @LONG
����������궫·�������ݵ�һ���Ͻ֡����ߵķ��ݿ���
ȥ�Ѿ��ܳ¾��ˡ�·����������ģ�ż����һ������·������
��ǰ�ߣ����������Ŀ�������¥�ˡ�Ҫ������ǵĻ�����Ҫ��
�����ˡ�Ҫ��Ȼ�ȳ��Ź��ˣ�����Ƕ������ˡ�
LONG);
	set("no_clean_up", 0);
	set("outdoors", "zhongzhou");
	set("exits", ([
  		"north" : __DIR__"gongyuan4",
  		"west" : __DIR__"chenglou",
  		"east" : __DIR__"yanling1",
	]));
	set("coor/x", -260);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
