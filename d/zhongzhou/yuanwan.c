inherit ROOM;

void create()
{
        set("short", "��Ա�⸮ۡ");
        set("long", @LONG
���������ݸ�����Ա�⸮ۡ��ǰԺ��һ�����ǽ���ϻ�
�˸���ĵ��ĸ��֡��ƹ�ǽ�ſ��Ե���Ա���ǰ����������˵
��Ա�������ݳ������Ķ�ԡ�ûʲô�µĻ����ǲ�Ҫ��ȥΪ�
LONG);
        set("objects",([
                __DIR__"npc/guanjia" : 1,
                __DIR__"npc/jiading" : 2,
        ]));
        set("exits", ([
  		"south" : __DIR__"yanlingdong1",
	]));
        set("outdoors", "zhongzhou");

        set("coor/x", -210);
	set("coor/y", 0);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
