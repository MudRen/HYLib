inherit ROOM;
void create()
{
  	set ("short", "������·");
  	set ("long", @LONG
�������������߾͵���������·���������ݳ��ڵ�һ����
�֡����ߵķ��ݿ���ȥ�Ѿ��ܳ¾��ˡ��ֵ��������һ���ڽ�
�ķ��ӿ���ȥ����һ�ҵ��̡�
LONG);

	set("outdoors", "zhongzhou");

  	set("exits", ([  
    		"west" : __DIR__"yanling1",
    		"south" : __DIR__"dangpu",
    		"east"  : __DIR__"shizhongxin",
	]));

        set("coor/x", -240);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
