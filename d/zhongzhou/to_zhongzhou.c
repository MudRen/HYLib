inherit ROOM;

void create()
{
  	set ("short", "���ݵ�");
  	set ("long", @LONG
������ֱ�Ĵ�·�������ϱ��Ľ�ͨҪ��������ͨ��������
�����ݳǡ��������ɿ�·��ͨ�򳤽������˽����������ˡ�
LONG);

  	set("outdoors", "zhongzhou");
  	set("exits", ([
  		"south" : __DIR__"to_zhongzhou2",
  		"north":__DIR__"dukoulu",
	]));
  	set("coor/x", -230);
	set("coor/y", 70);
	set("coor/z", 0);
	setup();
}
