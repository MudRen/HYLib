inherit ROOM;

void create()
{
	set("short", "Ӣ���ƼҶ�¥");
	set("long", @LONG
����Ӣ���ƼҶ�¥����������������Ļ����������˿���
�����۵ף������ϲ���徻һ�㣬����������䡣���ϻ��и�
���䣬�ȶ��˿���������С��Ƭ�̡�
LONG);

	set("exits", ([
		"west" : __DIR__"xiuxishi",
		"down" : __DIR__"yinghao",
	]));
        set("objects", ([
  		__DIR__"npc/richman1" : 1,
	]));

	set("coor/x", -220);
	set("coor/y", 0);
	set("coor/z", 10);
	setup();
}
