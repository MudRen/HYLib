inherit ROOM;

void create()
{
  	set ("short", "���궫·");
  	set ("long", @LONG
�������������߾͵������궫·���������ݳ��ڵ�һ����
�֡����ߵķ��ݿ���ȥ�Ѿ��ܳ¾��ˡ��������⵽���ֵط���
תһתҲ����һ����ζ��
LONG);

	set("outdoors", "zhongzhou");

  	set("exits", ([  
    		"west" : __DIR__"shizhongxin",
    		"east"  : __DIR__"yanlingdong1",
	]));
       
        set("objects", ([
        	"d/city/npc/liumang" : 1,
        ]));

        set("coor/x", -220);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
