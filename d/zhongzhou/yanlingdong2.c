inherit ROOM;

void create()
{
  	set ("short", "���궫·");
  	set ("long", @LONG
�������ݵ�һ����·����·��������������ݳǡ�������
�Ϳ��Գ����ݳ��ˡ����˳Ƕ��˱Ƚ�ƫƧ������ı����˴�
���ѷ��������ص���ס�ˡ�
LONG);

	set("outdoors", "zhongzhou");

  	set("exits", ([
    		"northwest" : __DIR__"yanlingdong1",
    		"east"  : __DIR__"dongmeng",
	]));

        set("objects",([
                __DIR__"npc/gugong":1,
                __DIR__"npc/laogugong":2,
        ]));

         set("coor/x", -200);
	set("coor/y", -20);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
