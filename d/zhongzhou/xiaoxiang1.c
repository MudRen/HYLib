inherit ROOM;

void create()
{
	set("short", "С��");
	set("long", @LONG
ǰ�濴��������Ҫ��С����ˣ���������Խ��ϡ�١�����
���Ϻ�����һ�����÷��ӣ�ԶԶ��ȥ�����������¾ɲ�����ԭ
����������
LONG);
	set("no_clean_up", 0);
	set("exits", ([
  		"northwest" : __DIR__"guandimiao",
  		"east" : __DIR__"xiaoxiang",
	]));
	set("outdoors", "zhongzhou");

	set("coor/x", -250);
	set("coor/y", 0);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
