inherit ROOM;
void create()
{
        set("short", "���Ƹ�");
        set("long", @LONG
�������Զ��������ͬ�罭�ϵ�֯�츮һ�������ġ�������ׯ������˵��
�Ǿ�����Ĺټ�С��̫̫Ҳ�ᵽ�����������·�����˵������·����Ͼͻ��
����һ˿���ǳ�����鲻�Խ��������Լ������ˣ��Լ�������....
LONG );
        set("exits", ([
                "north" : __DIR__"stdongjie1",
	]));
        set("objects", ([
                __DIR__"npc/huoji" : 1,
        ]));

	setup();
}
