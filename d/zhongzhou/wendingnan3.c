inherit ROOM;

void create()
{
	set("short", "�Ķ��Ͻ�");
	set("long", @LONG
�������ݳ��Ķ��Ͻ֣����Ľֵ����˲�������һ������
����һ�Ҳ�С�ķ��ӣ�����Ů�����ų����˵�΢Ц���϶��Ǹ�
���ɵĺõط��������������ں�����С��ͬ��
LONG);
	set("outdoors", "zhongzhou");
	set("objects", ([
  		__DIR__"npc/boy3" : 2,
	]));

	set("exits", ([
  		"south" : __DIR__"wendingnan4",
  		"northeast" : __DIR__"hutong",
  		"north" : __DIR__"wendingnan2",
	]));
	set("no_clean_up", 0);
	set("coor/x", -230);
	set("coor/y", -40);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
